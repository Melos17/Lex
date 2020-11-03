#ifndef Auto_Lex_LexWord_H
#define Auto_Lex_LexWord_H

#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <iostream>

namespace Auto_Lex {

struct DfaTable {
	std::vector<std::vector<int>> dfa;
	std::unordered_map<size_t, int> acceptStatus;
	std::array<size_t, 128> symbolIndex;
};

class LexWord {
public:
	LexWord(std::string source) : mSource(source) {
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

	// <user definition
	enum LexSymbolType {
		Parenthese_Left = '(',
		Parenthese_Right = ')',
		Star = '*',
		Plus = '+',
		Question = '?',
		Or = '|',
		Identifier = 128,
		String,
		Regex_Code,
		Constant,
		Segment_Constant_Left,
		Segment_Constant_Right,
		Segment_Target_Left,
		Segment_Target_Right,
		Segment_Code_H_Outside,
		Segment_Code_H_Public,
		Segment_Code_H_Private,
		Segment_Code_Cpp,
		Segment_Code_DFA_Cpp,
		Output,
		ClassName,
		Version,
		Namespace,
		Blank,
		Comment,
		End = -1,
	};
	// user definition>

private:
	std::string mSource;
	std::string mCurWord;
	size_t mIndex;
	static const DfaTable sDFA;
	
	int runRelativeCode(int type);

	// <user definition
	void catch_code();
	// user definition>

};

}

#endif