
import java.util.*;
import java.io.*;
import java.io.IOException;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;



public class MainInterpreter {


 	public static void main(String[] args) throws Exception {
        Context contexto = new Context();
        String linha, arquivo, avaliaTamanho;
        ValorInteiro inteiro;
        contexto.contextInsere(InterpreterView.instance().getEntry());
        while(!contexto.getExpressao().equals(":quit")){
            ANTLRInputStream input = new ANTLRInputStream(contexto.getExpressao());
            MiniLexer lexer = new MiniLexer(input);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            MiniParser parser = new MiniParser(tokens);
            ParseTree tree = parser.expressao();
            EvalVisitor eval = new EvalVisitor();
            PrettyPrinter printa = new PrettyPrinter();
            System.out.print(">>> ");
            Expressao tipo = eval.visit(tree);
            if(tipo.tipo() == Tipo.Booleano)
                printa.visitar((ValorBooleano) tipo);
            if(tipo.tipo() == Tipo.Inteiro){
                inteiro = (ValorInteiro) tipo;
                if(inteiro.getValor()!=null)
                    printa.visitar((ValorInteiro) tipo);
            }

            System.out.print("\n");
            contexto.contextInsere(InterpreterView.instance().getEntry());
        }
    }
}