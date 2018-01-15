--Autor: Gabriel Puppin Chaves Fulber  Matricula: 12/0031051

substituirPal string palAlvo palSub = case (string, palAlvo, palSub) of			--A funcao substituirPal recebe uma string principal(string), uma palavra
 (_,[],_) -> string									--a ser substituida(palAlvo) e a palavra que a substituira(palSub).
 (_,_,[]) -> string									--A funcao tranforma a string numa lista de palavras usando words e
 ([],_,_) -> []										--chama a funcao subLista para fazer a substituicao em si. Depois eh
 (string,palAlvo, palSub) -> unwords(subLista (words(string), palAlvo, palSub))		--chamada a funcao unwords para transformar o resultado em uma string normal

subLista (listaPal, palAlvo, palSub) = case(listaPal,palAlvo,palSub) of			--A função subLista recebe uma lista de palavras(strings) e
 (head:lista, alvo, sub)|head==alvo -> sub:subLista(lista,alvo,sub)			--substitui toda occorencia da palavra palAlvo pela palavra palSub
			|otherwise -> head:subLista(lista,alvo,sub)			--retornando uma lista de palavras atualizada.
 ([],_,_) -> []