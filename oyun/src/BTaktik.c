#include "BTaktik.h"
#include <stdio.h>
#include <string.h> 
int BTaktik_savas() {
    int puan = rand() % 1001;  //0-1000 arası rastgele değer seçilir ve puan olarak döndürlür
    return puan;
}

BTaktik* new_BTaktik() {
    BTaktik* taktik = malloc(sizeof(BTaktik));  //BTaktik türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi taktik işaretçisine atanır.
    if (taktik != NULL) {  //taktik işaretçisinin değeri kontrol edilir. Eğer taktik NULL değilse, bellek başarıyla ayrılmış demektir.
        Taktik* temel = &(taktik->temel);  //temel işaretçisi, taktik yapısının temel üyesine yönlendirilir.
        temel->savas = &BTaktik_savas;   //temel işaretçisinin savas üyesi, BTaktik_savas işlevinin adresini alır.
        temel->taktikId = 1;  //temel işaretçisinin taktikId üyesine 1 değeri atanır.
        strncpy(temel->taktik_Adi, "B", sizeof(temel->taktik_Adi) - 1);  //temel işaretçisinin taktik_Adi üyesi, "B" karakterini taktik_Adi dizisine kopyalar. Dizi boyutu, taktik_Adi dizisinin boyutunu aşmaması için kontrol edilir.
        temel->taktik_Adi[sizeof(temel->taktik_Adi) - 1] = '\0';  //temel işaretçisinin taktik_Adi dizisinin son elemanına null karakteri atanır.
    }
    return taktik;  //taktik işaretçisi döndürülerek oluşturulan BTaktik yapısının adresi kullanıcıya verilir.
}
