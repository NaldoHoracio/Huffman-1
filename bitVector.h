//
// Created by alvino on 15/10/16.
//

#ifndef STRING_BITVECTOR_H
#define STRING_BITVECTOR_H

#include "stringList.h"

Node_String* getBits(Node_String *str);

int get_bit(unsigned char c, int i); // Retorna o bit deposição i no byte c

unsigned char set_bit(unsigned char c, int i); // Seta para 1 o bit deposição i no byte c


#endif //STRING_BITVECTOR_H
