#include <unordered_map>
#include <queue>
#include <functional>
#include <assert.h>

#include "multi_regex_parse.h"

#ifdef AUTO_REGEX_PARSE
#include "Auto\auto_parse.h"
#else
#include "Manual\manual_parse.h"
#endif // ! AUTO_REGEX_PARSE


namespace std
{
	template<> struct hash<vector<size_t>>
	{
		size_t operator()(const vector<size_t> & arr) const noexcept
		{
			size_t hash = 534381;
			for (auto i : arr)
				hash += 31 * hash + i;
			return hash;
		}
	};

	template<> struct hash<SymbolCollection>
	{
		size_t operator()(const SymbolCollection& symbol) const noexcept
		{
			size_t hash = 534381;
			std::bitset<128> bs = symbol.getFlags();
			for (size_t i = 0; i < 128; ++i)
				hash += 31 * hash + bs[i];
			return hash;
		}
	};
}


AbstractTreeNode* RegexParse::parseSingle(const string& regex, int acceptId) {
	SingleRegexParse singleRegexParse(regex);
	singleRegexParse.parse();
	AbstractTreeNode* tree = singleRegexParse.getAbstractTree();
	AbstractTreeNode* right = new AbstractTreeEndLeaf(acceptId);
	return new AbstractTreeNode(AbstractTreeNode::And, tree, right);
}

AbstractTreeNode* RegexParse::parse(const string& regex, int acceptId) {
	AbstractTreeNode* tree = parseSingle(regex, acceptId);
	calculateSymbols(tree);
	independLeaves(tree);
	return tree;
}

AbstractTreeNode* RegexParse::parse(const vector<pair<string, int>>& regexes) {
	AbstractTreeNode* tree = nullptr;
	for (size_t i = 0; i < regexes.size(); ++i) {
		const string& regex = regexes[i].first;
		int acceptId = regexes[i].second;
		AbstractTreeNode* node = parseSingle(regex, acceptId);
		if (tree == nullptr) {
			tree = node;
		}
		else {
			tree = new AbstractTreeNode(AbstractTreeNode::Or, node, tree);
		}
	}
	calculateSymbols(tree);
	independLeaves(tree);
	return tree;
}

void RegexParse::independLeaves(AbstractTreeNode* head) {
	std::unordered_map<std::vector<size_t>, SymbolCollection> groupsToSymbol;

	for (size_t bit = 0; bit < 128; ++bit) {
		std::vector<size_t> related_ids;
		for (size_t id = 0; id < mSymbols.size(); ++id) {
			if (mSymbols[id].hasSymbol(bit)) {
				related_ids.push_back(id);
			}
		}
		groupsToSymbol[related_ids].addSymbol(bit);
	}

	std::unordered_map<SymbolCollection, std::vector<SymbolCollection>> OriSymbolsToIndependentSymbols;
	for (auto keyValue : groupsToSymbol) {
		SymbolCollection& independentSymbols = keyValue.second;
		for (auto oriSymbolsId : keyValue.first) {
			SymbolCollection& oriSymbols = mSymbols[oriSymbolsId];
			OriSymbolsToIndependentSymbols[oriSymbols].push_back(independentSymbols);
		}
	}

	std::queue<AbstractTreeNode*> nodes;
	nodes.push(head);
	while (!nodes.empty()) {
		AbstractTreeNode* node = nodes.front();
		nodes.pop();
		AbstractTreeNode* two_node[2] = { node->getLeftNode(), node->getRightNode() };
		for (int i = 0; i < 2; ++i) {
			if (two_node[i] != NULL) {
				if (two_node[i]->getType() == AbstractTreeNode::Symbols) {
					AbstractTreeLeaf* leaf = (AbstractTreeLeaf*)two_node[i];
					std::vector<SymbolCollection>& symbols = OriSymbolsToIndependentSymbols[leaf->getSymbols()];

					AbstractTreeNode* head = new AbstractTreeLeaf(symbols[0]);
					for (unsigned int i = 1; i < symbols.size(); ++i) {
						AbstractTreeNode* leaf = new AbstractTreeLeaf(symbols[i]);
						head = new AbstractTreeNode(AbstractTreeNode::Or, head, leaf);
					}

					AbstractTreeNode* newChild = head;
					if (i == 0) node->setLeftNode(newChild);
					else node->setRightNode(newChild);
					delete leaf;
				}
				else {
					nodes.push(two_node[i]);
				}
			}
		}
	}

	std::vector<SymbolCollection> symbols;
	for (auto symbol : groupsToSymbol) {
		symbols.emplace_back(symbol.second);
	}
	mSymbols = move(symbols);
}

void RegexParse::calculateSymbols(AbstractTreeNode* tree) {
	if (tree == nullptr) return;

	if (tree->getType() == AbstractTreeNode::Symbols) {
		AbstractTreeLeaf* leaf = (AbstractTreeLeaf*) tree;
		assert(leaf != nullptr);
		auto funcIf = [&leaf](SymbolCollection& symbols) { return symbols == leaf->getSymbols(); };
		if (std::find_if(mSymbols.begin(), mSymbols.end(), funcIf) == mSymbols.end()) {
			mSymbols.emplace_back(leaf->getSymbols());
		}
		return;
	}
	
	calculateSymbols(tree->getLeftNode());
	calculateSymbols(tree->getRightNode());
}
