#ifndef SYNTAX_H
#define SYNTAX_H

#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <iostream>

struct DFA {
	std::vector<std::vector<int>> dfa;
	std::unordered_map<int, int> acceptStatus;
	std::array<size_t, 128> symbolIndex;
};

class RegexWord {
public:
	RegexWord(std::string source) : mSource(source) {
		mIndex = 0;
	}
	
	std::string& getCurWord() {
		return mCurWord;
	}
	
	char getNextChar() {
		if (mIndex >= mSource.size()) return '\0';
		else return mSource[mIndex++];
	}
	
	// find next word, run relative code and return assigning value.
	// return -1 if reach the end.
	int GetNextWord() {
		mCurWord.clear();
		int status = 0;
		int type = -1;
		size_t startPos = mIndex;
		size_t acceptPos = mIndex;
		
		while (mIndex < mSource.size()) {
			char c = mSource[mIndex++];
			if (c < 0) continue; // ignore unkonwn ASCII
			size_t symbol = sDFA.symbolIndex[c];
			status = sDFA.dfa[symbol][status];
			if (status < 0) {
				if (type == -1) { // error
					mCurWord = mSource.substr(startPos, mIndex - startPos);
					std::cout << "Word Error:" << mCurWord << std::endl;
					return -2;
				}
				mIndex = acceptPos;
				break;
			}
			auto it = sDFA.acceptStatus.find(status);
			if (it != sDFA.acceptStatus.end()) {
				type = it->second;
				mCurWord = mSource.substr(startPos, mIndex - startPos);
				acceptPos = mIndex;
			}
		}
		
		if (type != -1) {
			int ret = runRelativeCode(type);
			if (ret != -1) {
				return ret;
			} else {
				return GetNextWord();
			}
		}
		return -1;
	}

private:
	std::string mSource;
	std::string mCurWord;
	size_t mIndex;
	static const DFA sDFA;
	
	int runRelativeCode(int type);
};

#endif