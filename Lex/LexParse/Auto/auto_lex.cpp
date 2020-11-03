#include "auto_lex_parse.h"
#include <assert.h>

using namespace Auto_Lex;

// part : Segment_Code_H_Outside ;
void LexParse::addCodeHOutSide(TerminalUnit* unit) {
	mCodeHOutside += unit->word.substr(15, unit->word.size()-30);
	delete unit;
}

// part : Segment_Code_H_Public ;
void LexParse::addCodeHPublic(TerminalUnit* unit) {
	mCodeHPublic += unit->word.substr(14, unit->word.size() - 28);
	delete unit;
}

// part : Segment_Code_H_Private ;
void LexParse::addCodeHPrivate(TerminalUnit* unit) {
	mCodeHPrivate += unit->word.substr(15, unit->word.size() - 30);
	delete unit;
}

// part : Segment_Code_Cpp ;
void LexParse::addCodeCpp(TerminalUnit* unit) {
	mCodeCpp += unit->word.substr(9, unit->word.size() - 18);
	delete unit;
}

// output : Output String ;
void LexParse::setOutput(TerminalUnit* unit1, TerminalUnit* unit2) {
	mOutput = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part : ClassName String ;
void LexParse::setClassName(TerminalUnit* unit1, TerminalUnit* unit2) {
	mClassName = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part : Version String ;
void LexParse::setVersion(TerminalUnit* unit1, TerminalUnit* unit2) {
	mVersion = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// part : Namespace String ;
void LexParse::setNamespace(TerminalUnit* unit1, TerminalUnit* unit2) {
	mNamespace = unit2->word.substr(1, unit2->word.size() - 2);
	delete unit1;
	delete unit2;
}

// segment_constant_single : Identifier regex ;
void LexParse::addConstant(TerminalUnit* unit1, Regex* unit2) {
	mConstantRegex[unit1->word] = unit2->regex;
	delete unit1;
	delete unit2;
}

// segment_target_single : regex Regex_Code ;
void LexParse::addTarget(Regex* unit1, TerminalUnit* unit2) {
	mRegexAndCode.emplace_back(unit1->regex, unit2->word);
	delete unit1;
	delete unit2;
}

// regex : regex regex_base ;
Regex* LexParse::generateRegexBase(Regex* unit1, Regex* unit2) {
	unit1->regex += unit2->regex;
	delete unit2;
	return unit1;
}

// regex : regex_base ;
Regex* LexParse::generateRegexBase(Regex* unit) {
	return unit;
}

// regex_base : Constant | String | '*' | '+' | '?' | '(' | ')' ;
Regex* LexParse::generateRegexBase(TerminalUnit* unit) {
	Regex* regex = new Regex();
	regex->regex = unit->word;
	switch (unit->type) {
	case LexWord::Constant: {
		string constantName = unit->word.substr(1, unit->word.size() - 2);
		assert(mConstantRegex.find(constantName) != mConstantRegex.end()); // use undefined constant
		regex->regex = '(' + mConstantRegex[constantName] + ')';
		break;
	}
	case LexWord::String: {
		regex->regex = unit->word.substr(1, unit->word.size() - 2);
		break;
	}
	case '*':
	case '+':
	case '?':
	case '|':
	case '(':
	case ')': {
		regex->regex = unit->type;
		break;
	}
	default: {
		assert(false);
		break;
	}
	}
	delete unit;
	return regex;
}
