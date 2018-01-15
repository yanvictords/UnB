# Controle de Estoque
************PROGRAMA CONTROLE DE ESTOQUE**************
// YAN VICTOR DOS SANTOS, 140033599.

Objetivo: Este programa tem por finalidade juntar dados de estoque de um arquivo texto "estoque.txt" e calcular o Estoque mínimo para o controle de estoque, gerando um relatorio.

Descrição: O programa recebe como entrada um Código, o nome do Produto, Unidades, demanda em períodos e calcula o total, a média, desvio padrão e o estoque mínimo. O programa contém a consulta On-line, onde o usuário é capaz de consultar informações sobre os produtos, mudar a demanda de algum periodo em run-time, assim como calcular individualmente o total, média, desvio padrão e estoque mínimo de cada produto também em run-time. Também é possível visualizar individualmente a demanda e as unidades de cada produto. O programa pode gerar um relatório no próprio terminal do linux conforme for pedido, mas sempre irá gerar um relatório em formato de arquivo texto com nome "Relatorio.txt".

Como executar: Pelo terminal do linux pelo seguinte comando
gcc -ansi -Wall ControleEstoque.c -o estoque -lm
./estoque

Observação: Foi usado a biblioteca math.h, logo é necessário acrescenter o -lm no comando do compilador gcc.


O relatorio: Contém Data e hora, período de referência, o Código do item, Descrição, Unidades existentes, Demanda, Total, Media e o ESTOQUE MINIMO.

-------- Entrada: 

CODIGO	DESCRICAO	UNIDADES	PERIODO 1	PERRIODO 2	PERDIODO 3	PERIODO 4	PERIODO 5
1	COMPUTADOR	400		300		250		310		380		130
2	MOUSE		620		580		500		550		530		560
3	RELOGIO		280		200		100		150		130		120
4	CELULAR		710		500		600		650		630		700
5	TABLET		300		150		100		110		250		230
6	TELEVISAO	130		100		80		50		120		60
7	VIDEOGAME	200		190		150		100		130		180
8	FONE		450		400		430		400		420		410
9	CADEIRA		320		50		80		130		60		250
10	MESA		260		60		70		150		250		150

--------- Saida(Arquivo texto):

Relatorio gerado em: Sep  4 2015 as 5:28:9

CODIGO	DESCRICAO	UNIDADES	PERIODO 1	PERRIODO 2	PERDIODO 3	PERIODO 4	PERIODO 5	
1		COMPUTADOR		400		300.0		250.0		310.0		380.0		130.0
2		MOUSE			620		580.0		500.0		550.0		530.0		560.0
3		RELOGIO			280		200.0		100.0		150.0		130.0		120.0
4		CELULAR			710		500.0		600.0		650.0		630.0		700.0
5		TABLET			300		150.0		100.0		110.0		250.0		230.0
6		TELEVISAO		130		100.0		80.0		50.0		120.0		60.0
7		VIDEOGAME		200		190.0		150.0		100.0		130.0		180.0
8		FONE			450		400.0		430.0		400.0		420.0		410.0
9		CADEIRA			320		50.0		80.0		130.0		60.0		250.0
10		MESA			260		60.0		70.0		150.0		250.0		150.0

CODIGO	DESCRICAO	TOTAL	MEDIA	ESTOQUE MINIMO
1		COMPUTADOR	1370	274.0		43.223
2		MOUSE		2720	544.0		14.189
3		RELOGIO		700		140.0		17.717
4		CELULAR		3080	616.0		34.600
5		TABLET		840		168.0		31.966
6		TELEVISAO	410		82.0		13.323
7		VIDEOGAME	750		150.0		17.095
8		FONE		2060	412.0		6.066
9		CADEIRA		570		114.0		38.170
10		MESA		680		136.0		35.678


