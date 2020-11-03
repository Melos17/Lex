#include "../../feature.h"

#ifdef AUTO_REGEX_PARSE

#ifndef REGEX_PARSE_AUTO_EXPRESSION_H
#define REGEX_PARSE_AUTO_EXPRESSION_H

#include "auto_parse.h"
#include "..\..\symbols.h"
#include "..\..\tree.h"
#include <assert.h>

struct Character {
	char val;
	bool all;
};

struct SymbolsExpression {
	SymbolCollection symbols;
};

// expression : expression '|' and_expression
AbstractTreeNode* generateExpression(AbstractTreeNode* unit1, TerminalUnit* unit2, AbstractTreeNode* unit3) {
	delete unit2;
	return new AbstractTreeNode(AbstractTreeNode::Or, unit1, unit3);
}

// expression : and_expression
// and_expression : unary_expression
// unary_expression : unique_expression
AbstractTreeNode* generateExpression(AbstractTreeNode* unit1) {
	return unit1;
}

// and_expression : and_expression unary_expression
AbstractTreeNode* generateAndExpression(AbstractTreeNode* unit1, AbstractTreeNode* unit2) {
	return new AbstractTreeNode(AbstractTreeNode::And, unit1, unit2);
}

// unary_expression
// : unique_expression '*'
// | unique_expression '+'
// | unique_expression '?'
AbstractTreeNode* generateUnaryExpression(AbstractTreeNode* unit1, TerminalUnit* unit2) {
	int type = unit2->type;
	delete unit2;
	switch (type) {
	case '*':
		return new AbstractTreeNode(AbstractTreeNode::Closure, unit1);
	case '+':
		return new AbstractTreeNode(AbstractTreeNode::ClosurePlus, unit1);
	case '?':
		return new AbstractTreeNode(AbstractTreeNode::OneOrNone, unit1);
	}
	assert(false);
	return nullptr;
}

// unique_expression : character
AbstractTreeNode* generateUniqueExpression(Character* unit1) {
	SymbolCollection symbols;
	if (unit1->all) {
		symbols.addAll();
	}
	else {
		symbols.addSymbol(unit1->val);
	}
	AbstractTreeLeaf* leaf = new AbstractTreeLeaf(symbols);
	delete unit1;
	return leaf;
}

// unique_expression : '(' expression ')'
AbstractTreeNode* generateUniqueExpression(TerminalUnit* unit1, AbstractTreeNode* unit2, TerminalUnit* unit3) {
	delete unit1;
	delete unit3;
	return unit2;
}

// unique_expression : '[' symbols_expression ']'
AbstractTreeNode* generateUniqueExpression(TerminalUnit* unit1, SymbolsExpression* unit2, TerminalUnit* unit3) {
	AbstractTreeLeaf* leaf = new AbstractTreeLeaf(unit2->symbols);
	delete unit1;
	delete unit2;
	delete unit3;
	return leaf;
}

// unique_expression : '-'
// unique_expression : '^'
AbstractTreeNode* generateUniqueExpression(TerminalUnit* unit1) {
	SymbolCollection symbols;
	symbols.addSymbol(unit1->word.at(0));
	AbstractTreeLeaf* leaf = new AbstractTreeLeaf(symbols);
	delete unit1;
	return leaf;
}

// character
// : Normal_Character
// | Escape_Character
// | '.'
Character* generateCharacter(TerminalUnit* unit1) {
	Character* unit = new Character();
	if (unit1->type == RegexWord::Normal_Character) {
		assert(unit1->word.size() == 1);
		unit->val = unit1->word.at(0);
	}
	else if (unit1->type == '.') {
		unit->all = true;
	}
	else {
		assert(unit1->word.size() == 2);
		assert(unit1->word.at(0) == '\\');
		switch (unit1->word.at(1)) {
		case '(': case ')':
		case '[': case ']':
		case '{': case '}':
		case '\'': case '\"':
		case '*': case '+': case '?': case '$':
		case '.':  case '|': case '-': case '^': case '\\': case ',':
			unit->val = unit1->word.at(1);
			break;
		case 't':
			unit->val = '\t';
			break;
		case 'r':
			unit->val = '\r';
			break;
		case 'v':
			unit->val = '\v';
			break;
		case 'n':
			unit->val = '\n';
			break;
		case 'f':
			unit->val = '\f';
			break;
		default:
			unit->val = unit1->word.at(1);
			break;
		}
	}

	return unit;
}

// symbols_expression : character
SymbolsExpression* generateSymbolsExpression(Character* unit1) {
	SymbolsExpression* unit = new SymbolsExpression();
	unit->symbols.addSymbol(unit1->val);
	delete unit1;
	return unit;
}

// symbols_expression : character '-' character
SymbolsExpression* generateSymbolsExpression(Character* unit1, TerminalUnit* unit2, Character* unit3) {
	SymbolsExpression* unit = new SymbolsExpression();
	unit->symbols.addSymbol(unit1->val, unit3->val);
	delete unit1;
	delete unit2;
	delete unit3;
	return unit;
}

// symbols_expression : '^' symbols_expression
SymbolsExpression* generateSymbolsExpression(TerminalUnit* unit1, SymbolsExpression* unit2) {
	delete unit1;
	unit2->symbols = ~unit2->symbols;
	return unit2;
}

// symbols_expression :  + 
//  | '|'
//  | '*'
//  | '?'
//  | '('
//  | ')'
SymbolsExpression* generateSymbolsExpression(TerminalUnit* unit1) {
	SymbolsExpression* unit = new SymbolsExpression();
	unit->symbols.addSymbol(unit1->word.at(0));
	delete unit1;
	return unit;
}

// symbols_expression : symbols_expression symbols_expression
SymbolsExpression* generateSymbolsExpression(SymbolsExpression* unit1, SymbolsExpression* unit2) {
	unit1->symbols.addCollection(unit2->symbols);
	delete unit2;
	return unit1;
}

#endif
#endif
