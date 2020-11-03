#ifndef MULTI_REGEX_PARSE_H
#define MULTI_REGEX_PARSE_H

#include "..\tree.h"
#include "..\feature.h"

using std::pair;

class RegexParse {
public:
	RegexParse() {}
	AbstractTreeNode* parse(const string& regex, int acceptId = 0);
	AbstractTreeNode* parse(const vector<pair<string, int>>& regexes);

	vector<SymbolCollection>& getSymbols() { return mSymbols; }
	SymbolCollection& getSymbol(size_t id) { return mSymbols[id]; }

private:
	void calculateSymbols(AbstractTreeNode* tree);

	AbstractTreeNode* parseSingle(const string& regex, int acceptId);
	void independLeaves(AbstractTreeNode* head);
	vector<SymbolCollection> mSymbols;
};

#endif // ! MULTI_REGEX_PARSE_H