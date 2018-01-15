package Aulas;

import java.util.Scanner;

public class Aula_17{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        System.out.println("Qual seu primeiro nome?");
        String primeiroNome = input.next();
        
        System.out.println("Qual seu último nome?");
        String ultimoNome = input.next();
        
        System.out.println("Qual sua idade?");
        int idade = input.nextInt();
        
        System.out.println("Olá " + primeiroNome +" " + ultimoNome +" de " + idade +"   anos.");
        
    }
}