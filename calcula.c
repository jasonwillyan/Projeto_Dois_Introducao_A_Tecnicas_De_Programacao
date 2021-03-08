#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "calcula.h"

/*
Função calcula:
	1. Calcula a variavel "t".
	2. Aloca memória usando a função malloc.
	3. Calcula a interação entre as populações.
		Formula:
			S(t)=S(t-1)-h.b.S(t-1).I(t-1)
			I(t)=I(t-1)+h.[b.S(t-1).I(t-1)-k.I(t-1)]
			R(t)=R(t-1)+h.k.I(t-1)
			tempo(t)=tempo(t-1)+h
Parametros:
	Struct: MEC
	Struct SIR
*/

SIR *calcula(MEC *mec, SIR *sir, int *c)
{
    mec->Tempo1 = (10*(24*mec->Tempo1));
    mec->Tempo2 = (10*(24*mec->Tempo2));
  	sir->t = (10*(24*mec->Tempo)); ///< Atribuíndo valor a condicional de tempo da simulação 
	sir->SUS = malloc(sir->t * sizeof(double));  ///< Alocando memória para o vetor SUS da struct SIR
	sir->INF = malloc(sir->t * sizeof(double));  ///< Alocando memória para o vetor INF da struct SIR
	sir->REM = malloc(sir->t * sizeof(double));  ///< Alocando memória para o vetor REM da struct SIR
	sir->time = malloc(sir->t * sizeof(double)); ///< Alocando memória para o vetor time da struct SIR

  	sir->SUS[0] = mec->S; ///< Recebendo o valor de S na primeira posição do vetor SUS
	sir->INF[0] = mec->I; ///< Recebendo o valor de I na primeira posição do vetor INF
	sir->REM[0] = mec->R; ///< Recebendo o valor de R na primeira posição do vetor REM
	sir->time[0] = 0; ///< Recebendo o valor de tempo na primeira posição do vetor time

	/*
	While usando o valor de "t" como condição de parada para calcular a equação da interação entre as populações
	*/

    float aux = 0; ///< Auxiliar para o índice time
  	int i = 1; ///< Variável para estrutura While começando do índice 1 pois o íncice 0 já foi preenchido
	int x=0, y=0;
	while(i <= sir->t)
	{
        if(*c==1 && mec->Tempo1 == i){
            x++;
        }
        if(*c==2 && mec->Tempo2 == i){
            y++;
        }
		sir->SUS[i] = sir->SUS[i-1]-(mec->h*mec->b[x])*sir->SUS[i-1]*sir->INF[i-1];
		sir->INF[i] = sir->INF[i-1]+mec->h*(mec->b[x]*sir->SUS[i-1]*sir->INF[i-1]-mec->k[y]*sir->INF[i-1]);
		sir->REM[i] = sir->REM[i-1]+mec->h*mec->k[y]*sir->INF[i-1];
		aux = aux+mec->h;
		sir->time[i] = aux;
		i++;
	}

  return sir;
}