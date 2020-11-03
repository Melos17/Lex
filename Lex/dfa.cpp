#include "dfa.h"
#include <iostream>

bool DFA::check(string str, int& acceptId, string& match) {
	int status = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		char c = str[i];
		size_t symbol = symbolIndex[c];
		status = dfa[status][symbol];
		if (status == -1) {
			return false;
		}
		else if (acceptStatus.find(status) != acceptStatus.end() && (i + 1 >= str.size() || dfa[symbolIndex[str[i + 1]]][status] == -1)) {
			acceptId = acceptStatus.find(status)->second;
			match = str.substr(0, i + 1);
			return true;
		}
	}
	return false;
}
