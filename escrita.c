#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "escrita.h"

/*
Função escrita:
	Cria um arquivo texto para leitura e gravação. Usa a função fprintf para escrever no arquivo usando as variaveis da struct passada por referência na função escrita.
Parametros:
	Struct SIR
*/

void escrita(SIR *sir)
{
  FILE *saida = fopen("saida.csv", "w+"); ///< Cria um arquivo texto para leitura e gravação. Se o arquivo existir, o conteúdo anterior será destruído. Se não existir, será criado.

 	if(saida == NULL) ///< Verifica se deu erro ao abrir o arquivo
	{
 		printf("Erro");
  		system("pause");
		exit(1);
 	}

	for(int x=0; x<=sir->t; x++) ///< Estrutura de repetição para imprimir os valores de SIR
	{
		fprintf(saida, "%.5f,%.5f,%.5f,%.1f\n", sir->SUS[x], sir->INF[x], sir->REM[x], sir->time[x]); ///< Usando a função fprintf(função que permite a escrita de dados formatos em um arquivo).
	}

 	fclose(saida); ///< Fechar o arquivo de texto
}