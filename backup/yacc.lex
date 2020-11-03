D			"[0-9]"
L			"[a-zA-Z_]"

%%

{L}({L}|{D})*			{ return(IDENTIFIER); }
"'\\?.'"				{ return(CHAR); }
"[ \t\v\n\f\r]"			{ break; }
":"						{ return(':'); }
"\|"					{ return('|'); }
";"						{ return(';'); }
"{"						{ return('{'); }
"}"						{ return('}'); }
"%%.*"					{ return(CODE); }

%%

enum TOKEN_TYPE {
	IDENTIFIER=128, CHAR, CODE
};