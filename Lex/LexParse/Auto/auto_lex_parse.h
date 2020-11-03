#ifndef Auto_Lex_LexParse_H
#define Auto_Lex_LexParse_H

#include <stack>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <memory>
#include <iostream>

#include "lex_auto_word.h"

using std::stack;
using std::string;
using std::unordered_map;
using std::vector;
using std::list;
using std::shared_ptr;
using std::cout;
using std::endl;

namespace Auto_Lex {

typedef int StatusId;
typedef int TerminalId;
typedef int NonterminalId;

struct Action {
	enum Type {
		S,
		R,
		E,
	};
	Type type;
	size_t val;
};

struct Reduce {
	NonterminalId parent;
	size_t childrenCount;
};

struct TerminalUnit {
	TerminalUnit(int type, string word) {
		this->type = type;
		this->word = word;
	}

	string word;
	int type;
};

// <user definition
struct Regex {
	string regex;
};
using std::pair;
// user definition>

class LexParse {
public:
	LexParse(string content) : mWord(content) {
	}

	void parse() {
		mStatusStack.emplace(0);
		int id = mWord.GetNextWord();
		while (1) {
			stack<StatusId> statusStack2(mStatusStack);
			list<StatusId> statusList;
			while (!statusStack2.empty()) {
				statusList.emplace_front(statusStack2.top());
				statusStack2.pop();
			}

			// cout << id << ":";
			// for (StatusId id : statusList) {
			// 	cout << id << " ";
			// }
			// printUnit(statusList);

			StatusId status = mStatusStack.top();
			Action action = sAction[status][sWordTypeToId[id]];
			switch (action.type) {
			case Action::E: {
				cout << "Error!" << endl;
				return;
			}
			case Action::R: {
				if (id == -1 && action.val == 0) {
					//cout << "Accept!" << endl;
					return;
				}
				//cout << "Reduce!" << endl;
				for (int i = 0; i < (int)sReduce[action.val].childrenCount; ++i) {
					mStatusStack.pop();
				}
				status = mStatusStack.top();
				StatusId newStatus = sGoto[status][sReduce[action.val].parent];
				mStatusStack.emplace(newStatus);
				reduce(action.val);
				break;
			}
			case Action::S: {
				//cout << "Shift!" << id << " " << mWord.getCurWord() << endl;
				mStatusStack.emplace(action.val);
				TerminalUnit* unit = new TerminalUnit(id, mWord.getCurWord());
				mUnitStack.emplace(unit);
				id = mWord.GetNextWord();
				break;
			}
			}
		}
	}

	// <user definition
	unordered_map<string, string>& getConstantRegex() { return mConstantRegex; }
	vector<pair<string, string>>& getRegexAndCode() { return mRegexAndCode; }
	string& getOutput() { return mOutput; }
	string& getClassName() { return mClassName; }
	string& getVersion() { return mVersion; }
	string& getNamespace() { return mNamespace; }
	string& getCodeHOutSide() { return mCodeHOutside; }
	string& getCodeHPublic() { return mCodeHPublic; }
	string& getCodeHPrivate() { return mCodeHPrivate; }
	string& getCodeCpp() { return mCodeCpp; }
	// user definition>

private:
	LexWord mWord;
	stack<void*> mUnitStack;
	stack<StatusId> mStatusStack;

	static vector<vector<Action>> sAction;
	static vector<vector<StatusId>> sGoto;
	static vector<Reduce> sReduce;
	static unordered_map<int, TerminalId> sWordTypeToId;
	static unordered_map <StatusId, string> sStatusToUnitName;
	
	void reduce(size_t reduceId);

	void printUnit(list<StatusId> statusIds) {
		for (StatusId id : statusIds) {
			cout << sStatusToUnitName[id] << " ";
		}
		cout << endl;
	}

	// <user definition
	void addCodeHOutSide(TerminalUnit* unit);
	void addCodeHPublic(TerminalUnit* unit);
	void addCodeHPrivate(TerminalUnit* unit);
	void addCodeCpp(TerminalUnit* unit);
	void setOutput(TerminalUnit* unit1, TerminalUnit* unit2);
	void setClassName(TerminalUnit* unit1, TerminalUnit* unit2);
	void setVersion(TerminalUnit* unit1, TerminalUnit* unit2);
	void setNamespace(TerminalUnit* unit1, TerminalUnit* unit2);
	void addConstant(TerminalUnit* unit1, Regex* unit2);
	void addTarget(Regex* unit1, TerminalUnit* unit2);
	Regex* generateRegexBase(Regex* unit1, Regex* unit2);
	Regex* generateRegexBase(Regex* unit);
	Regex* generateRegexBase(TerminalUnit* unit);

	unordered_map<string, string> mConstantRegex;
	vector<pair<string, string>> mRegexAndCode;
	string mOutput;
	string mClassName;
	string mVersion;
	string mNamespace;
	string mCodeHOutside;
	string mCodeHPublic;
	string mCodeHPrivate;
	string mCodeCpp;
	// user definition>

};

}

#endif
