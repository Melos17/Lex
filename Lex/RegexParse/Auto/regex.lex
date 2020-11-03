
%%

"\("													{ return(Parenthese_Left); }
"\)"													{ return(Parenthese_Right); }
"\["													{ return(Bracket_Left); }
"\]"													{ return(Bracket_Right); }
"\*"													{ return(Star); }
"\+"													{ return(Plus); }
"\?"													{ return(Question); }
"\|"													{ return(VerticalLine); }
"\."													{ return(Dot); }
"\-"													{ return(Hyphen); }
"\^"													{ return(Caret); }

/* $ , 0-9 {} will not be Normal_Character in future. */
"[\\ \t\r\v\n\f%\'\"{}/<=>&!;:,~#$`@a-zA-Z_0-9]"		{ return(Normal_Character); }
"\\[\(\)\[\]\{\}\'\"\*\+\?\$\.\|\-\^\\\,trvnf]"			{ return(Escape_Character); }

%%

enum TOKEN_TYPE {
		Unknown = -1,
		
		Parenthese_Left = '(', Parenthese_Right = ')',
		Bracket_Left = '[', Bracket_Right = ']',
		Star = '*',
		Plus = '+',
		Question = '?',
		VerticalLine = '|',
		Dot = '.',
		Hyphen = '-',
		Caret = '^',
		
		Normal_Character = 128,
		Escape_Character,
		
		// no support currently.
		Brace_Left, Brace_Right, // {}
		Dollar, // $
		Comma, // ,
		Number, // 0-9
};
