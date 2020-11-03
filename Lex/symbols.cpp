#include "symbols.h"

using std::to_string;

void SymbolCollection::addSymbol(size_t bit) {
	mFlags.set(bit, true);
}

void SymbolCollection::addSymbol(char c, bool exclusive) {
	if (c < 0) {
		throw "addSymbol: c is less than 0";
	}
	mFlags.set((size_t)c, !exclusive);
}

void SymbolCollection::addSymbol(char from_c, char to_c, bool exclusive) {
	if (from_c > to_c || from_c < 0) {
		throw "addSymbol: from_c is bigger than to_c or from_c is less than 0";
	}
	for (char c = from_c; c <= to_c; ++c) {
		mFlags.set((size_t)c, !exclusive);
	}
}

string SymbolCollection::getContent(bool showBracket) const {
	if (mFlags.all()) {
		if (showBracket) {
			return "[.]";
		}
		else {
			return ".";
		}
	}

	string str;
	char left = -1;
	char right = -1;

	for (unsigned char i = 0; i <= 128; ++i) {
		if (i != 128 && hasSymbol(i)) {
			right = i;
		}
		else {
			if (right - left > 1) {
				//str += std::to_string((int)(left + 1));
				str += getCharString(char(left + 1));
				str += '-';
				//str += std::to_string((int)right);
				str += getCharString(right);
			}
			else if (right - left > 0) {
				str += getCharString(right);
			}
			right = left = i;
		}
	}

	if (showBracket) {
		return "[" + str + "]";
	}
	else {
		return str;
	}
}

vector<bool> SymbolCollection::getArray() const {
	vector<bool> arr;
	for (size_t i = 0; i < 128; ++i) {
		arr.push_back(hasSymbol(i));
	}
	return arr;
}

void SymbolCollection::addAll() {
	mFlags.set();
}

void SymbolCollection::addCollection(SymbolCollection& collection) {
	mFlags |= collection.mFlags;
}

SymbolCollection operator~(const SymbolCollection& symbols) {
	SymbolCollection result;
	result.mFlags = ~symbols.mFlags;
	return result;
}

bitset<128> SymbolCollection::getFlags() const {
	return mFlags;
}

bool SymbolCollection::hasSymbol(size_t bit) const {
	return mFlags.test(bit);
}

string SymbolCollection::getCharString(char c) const {
	switch (c) {
	case '\n':
		return "\\n";
	case '\t':
		return "\\t";
	case '\v':
		return "\\v";
	case '\0':
		return "\\0";
	case '\\':
		return "\\\\";
	}
	if (c <= 32) {
		return "\\" + to_string((int)c);
	}
	return string() + c;
}
