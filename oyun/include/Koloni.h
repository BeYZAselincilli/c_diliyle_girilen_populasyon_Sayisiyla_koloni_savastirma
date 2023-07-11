#ifndef Koloni_h
#define Koloni_h
#include "Taktik.h"
#include "Uretim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Koloni {
   Taktik *koloni_taktigi;
   Uretim *uretim_sekli;
   int yemekStogu;
   int populasyon;
   int azalan_populasyon;
   int kazanma;
   int kaybetme;
    int koloniikontrol;
   char koloniSembolu;
   int koloni_uretim_yemek;
   char (*sembolUret)();
   void (*free_koloni)(struct Koloni*);
  
   
};
typedef struct Koloni* Koloni;

Koloni new_Koloni(int);
char sembolUret();
void free_koloni(const Koloni);


#endif