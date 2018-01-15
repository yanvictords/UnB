-- Autor: Gabriel Puppin Chaves Fulber  Matricula: 12/0031051

map3 f xs ys zs = case(xs, ys, zs) of				--A funcao map3 f xs ys zs aplica a funcao f as triplas (x,y,z)
 (x:xs, y:ys, z:zs) -> (f x, f y, f z):(map3 f xs ys zs)	--sendo que x eh a cabeca de xs, y de ys e z de zs, até que uma dessas listas
 (x:xs, y:ys, []) -> []						--fique vazia. A funcao so eh aplicada um numero de vezes igual ao comprimento
 (x:xs, [], z:zs) -> []						--da menor lista.
 (x:xs, [], []) -> []
 ([], y:ys, z:zs) -> []
 ([], y:ys, []) -> []
 ([], [], z:zs) -> []
 ([], [], []) -> []