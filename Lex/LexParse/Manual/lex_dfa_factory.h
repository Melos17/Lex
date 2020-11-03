#ifndef LEX_DFA_FACTORY_H
#define LEX_DFA_FACTORY_H

#include "..\..\dfa_factory.h"
#include "..\..\produce.h"

class LexDfaFactory {
public:
	enum LexSymbolType {
		Brace_Left = '{',
		Brace_Right = '}',
		Parenthese_Left = '(',
		Parenthese_Right = ')',
		Star = '*',
		Plus = '+',
		Question = '?',
		Or = '|',
		Identifier = 128, // abc
		String, // "..."
		Segment, // %%
		Blank,
		NextLine,
		Comment, // /* ... */
		End = -1,
	};

	LexDfaFactory() {}

	DFA produceDFA() {
		std::vector<std::pair<string, int>> regexes = {
			{ "[a-zA-Z_][a-zA-Z_0-9]*", Identifier },
			{ "\"([^\"\\\\]|\\\\.)*\"", String },
			{ "%%",Segment },
			{ "\\{", Brace_Left},
			{ "\\}", Brace_Right},
			{ "\\(", Parenthese_Left },
			{ "\\)", Parenthese_Right },
			{ "\\*", Star },
			{ "\\+", Plus },
			{ "\\?", Question },
			{ "\\|", Or },
			{ "[ \t\v\f]+", Blank },
			{ "\n", NextLine },
			{ "//[^\n]*\n", Comment },
			{ "/\\*/?([^/]|[^\\*]/)*\\*+/", Comment },
		};
		DfaFactory dfaFactory;
		return dfaFactory.produce(regexes);
	}
};

#endif
