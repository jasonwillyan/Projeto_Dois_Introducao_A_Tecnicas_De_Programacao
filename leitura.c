#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "leitura.h"

/*
Função leitura: 
	1. Abre o arquivo de texto no modo leitura e armazenar os dados em variáveis com o uso das funções strcmp e fscanf e fechamos o arquivo no final da leitura.
	2. Por fim Calculamos os valores de b e k.
		Formula:
			b = N_b / T_b * S_b0 * I_b0
			k = m_k / n_k * T_k

Parametros:
	Struct MEC
*/

void leitura(MEC *mec)
{
  FILE *texto = fopen("texto.txt", "r"); ///< Abrindo arquivo de texto no modo leitura

	if(texto == NULL) ///< Verificando se deu erro ao abrir o arquivo de texto
	{
		printf("Erro\n");
		system("pause");
		exit(1);
	}

	char str[10]; ///< variável criada para auxiliar

	float N_b;  ///< número de pessoas suscetíveis que se infectaram em um intervalo de tempo T_b
	float T_b;  ///< Intervalo de tempo
	float S_b0; ///< número de pessoas suscetíveis no início da observação
	float I_b0; ///< número de pessoas infectadas no início da observação
	float m_k;  ///< Individuos recuperados
	float n_k;  ///< Total de individuos
	float T_k;  ///< Intervalo de tempo
    float T_b1;
    float h1;
    float T_k1;
    float h2;
  
	/*
	While compara se string str com EOF(fim de arquivo), é uma condição do sistema operacional de um computador, atingida quando não há mais dados a serem lidos, usamos  a função strcmp (função que permite a comparação de duas strings) e a função fscanf (função que permite a leitura de dados a partir de uma fonte de caracteres de acordo com um formato pré determinado) para salvar os dados lidos em variáveis.
	*/

	while(fscanf(texto, "%s", str) != EOF)
	{
		if(strcmp(str,"S(0)") == 0)
		{
			fscanf(texto, "%f", &mec->S);
		}
		else if(strcmp(str, "I(0)") == 0)
		{
			fscanf(texto, "%f", &mec->I);
		}
		else if(strcmp(str, "R(0)") == 0)
		{
			fscanf(texto, "%f", &mec->R);
		}
		else if(strcmp(str, "h") == 0)
		{
			fscanf(texto, "%f", &mec->h);
		}
		else if(strcmp(str, "N_b") == 0)
		{
			fscanf(texto, "%f", &N_b);
		}
		else if(strcmp(str, "T_b") == 0)
		{
			fscanf(texto, "%f", &T_b);
		}
		else if(strcmp(str, "S_b0") == 0)
		{
			fscanf(texto, "%f", &S_b0);
		}
		else if(strcmp(str, "I_b0") == 0)
		{
			fscanf(texto, "%f", &I_b0);
		}
		else if(strcmp(str, "m_k") == 0)
		{
			fscanf(texto, "%f", &m_k);
		}
		else if(strcmp(str, "n_k") == 0)
		{
			fscanf(texto, "%f", &n_k);
		}
		else if(strcmp(str, "T_k") == 0)
		{
			fscanf(texto, "%f", &T_k);
		}
		else if(strcmp(str, "Tempo") == 0)
		{
			fscanf(texto, "%f", &mec->Tempo);
		}
        else if(strcmp(str, "T_b1") == 0)
		{
			fscanf(texto, "%f", &T_b1);
		}
        else if(strcmp(str, "Tempo1") == 0)
		{
			fscanf(texto, "%d", &mec->Tempo1);
		}
        else if(strcmp(str, "T_k1") == 0)
		{
			fscanf(texto, "%f", &T_k1);
		}
        else if(strcmp(str, "Tempo2") == 0)
		{
			fscanf(texto, "%d", &mec->Tempo2);
		}
	}

	fclose(texto); ///< Fechar o arquivo de texto

    mec->b = malloc(2 * sizeof(float));
    mec->k = malloc(2 * sizeof(float));

	mec->b[0] = N_b/(T_b*S_b0*I_b0); ///< Calcula o valor de b no cenário 0
	mec->k[0] = m_k/(n_k*T_k); ///< Calcula o valor de k no cenário 0

    mec->b[1] = N_b/(T_b1*S_b0*I_b0); ///< Calcula o valor de b no cenário 1
	mec->k[1] = m_k/(n_k*T_k1); ///< Calcula o valor de k no cenário 2
}