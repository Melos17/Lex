#ifndef DFA_FACTORY_H
#define DFA_FACTORY_H

#include "dfa.h"
#include "feature.h"
#include "RegexParse/multi_regex_parse.h"

using std::pair;

class DfaFactory {
public:
	DfaFactory() { mTableStatusCount = 0; }

	DFA produce(const string regex, int acceptId = 0);
	DFA produce(const vector<pair<string, int>>& regexes);
private:
	DFA calculateDFA_BFS(AbstractTreeNode* tree);
	DFA calculateDFA_DFS(AbstractTreeNode* tree);

	void calculateDFA_DFS2(DFA& dfa, unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> follows, unordered_set<AbstractTreeLeaf*>& statusSet, size_t statusId);
	unordered_map<AbstractTreeLeaf*, vector<AbstractTreeLeaf*>> calculateFollows(AbstractTreeNode* tree);

	unordered_set<AbstractTreeLeaf*>& getStatusSet(size_t id) { return mStatus[id]; }
	size_t getStatusCount() { return mStatus.size(); }
	size_t getStatusSetId(unordered_set<AbstractTreeLeaf*>& status);
	size_t addStatusSet(unordered_set<AbstractTreeLeaf*>& status);

	RegexParse mParse;
	vector<unordered_set<AbstractTreeLeaf*>> mStatus;
	unordered_map<size_t, int> mStatusIdSwitch;
	size_t mTableStatusCount;
};

#endif
