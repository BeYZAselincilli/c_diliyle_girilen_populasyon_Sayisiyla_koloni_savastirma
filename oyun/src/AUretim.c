#include "AUretim.h"
#include <stdio.h>
#include <string.h> 
int AUretim_uretim(){
    int uretilenDeger = rand() % 10 + 1; // 1-10 arası değer üretimi
    return uretilenDeger;
}

AUretim* new_AUretim() {
    AUretim* urun = malloc(sizeof(AUretim));  //AUretim türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi urun işaretçisine atanır.
    if (urun != NULL) {  //urun işaretçisinin değeri kontrol edilir. Eğer urun NULL değilse, bellek başarıyla ayrılmış demektir.
        Uretim* temel = &(urun->temel_uretim);  //temel işaretçisi, urun yapısının temel_uretim üyesine yönlendirilir.
        temel->uretim = &AUretim_uretim;  //temel işaretçisinin uretim üyesi, AUretim_uretim işlevinin adresini alır.
        temel->urunId = 0;  //temel işaretçisinin urunId üyesine 0 değeri atanır.
        strncpy(temel->urun_Adi, "A", sizeof(temel->urun_Adi) - 1);  //temel işaretçisinin urun_Adi üyesi, "A" karakterini urun_Adi dizisine kopyalar. Dizi boyutu, urun_Adi dizisinin boyutunu aşmaması için kontrol edilir.
      //temel işaretçisinin urun_Adi dizisinin son elemanına null karakteri atanır.
        temel->urun_Adi[sizeof(temel->urun_Adi) - 1] = '\0';
    } //urun işaretçisi döndürülerek oluşturulan AUretim yapısının adresi kullanıcıya verilir.
    return urun;
}



