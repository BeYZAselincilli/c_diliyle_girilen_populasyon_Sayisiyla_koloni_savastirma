#ifndef URETIM_H
#define URETIM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int urunId;
    char urun_Adi[2];
   int (*uretim)();
  
} Uretim;

Uretim *new_Uretim(int urunId);

#endif

