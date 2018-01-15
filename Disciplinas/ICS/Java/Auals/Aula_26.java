package Aulas;

import java.util.Scanner;

public class Aula_26{
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int numero;
        
        do{
            
        System.out.println("Digite um numero de 0 a 10");
        numero = input.nextInt();
        
        }while(numero < 0 || numero > 10);
        
        for(int i = 0; i<=10; ++i){
            
            if(i == numero){
                 System.out.println("O seu numero é "+i);
                 break;
            }else{
                System.out.println("O seu numero não é "+i);
                
            }
            
        }
        
        
    }
}