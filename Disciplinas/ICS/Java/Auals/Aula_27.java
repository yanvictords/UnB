package Aulas;

import java.util.Scanner;

public class Aula_27 {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        
        int num;
        do{
        System.out.println("Selecione um numero de 1 a 5.");
        num = input.nextInt();
        }while(num < 1 || num > 5);
        
        switch(num){
            case 1:
                System.out.println("você escolheu 1");
                break;
            case 2:
                System.out.println("você escolheu 2");
                break;
            case 3:
                System.out.println("você escolheu 3");
                break;
            case 4:
                System.out.println("você escolheu 4");
                break;
            case 5:
                System.out.println("você escolheu 5");
                break;
                
        }
    }
}
