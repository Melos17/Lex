#include "../../feature.h"

#ifdef MANUAL_REGEX_PARSE

#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include "..\..\tree.h"

using std::string;
using std::vector;
using std::pair;
using std::stack;


struct ParseUnit
{
	enum ParseUnitType {
		End,
		Parenthese_Left, Parenthese_Right, // ()
		Or, // [words]|[words]
		And, // [words]`[words]
		Closure, // [words]*
		ClosurePlus, // [words]+
		OneOrNone, // [words]?
		Symbols, // [words]
		Unknown,
	};
	ParseUnitType type;
	SymbolCollection symbols;
};


class SingleRegexParse {
	enum OpType {
		Push,
		Op1,
		Op2,
		Error,
		ParEnd,
		End,
	};

public:
	SingleRegexParse(const string& regex) : mRegex(regex) {}
	AbstractTreeNode* parse();

private:
	void op1(stack<ParseUnit>& parseUnitStack, stack<AbstractTreeNode*>& treeNodeStack);
	void op2(stack<ParseUnit>& parseUnitStack, stack<AbstractTreeNode*>& treeNodeStack);

	string mRegex;
};


#endif
#endif
