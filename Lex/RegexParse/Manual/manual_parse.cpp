#include "../../feature.h"

#ifdef MANUAL_REGEX_PARSE

#include <iostream>
#include <assert.h>
#include <stack>

#include "manual_parse.h"
#include "scan.h"


AbstractTreeNode* SingleRegexParse::parse() {
	const static OpType OP[8][8] =
	{
		//			#			(			)			|			¡¤			*			+		£¿
			{	End,		Push,		Error,	Push,		Push,		Push,		Push,		Push }, // #
			{	Error,	Push,	  ParEnd,	Push,		Push,		Push,		Push,		Push }, // (
			{	Error,	Error,	Error,	Error,	Error,	Error,	Error,	Error, }, // )
			{	Op2,		Push,		Op2,		Op2,		Push,		Push,		Push,		Push,	 }, // |
			{	Op2,		Push,		Op2,		Op2,		Op2,		Push,		Push,		Push,	 }, // ¡¤
			{	Op1,		Push,		Op1,		Op1,		Op1,		Op1,		Op1,		Op1,	 }, // *
			{	Op1,		Push,		Op1,		Op1,		Op1,		Op1,		Op1,		Op1,	 }, // +
			{	Op1,		Push,		Op1,		Op1,		Op1,		Op1,		Op1,		Op1,	 }, // ?
	};

	Scan scan(move(mRegex));

	ParseUnit parseUnit = scan.nextParseUnit();
	ParseUnit lastUnit = { ParseUnit::Unknown };
	std::stack<ParseUnit> parseUnitStack;
	parseUnitStack.push({ ParseUnit::End });
	std::stack<AbstractTreeNode*> treeNodeStack;

	while (parseUnitStack.size() > 0) {
		if (parseUnit.type == ParseUnit::Symbols || parseUnit.type == ParseUnit::Parenthese_Left) {
			if (lastUnit.type != ParseUnit::Unknown && lastUnit.type != ParseUnit::Parenthese_Left && lastUnit.type != ParseUnit::Or && lastUnit.type != ParseUnit::And) {
				scan.cacheParseUnit(parseUnit);
				parseUnit = { ParseUnit::And };
				continue;
			}
		}

		assert(parseUnit.type != ParseUnit::Unknown);

		if (parseUnit.type == ParseUnit::Symbols) {
			AbstractTreeLeaf* leaf = new AbstractTreeLeaf(parseUnit.symbols);
			treeNodeStack.push(leaf);
			lastUnit = parseUnit;
			parseUnit = scan.nextParseUnit();
		}
		else {
			OpType opType = OP[parseUnitStack.top().type][parseUnit.type];
			switch (opType) {
			case Push:
				parseUnitStack.push(parseUnit);
				lastUnit = parseUnit;
				parseUnit = scan.nextParseUnit();
				break;
			case Op1:
				op1(parseUnitStack, treeNodeStack);
				break;
			case Op2:
				op2(parseUnitStack, treeNodeStack);
				break;
			case Error:
				assert(false);
				break;
			case ParEnd:
				parseUnitStack.pop();
				lastUnit = parseUnit;
				parseUnit = scan.nextParseUnit();
				break;
			case End:
				parseUnitStack.pop();
				break;
			}
		}
	}

	assert(treeNodeStack.size() == 1 && parseUnitStack.size() == 0);

	return treeNodeStack.top();
}



void SingleRegexParse::op1(std::stack<ParseUnit>& parseUnitStack, std::stack<AbstractTreeNode*>& treeNodeStack) {
	assert(treeNodeStack.size() > 0);

	ParseUnit unit = parseUnitStack.top();
	parseUnitStack.pop();
	AbstractTreeNode* node = treeNodeStack.top();
	treeNodeStack.pop();

	switch (unit.type) {
	case ParseUnit::Closure: {
		AbstractTreeNode* closureNode = new AbstractTreeNode(AbstractTreeNode::Closure, node);
		treeNodeStack.push(closureNode);
		break;
	}
	case ParseUnit::ClosurePlus: {
		AbstractTreeNode* closureNode = new AbstractTreeNode(AbstractTreeNode::ClosurePlus, node);
		treeNodeStack.push(closureNode);
		break;
	}
	case ParseUnit::OneOrNone: {
		AbstractTreeNode* oneOrNoneNode = new AbstractTreeNode(AbstractTreeNode::OneOrNone, node);
		treeNodeStack.push(oneOrNoneNode);
		break;
	}
	}
}


void SingleRegexParse::op2(std::stack<ParseUnit>& parseUnitStack, std::stack<AbstractTreeNode*>& treeNodeStack) {
	assert(treeNodeStack.size() > 1);

	ParseUnit unit = parseUnitStack.top();
	parseUnitStack.pop();
	AbstractTreeNode* rightNode = treeNodeStack.top();
	treeNodeStack.pop();
	AbstractTreeNode* leftNode = treeNodeStack.top();
	treeNodeStack.pop();

	switch (unit.type) {
	case ParseUnit::Or: {
		AbstractTreeNode* node = new AbstractTreeNode(AbstractTreeNode::Or, leftNode, rightNode);
		treeNodeStack.push(node);
		break;
	}
	case ParseUnit::And: {
		AbstractTreeNode* node = new AbstractTreeNode(AbstractTreeNode::And, leftNode, rightNode);
		treeNodeStack.push(node);
		break;
	}
	}
}

#endif