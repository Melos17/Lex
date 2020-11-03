#ifndef LEX_WORD_H
#define LEX_WORD_H

#include <string>
#include <assert.h>

#include "../../dfa.h"

using std::string;

struct LexWord {
	string content;
	int type;
	bool isEnd;
	LexWord() : content(), type(-1), isEnd(false) {}
};


class WordReader {
public:
	WordReader(DFA&& dfa, const string& source) : mDFA(std::move(dfa)), mSource(source) {
		mIndex = 0;
	}

	LexWord getNextWord();
	char getNextChar();

private:
	DFA mDFA;
	string mSource;
	size_t mIndex;
};

#endif