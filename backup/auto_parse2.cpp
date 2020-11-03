#include "auto_parse.h"


vector<vector<Action>> SingleRegexParse::sAction = {
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	6},	{Action::Error, 	0},	{Action::Shift, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},},
	{	{Action::Reduce, 	2},	{Action::Shift, 	10},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	2},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},},
	{	{Action::Reduce, 	4},	{Action::Reduce, 	4},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	6},	{Action::Reduce, 	4},	{Action::Shift, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	5},	{Action::Reduce, 	5},	{Action::Shift, 	12},	{Action::Shift, 	13},	{Action::Shift, 	14},	{Action::Reduce, 	5},	{Action::Reduce, 	5},	{Action::Reduce, 	5},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	5},	{Action::Reduce, 	5},},
	{	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Reduce, 	9},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	9},	{Action::Reduce, 	9},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	6},	{Action::Error, 	0},	{Action::Shift, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	18},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},	{Action::Reduce, 	12},},
	{	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},	{Action::Reduce, 	13},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	6},	{Action::Error, 	0},	{Action::Shift, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	3},	{Action::Reduce, 	3},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	3},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},},
	{	{Action::Reduce, 	6},	{Action::Reduce, 	6},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	6},	{Action::Reduce, 	6},	{Action::Reduce, 	6},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	6},	{Action::Reduce, 	6},},
	{	{Action::Reduce, 	7},	{Action::Reduce, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	7},	{Action::Reduce, 	7},	{Action::Reduce, 	7},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	7},	{Action::Reduce, 	7},},
	{	{Action::Reduce, 	8},	{Action::Reduce, 	8},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	8},	{Action::Reduce, 	8},	{Action::Reduce, 	8},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	8},	{Action::Reduce, 	8},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	20},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	14},	{Action::Shift, 	21},	{Action::Reduce, 	14},	{Action::Reduce, 	14},	{Action::Reduce, 	14},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	23},	{Action::Error, 	0},	{Action::Shift, 	18},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	18},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	1},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	1},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},},
	{	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Reduce, 	10},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	10},	{Action::Reduce, 	10},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	17},	{Action::Error, 	0},	{Action::Shift, 	18},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Reduce, 	11},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	11},	{Action::Reduce, 	11},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	16},	{Action::Error, 	0},	{Action::Shift, 	18},	{Action::Shift, 	8},	{Action::Shift, 	9},},
	{	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Error, 	0},	{Action::Reduce, 	15},	{Action::Error, 	0},	{Action::Reduce, 	15},	{Action::Reduce, 	15},	{Action::Reduce, 	15},},
};

vector<vector<StatusId>> SingleRegexParse::sGoto = {
	{	1,	2,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	11,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	15,	2,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	16,	17,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	19,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	16,	22,},
	{	-1,	-1,	-1,	-1,	16,	24,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	25,	-1,},
	{	-1,	-1,	-1,	-1,	16,	22,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	16,	22,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
};

vector<Reduce> SingleRegexParse::sReduce = {
	{0,1},
	{0,3},
	{0,1},
	{1,2},
	{1,1},
	{2,1},
	{2,2},
	{2,2},
	{2,2},
	{3,1},
	{3,3},
	{3,3},
	{4,1},
	{4,1},
	{5,1},
	{5,3},
	{5,2},
	{5,2},
};

unordered_map <StatusId, string> SingleRegexParse::sStatusToUnitName = {
	{0,"$"},
	{1,"expression"},
	{2,"and_expression"},
	{3,"unary_expression"},
	{4,"unique_expression"},
	{5,"character"},
	{6,"("},
	{7,"["},
	{8,"Normal_Character"},
	{9,"Escape_Character"},
	{10,"|"},
	{11,"unary_expression"},
	{12,"*"},
	{13,"+"},
	{14,"?"},
	{15,"expression"},
	{16,"character"},
	{17,"symbols_expression"},
	{18,"^"},
	{19,"and_expression"},
	{20,")"},
	{21,"-"},
	{22,"symbols_expression"},
	{23,"]"},
	{24,"symbols_expression"},
	{25,"character"},
};

unordered_map<int, TerminalId> SingleRegexParse::sWordTypeToId = {
	{')',6},
	{'|',1},
	{'\0',0},
	{'*',2},
	{'[',7},
	{'+',3},
	{'?',4},
	{'(',5},
	{']',8},
	{'-',9},
	{'^',10},
	{RegexWord::Normal_Character,11},
	{RegexWord::Escape_Character,12},
};

void SingleRegexParse::reduce(size_t reduceId) {
	/*
	switch(reduceId) {
	case 1: {
// expression -> and_expression | and_expression 
		AndExpression* unit3 = (AndExpression*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		AndExpression* unit1 = (AndExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		Expression* parent = generateExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 2: {
// expression -> and_expression 
		AndExpression* unit1 = (AndExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		Expression* parent = generateExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 3: {
// and_expression -> unary_expression unary_expression 
		UnaryExpression* unit2 = (UnaryExpression*)mUnitStack.top();
		mUnitStack.pop();
		UnaryExpression* unit1 = (UnaryExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		AndExpression* parent = generateAndExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 4: {
// and_expression -> unary_expression 
		UnaryExpression* unit1 = (UnaryExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		AndExpression* parent = generateAndExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 5: {
// unary_expression -> unique_expression 
		UniqueExpression* unit1 = (UniqueExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		UnaryExpression* parent = generateUnaryExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 6: {
// unary_expression -> unique_expression * 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		UniqueExpression* unit1 = (UniqueExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		UnaryExpression* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 7: {
// unary_expression -> unique_expression + 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		UniqueExpression* unit1 = (UniqueExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		UnaryExpression* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 8: {
// unary_expression -> unique_expression ? 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		UniqueExpression* unit1 = (UniqueExpression*)mUnitStack.top();
		mUnitStack.pop();
		
		UnaryExpression* parent = generateUnaryExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 9: {
// unique_expression -> character 
		Character* unit1 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		
		UniqueExpression* parent = generateUniqueExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 10: {
// unique_expression -> ( expression ) 
		TerminalUnit* unit3 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Expression* unit2 = (Expression*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		UniqueExpression* parent = generateUniqueExpression(unit1, unit2, unit3);
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
		
		UniqueExpression* parent = generateUniqueExpression(unit1, unit2, unit3);
		mUnitStack.push(parent);
		break;
	}
	case 12: {
// character -> Normal_Character 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Character* parent = generateCharacter(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 13: {
// character -> Escape_Character 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Character* parent = generateCharacter(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 14: {
// symbols_expression -> character 
		Character* unit1 = (Character*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 15: {
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
	case 16: {
// symbols_expression -> ^ symbols_expression 
		SymbolsExpression* unit2 = (SymbolsExpression*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		SymbolsExpression* parent = generateSymbolsExpression(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 17: {
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
	}*/
}
