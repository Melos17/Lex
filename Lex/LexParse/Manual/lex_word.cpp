#include "lex_word.h"

char WordReader::getNextChar() {
	//std::cout << mSource[mIndex];
	if (mIndex >= mSource.size()) return '\0';
	else return mSource[mIndex++];
}

LexWord WordReader::getNextWord() {
	LexWord word;
	int status = 0;
	size_t startPos = mIndex;
	size_t acceptPos = mIndex;

	while (mIndex < mSource.size()) {
		char c = mSource[mIndex++];
		size_t symbol = mDFA.symbolIndex[c];
		status = mDFA.dfa[status][symbol];
		if (status == -1) {
			assert(word.type != -1);
			mIndex = acceptPos;
			break;
		}
		else if (mDFA.acceptStatus.find(status) != mDFA.acceptStatus.end()) {
			word.type = mDFA.acceptStatus.find(status)->second;
			word.content = mSource.substr(startPos, mIndex - startPos);
			acceptPos = mIndex;
			if (status < 0) {
				break;
			}
		}
	}

	if (word.type == -1 && mIndex == mSource.size()) {
		word.isEnd = true;
	}

	std::cout << word.type << ":" << word.content << std::endl; //

	return word;
}
