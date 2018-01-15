package Aulas;

import java.util.Scanner;

public class Aula_28 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        int numAlunos = 5;
        double[] notaAlunos = new double[numAlunos];
        
        for(int i = 0; i < numAlunos; ++i){
            System.out.println("Insira a nota do "+ (i+1) +"º aluno.");
             notaAlunos[i] = input.nextDouble();  
        }
        
        for(int i = 0; i < numAlunos; ++i){
            System.out.println("->" +notaAlunos[i]);
        }
    }
}
