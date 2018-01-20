# MuM - Repositório original do git: carlosemello/MuM. Composição Algorítmica
Este repositório contém apenas o trabalho desenvolvido na disciplina de Composição Algorítmica, em Universidade de Brasília, juntamente com o professor Carlos Eduardo Mello. Para o desenvolvimento do trabalho, foi utilizada a biblioteca encontrada no seguinte repositório: carlosemello/MuM.:<br />

- .sco: Definição da melodia. <br />
- .orc: Definição de instrumentos musicais.<br />
- .csd: .sco + .orc
- Execução de arquivos .csd:
1) Instale Csound, uma linguagem de programação para sons, através do comando:<br />
sudo apt-get install csound<br />
2) Execute:<br />
csound NomeDoArquivo.csd<br />
<br />

=> O projeto desta disciplina explora composição musical por meio do uso de computadores, simulando técnicas de improviso implementadas por meio de regras pré-definidas, baseando-se em teoria musical. Desenvolvemos 4 trabalhos e um projeto final. <br />
- Trabalho 1: Gerador e modificador de motivo simples.<br />
- Trabalho 2: Cantus firmus e contraponto.<br />
- Trabalho 3: Adição de acordes em melodia pronta.<br />
- Trabalho 4: Adição de melodia em sequência de acordes pronta.<br />
- Projeto Final: Trabalho 3 e 4 juntos. Usuário insere uma sequência de acordes quaisquer, e o programa deve se adaptar a esta sequência e gerar uma melodia com Trompete e Piano.<br />
- Execução de trabalhos e projeto final:<br />
1) Altere a variável "MAIN" dentro do arquivo "compile" na primeira linha, para o nome do arquivo que deseja executar.<br />
Exemplo: "MAIN=trabalho3" (Obs.: Não precisa adicionar .cpp). <br />
2) Atenção: Altere nos arquivos "trabalho1.cpp", "trabalho2.cpp", "trabalho3.cpp", "trabalho4.cpp", "ProjetoFinalv1.cpp", "ProjetoFinalv2.cpp" e "ProjetoFinalOficial.cpp" o diretório definido no #define PATH "diretorio" de acordo com o seu diretório. Ex.:<br />
'#define PATH "/user/Documentos/UnB/Disciplinas/Musical/MuM-master/"'<br />
Nota: Sempre deixe '/' no final do diretório.<br />
3) Execute: <br />
chmod 755 compileLib<br />
chmod 755 compile<br />
./compileLib<br />
./compile<br />
./NomeDoArquivoDefinidoNaVariavelMain (Exemplo: ./trabalho3)<br />

4) Provavelmente a música irá tocar automaticamente. Porém, recomenda-se executar o seguinte comando para tocar:<br />
csound Saida.orc Saida.sco -odac<br />
Nota: Caso queira gerar um arquivo .wav, retire a diretiva -odac do comando acima.




