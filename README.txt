Alunos:
	Jason Willyan Castro do Nascimento
	Robert Matheus Costa Targino

Como compilar e rodar o programa:
	1 - Abra o terminal (ctrl + alt + t)
	2 - Vá até o diretorio onde está seu programa.
		2.1 - Se você baixou o arquivo, provavelmente o programa se encontra na pasta download passa isso é preciso usar o comando "cd" para navegar pelos arquivos do sistema. Exemplo: aluno@linux:/$ cd/home/aluno/downlods
	3 - Para compilar é preciso usar uma linha de comando, por exemplo: gcc seucodigo.c -o 	seuprograma. Como o código é dividido em vários arquivos, execute a linha abaixo:

		gcc leitura.c calcula.c escrita.c main.c -o sir 

		Depois de compilar basta executar seu programa assim:

		./sir

Como escrever um arquivo de configuração de entrada:
    1 - O arquivo de entrada precisa ter o nome e tipo "texto.txt".
    2 - Todos os parâmetros necessários para a simulação precisam estar escritos em linhas diferentes e em      uma mesma sequência, seguidos do valor de seus respectivos parâmetros, assim como no exemplo abaixo.
    3 - Exemplo de entrada:
        S(0) 68
        I(0) 2
        R(0) 0
        h 0.1
        N_b 12
        T_b 24
        S_b0 10
        I_b0 50
        m_k 6
        n_k 22
        T_k 24
        Tempo 21



Checkpoint 1 sem limitações: 


