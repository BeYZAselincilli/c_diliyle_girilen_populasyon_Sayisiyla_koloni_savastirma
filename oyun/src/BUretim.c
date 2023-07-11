#include "BUretim.h"
#include <stdio.h>
#include <string.h> 
int BUretim_uretim(){
    int uretilenDeger = rand() % 10 + 1; // 1-10 arası değer üretimi
    return uretilenDeger;  //uretilen karakterin geri döndürülmnesi
}

BUretim* new_BUretim() {
    BUretim* urun = malloc(sizeof(BUretim));   //BUretim türünde bir bellek bölgesi için yer ayrılır ve bu bellek bölgesinin adresi urun işaretçisine atanır.
    if (urun != NULL) {  //urun işaretçisinin değeri kontrol edilir. Eğer urun NULL değilse, bellek başarıyla ayrılmış demektir.
        Uretim* temel = &(urun->temel_uretim);  //temel işaretçisi, urun yapısının temel_uretim üyesine yönlendirilir.
        temel->uretim = &BUretim_uretim;  //temel işaretçisinin uretim üyesi, BUretim_uretim işlevinin adresini alır.
        temel->urunId = 1;  //temel işaretçisinin urunId üyesine 1 değeri atanır.
        strncpy(temel->urun_Adi, "B", sizeof(temel->urun_Adi) - 1);  //temel işaretçisinin urun_Adi üyesi, "B" karakterini urun_Adi dizisine kopyalar. Dizi boyutu, urun_Adi dizisinin boyutunu aşmaması için kontrol edilir.
        temel->urun_Adi[sizeof(temel->urun_Adi) - 1] = '\0';  //temel işaretçisinin urun_Adi dizisinin son elemanına null karakteri atanır.
    }
    return urun;
} //urun işaretçisi döndürülerek oluşturulan BUretim yapısının adresi kullanıcıya verilir.
