##Readme MINIHASKELL PT2
Pedro Henrique Santos Gonzaga - 140030131
Rômulo de Vasconcelos Feijão Filho - 140031260
Yan Victor dos Santos - 140033599

#A segunda parte do trabalho foi implementada usando ANTLR
#A definição da linguagem está no arquivo Mini.g4
#Os Testes feitos estão no arquivo teste.mhs
#Usamos visitors para implementar as novas transformaciones (classe EvalVisitors)
#eval(""), :quit, loadFile(""), soma(,), subtracao(,), multiplicacao(,) e divisao(,) serao reconhecidos.

#COMO USAR: precisa ter o antlr. Utilize os seguintes comandos no terminal:


cd /usr/local/lib
sudo curl -O http://www.antlr.org/download/antlr-4.6-complete.jar
export CLASSPATH=".:/usr/local/lib/antlr-4.6-complete.jar:$CLASSPATH"
alias antlr4='java -jar /usr/local/lib/antlr-4.6-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'


antlr4 Mini.g4 -no-listener -visitor
javac Mini*.java
javac MainInterpreter.java
java MainInterpreter

#A classe MainInterpreter é a principal classe.
