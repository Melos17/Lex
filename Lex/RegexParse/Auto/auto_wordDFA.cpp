#include "auto_word.h"

using namespace Auto_Regex;

const DfaTable RegexWord::sDFA = 
{
	{
		// 0: . 
		// 1: \0-\8\14-\31 
		// 2: ( 
		// 3: \\ 
		// 4: \t-\13\32-!#%-&/->@-Z_-eg-mo-qsuw-z~ 
		// 5: "$',fnrtv{} 
		// 6: - 
		// 7: ) 
		// 8: * 
		// 9: + 
		// 10: ? 
		// 11: [ 
		// 12: ] 
		// 13: ^ 
		// 14: | 
		{ -2, -1, -3,  1, -6, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, },
		{ -5, -1, -5, -5, -1, -5, -5, -5, -5,  -5,  -5,  -5,  -5,  -5,  -5, },
	},
	{
		/* {	StatusId, AcceptedId	} */
		{ -10, 5 }, // \+ 
		{ -2, 8 }, // \. 
		{ -3, 0 }, // \( 
		{ -5, 12 }, // \\[\(\)\[\]\{\}\'\"\*\+\?\$\.\|\-\^\\\,trvnf] 
		{ -6, 11 }, // [\\ \t\r\v\n\f%\'\"{}/<=>&!;:,~#$`@a-zA-Z_0-9] 
		{ 1, 11 }, // [\\ \t\r\v\n\f%\'\"{}/<=>&!;:,~#$`@a-zA-Z_0-9] 
		{ -7, 9 }, // \- 
		{ -8, 1 }, // \) 
		{ -9, 4 }, // \* 
		{ -11, 6 }, // \? 
		{ -12, 2 }, // \[ 
		{ -13, 3 }, // \] 
		{ -14, 10 }, // \^ 
		{ -15, 7 }, // \| 
	},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 5, 4, 5, 4, 4, 5, 2, 7, 8, 9, 5, 6, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 10, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 11, 3, 12, 13, 4, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 4, 4, 4, 4, 5, 4, 4, 4, 5, 4, 5, 4, 5, 4, 4, 4, 4, 5, 14, 5, 4, 1, },
};
