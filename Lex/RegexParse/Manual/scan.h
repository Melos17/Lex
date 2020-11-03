#include "../../feature.h"

#ifdef MANUAL_REGEX_PARSE

#ifndef SCAN_H
#define SCAN_H

#include <string>
#include "manual_parse.h"

using std::string;

struct Character {
	enum CharType {
		Parenthese_Left, Parenthese_Right, // ()
		Bracket_Left, Bracket_Right, // []
		Star, // *
		Plus, // +
		Question, // ?
		Dot, // .
		VerticalLine, // |
		Hyphen, // -
		Caret, // ^
		Number, // 0-9
		Normal_Character,
		Unknown,
		End,
	};
	CharType type;
	char val;
};

class Scan {
public:
	Scan(string&& regex) :mRegex(regex) {
		mRegexPos = 0;
		mParseUnitCache = { ParseUnit::Unknown };
	}

	ParseUnit nextParseUnit();
	void cacheParseUnit(ParseUnit unit);
private:
	Character nextChar();
	SymbolCollection parseSymbolCollection();

	string mRegex;
	string::size_type mRegexPos;
	ParseUnit mParseUnitCache;
};

#endif //SCAN_H
#endif