grammar Mini;


expressao: EPARENTESES exp=expressao DPARENTESES									         	# Parenteses
		| LET nome=IDENTIFICADOR ATRIBUICAO valor=expressao IN EPARENTESES corpo=expressao DPARENTESES  # Let
		| IF condicao=expressao THEN clausula_then=expressao ELSE clausula_else=expressao 	 	# If
		| INTEIRO   																		 	# Inteiro
		| IDENTIFICADOR																		 	# Identificador
		| TRUE                                       									     	# True
		| FALSE																				 	# False
		| NOT exp=expressao                     										      	# Not
		| esq=expressao AND dir=expressao									  					# And
		| esq=expressao OR dir=expressao  									  					# Or
		| esq=expressao MAIORQ dir=expressao         							  				# Maior
		| esq=expressao MAIORIGUALQ	dir=expressao												# MaiorIgual
		| esq=expressao MENORQ dir=expressao         							  				# Menor
		| esq=expressao MENORIGUALQ	dir=expressao      								 			# MenorIgual
		| esq=expressao IGUALA dir=expressao									 				# Igual
		| esq=expressao MAIS dir=expressao         							  					# Soma
		| esq=expressao MENOS dir=expressao									  					# Subtracao
		| esq=expressao VEZES dir=expressao									 					# Multiplicacao
		| esq=expressao DIVIDIDOPOR	dir=expressao												# Divisao
		| Fsoma EPARENTESES esq=expressao Virgula dir=expressao DPARENTESES						# Soma
		| Fsubtracao EPARENTESES esq=expressao Virgula dir=expressao DPARENTESES				# Subtracao
		| Fdivisao EPARENTESES esq=expressao Virgula dir=expressao DPARENTESES					# Divisao
		| Fmultiplicacao EPARENTESES esq=expressao Virgula dir=expressao DPARENTESES			# Multiplicacao
		| Eval EPARENTESES Aspas exp=expressao Aspas DPARENTESES								# Avaliar	
		| Load EPARENTESES Aspas arquivo=IDENTIFICADOR Mhs  Aspas DPARENTESES       		    # Load

		; 	

ATRIBUICAO: '=';
Load: 'loadFile';
Mhs: '.mhs';
Aspas: '"';
Eval: 'eval';
LET: 'let';
IN: 'in';
IF: 'if';
THEN: 'then';
ELSE: 'else';
INT: 'Int';
BOOL: 'Bool';
ARROW: '->';
DOUBLE_COLON: '::';
NOT: 'not';
AND: '&&';
OR: '||';
MAIORQ: '>';
MAIORIGUALQ: '>=';
MENORQ: '<';
MENORIGUALQ: '<=';
IGUALA: '==';
TRUE: 'True';
FALSE: 'False';
EPARENTESES: '(';
DPARENTESES: ')';
MAIS: '+';
MENOS: '-';
VEZES: '*';
DIVIDIDOPOR: '/';
INTEIRO: [0-9]+;
ESPACO: [ \t\n\r]+ -> skip;
RAW_Tipo: ('Int'|'Bool');
Fsoma: 'soma';
Fsubtracao: 'subtracao';
Fdivisao: 'divisao';
Fmultiplicacao: 'multiplicacao';
Virgula: ',';
IDENTIFICADOR: [a-zA-Z_][a-zA-Z_0-9]*;
