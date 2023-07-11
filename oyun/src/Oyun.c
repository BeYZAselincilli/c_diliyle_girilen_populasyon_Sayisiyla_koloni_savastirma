#include "Oyun.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Oyun new_Oyun(int koloni_sayisi) {
    // Bellekte Oyun yapısı için yer ayırma
    Oyun this;
    this=(Oyun)malloc(sizeof(struct OYUN  ));  //Oyun yapısı için ayrılan bellek bloğunu gösterir
    this->koloni_sayisi = koloni_sayisi; //this->koloni_sayisi değişkeni, parametre olarak alınan koloni_sayisi değeriyle atanır.
    this->elenen_koloni_sayisi=0;
    this->sabitKoloniSayisi = 0;
     this->oyun_tur_sayisi = 0;
    // Diğer değişkenler (elenen_koloni_sayisi, sabitKoloniSayisi, oyun_tur_sayisi) ilgili başlangıç değerleriyle atanır.
    this->Oyun_Savas=&Oyun_Savas;  //İşlev göstericileri (Oyun_Savas, kolonileriCreate, ciktiVer, koloni_kontrol) ilgili işlevlere atanır.
    this->kolonileriCreate=&kolonileriCreate;
    this->ciktiVer=&ciktiVer;
    this->koloni_kontrol=&koloni_kontrol;
    return this;  //Oluşturulan Oyun yapısı olan this döndürülür.
}




void ciktiVer(struct OYUN* oyun, int tursayisi) {    //oyun_tur_sayisi değişkeni, tursayisi değeriyle güncellenir.
    oyun->oyun_tur_sayisi=tursayisi;  //Ekrana başlık bilgileri yazdırılır.
    printf("____________________________________________________________________________________\n");
    printf("Tur Sayisi: %d\n", oyun->oyun_tur_sayisi);
    printf("%-7s  %-18s  %-18s  %-10s  %-10s\n", "Koloni", "Popilasyon", "Yemek Stogu", "Kazanma", "Kaybetme\n");
 
    for (int i = 0; i < oyun->sabitKoloniSayisi; i++) {
        Koloni koloni = oyun->koloniler[i];
        printf("%-7c  ", koloni->koloniSembolu);  //Koloninin sembolü ekrana yazdırılır.

        if (koloni->populasyon <= 0 || koloni->yemekStogu <= 0) {
            printf("%-18s  %-18s  %-10s  %-10s\n",    //Koloninin popülasyonu ve yemek stoğu değerleri kontrol edilir. Eğer herhangi biri 0 veya daha küçükse, "-" veya "--" gibi belirteçler ekrana yazdırılır.
                "--", "---", "--", "--");
        } else {
            printf("%-18d  %-18d  %-10d  %-10d\n",  koloni->populasyon,koloni->yemekStogu,koloni->kazanma,koloni->kaybetme);
        } //Değerler mevcutsa, popülasyon, yemek stoğu, kazanma ve kaybetme sayıları ekrana yazdırılır.
    }

    printf("____________________________________________________________________________________\n");
}//Alt çizgilerle ayrılan bir çizgi ekrana yazdırılır.



 void kolonileriCreate (int* kolonidegerleri,int koloniSayisi,struct OYUN* oyun)  //kolonileriCreate adlı bir fonksiyon tanımlar
 {
    
    oyun->koloniler=(Koloni*) malloc (koloniSayisi*sizeof(Koloni));  //koloniler adlı dinamik bellek bloğuna, koloniSayisi kadar Koloni yapısının bellek ayırımı yapılır.

    for (int i = 0; i < koloniSayisi; i++) {
           oyun->koloniler[i]  = new_Koloni(kolonidegerleri[i]);
         oyun-> koloniler[i]->koloniSembolu =oyun-> koloniler[i]->sembolUret();  //oloni sembolü sembolUret fonksiyonuyla belirlenir ve oyun->koloniler[i]->koloniSembolu değişkenine atanır.

            int rastgele_sayi = rand() % 2;   //Rastgele bir sayı oluşturulur ve rastgele_sayi değişkenine atanır.
            if (rastgele_sayi == 0) {
               oyun->  koloniler[i]->koloni_taktigi = (Taktik*)new_ATaktik();  //Eğer rastgele_sayi değeri 0 ise, oyun->koloniler[i]->koloni_taktigi işaretçisi yeni bir ATaktik yapısını gösterir.
            } else if (rastgele_sayi == 1) {  //Bir başka rastgele sayı oluşturulur ve rastgele_sayi_uretim değişkenine atanır.
              oyun->   koloniler[i]->koloni_taktigi = (Taktik*)new_BTaktik();
            }

            int rastgele_sayi_uretim = rand() % 2;
            if (rastgele_sayi_uretim == 0) {
               oyun->  koloniler[i]->uretim_sekli = (Uretim*)new_AUretim();  //Eğer rastgele_sayi_uretim değeri 0 ise, oyun->koloniler[i]->uretim_sekli işaretçisi yeni bir AUretim yapısını gösterir.
            } else if (rastgele_sayi_uretim == 1) {
              oyun->   koloniler[i]->uretim_sekli = (Uretim*)new_BUretim();  //Eğer rastgele_sayi_uretim değeri 1 ise, oyun->koloniler[i]->uretim_sekli işaretçisi yeni bir BUretim yapısını gösterir.
            }

       
        }
}

void Oyun_Savas(Koloni koloni1,int indexOfKoloni1, Koloni koloni2,int indexOfKoloni2,struct OYUN* oyun) {   //Oyun_Savas adlı bir fonksiyon tanımlar.
    int guc1 = koloni1->koloni_taktigi->savas();   //İlk koloni için güç değeri (guc1) koloni1->koloni_taktigi->savas() çağrısı ile elde edilir.
    int guc2 = koloni2->koloni_taktigi->savas();   //İkinci koloni için güç değeri (guc2) koloni2->koloni_taktigi->savas() çağrısı ile elde edilir.

    
    int uretim1_ekle=oyun->koloniler[indexOfKoloni1]->uretim_sekli->uretim();
    int uretim2_ekle=oyun->koloniler[indexOfKoloni2]->uretim_sekli->uretim();
//Her bir koloninin üretim değeri (uretim1_ekle ve uretim2_ekle) oyun->koloniler[indexOfKoloni1]->uretim_sekli->uretim() çağrısı ile elde edilir.
    if (guc1 > guc2) {   //Eğer guc1 guc2'den büyük ise:
  
        int fark = guc1 - guc2;  ///Güç farkı fark hesaplanır.

        int transfer = (fark * koloni2->yemekStogu) / 1000;  //Koloni 1, koloni 2'nin yemek stoğunun belirli bir yüzdesini (transfer) alır.
        int azalan_populasyon=(fark* koloni2->populasyon) / 1000;


             if(oyun->koloniler[indexOfKoloni2]->populasyon==1){
            oyun->koloniler[indexOfKoloni2]->populasyon=0;    
        }

        oyun->koloniler[indexOfKoloni2]->populasyon=oyun->koloniler[indexOfKoloni2]->populasyon-azalan_populasyon;
        oyun->koloniler[indexOfKoloni1]->yemekStogu=oyun->koloniler[indexOfKoloni1]->yemekStogu+transfer;
        oyun->koloniler[indexOfKoloni2]->yemekStogu=oyun->koloniler[indexOfKoloni2]->yemekStogu-transfer;
//Koloni 1'in yemek stoğu artar, koloni 2'nin yemek stoğu azalır.
   

        oyun->koloniler[indexOfKoloni1]->kazanma++;
        oyun->koloniler[indexOfKoloni2]->kaybetme++;
        //Koloni 1 kazanır, koloni 2 kaybeder.
    } 
    else if (guc2 > guc1) { //Eğer guc2 guc1'den büyük ise:

        int fark = guc2 - guc1;//Güç farkı fark hesaplanır.
        int transfer = (fark * koloni1->yemekStogu) / 1000;    //Koloni 2, koloni 1'in yemek stoğunun belirli bir yüzdesini (transfer) alır.
        int azalan_populasyon=(fark*koloni1->populasyon)/1000;


     if(oyun->koloniler[indexOfKoloni1]->populasyon==1){
            oyun->koloniler[indexOfKoloni1]->populasyon=0;

        }

        oyun->koloniler[indexOfKoloni1]->populasyon=oyun->koloniler[indexOfKoloni1]->populasyon-azalan_populasyon;
        oyun->koloniler[indexOfKoloni2]->yemekStogu=oyun->koloniler[indexOfKoloni2]->yemekStogu+transfer;
        oyun->koloniler[indexOfKoloni1]->yemekStogu=oyun->koloniler[indexOfKoloni1]->yemekStogu-transfer;

        //Koloni 2'nin yemek stoğu artar, koloni 1'in yemek stoğu azalır.


        oyun->koloniler[indexOfKoloni2]->kazanma++;  //Koloni 2 kazanır, koloni 1 kaybeder.
        oyun->koloniler[indexOfKoloni1]->kaybetme++;
    }
     else {  //Eğer guc1 ve guc2 eşit ise:

            if(oyun->koloniler[indexOfKoloni1]->populasyon>oyun->koloniler[indexOfKoloni2]->populasyon)  //Eğer koloni 1'in popülasyonu koloni 2'nin popülasyonundan büyük ise:
           {
                //Popülasyonlar karşılaştırılır.
             if(oyun->koloniler[indexOfKoloni2]->populasyon==1){   
            oyun->koloniler[indexOfKoloni2]->populasyon=0;
       
        }

        oyun->koloniler[indexOfKoloni1]->kazanma++;  //Koloni 1 kazanır, koloni 2 kaybeder.
        oyun->koloniler[indexOfKoloni2]->kaybetme++;

           }
        else if (oyun->koloniler[indexOfKoloni2]->populasyon>oyun->koloniler[indexOfKoloni1]->populasyon) {  //Eğer koloni 2'nin popülasyonu koloni 1'in popülasyonundan büyük ise:
             if(oyun->koloniler[indexOfKoloni1]->populasyon==1){
            oyun->koloniler[indexOfKoloni1]->populasyon=0;

        }

        oyun->koloniler[indexOfKoloni2]->kazanma++;
        oyun->koloniler[indexOfKoloni1]->kaybetme++;  //Koloni 2 kazanır, koloni 1 kaybeder.
        }
         else {  ////Eğer popülasyonlar eşit ise:
         
            int beraberlik_sayi = rand() % 2;  //Rastgele bir sayı oluşturulur.
            if (beraberlik_sayi == 0) {
                    //Eğer sayı 0 ise, koloni 1 kazanır, koloni 2 kaybeder
        oyun->koloniler[indexOfKoloni1]->kazanma++;
        oyun->koloniler[indexOfKoloni2]->kaybetme++;
     
            } else {  //Eğer sayı 1 ise, koloni 2 kazanır, koloni 1 kaybeder.
        oyun->koloniler[indexOfKoloni2]->kazanma++;
        oyun->koloniler[indexOfKoloni1]->kaybetme++;
            }
        }
    }
  if(oyun->oyun_tur_sayisi>0){
    //oyun->oyun_tur_sayisi (oyun turu sayısı) sıfırdan büyük ise

    int her_tur_artacak_populasyon1=(oyun->koloniler[indexOfKoloni1]->populasyon*20)/100;
    int her_tur_artacak_populasyon2=(oyun->koloniler[indexOfKoloni2]->populasyon*20)/100;
    int her_tur_azalacak_yemek_stogu1=(oyun->koloniler[indexOfKoloni1]->populasyon*2);
    int her_tur_azalacak_yemek_stogu2=(oyun->koloniler[indexOfKoloni2]->populasyon*2);
    //(her_tur_artacak_populasyon1 ve her_tur_artacak_populasyon2) ve azalacak yemek stoğu (her_tur_azalacak_yemek_stogu1 ve her_tur_azalacak_yemek_stogu2) hesaplanır.
 
    oyun->koloniler[indexOfKoloni1]->populasyon=oyun->koloniler[indexOfKoloni1]->populasyon+her_tur_artacak_populasyon1;
    oyun->koloniler[indexOfKoloni2]->populasyon=oyun->koloniler[indexOfKoloni2]->populasyon+her_tur_artacak_populasyon2;
    oyun->koloniler[indexOfKoloni1]->yemekStogu=oyun->koloniler[indexOfKoloni1]->yemekStogu-her_tur_azalacak_yemek_stogu1;
    oyun->koloniler[indexOfKoloni2]->yemekStogu=oyun->koloniler[indexOfKoloni2]->yemekStogu-her_tur_azalacak_yemek_stogu2;

        //Koloni 1 ve koloni 2'nin popülasyonu artar, yemek stoğu azalır.
    oyun->koloniler[indexOfKoloni1]->yemekStogu=oyun->koloniler[indexOfKoloni1]->yemekStogu+uretim1_ekle;
    oyun->koloniler[indexOfKoloni2]->yemekStogu=oyun->koloniler[indexOfKoloni2]->yemekStogu+uretim2_ekle;
  } //Koloni 1 ve koloni 2'nin yemek stoğuna üretim değeri eklenir.

}


void koloni_kontrol(struct OYUN* oyun,int turSayisi) {
    int silinenKoloniler = 0; 
        //Oyunun kolonilerini kontrol eder ve silinmesi gereken kolonileri belirler.
    for (int i = 0; i < oyun->sabitKoloniSayisi; i++) {  //Her bir koloni için popülasyonunun veya yemek stoğunun sıfır veya daha küçük olduğunu kontrol eder.
        if (oyun->koloniler[i]->koloniikontrol == 1) {  //Eğer bir koloninin popülasyonu veya yemek stoğu sıfır veya daha küçük ise, 
            if (oyun->koloniler[i]->populasyon <= 0 || oyun->koloniler[i]->yemekStogu <= 0) {
              oyun->koloniler[i]->koloniikontrol = 0;  //koloniikontrol değeri sıfıra (0) atanır ve silinenKoloniler sayacı artırılır.
                silinenKoloniler++; //
            }
        }
    }
    
    oyun->koloni_sayisi =oyun->koloni_sayisi - silinenKoloniler;
    //silinenKoloniler değeri, oyunun toplam koloni sayısından çıkarılarak aktif koloni sayısı güncellenir.
   }
   
    void free_oyun(Oyun oyun_sil){ //Aldığı oyun_sil parametresi üzerinde bellek yönetimi yapar.
        if(oyun_sil==NULL) return;

        free(oyun_sil->koloniler);
        free(oyun_sil); //koloniler dizisini ve oyun_sil yapısını bellekten serbest bırakır.

    }

