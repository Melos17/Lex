
output:"LexParse/Auto/lex_auto_word"
classname:"LexWord"
version:"1.1.1"
namespace:"Auto_Lex"

{Target
"[a-zA-Z_][a-zA-Z_0-9]*"											{ return(Identifier); }
"\"([^\"\\]|\\.)*\""												{ return(String); }
"\("																{ return(Parenthese_Left); }
"\)"																{ return(Parenthese_Right); }
"\*"																{ return(Star); }
"\+"																{ return(Plus); }
"\?"																{ return(Question); }
"\|"																{ return(Or); }
"[ \t\v\f\n]+"														{ /*return(Blank);*/ }
"//[^\n]*\n"														{ /*return(Comment);*/ }
"/\*/?([^/]|[^\*]/)*\*+/"											{ /*return(Comment);*/ }

"output:"															{ return(Output); }
"classname:"														{ return(ClassName); }
"version:"															{ return(Version); }
"namespace:"														{ return(Namespace); }

// Manual catch {...}
"\{"																{ catch_code(); return(Regex_Code); }

"\{[a-zA-Z_][a-zA-Z_0-9]*\}"										{ return(Constant); }

"\{Constant"														{ return(Segment_Constant_Left); }
"Constant\}"														{ return(Segment_Constant_Right); }
"\{Target"															{ return(Segment_Target_Left); }
"Target\}"															{ return(Segment_Target_Right); }

// No support No Greedy for convenience, meaning you should not insert two same kind segment
"\{Code\-H\-Outside.*Code\-H\-Outside\}"							{ return(Segment_Code_H_Outside); }
"\{Code\-H\-Public.*Code\-H\-Public\}"								{ return(Segment_Code_H_Public); }
"\{Code\-H\-Private.*Code\-H\-Private\}"							{ return(Segment_Code_H_Private); }
"\{Code\-CPP.*Code\-CPP\}"											{ return(Segment_Code_Cpp); }
"\{Code\-DFA\-CPP.*Code\-DFA\-CPP\}"								{ return(Segment_Code_DFA_Cpp); }
Target}

{Code-H-Public
	enum LexSymbolType {
		Parenthese_Left = '(',
		Parenthese_Right = ')',
		Star = '*',
		Plus = '+',
		Question = '?',
		Or = '|',
		Identifier = 128,
		String,
		Regex_Code,
		Constant,
		Segment_Constant_Left,
		Segment_Constant_Right,
		Segment_Target_Left,
		Segment_Target_Right,
		Segment_Code_H_Outside,
		Segment_Code_H_Public,
		Segment_Code_H_Private,
		Segment_Code_Cpp,
		Segment_Code_DFA_Cpp,
		Output,
		ClassName,
		Version,
		Namespace,
		Blank,
		Comment,
		End = -1,
	};
Code-H-Public}

{Code-H-Private
	void catch_code();
Code-H-Private}


{Code-CPP
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
Code-CPP}
