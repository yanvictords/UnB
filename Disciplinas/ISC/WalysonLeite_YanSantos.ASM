.data
	mensagemInicial1: .asciiz "Digite a quantidade de numeros a serem ordenados:\n"
	mensagemInicial2: .asciiz "Digite os "
	mensagemInicial3: .asciiz " numeros a serem ordenados -Aperte enter apos digitar cada um dos numeros -:\n"
	virgula: .asciiz ","
 	quebralinha: .asciiz "\n"
	teste: .asciiz "entrou\n"
.text
	main:

	jal RecebeQuantidadeDeNumeros #Chama a função
	jal AlocaArray 				  #Chama a funcao
	jal PreencheArray
	addi $t3,$zero,0 			  #contador para percorrer array t3=0
	jal PrintArray	
	
	li $v0,4				#Imprime quebra de linha
	la $a0,quebralinha
	syscall
		
	addi $t3,$zero,0 #contador para percorrer array t3=0
	addi $t4,$zero,0 #contador para percorrer array t3=0

	jal Ordena
	addi $t3,$zero,0 #contador para percorrer array t3=0
	
	
	jal PrintArray	

	li $v0 10
	syscall
###########################################################
###########################################################
	
	RecebeQuantidadeDeNumeros:
	
		li $v0,4
		la $a0,mensagemInicial1 # "Digite a quantidade de numeros a serem ordenados:\n"
		syscall
		
		li $v0,5				#Pega input do usuario e armazena em v0
		syscall					
		move $t0,$v0			#t0 - inteiro armazena a quantidade de numeros a serem lidos
		move $a1,$v0			
		add $a1,$a1,-1			#a1 - inteiro armazena a quantidade de numeros a serem lidos - 1
	
		li $v0,4				
		la $a0,mensagemInicial2		#"Digite os "
		syscall
		
		li $v0,1				
		move $a0,$t0		#"Printa a quantidade de numeros "
		syscall


	
		li $v0,4
		la $a0,mensagemInicial3	#"numeros a serem ordenados:\n"
		syscall
		jr $ra #call back
		
	AlocaArray:
		mul $t1,$t0,-4 	#Considerando que 1 inteiro = 4bytes, multiplica a 
					  	#quantidade de numeros por 4 para obter a memoria necessaria para armazenar o array
		add  $sp,$sp,$t1#t1 Reserva uma quantidade de bytes equivalente a t1 no stack
		move $t1,$sp	#t1 recebe endereco da memoria resevada para o vetor
		move $t2,$sp	#t2 recebe endereco da memoria resevada para o vetor

		jr $ra #call back,volta para main
		
		
	PreencheArray:
		bge  $t3,$t0,Voltar		#Sairá do loops apenas se t3>=t0,sendo t0 a quantidade de numeros e t3 um contador
		addi $t3,$t3,1			#incrementa o contador t3=t3+1
		
		li $v0,5				#Pega input do usuario e armazena em v0
		syscall					
			
		sw  $v0,0($t2)			#Armazena o numero no endereço de memoria t2
		addi $t2,$t2,4			#incrementa a posição de memória t2 em 4

		
		j PreencheArray			#while loop
		
	PrintArray:
		bge  $t3,$t0,Voltar		#Sairá do loops apenas se t3>=t0,sendo t0 a quantidade de numeros e t3 um contador
		addi $t3,$t3,1			#incrementa o contador t3=t3+1
		
		li $v0,1				#Printa na tela um numero do array
		lw $a0,0($t2)			#Posicao de onde o numero vai ser buscado
		syscall
		addi $t2,$t2,4			#incrementa o endereco para acesso ao vetor em 4.Poe o endereco no proximo numero
		
		li $v0,4				#Imprime uma virgula
		la $a0,virgula
		syscall

		
		
		j PrintArray			#while loop
			
	Voltar:
		move $t2,$t1 #t2 recebe o endereco inicial do vetor t2=t1		
		add $t3,$zero,0
		jr $ra #call back
################
	Ordena:
	
	move $t8,$ra
		bge  $t3,$a1,VoltarOrdena		#Sairá do loops apenas se t3>=a1,sendo a1 a quantidade de numeros -1 e t3 um contador
	
		add $t4,$t3,1 	
		move $s3,$t3
		jal Menor
		move $ra,$t8
		
		jal Swap
		move $ra,$t8
		
		add $t3,$t3,1
		j Ordena			#while loop
		
	VoltarOrdena:
		jr $ra #call back

	Menor:	
		bge  $t4,$t0,VoltarMenor #Sairá do loops apenas se t4>=t0,sendo t0 a quantidade de numeros e t4 um contador
		
		add $t6,$zero,0
		mul $t6,$s3,4			#Calcula a posicao do indice s3 dentro do vetor e armazena em t6
		add $t6,$t6,$t1			#soma a posicao do incide t6 ao endereco inicial do vetor para obter o valor contido no indice
		lw $s2,0($t6)			#s2 recebe o numero contido no endereco de memoria t6

		mul $t5,$t4,4			#Calcula a posicao do indice t4 dentro do vetor e armazena em t5
		add $t5,$t5,$t1			#soma a posicao do incide t5 ao endereco inicial do vetor para obter o valor contido no indice
		lw $s1,0($t5)			#armazena em s1 o valor contido em vetor[t5]

		blt $s1,$s2,Operacao 
		add $t4,$t4,1
		j Menor			#while loop
	
	Operacao:
		 move $s3,$t4 
		 add $t4,$t4,1	
		 j Menor
		
	VoltarMenor:	
		jr $ra
	
	Swap:
		mul $s4,$t3,4			#Calcula a posicao do indice t3 dentro do vetor e armazena em s4
		add $s4,$s4,$t1			#soma a posicao do incide t3 ao endereco inicial do vetor para obter o valor contido no indice
		lw $s5,0($s4)			#armazena em s5 o valor contido  em vetor[t3]
		
		move $t9,$s5
		
		mul $s6,$s3,4			#Calcula a posicao do indice s3 dentro do vetor e armazena em s6
		add $s6,$s6,$t1			#soma a posicao do incide s6 ao endereco inicial do vetor para obter o valor contido no indice
		lw $s7,0($s6)			#armazena em s7 o valor contido  em vetor[s6]
	
		sw $s7,0($s4)			#armazena o numero contido em s7 no endereço s4 
		sw $t9,0($s6)			#armazena o numero contido em t9 no endereço s6
		jr $ra
