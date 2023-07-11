/**
*
* @author İsim:Beyza Selin Çilli 

* @since 21.05.2023
*
* </p>
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Oyun.h"
#include <ctype.h>

int * getNumbers(int * size) {
  int capacity = 100; //kapasite 100 olarak belirlenir
  int * numbers = malloc(capacity * sizeof(int)); //kapasite türünde numbers değeri oluşturulur.

  if (numbers == NULL) { //eğer numbers boş değilse
    printf("Bellek atamasi olusmadi.");
    return NULL; //null döndür
  }

  int count = 0;  //count değerli int atanır
  int number; //number adında int deget tanımlanır


  printf("Koloniler icin populasyon girisi yapin: ");

  char ch; //ch isimli char değişkeni atanır
  while ((ch = getchar()) != '\n') {  //sayıları numbers dizisine kaydetmeyi sağlar
    if (isdigit(ch)) {  //Döngü her karakteri kontrol eder ve eğer karakter bir sayı ise isdigit(ch) kontrolüyle kontrol edilir. 
      ungetc(ch, stdin); 
      scanf("%d", & number);  //ayı ise ungetc(ch, stdin) kullanılarak karakter geri itilir ve scanf fonksiyonuyla bu sayı number değişkenine okunur. 
      numbers[count] = number;  //numbers dizisinin count indisine bu sayı atanır ve count değeri bir arttırılı
      count++;  

      if (count >= capacity) {  //count değeri, capacity değerine eşit veya daha büyük olduğunda bir kontrol yapılır. 
        capacity *= 2;  //capacity değeri iki katına çıkarılır.
        int * temp = realloc(numbers, capacity * sizeof(int));   //realloc fonksiyonu kullanılarak numbers dizisinin boyutu capacity * sizeof(int) olarak yeniden boyutlandırılır
        if (temp == NULL) {       //Eğer bellek tahsisi başarısız olursa (temp == NULL kontrolüyle kontrol edilir), bir hata mesajı yazdırılır, 
          printf("Bellek atamasi olusmadi.");
          free(numbers);    // (free(numbers)) ve NULL değeri döndürülerek fonksiyondan çıkılır.
          return NULL;
        }
        numbers = temp;   //Eğer bellek tahsisi başarılıysa, numbers dizisi artık yeni boyutuna sahip olur ve işlem devam eder. 
      }
    }
  
    
  }

  * size = count;
//size işaretçisinin gösterdiği bellek adresine count değeri atanır. size işaretçisi, getNumbers fonksiyonundan döndürülecek olan numbers dizisinin boyutunu temsil eder. 
  return numbers;
}

int main() {
  srand(time(NULL));
//astgele sayı üretmek için srand fonksiyonu çağrılır ve zamanın NULL olarak ayarlanması kullanılır.
  int size;
  int * numbers = getNumbers( & size);
//getNumbers(&size) fonksiyonu çağrılarak kullanıcıdan koloniler için populasyon girişi yapması istenir ve numbers işaretçisi ile bu değerler döndürülür.
  if (numbers != NULL) {
    //numbers dizisinin NULL olmadığı kontrol edilir. 
    Koloni * koloniler = (Koloni * ) malloc(size * sizeof(Koloni));
    Uretim* uretimler = (Uretim * ) malloc(size * sizeof(Uretim));
//Koloni ve Uretim struct'ları için yer ayrılır. 

    if (koloniler == NULL) {
      printf("Bellek tahsisi başarisiz oldu.");
      free(numbers);
      return 0;  //Eğer bellek tahsisi başarısız olursa, hata mesajı verilir, numbers dizisi serbest bırakılır ve program sonlandırılır.
    }

    Oyun oyunlar = new_Oyun(size);
//new_Oyun(size) fonksiyonu çağrılarak Oyun türünde bir oyun nesnesi oluşturulur ve bu nesne oyunlar işaretçisi ile işaretlenir.
    if (oyunlar == NULL) {   //oyunlar nesnesinin NULL olup olmadığı kontrol edilir. 
      printf("Bellek tahsisi başarisiz oldu.");
      free(koloniler);
      free(numbers);
      //koloniler ve numbers dizileri serbest bırakılır ve program sonlandırılır.
      return 0;
    }

    oyunlar -> koloni_sayisi = size;
//oyunlar nesnesi NULL değilse, oyunlar->koloni_sayisi değişkenine size değeri atanır. 
    oyunlar -> kolonileriCreate(numbers, size, oyunlar);   //, oyunlar->kolonileriCreate(numbers, size, oyunlar) fonksiyonu çağrılarak oyunlar nesnesi üzerindeki kolonileriCreate işlevi çalıştırılır
    oyunlar->sabitKoloniSayisi=oyunlar->koloni_sayisi;

    //int tur = 0;

    while (oyunlar -> koloni_sayisi != 1) {    //sadece bir koloni kaldığında döngünün sona ermesini sağlar.
    
      oyunlar->ciktiVer(oyunlar,oyunlar->oyun_tur_sayisi);
      //Her turda oyunlar->ciktiVer(oyunlar, oyunlar->oyun_tur_sayisi) çağrılır ve oyunun o anki durumunu ekrana yazdırır.
      oyunlar->koloni_kontrol(oyunlar,oyunlar->oyun_tur_sayisi);
//oyunlar->koloni_kontrol(oyunlar, oyunlar->oyun_tur_sayisi) fonksiyonu çağrılır ve her koloninin durumunu kontrol eder. 
      for (int i = 0; i < oyunlar ->sabitKoloniSayisi; i++) {
// tüm koloniler arasında savaşlar gerçekleştirilir. 
        for (int j = i + 1; j < oyunlar->sabitKoloniSayisi; j++) {
        
         
         
          if (i != j) {
       if (oyunlar->koloniler[i]->koloniikontrol==0 ||oyunlar->koloniler[j]->koloniikontrol==0 ) {
            continue; 
          }
          else{
       
            oyunlar->Oyun_Savas(oyunlar->koloniler[i], i, oyunlar->koloniler[j], j, oyunlar);
          }//oyunlar->Oyun_Savas() fonksiyonu çağrılarak savaş gerçekleştirilir.
           
          }
        }
      }


      oyunlar->oyun_tur_sayisi++;
      
    }
  printf("\n\t\t\t\t...OYUN SONUCU:..\n");
    oyunlar->ciktiVer(oyunlar,oyunlar->oyun_tur_sayisi-1);
//oyunlar->ciktiVer(oyunlar, oyunlar->oyun_tur_sayisi-1) çağrılarak son turun durumu ekrana yazdırılır.
     free_oyun(oyunlar);
  free_koloni(*koloniler);   //Bellek serbest bırakma işlemleri yapılır:
  free(numbers);
  }

 

  return 0;
}
