//package br.unb.poo.mh;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.*;
import org.antlr.v4.runtime.Token;

import Visitors.Converter;
import Visitors.FunctionLoader;

public class InterpreterController {
	String raw;
	private static InterpreterController instance;

	public void init(){
		processaComandos();
	}

	private void processaComandos(){
		while(true){
			raw = InterpreterView.instance().getEntry();
			if(raw.equals("exit"))
				System.exit(0);
			if(isLoadFile(raw)){
				loadFile(raw);
				continue;
			}
			
			ANTLRInputStream input  = new ANTLRInputStream(raw);
			MiniHaskellLexer lexer = new MiniHaskellLexer(input);
			CommonTokenStream tokens = new CommonTokenStream(lexer);
			MiniHaskellParser parser = new MiniHaskellParser(tokens);
			ParseTree tree = parser.expression();
			Converter aval = new Converter();
			Expressao e = aval.visit(tree);
			if(e.tipo() != Tipo.Error){
				ValorParametrizado v = (ValorParametrizado) e.avaliar();
				System.out.println(v.getValor());
			}
			else
				System.out.println("syntax error!");
		}
	}

	private void loadFile(String raw) {
		String filename = raw.substring(10,raw.length()-2);
		String context = ""; 
		try {
			context = getFileContent(filename);
		} catch (IOException e) {
			System.out.println("error ocurred while opening file");
		}
		ANTLRInputStream input  = new ANTLRInputStream(context);
		MiniHaskellLexer lexer = new MiniHaskellLexer(input);
		CommonTokenStream tokens = new CommonTokenStream(lexer);
		MiniHaskellParser parser = new MiniHaskellParser(tokens);
		ParseTree tree = parser.declaration();
		FunctionLoader fl = new FunctionLoader();
		fl.visit(tree);
		
		
	}

	private String getFileContent(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("./modules/" + filename));
		String everything;
		try {
		    StringBuilder sb = new StringBuilder();
		    String line = br.readLine();
		    while (line != null) {
		        sb.append(line);
		        sb.append(System.lineSeparator());
		        line = br.readLine();
		    }
		    everything = sb.toString();
		} finally {
		    br.close();
		}
		return everything;
	}

	private boolean isLoadFile(String raw) {
		return raw.startsWith("loadFile(\"") && raw.endsWith("\")");
		
		
	}

	public static InterpreterController instance() {
		if(instance == null){
			instance = new InterpreterController();
		}
		return instance;
	}
}
