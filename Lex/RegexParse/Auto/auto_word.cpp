#include "auto_word.h"

using namespace Auto_Regex;

int RegexWord::runRelativeCode(int type) {
	switch( type ) {
		case 0:
			{ return(Parenthese_Left); }
			break;
		case 1:
			{ return(Parenthese_Right); }
			break;
		case 2:
			{ return(Bracket_Left); }
			break;
		case 3:
			{ return(Bracket_Right); }
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
			{ return(VerticalLine); }
			break;
		case 8:
			{ return(Dot); }
			break;
		case 9:
			{ return(Hyphen); }
			break;
		case 10:
			{ return(Caret); }
			break;
		case 11:
			{ return(Normal_Character); }
			break;
		case 12:
			{ return(Escape_Character); }
			break;
	}
	return -1;
}
