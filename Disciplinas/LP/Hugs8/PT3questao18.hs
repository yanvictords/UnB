--Autor: Gabriel Puppin Chaves Fulber  Matricula: 12/0031051

stringSepara xs = (firstHalf xs, secondHalf xs)   --Funcao principal, chama as duas funcoes que separam a string

firstHalf xs = case(xs) of			  --A funcao firstHalf percorre a string ate achar o caracter '/'
 (x:xs)|x=='/' -> []				  --concatenando os elementos percorridos em uma lista.
       |otherwise -> x:firstHalf xs
 [] -> []

secondHalf xs = case(xs) of			  --A funcao secondHalf percorre a string passada, ignorando
 (x:xs)|x=='/' -> firstHalf xs			  --todos os elementos percorridos ate encontrar um caracter '/'.
       |otherwise -> secondHalf xs		  --Depois de encontrado esse caracter, eh chamada a funcao firstHalf
 [] -> []					  --que percorre o resto da string, concatenando todos os elementos percorridos
						  --ate chegar ao final.