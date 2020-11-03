#include "produce.h"

string Produce::mOutputPath;
string Produce::mHeadName;
string Produce::mClassName;
string Produce::mNamespace;
string Produce::mVersion;

void Produce::setOutputPath(const string& str) {
	mOutputPath = str;
	string::size_type pos1 = mOutputPath.find_last_of('/');
	if (pos1 > mOutputPath.size()) pos1 = 0;
	string::size_type pos2 = mOutputPath.find_last_of('\\');
	if(pos2 > mOutputPath.size()) pos2 = 0;
	string::size_type pos = pos1 > pos2 ? pos1 : pos2;
	mHeadName = mOutputPath.substr(pos, mOutputPath.size() - pos);
	if (!mHeadName.empty() && (mHeadName.at(0) == '/' || mHeadName.at(0) == '\\')) {
		mHeadName = mHeadName.substr(1, mHeadName.size() - 1);
	}
}


string Produce::getDfaString(const DFA& dfa, int prefixCount /*= 0*/, bool detail /*= false*/) {
	// dfa rect
	string prefix(prefixCount, '\t');
	string content;
	content += prefix + "{\n";
	if (dfa.dfa.size() == 0) {
		content += prefix + "};\n";
		return content;
	}
	vector<size_t> columnWidth;
	size_t columnSize = dfa.dfa[0].size();
	columnWidth.resize(columnSize, 0);
	for (auto row : dfa.dfa) {
		for (size_t i = 0; i < columnSize; ++i) {
			size_t width = 0;
			int val = row[i];
			if (val < 0) {
				width = 1;
				val = -val;
			}
			do {
				width += 1;
				val /= 10;
			} while (val > 0);
			if (columnWidth[i] < width) {
				columnWidth[i] = width;
			}
		}
	}

	content += prefix + "\t{\n";
	// content += prefix + "\t\t//";
	// for (size_t i = 0; i < columnSize; ++i) {
	// 	string str = to_string(i);
	// 	content += str;
	// 	for (size_t k = str.size(); k <= columnWidth[i] + 1; ++k) {
	// 		content += ' ';
	// 	}
	// }
	// content += "\n";

	for (size_t i = 0; i < dfa.symbolsInfo.size(); ++i) {
		content += prefix + "\t\t// " + to_string(i) + ": " + dfa.symbolsInfo[i] + " \n";
	}

	for (size_t i = 0; i < dfa.dfa.size(); ++i) {
		auto column = dfa.dfa[i];
		// content += prefix + "\t\t// " + dfa.symbolsInfo[i] + " \n";
		content += prefix + "\t\t{";
		for (size_t j = 0; j < columnSize; ++j) {
			auto status = column[j];
			string str = to_string(status) + ",";
			for (size_t k = str.size(); k <= columnWidth[j] + 1; ++k) {
				content += ' ';
			}
			content += str;
		}
		content += " },\n";
	}
	content += prefix + "\t},\n";

	// status id to accepted id
	content += prefix + "\t{\n";
	content += prefix + "\t\t/* {\tStatusId, AcceptedId\t} */\n";
	for (auto val : dfa.acceptStatus) {
		auto it = dfa.acceptRegex.find(val.second);
		if (it != dfa.acceptRegex.end()) {
			content += prefix + "\t\t{ " + to_string(val.first) + ", " + to_string(val.second) + " }, // " + it->second + " \n";
		}
	}
	content += prefix + "\t},\n";

	// symbols index to collection id
	content += prefix + "\t{";
	for (auto val : dfa.symbolIndex) {
		content += " " + to_string(val) + ",";
	}
	content += " },\n";
	content += prefix + "};\n";
	return move(content);
}


void Produce::produceWordHead(const string& codeOutside, const string& codePublic, const string& codePrivate) {
	string srcPath = "word_ori.h";
	ifstream in(srcPath, ios::binary);
	string content;
	in.seekg(0, ios::end);
	long long length = in.tellg();
	in.seekg(0);
	char buf[2048];
	while (length > 0) {
		int bufSize = (int) (length >= 2048 ? 2048 : length);
		in.read(buf, bufSize);
		length -= bufSize;
		content.append(buf, buf + bufSize);
	}
	in.close();

	replaceStr(content, "WordClassName", mClassName);
	
	if (!mNamespace.empty()) {
		replaceStr(content, "HEAD_H", mNamespace + "_" + mClassName + "_H");
	}
	else {
		replaceStr(content, "HEAD_H", mClassName + "_H");
	}

	if (mNamespace.empty()) {
		replaceStr(content, "// namespace_left", "");
		replaceStr(content, "// namespace_right", "");
	}
	else {
		replaceStr(content, "// namespace_left", "namespace " + mNamespace + " {\n");
		replaceStr(content, "// namespace_right", "}\n");
	}
	
	if (codeOutside.empty()) {
		replaceStr(content, "// CodeHOutSide", "");
	}
	else {
		replaceStr(content, "// CodeHOutSide", string("\n// <user definition") + codeOutside + "// user definition>\n");
	}
	
	if (codePublic.empty()) {
		replaceStr(content, "	// CodeHPublic", "");
	}
	else {
		replaceStr(content, "	// CodeHPublic", string("\n\t// <user definition") + codePublic + "	// user definition>\n");
	}
	
	if (codePrivate.empty()) {
		replaceStr(content, "	// CodeHPrivate", "");
	}
	else {
		replaceStr(content, "	// CodeHPrivate", string("\n\t// <user definition") + codePrivate + "	// user definition>\n");
	}

	string destPath = mOutputPath + ".h";
	ofstream out(destPath, ios::binary | ios::trunc);
	out.write(content.data(), content.size());
	out.close();
}


void Produce::produceDfaCpp(const DFA& dfa, bool detail /*= false*/) {
	string filePath = mOutputPath + "DFA.cpp";
	ofstream out(filePath, ios::trunc);
	
	out << "#include \"" + mHeadName + ".h\"\n\n";
	if(!mNamespace.empty()) {
		out << "using namespace " + mNamespace + ";\n\n";
	}
	
	out << "const DfaTable " + mClassName + "::sDFA = \n";
	out << getDfaString(dfa);
	out.close();
}


void Produce::produceWordCpp(const vector<pair<string, string>>& regexAndCode, const string& codeCpp) {
	string filePath = mOutputPath + ".cpp";
	ofstream out(filePath, ios::trunc);
	
	out << "#include \"" + mHeadName + ".h\"\n\n";
	if(!mNamespace.empty()) {
		out << "using namespace " + mNamespace + ";\n\n";
	}

	if (codeCpp.size() > 0) {
		out << "// <user definition";
		out << codeCpp;
		out << "// user definition>\n\n";
	}

	out << "int " + mClassName + "::runRelativeCode(int type) {\n";
	out << "\tswitch( type ) {\n";
	for (size_t i = 0; i < regexAndCode.size(); ++i) {
		out << "\t\tcase "; out << to_string(i); out << ":\n";
		out << "\t\t\t" << regexAndCode[i].second << "\n";
		out << "\t\t\tbreak;\n";
	}
	out << "\t}\n";
	out << "\treturn -1;\n";
	out << "}\n";
	out.close();
}


void Produce::replaceStr(string& source, const string& from, const string& to) {
	auto n = source.find(from);
	while (n != -1) {
		source.replace(n, from.size(), to);
		n = source.find(from);
	}
}
