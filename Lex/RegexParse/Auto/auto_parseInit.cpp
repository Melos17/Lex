#include "auto_parse.h"

vector<vector<Action>> SingleRegexParse::sAction = {
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0006}, {Action::E, 0x0000}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x0000}, {Action::S, 0x000d}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0006}, {Action::R, 0x0002}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004},},
	{ {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::S, 0x000f}, {Action::S, 0x0010}, {Action::S, 0x0011}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::E, 0x0000}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005},},
	{ {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::E, 0x0000}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0006}, {Action::E, 0x0000}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::E, 0x0000}, {Action::S, 0x0013}, {Action::S, 0x0014}, {Action::S, 0x0015}, {Action::S, 0x0016}, {Action::S, 0x0018}, {Action::S, 0x0019}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001b}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::E, 0x0000}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c},},
	{ {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::E, 0x0000}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d}, {Action::R, 0x000d},},
	{ {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e}, {Action::R, 0x000e},},
	{ {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f},},
	{ {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0006}, {Action::E, 0x0000}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003},},
	{ {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006},},
	{ {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007},},
	{ {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008},},
	{ {Action::E, 0x0000}, {Action::S, 0x000d}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001d}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015},},
	{ {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016},},
	{ {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014},},
	{ {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017},},
	{ {Action::E, 0x0000}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::E, 0x0000}, {Action::R, 0x0011}, {Action::S, 0x001e}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011}, {Action::R, 0x0011},},
	{ {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018},},
	{ {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019},},
	{ {Action::E, 0x0000}, {Action::S, 0x0013}, {Action::S, 0x0014}, {Action::S, 0x0015}, {Action::S, 0x0016}, {Action::S, 0x0018}, {Action::S, 0x0019}, {Action::E, 0x0000}, {Action::S, 0x0020}, {Action::E, 0x0000}, {Action::S, 0x001b}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::E, 0x0000}, {Action::S, 0x0013}, {Action::S, 0x0014}, {Action::S, 0x0015}, {Action::S, 0x0016}, {Action::S, 0x0018}, {Action::S, 0x0019}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001b}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0006}, {Action::R, 0x0001}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::E, 0x0000}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::E, 0x0000}, {Action::S, 0x0013}, {Action::S, 0x0014}, {Action::S, 0x0015}, {Action::S, 0x0016}, {Action::S, 0x0018}, {Action::S, 0x0019}, {Action::E, 0x0000}, {Action::R, 0x001a}, {Action::E, 0x0000}, {Action::S, 0x001b}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::E, 0x0000}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b},},
	{ {Action::E, 0x0000}, {Action::S, 0x0013}, {Action::S, 0x0014}, {Action::S, 0x0015}, {Action::S, 0x0016}, {Action::S, 0x0018}, {Action::S, 0x0019}, {Action::E, 0x0000}, {Action::R, 0x0013}, {Action::E, 0x0000}, {Action::S, 0x001b}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c},},
	{ {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012},},
};

vector<vector<StatusId>> SingleRegexParse::sGoto = {
	{	1,	2,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	14,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	18,	2,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	23,	26,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	28,	3,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	23,	31,},
	{	-1,	-1,	-1,	-1,	23,	33,},
	{	-1,	-1,	14,	4,	5,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	34,	-1,},
	{	-1,	-1,	-1,	-1,	23,	31,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	23,	31,},
	{	-1,	-1,	-1,	-1,	-1,	-1,},
};

vector<Reduce> SingleRegexParse::sReduce = {
	{ 0, 1},
	{ 0, 3},
	{ 0, 1},
	{ 1, 2},
	{ 1, 1},
	{ 2, 1},
	{ 2, 2},
	{ 2, 2},
	{ 2, 2},
	{ 3, 1},
	{ 3, 3},
	{ 3, 3},
	{ 3, 1},
	{ 3, 1},
	{ 4, 1},
	{ 4, 1},
	{ 4, 1},
	{ 5, 1},
	{ 5, 3},
	{ 5, 2},
	{ 5, 1},
	{ 5, 1},
	{ 5, 1},
	{ 5, 1},
	{ 5, 1},
	{ 5, 1},
	{ 5, 2},
};

unordered_map <StatusId, string> SingleRegexParse::sStatusToUnitName = {
	{ 0, "$"},
	{ 1, "expression"},
	{ 2, "and_expression"},
	{ 3, "unary_expression"},
	{ 4, "unique_expression"},
	{ 5, "character"},
	{ 6, "("},
	{ 7, "["},
	{ 8, "-"},
	{ 9, "^"},
	{ 10, "Normal_Character"},
	{ 11, "Escape_Character"},
	{ 12, "."},
	{ 13, "|"},
	{ 14, "unary_expression"},
	{ 15, "*"},
	{ 16, "+"},
	{ 17, "?"},
	{ 18, "expression"},
	{ 19, "|"},
	{ 20, "*"},
	{ 21, "+"},
	{ 22, "?"},
	{ 23, "character"},
	{ 24, "("},
	{ 25, ")"},
	{ 26, "symbols_expression"},
	{ 27, "^"},
	{ 28, "and_expression"},
	{ 29, ")"},
	{ 30, "-"},
	{ 31, "symbols_expression"},
	{ 32, "]"},
	{ 33, "symbols_expression"},
	{ 34, "character"},
};

unordered_map<int, TerminalId> SingleRegexParse::sWordTypeToId = {
	{ '\0', 0},
	{ '|', 1},
	{ '*', 2},
	{ '+', 3},
	{ '?', 4},
	{ '(', 5},
	{ ')', 6},
	{ '[', 7},
	{ ']', 8},
	{ '-', 9},
	{ '^', 10},
	{ RegexWord::Normal_Character, 11},
	{ RegexWord::Escape_Character, 12},
	{ '.', 13},
};

