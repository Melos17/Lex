#include "auto_lex_parse.h"

using namespace Auto_Lex;

vector<vector<Action>> LexParse::sAction = {
	{ {Action::E, 0x0000}, {Action::S, 0x0003}, {Action::E, 0x0000}, {Action::S, 0x0004}, {Action::S, 0x0005}, {Action::S, 0x0006}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::E, 0x0000}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0000}, {Action::S, 0x0003}, {Action::E, 0x0000}, {Action::S, 0x0004}, {Action::S, 0x0005}, {Action::S, 0x0006}, {Action::S, 0x0007}, {Action::E, 0x0000}, {Action::S, 0x0008}, {Action::E, 0x0000}, {Action::S, 0x0009}, {Action::S, 0x000a}, {Action::S, 0x000b}, {Action::S, 0x000c}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::E, 0x0000}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::E, 0x0000}, {Action::R, 0x0002}, {Action::E, 0x0000}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::R, 0x0002}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x000e}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x000f}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0010}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0011}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0014}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001a}, {Action::S, 0x001b}, {Action::S, 0x001c}, {Action::S, 0x001d}, {Action::S, 0x001e}, {Action::S, 0x001f}, {Action::S, 0x0020},},
	{ {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::E, 0x0000}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::E, 0x0000}, {Action::R, 0x0009}, {Action::E, 0x0000}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::R, 0x0009}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::E, 0x0000}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::E, 0x0000}, {Action::R, 0x000a}, {Action::E, 0x0000}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::R, 0x000a}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::E, 0x0000}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::E, 0x0000}, {Action::R, 0x000b}, {Action::E, 0x0000}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::R, 0x000b}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::E, 0x0000}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::E, 0x0000}, {Action::R, 0x000c}, {Action::E, 0x0000}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::R, 0x000c}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::E, 0x0000}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::E, 0x0000}, {Action::R, 0x0001}, {Action::E, 0x0000}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::R, 0x0001}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::R, 0x0003}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::R, 0x0004}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::E, 0x0000}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::E, 0x0000}, {Action::R, 0x0005}, {Action::E, 0x0000}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::R, 0x0005}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::R, 0x0006}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0021}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0014}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000d}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000d}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001a}, {Action::S, 0x001b}, {Action::S, 0x001c}, {Action::S, 0x001d}, {Action::S, 0x001e}, {Action::S, 0x001f}, {Action::S, 0x0020},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016}, {Action::R, 0x0016},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0024}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x001a}, {Action::S, 0x001b}, {Action::S, 0x001c}, {Action::S, 0x001d}, {Action::S, 0x001e}, {Action::S, 0x001f}, {Action::S, 0x0020},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0026}, {Action::S, 0x001a}, {Action::S, 0x001b}, {Action::S, 0x001c}, {Action::S, 0x001d}, {Action::S, 0x001e}, {Action::S, 0x001f}, {Action::S, 0x0020},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000f}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000f}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f}, {Action::R, 0x000f},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012}, {Action::R, 0x0012},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015}, {Action::R, 0x0015},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017}, {Action::R, 0x0017},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018}, {Action::R, 0x0018},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019}, {Action::R, 0x0019},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001a}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001a}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a}, {Action::R, 0x001a},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001b}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001b}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b}, {Action::R, 0x001b},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001c}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001c}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c}, {Action::R, 0x001c},},
	{ {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::R, 0x0007}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000e}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x000e}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::S, 0x0015}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0011}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0011}, {Action::E, 0x0000}, {Action::S, 0x001a}, {Action::S, 0x001b}, {Action::S, 0x001c}, {Action::S, 0x001d}, {Action::S, 0x001e}, {Action::S, 0x001f}, {Action::S, 0x0020},},
	{ {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::R, 0x0008}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0010}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0010}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010}, {Action::R, 0x0010},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014}, {Action::R, 0x0014},},
	{ {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0013}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0013}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::E, 0x0000}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013}, {Action::R, 0x0013},},
};

vector<vector<StatusId>> LexParse::sGoto = {
	{	1,	2,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	13,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	18,	-1,	19,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	22,	-1,	23,	24,	25,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	34,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	35,	-1,	25,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	23,	37,	25,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	39,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	39,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
	{	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,},
};

vector<Reduce> LexParse::sReduce = {
	{ 0, 1},
	{ 0, 2},
	{ 0, 1},
	{ 1, 2},
	{ 1, 2},
	{ 1, 2},
	{ 1, 2},
	{ 1, 3},
	{ 1, 3},
	{ 1, 1},
	{ 1, 1},
	{ 1, 1},
	{ 1, 1},
	{ 2, 1},
	{ 2, 2},
	{ 3, 1},
	{ 3, 2},
	{ 4, 2},
	{ 5, 1},
	{ 5, 2},
	{ 6, 2},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
	{ 7, 1},
};

unordered_map <StatusId, string> LexParse::sStatusToUnitName = {
	{ 0, "$"},
	{ 1, "lex"},
	{ 2, "part"},
	{ 3, "Output"},
	{ 4, "ClassName"},
	{ 5, "Version"},
	{ 6, "Namespace"},
	{ 7, "Segment_Constant_Left"},
	{ 8, "Segment_Target_Left"},
	{ 9, "Segment_Code_H_Outside"},
	{ 10, "Segment_Code_H_Public"},
	{ 11, "Segment_Code_H_Private"},
	{ 12, "Segment_Code_Cpp"},
	{ 13, "part"},
	{ 14, "String"},
	{ 15, "String"},
	{ 16, "String"},
	{ 17, "String"},
	{ 18, "segment_constant"},
	{ 19, "segment_constant_single"},
	{ 20, "Identifier"},
	{ 21, "String"},
	{ 22, "segment_target"},
	{ 23, "regex"},
	{ 24, "segment_target_single"},
	{ 25, "regex_base"},
	{ 26, "Constant"},
	{ 27, "*"},
	{ 28, "+"},
	{ 29, "?"},
	{ 30, "|"},
	{ 31, "("},
	{ 32, ")"},
	{ 33, "Segment_Constant_Right"},
	{ 34, "segment_constant_single"},
	{ 35, "regex"},
	{ 36, "Segment_Target_Right"},
	{ 37, "segment_target_single"},
	{ 38, "Regex_Code"},
	{ 39, "regex_base"},
};

unordered_map<int, TerminalId> LexParse::sWordTypeToId = {
	{ '\0', 0},
	{ LexWord::Output, 1},
	{ LexWord::String, 2},
	{ LexWord::ClassName, 3},
	{ LexWord::Version, 4},
	{ LexWord::Namespace, 5},
	{ LexWord::Segment_Constant_Left, 6},
	{ LexWord::Segment_Constant_Right, 7},
	{ LexWord::Segment_Target_Left, 8},
	{ LexWord::Segment_Target_Right, 9},
	{ LexWord::Segment_Code_H_Outside, 10},
	{ LexWord::Segment_Code_H_Public, 11},
	{ LexWord::Segment_Code_H_Private, 12},
	{ LexWord::Segment_Code_Cpp, 13},
	{ LexWord::Identifier, 14},
	{ LexWord::Regex_Code, 15},
	{ LexWord::Constant, 16},
	{ '*', 17},
	{ '+', 18},
	{ '?', 19},
	{ '|', 20},
	{ '(', 21},
	{ ')', 22},
};
