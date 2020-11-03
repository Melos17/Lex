#include "auto_lex_parse.h"

using namespace Auto_Lex;

void LexParse::reduce(size_t reduceId) {
	switch(reduceId) {
	case 3: {
		// part -> Output String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setOutput(unit1, unit2);
		break;
	}
	case 4: {
		// part -> ClassName String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setClassName(unit1, unit2);
		break;
	}
	case 5: {
		// part -> Version String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setVersion(unit1, unit2);
		break;
	}
	case 6: {
		// part -> Namespace String 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		setNamespace(unit1, unit2);
		break;
	}
	case 9: {
		// part -> Segment_Code_H_Outside 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHOutSide(unit1);
		break;
	}
	case 10: {
		// part -> Segment_Code_H_Public 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHPublic(unit1);
		break;
	}
	case 11: {
		// part -> Segment_Code_H_Private 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeHPrivate(unit1);
		break;
	}
	case 12: {
		// part -> Segment_Code_Cpp 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addCodeCpp(unit1);
		break;
	}
	case 17: {
		// segment_constant_single -> Identifier regex 
		Regex* unit2 = (Regex*)mUnitStack.top();
		mUnitStack.pop();
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		addConstant(unit1, unit2);
		break;
	}
	case 18: {
		// regex -> regex_base 
		Regex* unit1 = (Regex*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 19: {
		// regex -> regex regex_base 
		Regex* unit2 = (Regex*)mUnitStack.top();
		mUnitStack.pop();
		Regex* unit1 = (Regex*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1, unit2);
		mUnitStack.push(parent);
		break;
	}
	case 20: {
		// segment_target_single -> regex Regex_Code 
		TerminalUnit* unit2 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		Regex* unit1 = (Regex*)mUnitStack.top();
		mUnitStack.pop();
		
		addTarget(unit1, unit2);
		break;
	}
	case 21: {
		// regex_base -> Constant 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 22: {
		// regex_base -> String 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 23: {
		// regex_base -> * 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 24: {
		// regex_base -> + 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 25: {
		// regex_base -> ? 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 26: {
		// regex_base -> | 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 27: {
		// regex_base -> ( 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	case 28: {
		// regex_base -> ) 
		TerminalUnit* unit1 = (TerminalUnit*)mUnitStack.top();
		mUnitStack.pop();
		
		Regex* parent = generateRegexBase(unit1);
		mUnitStack.push(parent);
		break;
	}
	default:
		break;
	}
}
