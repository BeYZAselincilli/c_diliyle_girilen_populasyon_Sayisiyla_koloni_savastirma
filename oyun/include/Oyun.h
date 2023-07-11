#ifndef OYUN_H
#define OYUN_H
#include "Koloni.h"
#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct OYUN {
    Koloni* koloniler;
    int koloni_sayisi;
    int elenen_koloni_sayisi;
    int sabitKoloniSayisi;
    int oyun_tur_sayisi;
    void (*Oyun_Savas)(Koloni koloni1,int indexOfKoloni1, Koloni koloni2,int indexOfKoloni2,struct OYUN* oyun) ;
    void (*kolonileriCreate)(int*, int, struct OYUN*);
    void (*ciktiVer)(struct OYUN *  , int );
    void (*koloni_kontrol) (struct OYUN* oyun,int turSayisi);
    void (*free_oyun)(struct OYUN*);
};

typedef struct OYUN *  Oyun;

Oyun new_Oyun(int koloni_sayisi);
void Oyun_Savas(Koloni koloni1,int indexOfKoloni1, Koloni koloni2,int indexOfKoloni2,struct OYUN* oyun) ;
void kolonileriCreate(int* ,int ,struct OYUN *);
void ciktiVer(struct OYUN * oyun , int tursayisi);
void koloni_kontrol(struct OYUN* oyun,int turSayisi);
void free_oyun(const Oyun);

#endif