package Aulas;

import java.util.Scanner;
import java.util.Random;

public class Aula_22{
    public static void main(String[] args){
        
        Scanner input = new Scanner(System.in);
        Random random = new Random();
        
        boolean acertou = false;
        int  tentativas = 10;
        int numeroSecreto = random.nextInt();
        long chute = 0;
        
        while(tentativas > 0 && acertou == false){
            System.out.println("Qual o seu chute? Você tem 10 tentativas.");
            chute = input.nextLong();
            
            if(chute == numeroSecreto){
                acertou = true;
                System.out.println("Parabéns, você acertou");
            }else if(chute < numeroSecreto){
                --tentativas;
                System.out.println("Numero menor que a chave. "+tentativas+" tentativas restantes.");
            }else{
                --tentativas;
                System.out.println("Numero maior que a chave. " +tentativas+" tentativas restantes.");
            }
        }
        System.out.println("Você não conseguu :( O número era "+numeroSecreto+".");
    }
}