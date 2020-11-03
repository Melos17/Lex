#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <iostream>

#include "lex.h"
#include "..\..\RegexParse\multi_regex_parse.h"
#include "..\..\dfa.h"
#include "..\..\produce.h"
#include "..\..\dfa_factory.h"
#include "lex_dfa_factory.h"

using std::string;
using std::ofstream;


void LexHandler::handle() {
	handlePart1StringConstant();
	handlePart2Target();
	handlePart3Code();
}


void LexHandler::handlePart1StringConstant() {
	LexWord word = mWordReader.getNextWord();
	string constantName;
	string stringContent;
	while (!word.isEnd && word.type != LexDfaFactory::Segment) {
		switch (word.type) {
		case LexDfaFactory::NextLine: {
			if (constantName.size() > 0 && stringContent.size() > 0) {
				mStringConstant[constantName] = stringContent;
			}
			constantName.clear();
			stringContent.clear();
			break;
		}
		case LexDfaFactory::Identifier: {
			constantName = word.content;
			break;
		}
		case LexDfaFactory::String: {
			string content = word.content.substr(1, word.content.size() - 2);
			stringContent += "(" + content + ")";
			break;
		}
		case LexDfaFactory::Parenthese_Left:
		case LexDfaFactory::Parenthese_Right:
		case LexDfaFactory::Star:
		case LexDfaFactory::Plus:
		case LexDfaFactory::Question:
		case LexDfaFactory::Or: {
			stringContent += word.content;
			break;
		}
		case LexDfaFactory::Brace_Left: { // need error handler in future
			word = mWordReader.getNextWord();
			assert(word.type == LexDfaFactory::Identifier);

			stringContent += "(" + mStringConstant[word.content] + ")";
			word = mWordReader.getNextWord();
			assert(word.type == LexDfaFactory::Brace_Right);
			break;
		}
		case LexDfaFactory::Blank: {
			break;
		}
		case LexDfaFactory::Brace_Right: {
			assert(false);
			break;
		}
		}

		word = mWordReader.getNextWord();
	}
}


void LexHandler::handlePart2Target() {
	LexWord word = mWordReader.getNextWord();
	string regex;
	bool scanChunk = false;
	while (!word.isEnd && word.type != LexDfaFactory::Segment) {
		switch (word.type) {
		case LexDfaFactory::String: {
			regex += word.content.substr(1, word.content.size() - 2);
			break;
		}
		case LexDfaFactory::Parenthese_Left:
		case LexDfaFactory::Parenthese_Right:
		case LexDfaFactory::Star:
		case LexDfaFactory::Plus:
		case LexDfaFactory::Question:
		case LexDfaFactory::Or: {
			regex += word.content;
			break;
		}
		case LexDfaFactory::Brace_Left: { // need error handler in future
			if (!scanChunk) {
				word = mWordReader.getNextWord();
				assert(word.type == LexDfaFactory::Identifier);
				regex += mStringConstant[word.content];
				word = mWordReader.getNextWord();
				assert(word.type == LexDfaFactory::Brace_Right);
			}
			else {
				string chunk = "{";
				int braceCount = 1;
				char last = 0;
				char nextChar = mWordReader.getNextChar();
				while (braceCount > 0 && nextChar != '\0') {
					if (nextChar == '}' && last != '\'') {
						--braceCount;
					}
					else if(nextChar == '{' && last != '\'') {
						++braceCount;
					}
					chunk += nextChar;
					last = nextChar;
					nextChar = mWordReader.getNextChar();
				}
				assert(braceCount == 0);
				mRegexAndCode.push_back(make_pair(regex, chunk));
				std::cout << regex << "~" << chunk << std::endl; //
				regex = "";
				scanChunk = false;
			}
			break;
		}
		case LexDfaFactory::NextLine: {
			break;
		}
		case LexDfaFactory::Blank: {
			scanChunk = true;
			break;
		}
		case LexDfaFactory::Identifier:
		case LexDfaFactory::Brace_Right: {
			assert(false);
			break;
		}
		}

		word = mWordReader.getNextWord();
	}
}


void LexHandler::handlePart3Code() {
	char c = mWordReader.getNextChar();
	while (c != '\0') {
		mComposeCode += c;
		c = mWordReader.getNextChar();
	}
}


void LexHandler::output(string filePath, string className) {
	std::vector<std::pair<string, int>> regexes;
	for (size_t i = 0; i < mRegexAndCode.size(); ++i) {
		regexes.push_back(make_pair(mRegexAndCode[i].first, (int)i));
	}
	DfaFactory dfaFactory;
	DFA dfa = dfaFactory.produce(regexes);

	// Produce::produceWordH("word_ori.h", filePath + "word.h");
	// Produce::produceDfaCpp(filePath + "wordDfa.cpp", dfa, className);
	// Produce::produceWordCpp(filePath + "word.cpp", mRegexAndCode, mComposeCode, className);
}
