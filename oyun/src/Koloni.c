#include "koloni.h"
#include <stdio.h>


Koloni new_Koloni(int populasyon) {  // Koloni yapısı için yeni bir nesne oluşturan new_Koloni fonksiyonunu tanımlamaktadır.
    Koloni this = (Koloni)malloc(sizeof(struct Koloni));  //Bellekte Koloni yapısı için yer ayrılır (malloc ile).
    this->populasyon = populasyon;  //populasyon parametresiyle aldığı değer, oluşturulan koloninin populasyon özelliğine atanır.
    this->yemekStogu=populasyon*populasyon;  //Koloninin yemekStogu özelliği, populasyon değerinin karesi ile hesaplanır.
    this->sembolUret=&sembolUret;  //sembolUret işlevi, koloninin sembolUret işlev göstericisine atanır.
    this->kaybetme=0;
    this->kazanma=0;
    //kaybetme ve kazanma sayacı sıfırlanır.
    this->koloniikontrol=1;  //koloniikontrol değeri 1 olarak atanır, bu da koloninin aktif olduğunu gösterir.
    return this;
}  //Oluşturulan koloni nesnesi (this) döndürülür.


char sembolUret() {
    static char kullanilanSemboller[94] = {0}; //kullanilanSemboller adlı bir 94 elemanlı karakter dizisi tanımlanır. Bu dizide, daha önce kullanılan sembollerin takibini yapmak için her bir sembol için bir bayrak tutulur.
    int kucuk_sayi = 33;
    int buyuk_sayi = 126;
    //kucuk_sayi ve buyuk_sayi değişkenleri, sembollerin ASCII değer aralığını belirtir. Bu durumda, 33 ile 126 arasında (dahil) olan semboller kullanılabilir.
    int sayi_rast;
    //Bir döngü içinde, rastgele bir sayı üretilir ve bu sayı kullanılan semboller dizisinde bir bayrağın durumuna bakmak için kullanılır.
    char smbl;

    do { //Eğer seçilen sembol daha önce kullanılmışsa, yani ilgili bayrak 1 ise, döngü devam eder ve farklı bir sembol seçmek için adımlar tekrarlanır.
        sayi_rast = rand() % (buyuk_sayi - kucuk_sayi + 1) + kucuk_sayi;
        smbl = (char)sayi_rast;
    } while (kullanilanSemboller[sayi_rast - kucuk_sayi] == 1);
        //Eğer seçilen sembol daha önce kullanılmamışsa, yani ilgili bayrak 0 ise, sembol kullanılmış olarak işaretlenir (kullanilanSemboller dizisindeki ilgili bayrak 1 yapılır).
    kullanilanSemboller[sayi_rast - kucuk_sayi] = 1;
    //Seçilen sembol, karakter olarak dönüştürülerek geri döndürülür.
    return smbl;
}


  void free_koloni(Koloni koloni_sil){  //Fonksiyon koloni_sil parametresini alır ve bu parametrenin değerini kontrol eder.
        if(koloni_sil==NULL) return;   //Eğer koloni_sil parametresi NULL ise, yaptığı işlem olmadan fonksiyondan çıkar ve bellek serbest bırakma işlemi yapılmaz.
        free(koloni_sil);  //free fonksiyonu kullanılarak koloni_sil bellek bölgesi serbest bırakılır. 

    }
