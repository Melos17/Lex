#include "lex_auto_word.h"

using namespace Auto_Lex;

// <user definition
void LexWord::catch_code() {
	char last = 0;
	char c = getNextChar();
	std::string& mStr = getCurWord();
	// simply handle here without considering '}' in another {}, string and comment
	while ((last == '\'' || c != '}') && c != '\0') {
		mStr.push_back(c);
		last = c;
		c = getNextChar();
	}
	if (c == '}') {
		mStr.push_back(c);
	}
}
// user definition>

int LexWord::runRelativeCode(int type) {
	switch( type ) {
		case 0:
			{ return(Identifier); }
			break;
		case 1:
			{ return(String); }
			break;
		case 2:
			{ return(Parenthese_Left); }
			break;
		case 3:
			{ return(Parenthese_Right); }
			break;
		case 4:
			{ return(Star); }
			break;
		case 5:
			{ return(Plus); }
			break;
		case 6:
			{ return(Question); }
			break;
		case 7:
			{ return(Or); }
			break;
		case 8:
			{ /*return(Blank);*/ }
			break;
		case 9:
			{ /*return(Comment);*/ }
			break;
		case 10:
			{ /*return(Comment);*/ }
			break;
		case 11:
			{ return(Output); }
			break;
		case 12:
			{ return(ClassName); }
			break;
		case 13:
			{ return(Version); }
			break;
		case 14:
			{ return(Namespace); }
			break;
		case 15:
			{ catch_code(); return(Regex_Code); }
			break;
		case 16:
			{ return(Constant); }
			break;
		case 17:
			{ return(Segment_Constant_Left); }
			break;
		case 18:
			{ return(Segment_Constant_Right); }
			break;
		case 19:
			{ return(Segment_Target_Left); }
			break;
		case 20:
			{ return(Segment_Target_Right); }
			break;
		case 21:
			{ return(Segment_Code_H_Outside); }
			break;
		case 22:
			{ return(Segment_Code_H_Public); }
			break;
		case 23:
			{ return(Segment_Code_H_Private); }
			break;
		case 24:
			{ return(Segment_Code_Cpp); }
			break;
		case 25:
			{ return(Segment_Code_DFA_Cpp); }
			break;
	}
	return -1;
}
