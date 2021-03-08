#ifndef struct_h ///< Estrutura de condição que verifica se arquivo .h já foi incluído
#define struct_h ///< Faz a inserção caso o arquivo .h não tenha sido inserido 

/*
Armazena os valores recebidos do arquivo de texto
*/

typedef struct
{
	float S; ///< Valor inicial de indivíduos suscetíveis (que ainda não estão contaminados).
	float I; ///< Valor inicial de indivíduos infectados (capazes de infectar indivíduos suscetíveis)
	float R; ///< Valor inicial de indivíduos removidos (que se recuperaram, tornaram-se imunes ou faleceram).
  	float h; ///< Pequeno intervalo de tempo (em horas);
  	float *b; ///< Facilidade de contágio de um indivíduo;
  	float *k; ///< Probabilidade que um indivíduo se recupere;
  	float Tempo; ///< Instantes de tempo nos quais o modelo é simulado (em dias).
    int Tempo1;
    int Tempo2;
}MEC; ///< Nome da struct que se refere aos Modelos epidemiológicos computacionais (MEC)

/*
Armazena os valores calculados nas equações de interação entre as populações
*/

typedef struct
{
	double *SUS; ///< Vetor que armazena as informações dos indivíduos suscetíveis
  	double *INF; ///< Vetor que armazena as informações dos indivíduos infectados
  	double *REM; ///< Vetor que armazena as informações dos indivíduos removidos
  	float *time; ///< Vetor que armazena as informações do horário (em horas)
  	int t; ///< Variável que armazena a informação de tempo da simulação 
}SIR; ///< Nome da struct que se refere ao sistema Suscetível-Infectado-Removido (SIR)

#endif ///< Fim da estrutura de condição