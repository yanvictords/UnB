# Computação Básica
||YAN VICTOR DOS SANTOS - 140033599  || COMPUTACAO BASICA - CARLA KOIKE - TURMA A||<br />
RESUMO DO PROGRAMA: O PROGRAMA É UM PROTÓTIPO DO JOGO VERDADEIRO CONHECIDO COMO "TETRIS". O JOGADOR MANIPULARÁ VÁRIAS PEÇAS <br />
EMPILHANDO-AS NA PARTE DE BAIXO DO JOGO. GANHA SE CONSEGUIR USAR TODAS AS PEÇAS. PERDE SE AS PEÇAS SE EMPILHAREM ATÉ O LIMITE.<br />

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

--------------- EXEMPLO - GANHANDO O JOGO ----------------<br />

***BEM VINDO AO CBETRIS***<br />

  +--------------------+           PONTUACAO: 200<br />
  |                    |<br />
  |                    |<br />
  |                    |<br />
  |                    |<br />
  |                    |<br />
  |                    |<br />
=>+                    +<=<br />
  |                    |<br />
  |                    |<br />
  |                    |<br />
  |          **       &|<br />
  |          &        &|<br />
  |          &        &|<br />
  |* #####  $$$$      &|<br />
  |*    @@@@   & @@@@@&|<br />
  +--------------------+<br />
<br />
R-rotar D-direita E-esquerda C-cair<br />
ACAO:<br />
<br />
<br />
**PARABENS, VOCE GANHOU!!!**<br />
        PONTUAÇÃO: 200<br />
<br />
<br />
Pressione <ENTER> para encerrar<br />
<br />
--------------- EXEMPLO - PERDENDO O JOGO ----------------<br />
<br />
***BEM VINDO AO CBETRIS***<br />
<br />
  +--------------------+           PONTUACAO: 100<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
=>+XXXXXXXXXXXXXXXXXXXX+<=<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  |XXXXXXXXXXXXXXXXXXXX|<br />
  +--------------------+<br />
<br />
R-rotar D-direita E-esquerda C-cair<br />
ACAO:<br />
<br />
<br />
      **GAME OVER**<br />
        PONTUAÇÃO: 100<br />
<br />
<br />
<br />
Pressione <ENTER> para encerrar<br />


