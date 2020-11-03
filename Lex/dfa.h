#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <array>
#include <fstream>

#include "tree.h"

using std::vector;
using std::string;
using std::queue;
using std::unordered_map;
using std::unordered_set;
using std::array;
using std::to_string;

struct DFA {
	DFA() = default;
	DFA(const DFA& dfa) = default; // delete;
	DFA& operator=(DFA& dfa) = default; // delete;

	DFA(DFA&& dfa) {
		this->dfa = move(dfa.dfa);
		this->acceptStatus = move(dfa.acceptStatus);
		this->symbolIndex = move(dfa.symbolIndex);
		this->symbolsInfo = move(dfa.symbolsInfo);
		this->acceptRegex = move(dfa.acceptRegex);
	}

	DFA operator=(DFA&& dfa) {
		this->dfa = move(dfa.dfa);
		this->acceptStatus = move(dfa.acceptStatus);
		this->symbolIndex = move(dfa.symbolIndex);
		this->symbolsInfo = move(dfa.symbolsInfo);
		this->acceptRegex = move(dfa.acceptRegex);
		return std::move(*this);
	}

	vector<vector<int>> dfa;
	unordered_map<int, int> acceptStatus;
	array<size_t, 128> symbolIndex;

	vector<string> symbolsInfo;
	unordered_map<int, string> acceptRegex;

	bool check(string str, int& acceptId, string& match);
};

#endif