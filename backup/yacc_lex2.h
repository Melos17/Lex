#ifndef  CLEX_H
#define CLEX_H
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
using std::string;

struct DFA {
	std::vector<std::vector<int>> dfa;
	std::unordered_map<size_t, int> acceptStatus;
	std::array<size_t, 128> symbolIndex;
};

class CWord {
public:
	
	
	enum TOKEN_TYPE {
		IDENTIFIER=128, CHAR, CODE
	};	
	CWord(string source) : mSource(source) { mIndex = 0; }

	string& getCurWord() { return mCurWord; }
	char getNextChar() { if (mIndex >= mSource.size()) return '\0'; else return mSource[mIndex++]; }

	int GetNextWord() {
NextWordLoop:
		mCurWord.clear();
		int status = 0;
		int type = -1;
		size_t startPos = mIndex;
		while (mIndex < mSource.size()) {
			char c = mSource[mIndex++];
			if (c < 0) continue;
			size_t symbol = mDFA.symbolIndex[c];
			status = mDFA.dfa[symbol][status];
			if (status < 0) {
				--mIndex;
				break;
			}
			else if (mDFA.acceptStatus.find(status) != mDFA.acceptStatus.end()) {
				type = mDFA.acceptStatus.find(status)->second;
				mCurWord = mSource.substr(startPos, mIndex - startPos);
			}
		}
		if (type != -1) {
			switch( type ) {
				case 0:{ return(IDENTIFIER); }
				case 1:{ return(CHAR); }
				case 2:{ break; }
				case 3:{ return(':'); }
				case 4:{ return('|'); }
				case 5:{ return(';'); }
				case 6:{ return('{'); }
				case 7:{ return('}'); }
				case 8:{ return(CODE); }
			}
			goto NextWordLoop;
		}
		return -1;
	}

private:
	string mSource;
	string mCurWord;
	size_t mIndex;
	DFA mDFA =
	{
		{
			{	1,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	-1,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	2,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	13,	14,	12,	-1,	13, },
			{	3,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	4,	-1,	10,	-1,	4,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	-1,	-1,	11,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	5,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	6,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	7,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	8,	-1,	10,	-1,	-1,	-1,	-1,	-1,	12,	-1,	-1,	10,	12,	-1,	-1, },
			{	-1,	-1,	10,	-1,	4,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
			{	9,	-1,	10,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	10,	12,	-1,	-1, },
		},
		{
			{ 9, 5 },
			{ 1, 7 },
			{ 3, 3 },
			{ 12, 8 },
			{ 4, 0 },
			{ 13, 1 },
			{ 5, 4 },
			{ 6, 6 },
			{ 7, 2 },
			{ 14, 1 },
		},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 8, 8, 8, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 9, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 3, 11, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 5, 1, 1, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 6, 0, 1, 1, },
	};
};

#endif