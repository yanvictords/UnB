-- PARTE 4 FEITA POR YAN VICTOR DOS SANTOS 14/0033599
--22. A função mediapond recebe inteiros a,b e os pesos pa,pb e calcula a media ponderada.

mediapond a b pa pb = ponderada a b pa pb where ponderada a b pa pb = (a*pa + b*pb)/(pa+pb)

---------------------
--23. A função listapar recebe uma lista de inteiros e retorna uma outra lista contendo apenas os elementos pares.
listapar xs = let par xs = (filter even xs) in par xs

---------------------
--24. A lista funcaoexp recebe uma lista de inteiros, e da um menu de opçoes onde z=0 calcula o quadrado de cada elemento, z=1 calcula a metade de cada elemento e z=2 calcula o fatorial de cada elemento. Caso z seja diferente, retorna lista contendo apenas zeros. Usa a função lambda e map.
funcaoexp xs z   
		    | z==0 = map(\x -> x^2)xs 
		    | z==1 = map(\x -> x/2)xs
		    | z==2 = map(\x -> product[1..x])xs
		    |otherwise = map(\x -> x-x)xs
---------------------
--25. A funcao volumesfera recebe como parametro o raio que pode ser do tipo float ou int (polimorfismo) e para a realizar operacao da formula usa composição de funções.
volumesfera r = ((*4).(*3.14).(^3))r

	
---------------------
--26. A funcao 'lista a b c' calcula o dobro da soma dos elementos de uma lista retornada da funcao 'listacomintervalo a b c' que cria uma lista a partir de um objeto infinito, onde cada elemento de tal lista é elevada a quarta potencia na funcao quadrad por avaliação preguiçosa em 'lista a b c'.
	
lista a b c =  sum (quadrad (quadrad (listacomintervalo a b c))) + sum (quadrad (quadrad (listacomintervalo a b c)))

quadrad xs = map(\x -> x^2)xs

listacomintervalo a b c  | a==c = []
			 | a>c = listacomintervalo c b a
			 | b == 0 = listacomintervalo a 1 c
	    		 | b < 0 = listacomintervalo a (b*(-1)) c
			 | a<c && b>0 = let vet n = take n [a,(b+1)..] in vet c


