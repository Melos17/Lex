
expression { AbstractTreeNode : generateExpression }
	: expression '|' and_expression
	| and_expression
	;

and_expression { AbstractTreeNode}
	: and_expression unary_expression {generateAndExpression}
	| unary_expression {generateExpression}
	;

unary_expression { AbstractTreeNode : generateUnaryExpression }
	: unique_expression {generateExpression}
	| unique_expression '*'
	| unique_expression '+'
	| unique_expression '?'
	;

unique_expression { AbstractTreeNode : generateUniqueExpression }
	: character
	| '(' expression ')'
	| '[' symbols_expression ']'
	| '-'
	| '^'
	;

symbols_expression { SymbolsExpression : generateSymbolsExpression }
	: character
	| character '-' character
	| '^' symbols_expression
	| symbols_expression symbols_expression
	;

character { Character : generateCharacter }
	: Normal_Character
	| Escape_Character
	| '.'
	;

%%
