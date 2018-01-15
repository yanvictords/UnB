//package br.unb.poo.mh;

import java.util.Scanner;

public class InterpreterView {
	private static InterpreterView instance;
	
	private InterpreterView(){

	}
	
	public static InterpreterView instance() {
		if(instance == null){
			System.out.println("MiniHaskell Interpreter\n");
			instance = new InterpreterView();
		}
		return instance;
	}
	
	
	public String getEntry(){
		System.out.print (">>> ");
		return new Scanner(System.in).nextLine();
	}
	
}
