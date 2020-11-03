D			"[0-9]"
L			"[a-zA-Z_]"
H			"[a-fA-F0-9]"

%%


{D}*					{ count(); return(check_type()); }
"\+"					{ count(); return('+'); }
"\*"					{ count(); return('*'); }
"\("					{ count(); return('('); }
"\)"					{ count(); return(')'); }
"[ \t\v\n\f]"			{ count(); break; }

%%

enum TOKEN_TYPE {
	IDENTIFIER
};

void count() {
	
}

void comment()
{
	char c = getNextChar();
	while(c) {
		while(c == '*') {
			c = getNextChar();
			if(c == '/') return;
		}
		c = getNextChar();
	}
}

int check_type()
{
	return(IDENTIFIER);
}
