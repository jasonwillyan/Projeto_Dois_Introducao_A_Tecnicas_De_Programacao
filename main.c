#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "leitura.h"
#include "calcula.h"
#include "escrita.h"

/*
Principal ponto de entrada do programa
*/

int main(int argc, char const *argv[])
{
    int c;
    scanf("%d", &c);
    MEC *mec = malloc(sizeof(MEC)); ///< Alocando memória para struct MEC
    SIR *sir = malloc(sizeof(SIR)); ///< Alocando memória para struct SIR
    leitura(mec); ///< Chamada da função leitura
    calcula(mec, sir, &c); /// Chamada da função calcula
    escrita(sir); ///< Chamada da função escrita
    free(mec); ///< Liberando a memória alocada na struct MEC
    free(sir); ///< Liberando a memória alocada na struct SIR
  
	return 0;
}