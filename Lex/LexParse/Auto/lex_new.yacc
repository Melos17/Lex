
output:"F:/Programme/Lex/Lex/LexParse/Auto/auto_lex_parse"
version:"1.1.1"
parsename:"LexParse"
wordname:"LexWord"
wordheader:"lex_auto_word.h"
namespace:"Auto_Lex"
start:"lex"

{Grammar
lex
	: lex part
	| part
	;

part
	: Output String {setOutput}
	| ClassName String {setClassName}
	| Version String {setVersion}
	| Namespace String {setNamespace}
	| Segment_Constant_Left segment_constant Segment_Constant_Right
	| Segment_Target_Left segment_target Segment_Target_Right
	| Segment_Code_H_Outside {addCodeHOutSide}
	| Segment_Code_H_Public {addCodeHPublic}
	| Segment_Code_H_Private {addCodeHPrivate}
	| Segment_Code_Cpp {addCodeCpp}
	;

segment_constant
	: segment_constant_single
	| segment_constant segment_constant_single
	;

segment_constant_single
	: Identifier regex {addConstant}
	;

segment_target
	: segment_target_single
	| segment_target segment_target_single
	;

segment_target_single
	: regex Regex_Code {addTarget}
	;

regex {Regex : generateRegexBase}
	: regex_base
	| regex regex_base
	;

regex_base {Regex : generateRegexBase}
	: Constant
	| String
	| '*'
	| '+'
	| '?'
	| '|'
	| '('
	| ')'
	;
Grammar}

{Code-H-Outside
// <user definition
struct Regex {
	string regex;
};
using std::pair;
// user definition>
Code-H-Outside}

{Code-H-Public
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
Code-H-Public}

{Code-H-Private
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
Code-H-Private}
