#ifndef REPORT_H
#define REPORT_H

#include <fstream>

#include "dfa.h"

using std::ofstream;
using std::string;
using std::ios;

class Report {
public:
	static Report* getInstance() {
		if (sInstance == nullptr) {
			sInstance = new Report();
		}
		return sInstance;
	}

	void output(const string& filePath, const DFA& dfa) const {
		ofstream os(filePath, ios::trunc);

		os.close();
	}

private:
	static Report* sInstance;
};

#endif