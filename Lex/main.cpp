#include <iostream>

#include "LexParse/Manual/lex_dfa_factory.h"
#include "LexParse/Manual/lex.h"

#include "LexParse/Auto/auto_lex_parse.h"

#define lexDfaPath "LexParse/Manual/lexScanDFA.cpp"

int main()
{
#ifdef false // read lex dfa directly.
#include lexDfaPath;
#else // reproduce lex dfa.
	LexDfaFactory dfaFactory;
	DFA dfa = dfaFactory.produceDFA();
	std::ofstream out(lexDfaPath, std::ios_base::out);
	out << "DFA dfa = ";
	out << Produce::getDfaString(dfa);
	out.close();
#endif

	string inputFilePath;
	std::cout << "input file path:";
	std::cin >> inputFilePath;

	std::ifstream ifs(inputFilePath);
	string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

	// classname:"LexWord"
	Auto_Lex::LexParse parse(content);
	parse.parse();
	std::vector<std::pair<string, int>> regexes;
	for (size_t i = 0; i < parse.getRegexAndCode().size(); ++i) {
		regexes.push_back(make_pair(parse.getRegexAndCode()[i].first, (int)i));
	}
	DfaFactory dfaFactory2;
	DFA dfa2 = dfaFactory2.produce(regexes);

	const string& className = parse.getClassName().empty() ? "Word" : parse.getClassName();
	Produce::setClassName(className);
	Produce::setNamespace(parse.getNamespace());
	Produce::setOutputPath(parse.getOutput());
	Produce::setVersion(parse.getVersion());
	Produce::produceWordHead(parse.getCodeHOutSide(), parse.getCodeHPublic(), parse.getCodeHPrivate());
	Produce::produceDfaCpp(dfa2);
	Produce::produceWordCpp(parse.getRegexAndCode(), parse.getCodeCpp());


	std::cout << "\nDone!\nEnter any key to exit: ";
	std::cin >> inputFilePath;
}
