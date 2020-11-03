#include <assert.h>
#include <functional>

#include "dfa_factory.h"

using std::find_if;
using std::not1;
using std::mem_fun;

DFA DfaFactory::produce(const string regex, int acceptId) {
	AbstractTreeNode* tree = mParse.parse(regex, acceptId);
	DFA dfa = calculateDFA_DFS(tree);
	return dfa;
}


DFA DfaFactory::produce(const vector<pair<string, int>>& regexes) {
	AbstractTreeNode* tree = mParse.parse(regexes);

	size_t symbolsCount = mParse.getSymbols().size();
	//DFA dfa = calculateDFA_BFS(tree);
	DFA dfa = calculateDFA_DFS(tree);

	for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
		SymbolCollection& symbol = mParse.getSymbol(symbolsId);
		for (size_t i = 0; i < 128; ++i) {
			if (symbol.hasSymbol(i)) {
				dfa.symbolIndex[i] = symbolsId;
			}
		}
	}

	dfa.symbolsInfo.resize(symbolsCount);
	// record auxiliary info.
	for (size_t i = 0; i < symbolsCount; ++i) {
		dfa.symbolsInfo[i] = mParse.getSymbol(i).getContent();
	}
	for (auto p : regexes) {
		dfa.acceptRegex[p.second] = p.first;
	}

#ifdef false
	int c = 0;
	for (auto column : dfa.dfa) {
		std::cout << c++ << ": ";
		for (auto val : column) {
			std::cout << val << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
		std::cout << "!" << symbolsId << ":" << parse.getSymbol(symbolsId).getContent() << std::endl;
	}

	for (size_t i = 0; i < 128; ++i) {
		std::cout << i << ":" << dfa.symbolIndex[i] << ";";
	}
	std::cout << std::endl;
#endif
	return dfa;
}


DFA DfaFactory::calculateDFA_BFS(AbstractTreeNode* tree) {
	DFA dfa;
	size_t symbolsCount = mParse.getSymbols().size();

	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows = calculateFollows(tree);
	unordered_set<AbstractTreeLeaf*> statusSet = tree->getFirstPos();
	queue<size_t> uncheckedStatusSetIds;
	size_t statusId = addStatusSet(statusSet);
	uncheckedStatusSetIds.push(statusId);

	while (!uncheckedStatusSetIds.empty()) {
		size_t statusId = uncheckedStatusSetIds.front();
		uncheckedStatusSetIds.pop();
		unordered_set<AbstractTreeLeaf*> statusSet = getStatusSet(statusId);
		if (dfa.dfa.size() <= statusId) {
			dfa.dfa.resize(statusId + 1, vector<int>(symbolsCount, -1));
		}

		for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
			unordered_set<AbstractTreeLeaf*> newStatus;
			bool accepted = false;
			int acceptedId = -1;

			for (AbstractTreeLeaf* status : statusSet) {
				assert(status != nullptr);
				if (mParse.getSymbol(symbolsId) == status->getSymbols()) {
					for (AbstractTreeLeaf* follow : follows[status]) {
						if (follow->getType() == AbstractTreeNode::End) {
							accepted = true;
							AbstractTreeEndLeaf* endLeaf = (AbstractTreeEndLeaf*)follow;
							if (acceptedId == -1 || acceptedId > endLeaf->getAcceptId()) {
								acceptedId = endLeaf->getAcceptId();
							}
						}
						newStatus.emplace(follow);
					}
				}
			}

			if (newStatus.size() > 0) {
				size_t newStatusSetId = getStatusSetId(newStatus);;
				if (newStatusSetId == 0xffffffff) {
					newStatusSetId = addStatusSet(newStatus);
					uncheckedStatusSetIds.push(newStatusSetId);
				}
				if (accepted) {
					assert(dfa.acceptStatus.find(newStatusSetId) == dfa.acceptStatus.end() || dfa.acceptStatus[newStatusSetId] == acceptedId); // conflict. report in future.
					dfa.acceptStatus[newStatusSetId] = acceptedId;
				}

				dfa.dfa[statusId][symbolsId] = (int)newStatusSetId;
			}
		}
	}
	return dfa;
}


DFA DfaFactory::calculateDFA_DFS(AbstractTreeNode* tree) {
	DFA dfa;
	size_t symbolsCount = mParse.getSymbols().size();

	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows = calculateFollows(tree);
	unordered_set<AbstractTreeLeaf*> statusSet = tree->getFirstPos();
	size_t newStatusId = addStatusSet(statusSet);
	mStatusIdSwitch[newStatusId] = mTableStatusCount++;
	dfa.dfa.resize(1, vector<int>(symbolsCount, -1));
	calculateDFA_DFS2(dfa, follows, statusSet, mStatusIdSwitch[newStatusId]);
	return dfa;
}


void DfaFactory::calculateDFA_DFS2(DFA& dfa, unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows, unordered_set<AbstractTreeLeaf*>& statusSet, size_t statusId) {
	size_t symbolsCount = mParse.getSymbols().size();
	for (size_t symbolsId = 0; symbolsId < symbolsCount; ++symbolsId) {
		unordered_set<AbstractTreeLeaf*> newStatusSet;
		bool accepted = false;
		int acceptedId = -1;

		for (AbstractTreeLeaf* status : statusSet) {
			assert(status != nullptr);
			if (mParse.getSymbol(symbolsId) == status->getSymbols()) {
				for (AbstractTreeLeaf* follow : follows[status]) {
					if (follow->getType() == AbstractTreeNode::End) {
						accepted = true;
						AbstractTreeEndLeaf* endLeaf = (AbstractTreeEndLeaf*)follow;
						// accept the bigger Id -- meaning the later regex.
						if (acceptedId == -1 || acceptedId > endLeaf->getAcceptId()) {
							acceptedId = endLeaf->getAcceptId();
						}
					}
					newStatusSet.emplace(follow);
				}
			}
		}

		if (newStatusSet.size() > 0) {

			size_t newStatusId = getStatusSetId(newStatusSet);
			if (newStatusId == 0xffffffff) {
				newStatusId = addStatusSet(newStatusSet);

				if (find_if(newStatusSet.begin(), newStatusSet.end(), not1(mem_fun(&AbstractTreeLeaf::isEnd))) == newStatusSet.end()) {
					mStatusIdSwitch[newStatusId] = -1 - mStatusIdSwitch.size();
				}
				else {
					mStatusIdSwitch[newStatusId] = mTableStatusCount++;
					dfa.dfa.resize(mTableStatusCount, vector<int>(symbolsCount, -1));
				}

				calculateDFA_DFS2(dfa, follows, newStatusSet, newStatusId);
			}

			int newStatusIdSwitch = mStatusIdSwitch[newStatusId];
			int oriStatusIdSwitch = mStatusIdSwitch[statusId];
			if (accepted) {
				assert(dfa.acceptStatus.find(newStatusIdSwitch) == dfa.acceptStatus.end() || dfa.acceptStatus[newStatusIdSwitch] == acceptedId); // conflict. report in future.
				dfa.acceptStatus[newStatusIdSwitch] = acceptedId;
			}

			dfa.dfa[oriStatusIdSwitch][symbolsId] = newStatusIdSwitch;
		}
	}

#ifdef LEX_INVALID_STATUS_SPATIAL_OPTIMIZATION

#endif
}

unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> DfaFactory::calculateFollows(AbstractTreeNode* tree) {
	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows;

	queue<AbstractTreeNode*> nodes;
	nodes.push(tree);
	while (!nodes.empty()) {
		AbstractTreeNode* node = nodes.front();
		nodes.pop();

		AbstractTreeNode* leftNode = NULL;
		AbstractTreeNode* rightNode = NULL;

		if (node->getType() == AbstractTreeNode::Or) {
			leftNode = node->getLeftNode();
			rightNode = node->getRightNode();
			nodes.push(leftNode);
			nodes.push(rightNode);
		}
		else {
			if (node->getType() == AbstractTreeNode::And) {
				leftNode = node->getLeftNode();
				rightNode = node->getRightNode();
			}
			else if (node->getType() == AbstractTreeNode::Closure || node->getType() == AbstractTreeNode::ClosurePlus) {
				leftNode = node->getNode();
				rightNode = node->getNode();
			}

			if (leftNode != NULL && rightNode != NULL) {
				unordered_set<AbstractTreeLeaf*> lastPosSet = leftNode->getLastPos();
				unordered_set<AbstractTreeLeaf*> firstPosSet = rightNode->getFirstPos();
				for (AbstractTreeLeaf* lastPos : lastPosSet) {
					for (AbstractTreeLeaf* firstPos : firstPosSet) {
						follows[lastPos].push_back(firstPos);
						//std::cout << (lastPos ? lastPos->getSymbols().getContent() : "#") << ">" << (firstPos ? firstPos->getSymbols().getContent() : "#") << std::endl; //
					}
				}
				nodes.push(leftNode);
				nodes.push(rightNode);
			}
		}

	}

	return move(follows);
}


size_t DfaFactory::getStatusSetId(unordered_set<AbstractTreeLeaf*>& status) {
	for (size_t i = 0; i < mStatus.size(); ++i) {
		if (mStatus[i] == status) {
			return i;
		}
	}
	return 0xffffffff;
}

size_t DfaFactory::addStatusSet(unordered_set<AbstractTreeLeaf*>& status) {
	mStatus.push_back(status);
	return mStatus.size() - 1;
}
