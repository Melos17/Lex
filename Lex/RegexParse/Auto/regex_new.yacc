
output:"F:/Programme/Lex/Lex/RegexParse/Auto/auto_parse"
version:"1.1.1"
parsename:"SingleRegexParse"
wordname:"RegexWord"
wordheader:"auto_word.h"
start:"expression"

{Grammar
expression { AbstractTreeNode : generateExpression }
	: expression '|' and_expression
	| and_expression
	;

and_expression { AbstractTreeNode}
	: and_expression unary_expression {generateAndExpression}
	| unary_expression {generateExpression}
	;

unary_expression { AbstractTreeNode : generateUnaryExpression }
	: unique_expression {generateExpression}
	| unique_expression '*'
	| unique_expression '+'
	| unique_expression '?'
	;

unique_expression { AbstractTreeNode : generateUniqueExpression }
	: character
	| '(' expression ')'
	| '[' symbols_expression ']'
	| '-'
	| '^'
	;

symbols_expression { SymbolsExpression : generateSymbolsExpression }
	: character
	| character '-' character
	| '^' symbols_expression
	| '+'
	| '|'
	| '*'
	| '?'
	| '('
	| ')'
	| symbols_expression symbols_expression
	;

character { Character : generateCharacter }
	: Normal_Character
	| Escape_Character
	| '.'
	;
Grammar}

{Code-H-Outside
// <user definition
using namespace Auto_Regex;
class AbstractTreeNode;
// user definition>
Code-H-Outside}

{Code-H-Public
	// <user definition
	AbstractTreeNode* getAbstractTree();
	// user definition>
Code-H-Public}

{Code-CPP
// <user definition
#include "expression.h"

AbstractTreeNode* SingleRegexParse::getAbstractTree() {
	AbstractTreeNode* tree = (AbstractTreeNode*)mUnitStack.top();
	mUnitStack.pop();
	return tree;
}
// user definition>
Code-CPP}
