Parte 2 - Feito por Diego Brian

--15) Esta função verifica se o ponto (x,y) respeita a equação do círculo, que é dada por (x-a)^2 + (y-b)^2 = r^2. Caso o ponto (x,y) respeite essa equação, a função retorna verdadeiro, caso contrario, retorna falso.
circ x y r a b 
	|(x-a)^2 + (y-b)^2 == r^2 = True
	|otherwise = False

--14) Esta função, a partir de uma lista numeros, retorna duas listas, uma contendo os números pares e outra contendo os numeros ímpares, para isso, são realizados dois filtros, um que separa os números pares e outro que separa os números ímpares.
imparpar (x:y) = (z,w)
	where {z = filter even (x:y) ;
		w = filter odd(x:y)}

--13) Esta função varre a lista, elemento a elemento, e se este elemento for diferente do elemento que está sendo buscado. Caso seja, a função adiciona uma unidade a uma espécie de contador rescursivo que vai contando as posições. Se o elemento for igual ao que está sendo buscado, a função soma 0 à contagem e encerra, obtendo assim a posição do elemento buscado.
pos a (x:y)
	|(a /= x) = 1 + pos a y
	|(a == x) = 0

--8) Semelhante à questão 13, esta função varre a lista elemento a elemento e vai fazendo uma espécie de contagem, somando 1 caso o elemento seja igual ao que está sendo buscado, e 0 caso não seja. Ao chegar ao final da lista, a função soma 0 à contagem e encerra. Dessa forma, é obtida a quantidade de vezes que o determinado elemento que está sendo buscado aparece na lista.
quant a [] = 0
quant a (x:y)
	|(a /= x) = 0 + quant a y
	|(a == x) = 1 + quant a y
