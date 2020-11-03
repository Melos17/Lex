#ifndef PRODUCE_H
#define PRODUCE_H

#include <vector>
#include <string>
#include <fstream>

#include "dfa.h"

using std::vector;
using std::string;
using std::pair;
using std::ofstream;
using std::ifstream;
using std::ios;

class Produce {
public:
	static string getDfaString(const DFA& dfa, int prefixCount = 0, bool detail = false);
	static void produceWordHead(const string& codeOutside, const string& codePublic, const string& codePrivate);
	static void produceDfaCpp(const DFA& dfa, bool detail = false);
	static void produceWordCpp(const vector<pair<string, string>>& regexAndCode, const string& codeCpp);

	static void setOutputPath(const string& str);
	static void setClassName(const string& str) { mClassName = str; }
	static void setNamespace(const string& str) { mNamespace = str; }
	static void setVersion(const string& str) { mVersion = str; }

private:
	static string mOutputPath;
	static string mHeadName;
	static string mClassName;
	static string mNamespace;
	static string mVersion;
	
	static void replaceStr(string& source, const string& from, const string& to);
};

#endif // ! PRODUCE_H
