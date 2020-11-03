#include "../../feature.h"

#ifdef MANUAL_REGEX_PARSE

#include <iostream>

#include "scan.h"

Character Scan::nextChar() {
	if (mRegexPos == mRegex.size()) { return { Character::End }; }

	char c = mRegex.at(mRegexPos++);

	switch (c)
	{
	case '(': return { Character::Parenthese_Left , c };
	case ')': return  { Character::Parenthese_Right , c };
	case '[': return { Character::Bracket_Left , c };
	case ']': return  { Character::Bracket_Right , c };
	case '*': return  { Character::Star , c };
	case '+': return  { Character::Plus , c };
	case '?': return  { Character::Question , c };
	case '.': return  { Character::Dot , c };
	case '|': return  { Character::VerticalLine , c };
	case '-': return  { Character::Hyphen , c };
	case '^': return  { Character::Caret , c };
	case ' ': case '\t': case '\r': case '\v': case '\n': case '\f': case '%': case '\'': case '"':  case '{': case '}': case '/': case '<': case '>': case '=': case'&': case '!': case ';': case ':': case ',': case '~': case '#':
	case '$': case '`': case '@':
		return { Character::Normal_Character , c };
	}

	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_') { return { Character::Normal_Character , c }; }
	if (c >= '0' && c <= '9') { return { Character::Number , c }; }

	if (c == '\\') {
		if (mRegexPos != mRegex.size()) {
			c = mRegex.at(mRegexPos++);
			switch (c)
			{
			case '(': case ')':
			case '[': case ']':
			case '{': case '}':
			case '\'': case '\"':
			case '*': case '+': case '?': case '$':
			case '.':  case '|': case '-': case '^': case '\\':
				return { Character::Normal_Character , c };
			case 't':
				return { Character::Normal_Character , '\t' };
			case 'r':
				return { Character::Normal_Character , '\r' };
			case 'v':
				return { Character::Normal_Character , '\v' };
			case 'n':
				return { Character::Normal_Character , '\n' };
			case 'f':
				return { Character::Normal_Character , '\f' };
			default:
				--mRegexPos;
				return { Character::Normal_Character , '\\' };
			}
		}
		else {
			return { Character::Normal_Character , '\\' };
		}
	}

	return { Character::Unknown };
}


ParseUnit Scan::nextParseUnit() {
	if (mParseUnitCache.type != ParseUnit::Unknown) {
		ParseUnit unit = mParseUnitCache;
		mParseUnitCache = { ParseUnit::Unknown };
		return unit;
	}

	Character c = nextChar();

	//std::cout << c.val;

	switch (c.type) {
	case Character::Parenthese_Left: return { ParseUnit::Parenthese_Left };
	case Character::Parenthese_Right: return { ParseUnit::Parenthese_Right };
	case Character::Star: return { ParseUnit::Closure };
	case Character::Plus: return { ParseUnit::ClosurePlus };
	case Character::Question: return { ParseUnit::OneOrNone };
	case Character::VerticalLine: return { ParseUnit::Or };
	case Character::Hyphen:
	case Character::Caret:
	case Character::Number:
	case Character::Normal_Character: {
		SymbolCollection symbols(c.val);
		return { ParseUnit::Symbols , symbols };
	}
	case Character::Dot: {
		SymbolCollection symbols;
		symbols.addAll();
		return { ParseUnit::Symbols , symbols };
	}
	case Character::End: return { ParseUnit::End };
	case Character::Bracket_Left: {
		try {
			ParseUnit unit;
			unit.type = ParseUnit::Symbols;
			unit.symbols = parseSymbolCollection();
			return unit;
		}
		catch (...) {
			return { ParseUnit::Unknown };
		}
	}
	}

	return { ParseUnit::Unknown };
}

SymbolCollection Scan::parseSymbolCollection() {
	SymbolCollection symbols;
	Character stack[2];
	int stack_index = 0;
	bool exclusive = false;
	while (true) {
		Character c = nextChar();

		//std::cout << c.val;

		switch (c.type) {
		case Character::Caret: {
			symbols.addAll();
			exclusive = true; 
			break; 
		}
		case Character::Bracket_Right: { return symbols; }
		case Character::Number:
		case Character::Plus:
		case Character::Normal_Character:
			if (stack_index == 2) {
				if (stack[1].type != Character::Hyphen || stack[0].val > c.val) {
					throw "error stack overflow";
				}
				symbols.addSymbol(stack[0].val, c.val, exclusive);
				stack_index = 0;
			}
			else {
				symbols.addSymbol(c.val, exclusive);
				stack[0] = c;
				stack_index = 1;
			}
			break;
		case Character::Hyphen:
			if (stack_index == 0) {
				symbols.addSymbol('-', exclusive);
			}
			else if (stack_index == 1) {
				stack[stack_index++] = c;
			}
			else {
				throw "error stack overflow";
			}
			break;
		default: { throw "error [] expression"; }
		}
	}
	return symbols;
}


void Scan::cacheParseUnit(ParseUnit unit) {
	if (unit.type == ParseUnit::Unknown || mParseUnitCache.type != ParseUnit::Unknown) {
		throw "cacheParseUnit error";
	}
	mParseUnitCache = unit;
}

#endif