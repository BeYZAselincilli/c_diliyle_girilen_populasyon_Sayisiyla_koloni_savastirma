#include "Uretim.h"
#include <stdio.h>

Uretim *new_Uretim(int urunId){
  Uretim* this = (Uretim*)malloc(sizeof(Uretim));  //Uretim türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi this işaretçisine atanır.
    this->urunId = urunId;  //this işaretçisinin urunId üyesine urunId değeri atanır. Bu, fonksiyona parametre olarak verilen urunId değerini Uretim yapısının ilgili üyesine aktarır.
    return this;  //this işaretçisi döndürülerek oluşturulan Uretim yapısının adresi kullanıcıya verilir.
}

int uretim() {
  int uretilenDeger = rand() % 10 + 1; // 1-10 arası değer üretimi
    return uretilenDeger;
}