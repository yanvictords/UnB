import Data.Char



--22 função que tem como entrada 3 valores inteiros e retorna a media desses valores (resultado nos inteiros)

media a b c = media a b c where media a b c = div (a+b+c) 3

--23 função que recebe tres valores inteiros(a,b,c) e retorna a multiplicação de (a*b)*c

multiplica a b c = let product a b c = (a*b*c)*c in product a b c

--24 função que recebe uma lista de inteiros e retorna outra lista com duas unidades somadas aos seus elementos. a função map aplica a expressão lambda a todos os elementos da lista (somando 2 unidades) 

soma2 xs=map(\x->x+2)xs    
	
--3 Para retornar o resto de uma divisão de 2 números inteiro (a,b), basta subtrair "a" da multiplicação de "b" pela divisão inteira de "a" por "b"
-- Exemplo: a=15 e b =7 resto da divisão : 15-(7*2) =1, onde 7 = 15/7 (com resultado nos inteiros).

mod1 a b = a-((div a b)*b)

--5 A função "sum" soma todos os elementos de xs, que depois são multiplicados por 2.
dobroSoma xs = 2*(sum xs)  

--14 A função recebe uma lista de inteiros que tem seus elementos analisados pelas funções "filter even" e "filter odd", retornando duas listas, uma com os elementos ímpares da lista original e outra com elementos pares.

paridade xs = ((filter even xs),( filter odd xs)) 

--11 Função que recebe uma lista de valores inteiros e retorna aqueles que são maiores que a media da lista. para fazer tal verificação, é utilizada a função div para dividir a soma dos valores da lista pela tamanho da mesma.

acimaMedia xs = [a|a<-xs , a > (div (sum xs) (length xs))]


--7 divisores de n : a função utiliza a função mod1 implementada mais acima para verificar quais números anteriores ao número de entrada tem resto 0 na divisao de y(entrada) por a(valores menores que y)

divisores y = [a|a<-[1..y], mod1 y a == 0]


--10 função que retorna a quantidade de vezes que um número aparece em uma lista. tem como entrada uma lista e o número do qual se deseja saber o número de ocorrências. utiliza a funcao length para saber o tamanho da lista formada pelo elementos iguais a n.
 
repeticoes xs n = length ([a|a<-xs, a == n ])

--13 

--posicao xs n = [a|a<-xs, a]


