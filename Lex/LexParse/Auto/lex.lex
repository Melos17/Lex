
%%

"[a-zA-Z_][a-zA-Z_0-9]*"											{ return(Identifier); }
"\"([^\"\\]|\\.)*\""                                		     	{ return(String); }
"\("                                                   		     	{ return(Parenthese_Left); }
"\)"                                                   		     	{ return(Parenthese_Right); }
"\*"                                                   		     	{ return(Star); }
"\+"                                                   		     	{ return(Plus); }
"\?"                                                   		     	{ return(Question); }
"\|"                                                   		     	{ return(Or); }
"[ \t\v\f\n]+"                                          			{ /*return(Blank);*/ break; }
"//[^\n]*\n"                                            			{ /*return(Comment);*/ break; }
"/\*/?([^/]|[^\*]/)*\*+/"                            			    { /*return(Comment);*/ break; }

"output:"                                                           { return(Output); }
"parsename:"                                                        { return(ParseName); }
"wordname:"															{ return(WordName); }
"version:"                                                          { return(Version); }
"namespace:"                                                        { return(Namespace); }

// Manual catch {...}
"\{"			                                                   	{ catch_code(); return(Regex_Code); }

"\{[a-zA-Z_][a-zA-Z_0-9]*\}"			                            { return(Constant); }

"\{Constant"                                                        { return(Segment_Constant_Left); }
"Constant\}"                                                        { return(Segment_Constant_Right); }
"\{Target"                                                          { return(Segment_Target_Left); }
"Target\}"                                                          { return(Segment_Target_Right); }

// No support No Greedy for convenience, meaning you should not insert two same kind segment
"\{Code\-H\-Outside.*Code\-H\-Outside\}"                            { return(Segment_Code_H_Outside); }
"\{Code\-H\-Public.*Code\-H\-Public\}"                              { return(Segment_Code_H_Public); }
"\{Code\-H\-Private.*Code\-H\-Private\}"                            { return(Segment_Code_H_Private); }
"\{Code\-CPP.*Code\-CPP\}"                                          { return(Segment_Code_Cpp); }

%%

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
		Output,
		ParseName,
		WordName,
		Version,
		Namespace,
		Blank,
		Comment,
		End = -1,
	};
