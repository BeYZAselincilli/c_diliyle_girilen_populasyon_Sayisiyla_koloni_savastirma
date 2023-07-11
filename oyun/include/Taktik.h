#ifndef Taktik_h
#define Taktik_h

#include <time.h>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int taktikId;
    char taktik_Adi[2];
    int (*savas)();
 // void (*Taktik_YokEt)( Taktik taktik) ;
} Taktik;

Taktik* new_Taktik(int taktikId);
//void taktikYazdir(Taktik* taktik);


#endif