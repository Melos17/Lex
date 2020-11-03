#include "auto_parse.h"

// <user definition
#include "expression.h"

AbstractTreeNode* SingleRegexParse::getAbstractTree() {
	AbstractTreeNode* tree = (AbstractTreeNode*)mUnitStack.top();
	mUnitStack.pop();
	return tree;
}
// user definition>

void SingleRegexParse::reduce(size_t reduceId) {
	switch(reduceId) {
	case 1: {
		// expression -> expression | and_expression 
		AbstractTreeNode* unit3 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 2: {
		// expression -> and_expression 
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 3: {
		// and_expression -> and_expression unary_expression 
		AbstractTreeNode* unit2 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateAndExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 4: {
		// and_expression -> unary_expression 
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 5: {
		// unary_expression -> unique_expression 
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 6: {
		// unary_expression -> unique_expression * 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 7: {
		// unary_expression -> unique_expression + 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 8: {
		// unary_expression -> unique_expression ? 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit1 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 9: {
		// unique_expression -> character 
		Character* unit1 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUniqueExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 10: {
		// unique_expression -> ( expression ) 
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AbstractTreeNode* unit2 = (AbstractTreeNode*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUniqueExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 11: {
		// unique_expression -> [ symbols_expression ] 
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		SymbolsExpression* unit2 = (SymbolsExpression*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUniqueExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 12: {
		// unique_expression -> - 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUniqueExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 13: {
		// unique_expression -> ^ 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		AbstractTreeNode* parent = generateUniqueExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 14: {
		// character -> Normal_Character 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Character* parent = generateCharacter(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 15: {
		// character -> Escape_Character 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Character* parent = generateCharacter(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 16: {
		// character -> . 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Character* parent = generateCharacter(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 17: {
		// symbols_expression -> character 
		Character* unit1 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 18: {
		// symbols_expression -> character - character 
		Character* unit3 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Character* unit1 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 19: {
		// symbols_expression -> ^ symbols_expression 
		SymbolsExpression* unit2 = (SymbolsExpression*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 20: {
		// symbols_expression -> + 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 21: {
		// symbols_expression -> | 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 22: {
		// symbols_expression -> * 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 23: {
		// symbols_expression -> ? 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 24: {
		// symbols_expression -> ( 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 25: {
		// symbols_expression -> ) 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 26: {
		// symbols_expression -> symbols_expression symbols_expression 
		SymbolsExpression* unit2 = (SymbolsExpression*)mUnitStack.top();
		mUnitStack.pop();
		SymbolsExpression* unit1 = (SymbolsExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	default:
		break;
	}
}
