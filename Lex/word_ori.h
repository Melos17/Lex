#ifndef HEAD_H
#define HEAD_H

#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <iostream>

// namespace_left
struct DfaTable {
	std::vector<std::vector<int>> dfa;
	std::unordered_map<size_t, int> acceptStatus;
	std::array<size_t, 128> symbolIndex;
};
// CodeHOutSide
class WordClassName {
public:
	WordClassName(std::string source) : mSource(source) {
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
			status = sDFA.dfa[status][symbol];
			auto it = sDFA.acceptStatus.find(status);
			if (it != sDFA.acceptStatus.end()) {
				type = it->second;
				mCurWord = mSource.substr(startPos, mIndex - startPos);
				acceptPos = mIndex;
			}
			if (status < 0) {
				if (type == -1) { // error
					mCurWord = mSource.substr(startPos, mIndex - startPos);
					std::cout << "Word Error:" << mCurWord << std::endl;
					return -2;
				}
				mIndex = acceptPos;
				break;
			}
		}
		
		if (type != -1) {
			mIndex = acceptPos;
			int ret = runRelativeCode(type);
			if (ret != -1) {
				return ret;
			} else {
				return GetNextWord();
			}
		}
		return -1;
	}
	// CodeHPublic
private:
	std::string mSource;
	std::string mCurWord;
	size_t mIndex;
	static const DfaTable sDFA;
	
	int runRelativeCode(int type);
	// CodeHPrivate
};

// namespace_right
#endif
