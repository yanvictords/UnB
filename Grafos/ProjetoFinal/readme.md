# Projeto Final da Disciplina - Agrupamento Espectral

//******UNIVERSIDADE DE BRASÍLIA*****************
//******TAG: 2017/01
//******ALUNOS: GUILHERME ANDREÚCE - 
//******ALUNOS: RODRIGO VILAÇA - 14/0031111
//******ALUNOS: YAN VICTOR - 14/0033599
//***********************************************


- Objetivo: Dado um conjunto de dados, deve-se realizar um agrupamento utilizando uma tecnica de agrupamento espectral. Especificamente, deve-se agrupar os registros (instâncias) de um conjunto de dados de acordo com os atributos que os descrevem. Espera-se que instâncias similares em relacao aos seus atributos pertencam ao mesmo grupo, enquanto que instâncias bem diferentes entre si estejam em grupos distintos.

- Descrição: As instâncias utilizadas são diversos animais cujos dados estão inseridos em um arquivo chamado "lista_de_animais.in". Os dados foram retirados do site UCI Machile Learning Repository: https://archive.ics.uci.edu/ml/datasets.html.

- Ferramentas: Utilizamos a MathLab para a representação dos dados, e a implementação da Kmeans: http://mnemstudio.org/clustering-k-means-example-1.htm.

Execução: Para executar o programa, basta executar os seguintes comandos:

g++ trab.cpp kmeans.cpp -o t

./t < entradaKmeans.in

