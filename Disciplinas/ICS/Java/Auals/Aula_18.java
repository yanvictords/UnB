package Aulas;

import java.util.Scanner;

public class Aula_18{
    public static void main (String[] args){
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("Qual seu nome?");
        String nome = input.nextLine();
        
        System.out.println("Qual sua idade?");
        int idade = input.nextInt();
        
        if(idade < 18){
            System.out.println("Olá " +nome +" Você tem " +idade +" anos e portanto é menor de idade");
        }else{
            System.out.println("Olá " +nome +" Você tem " +idade +" anos e portanto é maior de idade");
        }
        
    }
}