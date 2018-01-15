# Segurança de Dados

Este pequeno projeto apresenta uma solução simples para decriptação usando cifra de Vigenere. <br />
- Como executar o programa: Execute os seguintes comandos:<br />
gcc vigenere.c -o vigenere <br />
./vigenere <br />

- Descrição: O arquivo "mensagem.txt" está criptografado. Seu conteúdo contém apenas números, cuja representação está no formato ASCII. O programa vigenere.c recebe o conteúdo deste arquivo como entrada, faz a decriptação e gera como saída um novo arquivo chamado "mensagemfinal.txt" contendo a verdadeira mensagem, além de um outro arquivo chamado "chave.txt" contendo a chave.

- Metadados: 
Criptograma gerado por "Cripto_1.exe" a partir do arquivo "m164.txt"

{150, 151, 148, 21, 65, 24, 117, 149}<br />

fatia 0: 12 |150|<br />
fatia 0: 12 |146|<br />
fatia 0: 9 |211|<br />
-----------<br />
fatia 1: 11 |151|<br />
fatia 1: 8 |147|<br />
fatia 1: 8 |214|<br />
-----------<br />
fatia 2: 17 |148|<br />
fatia 2: 7 |209|<br />
fatia 2: 7 |213|<br />
-----------<br />
fatia 3: 10 |21|<br />
fatia 3: 8 |90|<br />
-----------<br />
fatia 4: 12 |65|<br />
fatia 4: 11 |0|<br />
fatia 4: 7 |73|<br />
fatia 4: 7 |67|<br />
fatia 4: 7 |69|<br />
-----------<br />
fatia 5: 15 |24|<br />
fatia 5: 10 |10|<br />
-----------<br />
fatia 6: 10 |117|<br />
fatia 6: 9 |60|<br />
-----------<br />
fatia 7: 15 |149|<br />
fatia 7: 9 |198|<br />

//FATIAS E REPETIÇÕES DE LETRAS<br />
//150/146 <br />
//214      <br />
//148     <br />
//21       <br />
//0/69     <br />
//26       <br />
//117      <br />
//218     <br />


// 10010110 / 10010010 = 10110110 / 10110010 = 182 / 178<br />
// 11010110 = 11110110 = 246<br />
// 10010100 = 10110100  = 180<br />
// 00010101 = 110101 = 53<br />
// 00000000 / 01000101 =  100000 / 10101010 = 32 / 170<br />
// 00011010 = 111010 = 58<br />
// 01110101 = 1010101 = 85<br />
// 11011010 = 11111010 = 250<br />
<br />
150 214 148 21 0 26 117 218<br />
<br />
// 00100000 (32)<br />
<br />
// <br />
<br />
Distribuição de ocorrencias dos 570 caracteres do texto e criptograma:<br />
                   TEXTO              ||      CRIPTOGRAMA              <br />
  1º- chr( 32) ' ':  87 (prob=0.1526) || chr(148)  18 (prob=0.0316)<br />
  2º- chr( 97) 'a':  73 (prob=0.1281) || chr(149)  17 (prob=0.0298)<br />
  3º- chr(101) 'e':  50 (prob=0.0877) || chr( 65)  16 (prob=0.0281)<br />
  4º- chr(111) 'o':  44 (prob=0.0772) || chr( 24)  15 (prob=0.0263)<br />
  5º- chr(115) 's':  42 (prob=0.0737) || chr(146)  15 (prob=0.0263)<br />
  6º- chr(105) 'i':  37 (prob=0.0649) || chr(218)  15 (prob=0.0263)<br />
  7º- chr(110) 'n':  32 (prob=0.0561) || chr(151)  14 (prob=0.0246)<br />
  8º- chr(100) 'd':  23 (prob=0.0404) || chr(150)  12 (prob=0.0211)<br />
  9º- chr(114) 'r':  22 (prob=0.0386) || chr(  0)  11 (prob=0.0193)<br />
 10º- chr(116) 't':  21 (prob=0.0368) || chr( 21)  11 (prob=0.0193)<br />
 11º- chr( 99) 'c':  20 (prob=0.0351) || chr(198)  11 (prob=0.0193)<br />
 12º- chr(109) 'm':  18 (prob=0.0316) || chr(219)  11 (prob=0.0193)<br />
 13º- chr(112) 'p':  17 (prob=0.0298) || chr( 10)  10 (prob=0.0175)<br />
 14º- chr(117) 'u':  16 (prob=0.0281) || chr(117)  10 (prob=0.0175)<br />
 15º- chr(108) 'l':  14 (prob=0.0246) || chr(214)  10 (prob=0.0175)<br />
 16º- chr( 44) ',':  10 (prob=0.0175) || chr(216)  10 (prob=0.0175)<br />
 17º- chr(113) 'q':   5 (prob=0.0088) || chr( 60)   9 (prob=0.0158)<br />
 18º- chr(227) 'ã':   5 (prob=0.0088) || chr( 69)   9 (prob=0.0158)<br />
 19º- chr(231) 'ç':   4 (prob=0.0070) || chr( 90)   9 (prob=0.0158)<br />
 20º- chr(102) 'f':   3 (prob=0.0053) || chr(199)   9 (prob=0.0158)<br />
 21º- chr(118) 'v':   3 (prob=0.0053) || chr(211)   9 (prob=0.0158)<br />
 22º- chr( 49) '1':   2 (prob=0.0035) || chr( 67)   8 (prob=0.0140)<br />
 23º- chr( 98) 'b':   2 (prob=0.0035) || chr( 89)   8 (prob=0.0140)<br />
 24º- chr(104) 'h':   2 (prob=0.0035) || chr(147)   8 (prob=0.0140)<br />
 25º- chr(122) 'z':   2 (prob=0.0035) || chr(208)   8 (prob=0.0140)<br />
 26º- chr(234) 'ê':   2 (prob=0.0035) || chr(209)   8 (prob=0.0140)<br />
 27º- chr( 50) '2':   1 (prob=0.0018) || chr( 73)   7 (prob=0.0123)<br />
 28º- chr( 56) '8':   1 (prob=0.0018) || chr( 79)   7 (prob=0.0123)<br />
 29º- chr( 59) ';':   1 (prob=0.0018) || chr( 84)   7 (prob=0.0123)<br />
 30º- chr( 81) 'Q':   1 (prob=0.0018) || chr(133)   7 (prob=0.0123)<br />
 31º- chr(103) 'g':   1 (prob=0.0018) || chr(153)   7 (prob=0.0123)<br />
 32º- chr(106) 'j':   1 (prob=0.0018) || chr(213)   7 (prob=0.0123)<br />
 33º- chr(119) 'w':   1 (prob=0.0018) || chr( 16)   6 (prob=0.0105)<br />
 34º- chr(120) 'x':   1 (prob=0.0018) || chr( 48)   6 (prob=0.0105)<br />
 35º- chr(224) 'à':   1 (prob=0.0018) || chr( 52)   6 (prob=0.0105)<br />
 36º- chr(225) 'á':   1 (prob=0.0018) || chr( 81)   6 (prob=0.0105)<br />
 37º- chr(233) 'é':   1 (prob=0.0018) || chr( 91)   6 (prob=0.0105)<br />
 38º- chr(237) 'í':   1 (prob=0.0018) || chr(154)   6 (prob=0.0105)<br />
 39º- chr(243) 'ó':   1 (prob=0.0018) || chr(157)   6 (prob=0.0105)<br />
 40º- chr(250) 'ú':   1 (prob=0.0018) || chr(159)   6 (prob=0.0105)<br />
 40º-                                 || chr( 22)   5 (prob=0.0088)<br />
 41º-                                 || chr( 33)   5 (prob=0.0088)<br />
 42º-                                 || chr(128)   5 (prob=0.0088)<br />
 43º-                                 || chr(130)   5 (prob=0.0088)<br />
 44º-                                 || chr( 26)   4 (prob=0.0070)<br />
 45º-                                 || chr( 29)   4 (prob=0.0070)<br />
 46º-                                 || chr( 32)   4 (prob=0.0070)<br />
 47º-                                 || chr( 38)   4 (prob=0.0070)<br />
 48º-                                 || chr( 49)   4 (prob=0.0070)<br />
 49º-                                 || chr( 78)   4 (prob=0.0070)<br />
 50º-                                 || chr( 83)   4 (prob=0.0070)<br />
 51º-                                 || chr( 85)   4 (prob=0.0070)<br />
 52º-                                 || chr( 88)   4 (prob=0.0070)<br />
 53º-                                 || chr(131)   4 (prob=0.0070)<br />
 54º-                                 || chr(158)   4 (prob=0.0070)<br />
 55º-                                 || chr(197)   4 (prob=0.0070)<br />
 56º-                                 || chr(212)   4 (prob=0.0070)<br />
 57º-                                 || chr(217)   4 (prob=0.0070)<br />
 58º-                                 || chr(221)   4 (prob=0.0070)<br />
 59º-                                 || chr(  9)   3 (prob=0.0053)<br />
 60º-                                 || chr( 11)   3 (prob=0.0053)<br />
 61º-                                 || chr( 37)   3 (prob=0.0053)<br />
 62º-                                 || chr( 56)   3 (prob=0.0053)<br />
 63º-                                 || chr( 58)   3 (prob=0.0053)<br />
 64º-                                 || chr( 68)   3 (prob=0.0053)<br />
 65º-                                 || chr( 70)   3 (prob=0.0053)<br />
 66º-                                 || chr( 71)   3 (prob=0.0053)<br />
 67º-                                 || chr( 80)   3 (prob=0.0053)<br />
 68º-                                 || chr(121)   3 (prob=0.0053)<br />
 69º-                                 || chr(129)   3 (prob=0.0053)<br />
 70º-                                 || chr(132)   3 (prob=0.0053)<br />
 71º-                                 || chr(134)   3 (prob=0.0053)<br />
 72º-                                 || chr(144)   3 (prob=0.0053)<br />
 73º-                                 || chr(152)   3 (prob=0.0053)<br />
 74º-                                 || chr(156)   3 (prob=0.0053)<br />
 75º-                                 || chr(192)   3 (prob=0.0053)<br />
 76º-                                 || chr(196)   3 (prob=0.0053)<br />
 77º-                                 || chr(215)   3 (prob=0.0053)<br />
 78º-                                 || chr(223)   3 (prob=0.0053)<br />
 79º-                                 || chr( 13)   2 (prob=0.0035)<br />
 80º-                                 || chr( 20)   2 (prob=0.0035)<br />
 81º-                                 || chr( 23)   2 (prob=0.0035)<br />
 82º-                                 || chr( 28)   2 (prob=0.0035)<br />
 83º-                                 || chr( 31)   2 (prob=0.0035)<br />
 84º-                                 || chr( 59)   2 (prob=0.0035)<br />
 85º-                                 || chr( 64)   2 (prob=0.0035)<br />
 86º-                                 || chr( 77)   2 (prob=0.0035)<br />
 87º-                                 || chr( 82)   2 (prob=0.0035)<br />
 88º-                                 || chr( 86)   2 (prob=0.0035)<br />
 89º-                                 || chr( 92)   2 (prob=0.0035)<br />
 90º-                                 || chr( 94)   2 (prob=0.0035)<br />
 91º-                                 || chr(155)   2 (prob=0.0035)<br />
 92º-                                 || chr(193)   2 (prob=0.0035)<br />
 93º-                                 || chr(210)   2 (prob=0.0035)<br />
 94º-                                 || chr( 12)   1 (prob=0.0018)<br />
 95º-                                 || chr( 17)   1 (prob=0.0018)<br />
 96º-                                 || chr( 25)   1 (prob=0.0018)<br />
 97º-                                 || chr( 36)   1 (prob=0.0018)<br />
 98º-                                 || chr( 39)   1 (prob=0.0018)<br />
 99º-                                 || chr( 45)   1 (prob=0.0018)<br />
100º-                                 || chr( 55)   1 (prob=0.0018)<br />
101º-                                 || chr( 57)   1 (prob=0.0018)<br />
102º-                                 || chr( 72)   1 (prob=0.0018)<br />
103º-                                 || chr(103)   1 (prob=0.0018)<br />
104º-                                 || chr(135)   1 (prob=0.0018)<br />
105º-                                 || chr(162)   1 (prob=0.0018)<br />
106º-                                 || chr(166)   1 (prob=0.0018)<br />
107º-                                 || chr(180)   1 (prob=0.0018)<br />
108º-                                 || chr(182)   1 (prob=0.0018)<br />
109º-                                 || chr(194)   1 (prob=0.0018)<br />
110º-                                 || chr(195)   1 (prob=0.0018)<br />
111º-                                 || chr(205)   1 (prob=0.0018)<br />
112º-                                 || chr(220)   1 (prob=0.0018)<br />
<br />
Tamanho médio de palavras do texto = 5.552;<br />
<br />
Total de bytes do criptograma: 570<br />

