//
// Created by edvonaldoh on 30/09/16.
//

#include "helpful_function.h"

// Verifica se o bit de posição i do caractere c está setado - tem valor 1
int is_bit_i_set(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask & c;
}

unsigned char set_bit(unsigned char c, int i)
{
    unsigned char mask = 1 << i;
    return mask | c;
}