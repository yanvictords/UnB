// Generated from Mini.g4 by ANTLR 4.6
import org.antlr.v4.runtime.tree.AbstractParseTreeVisitor;
import java.util.*;
import java.io.*;
import java.io.IOException;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;


public class EvalVisitor extends MiniBaseVisitor<Expressao> {

    @Override public Expressao visitLet(MiniParser.LetContext ctx) { 
        ValorInteiro trash;
        String corpo = ctx.corpo.getText();
        String nome = ctx.nome.getText();
        String principal="";
    for(int i=0; i<corpo.length();i++){

        if(nome.equals(corpo.substring(i, i+(nome.length()))) ){
            principal = principal + "(" + ctx.valor.getText() + ")";
        }else{
            principal = principal + corpo.substring(i, i+(nome.length()));
        }
    }

        avaliarexpressao(principal, 0);

        return new ValorInteiro(null);
    }


    @Override public Expressao visitMenorIgual(MiniParser.MenorIgualContext ctx) { 
        return new MenorIgual(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitMultiplicacao(MiniParser.MultiplicacaoContext ctx) { 
        return new  Multiplicacao(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitAvaliar(MiniParser.AvaliarContext ctx) { 
        return this.visit(ctx.exp); 
    }

    @Override public Expressao visitLoad(MiniParser.LoadContext ctx) { 
        String linha,ultima;
        try {
            FileReader arq = new FileReader(ctx.arquivo.getText() + ".mhs");
            BufferedReader lerArq = new BufferedReader(arq);
            linha = lerArq.readLine();
            while(linha != null) {
                if(linha.length()>=3)

                    if(linha.substring(0,3).equals("let")) {
                        avaliarexpressao(linha, 1);

                    }else{
                        avaliarexpressao(linha, 0);
                    }
            linha = lerArq.readLine();
            }
            arq.close();
        }catch (IOException e) {
            System.err.printf(">>> Erro na abertura do arquivo: %s.\n",
            e.getMessage());
            System.exit(0);
        }
        return new ValorInteiro(null);
    }

    @Override public Expressao visitParenteses(MiniParser.ParentesesContext ctx) { 
        return this.visit(ctx.exp);
    }

    @Override public Expressao visitOr(MiniParser.OrContext ctx) { 
        return new  Or(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitTrue(MiniParser.TrueContext ctx) { 
        return  new ValorBooleano(true);
    }

    @Override public Expressao visitFalse(MiniParser.FalseContext ctx) {
        return  new ValorBooleano(false);
    }

    @Override public Expressao visitSubtracao(MiniParser.SubtracaoContext ctx) { 
        return new  Subtracao(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitDivisao(MiniParser.DivisaoContext ctx) { 
        return new  Divisao(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitNot(MiniParser.NotContext ctx) { 
        return new  Not(this.visit(ctx.exp)).avaliar();
    }

    @Override public Expressao visitMaior(MiniParser.MaiorContext ctx) {
        return new Maior(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitMenor(MiniParser.MenorContext ctx) { 
        return new Menor(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitAnd(MiniParser.AndContext ctx) { 
        return new And(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitIgual(MiniParser.IgualContext ctx) { 
        return new Igual(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }


    @Override public Expressao visitSoma(MiniParser.SomaContext ctx) {
        return new  ExpressaoSoma(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }


    @Override public Expressao visitMaiorIgual(MiniParser.MaiorIgualContext ctx) { 
        return new  MaiorIgual(this.visit(ctx.esq),this.visit(ctx.dir)).avaliar();
    }

    @Override public Expressao visitIdentificador(MiniParser.IdentificadorContext ctx) {
        return new Identificador(ctx.getText());
    }

    @Override public Expressao visitIf(MiniParser.IfContext ctx) { 
        return new IfThenElse(this.visit(ctx.condicao), this.visit(ctx.clausula_then),this.visit(ctx.clausula_else)).avaliar();
    }

    @Override public Expressao visitInteiro(MiniParser.InteiroContext ctx) { 
        return  new ValorInteiro(Integer.parseInt(ctx.getText()));
    }

    public static void avaliarexpressao(String expr, int flag){
        ANTLRInputStream input = new ANTLRInputStream(expr);
        MiniLexer lexer = new MiniLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        MiniParser parser = new MiniParser(tokens);
        ParseTree tree = parser.expressao();
        EvalVisitor eval = new EvalVisitor();
        PrettyPrinter printa = new PrettyPrinter();

        if(flag==0){
            System.out.print("\n|Resposta: ");
            if(eval.visit(tree).tipo() == Tipo.Booleano)
                printa.visitar((ValorBooleano) eval.visit(tree));
            if(eval.visit(tree).tipo() == Tipo.Inteiro)
                printa.visitar((ValorInteiro) eval.visit(tree));
        }else{
               ValorInteiro trash = (ValorInteiro) eval.visit(tree);
        }

        

    }
}