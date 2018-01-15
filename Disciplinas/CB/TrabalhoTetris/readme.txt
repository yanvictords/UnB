# Computação Básica
||YAN VICTOR DOS SANTOS - 140033599  || COMPUTACAO BASICA - CARLA KOIKE - TURMA A||
RESUMO DO PROGRAMA: O PROGRAMA É UM PROTÓTIPO DO JOGO VERDADEIRO CONHECIDO COMO "TETRIS". O JOGADOR MANIPULARÁ VÁRIAS PEÇAS 
EMPILHANDO-AS NA PARTE DE BAIXO DO JOGO. GANHA SE CONSEGUIR USAR TODAS AS PEÇAS. PERDE SE AS PEÇAS SE EMPILHAREM ATÉ O LIMITE.

DESCRIÇÃO DO PROGRAMA: Ao executar o programa, aparecerá a sua tela inicial. Teclando <enter> poderemos iniciar o jogo. 
O jogo é composto por '20' peças, onde aparecerá uma de cada vez, de diferentes tamanhos. Os movimentos básicos de cada peça são:
R - rotar; D - ir para a direita; E - ir para a esquerda; C - Cair.
Os comandos 'R', 'D' e 'E' poderão ser executados para uma mesma peça enquanto o jogador não usar o comando 'C'.
Quando o comando 'C' for usado, a peça cairá na área inferior do jogo nas mesmas coluna de onde ela estava na sua área superior.
Ao cair uma peça na mesma coluna onde outra já se encontra existente, as peças se empilharão.
Ao completar uma linha na área inferior, tal linha será eliminada. Quando tal ação for efetuada,
o jogador será contemplado com um ganho de 100 pontos. Toda vez que tal ação ocorrer, mais 100 pontos serão acrescentados no total.
-Se as peças empilhadas da área inferior alcançarem o limite marcado pelas setas, ele PERDERÁ o jogo.
-Se o jogador conseguir chegar ao final das '20' sequências(peças) sem que as peças da área inferior alcancem o limite das setas, ele GANHARÁ o jogo. 

COMO COMPILAR: O programa "CBETRIS", no Linux, pode ser compilado por GCC e executado atraves dos comandos digitados no terminal:
gcc -ansi -Wall tetris.c -o tetris
./jogodaforca

--------------- EXEMPLO - GANHANDO O JOGO ----------------

***BEM VINDO AO CBETRIS***

  +--------------------+           PONTUACAO: 200
  |                    |
  |                    |
  |                    |
  |                    |
  |                    |
  |                    |
=>+                    +<=
  |                    |
  |                    |
  |                    |
  |          **       &|
  |          &        &|
  |          &        &|
  |* #####  $$$$      &|
  |*    @@@@   & @@@@@&|
  +--------------------+

R-rotar D-direita E-esquerda C-cair
ACAO:


**PARABENS, VOCE GANHOU!!!**
        PONTUAÇÃO: 200


Pressione <ENTER> para encerrar

--------------- EXEMPLO - PERDENDO O JOGO ----------------

***BEM VINDO AO CBETRIS***

  +--------------------+           PONTUACAO: 100
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
=>+XXXXXXXXXXXXXXXXXXXX+<=
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  |XXXXXXXXXXXXXXXXXXXX|
  +--------------------+

R-rotar D-direita E-esquerda C-cair
ACAO:


      **GAME OVER**
        PONTUAÇÃO: 100



Pressione <ENTER> para encerrar


