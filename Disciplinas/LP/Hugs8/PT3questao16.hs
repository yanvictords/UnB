--Autor: Gabriel Puppin Chaves Fulber  Matricula: 12/0031051

isDiv x y = mod y x == 0				--A funcao isDiv x y determina se y eh dividivel por x. Caso for, retorna True, senao retorna False.


peneiraPrimo xs = case(xs) of				--A funcao peneiraPrimo recebe uma lista de inteiros xs e retorna uma lista
 (x:xs) -> x:peneiraPrimo(filter ((not.isDiv x)) xs)    --contendo somente os elementos primos da lista original
 ([]) -> []

primoMenor 0 = []
primoMenor 1 = []					--A funcao primoMenor eh a principal funcao do programa.
primoMenor 2 = []					--Quando eh chamada com valores maiores que 1, ela passa uma lista
primoMenor x = peneiraPrimo [2..x-1]			--contendo todos os numeros entre 2 e o parametro x para a funcao peneiraPrimo.
							--A funcao peneiraPrimo entao retorna uma lista contendo somente os elementos primos
							--da lista original, sendo que o resultado final eh uma lista contendo todos os numeros
							--primos menores que o parametro x.



