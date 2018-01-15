package Aulas;

import java.util.Scanner;

public class Aula_20 {
    public static void main(String[] args){
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("Digite o ano que deseja verificar se é bissexto");
        int ano = input.nextInt();
        boolean x =((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)));
        
        if(x == true){
     
            System.out.println("O ano " +ano+" é bissexto");
        }else{
            System.out.println("O ano " +ano+ " não é bissexto");
        }
    }
}
