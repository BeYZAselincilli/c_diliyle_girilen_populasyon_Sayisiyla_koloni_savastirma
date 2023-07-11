#include "ATaktik.h"
#include <stdio.h>
#include <string.h> 
   int ATaktik_savas() {
    int puan = rand() % 1001;
    return puan;
}

ATaktik* new_ATaktik() {
    ATaktik* taktik = malloc(sizeof(ATaktik));  //ATaktik türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi taktik işaretçisine atanır.
    if (taktik != NULL) {  //taktik işaretçisinin değeri kontrol edilir. Eğer taktik NULL değilse, bellek başarıyla ayrılmış demektir.
        Taktik* temel = &(taktik->temel);  //temel işaretçisi, taktik yapısının temel üyesine yönlendirilir.
        temel->savas = &ATaktik_savas;  //temel işaretçisinin savas üyesi, ATaktik_savas işlevinin adresini alır.
        temel->taktikId = 0;  //temel işaretçisinin taktikId üyesine 0 değeri atanır.
        strncpy(temel->taktik_Adi, "A", sizeof(temel->taktik_Adi) - 1);
        //temel işaretçisinin taktik_Adi üyesi, "A" karakterini taktik_Adi dizisine kopyalar. Dizi boyutu, taktik_Adi dizisinin boyutunu aşmaması için kontrol edilir.
        temel->taktik_Adi[sizeof(temel->taktik_Adi) - 1] = '\0';
    }   //temel işaretçisinin taktik_Adi dizisinin son elemanına null karakteri atanır.
    return taktik;
}//taktik işaretçisi döndürülerek oluşturulan ATaktik yapısının adresi kullanıcıya verilir.