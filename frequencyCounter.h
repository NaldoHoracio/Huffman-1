//
// Created by alvino on 04/10/16.
//

#ifndef STRING_FREQUENCYCOUNTER_H
#define STRING_FREQUENCYCOUNTER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arrayFrequency[256];
//extern int arrayFrequency[256]; //variavel global para todos os arquivos que referenciam o array
//guarda o valor da frequencia
void counter(char *fileName);   //funçao para contar caracteres

//void printFrequency(int array[256]); // funçao para imprimir a frequencia dos caracteres

#endif //STRING_FREQUENCYCOUNTER_H
