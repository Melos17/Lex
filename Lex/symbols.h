#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <bitset>
#include <vector>

using std::bitset;
using std::string;
using std::vector;

class SymbolCollection {
public:
	explicit SymbolCollection() {
	}

	explicit SymbolCollection(char c) {
		addSymbol(c);
	}
	bool operator==(const SymbolCollection& collection) const {
		return this->mFlags == collection.mFlags;
	}


	void addSymbol(size_t bit);
	void addSymbol(char c, bool exclusive = false);
	void addSymbol(char from_c, char to_c, bool exclusive = false);
	void addAll();
	void addCollection(SymbolCollection& collection);
	bool hasSymbol(size_t bit) const;

	string getContent(bool showBracket = false) const;
	vector<bool> getArray() const;
	bitset<128> getFlags() const;

	friend SymbolCollection operator~(const SymbolCollection& symbols);

private:
	bitset<128> mFlags;

	string getCharString(char c) const;
};

SymbolCollection operator~(const SymbolCollection& symbols);


#endif