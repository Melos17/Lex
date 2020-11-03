
all
	: all part
	| part
	;

part
	: Output String {setOutput}
	| ClassName String {setClassName}
	| Version String {setVersion}
	| Namespace String {setNamespace}
	| Segment_Constant_Left segment_constant_list Segment_Constant_Right
	| Segment_Target_Left segment_target_list Segment_Target_Right
	| Segment_Code_H_Outside {addCodeHOutSide}
	| Segment_Code_H_Public {addCodeHPublic}
	| Segment_Code_H_Private {addCodeHPrivate}
	| Segment_Code_Cpp {addCodeCpp}
	;

segment_constant_list
	: segment_constant
	| segment_constant_list segment_constant
	;

segment_constant
	: Identifier regex {addConstant}
	;

segment_target_list
	: segment_target
	| segment_target_list segment_target
	;

segment_target
	: regex Regex_Code {addTarget}
	;

regex {Regex : generateRegexBase}
	: regex_base
	| regex regex_base
	;

regex_base {Regex : generateRegexBase}
	: Constant
	| String
	| '*'
	| '+'
	| '?'
	| '|'
	| '('
	| ')'
	;

%%
