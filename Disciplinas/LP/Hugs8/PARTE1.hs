--Parte I, exe1
fun [a,b,c,d] = (a==b) && (a==c) && (a==d)
--Se todos os elementos da lista forem iguais retorna True

--Parte I, exe3
resto a b = (rem a b)
--Calcula o resto de uma divisão usando o operador rem

--Parte I, exe6
bissexto:: Int-> Bool
bissexto b 	| (mod b 400 == 0) = True
			| (mod b 4 == 0) && (mod b 100 /= 0) = True
			| otherwise = False
--Caso o ano inserido seja múltiplo de 400 ou multiplo de 4 e não multiplo de 100, então,
--ele é considerado ano bissexto.
