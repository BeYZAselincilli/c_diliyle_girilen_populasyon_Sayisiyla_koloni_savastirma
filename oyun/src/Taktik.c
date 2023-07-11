#include "Taktik.h"
#include <stdio.h>

Taktik* new_Taktik(int taktikId) {  
    Taktik* this = (Taktik*)malloc(sizeof(Taktik));  //Taktik türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi this işaretçisine atanır.
    this->taktikId = taktikId;  //this işaretçisinin taktikId üyesine taktikId değeri atanır.
    return this;  //this işaretçisi döndürülerek oluşturulan Taktik yapısının adresi kullanıcıya verilir.
}


int savas() {
    int puan = rand() % 1001; //rastgele 0-1000 arası değer seçilir 
    return puan;  // puan olarak gerş döndürlür.
}