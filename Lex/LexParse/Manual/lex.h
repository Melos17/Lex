#ifndef LEX_H
#define LEX_H

#include <string>
#include <vector>
#include <unordered_map>

#include "lex_word.h"

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;


class LexHandler {
public:
	LexHandler(DFA&& dfa, const string& source) : mWordReader(std::move(dfa), source) {}

	void handle();

	void handlePart1StringConstant();
	void handlePart2Target();
	void handlePart3Code();

	void output(string filePath, string className);

private:
	WordReader mWordReader;
	unordered_map<string, string> mStringConstant;
	vector<pair<string, string>> mRegexAndCode;
	string mComposeCode;
};

#endif //LEX_H