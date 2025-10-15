#include <stdio.h>    // printf ve getchar gibi temel giriþ/çýkýþ fonksiyonlarý için
#include <stdlib.h>   // Genel amaçlý iþlevler için (bu kodda þart deðil)
#include <windows.h>  // Windows'ta programý bekletmek için kullanýlan Sleep fonksiyonu için

int main() {
    /* Kullanýcýnýn girdiði '0' ile '9' arasýndaki rakam karakterlerini tutar. */
    char ascii1, ascii2;
    
    /* getchar() fonksiyonunun dönüþ deðerini (veya tampon kontrolünü) tutmak için int kullanýrýz. 
       Çünkü getchar() özel bir deðer olan EOF'u (dosya sonu) da döndürebilir. */
    int ch;
    
    
    // BÝRÝNCÝ RAKAM GÝRÝÞÝ
    // ===================================

    /* Kullanýcýya ne yapmasý gerektiðini söyle */
    printf("ilk rakami (0-9) girin: ");
    
    /* Konsoldan tek bir karakteri oku ve ascii1'e kaydet. */
    ascii1 = (char)getchar();
    
    /* Kullanýcý rakamý girip Enter'a bastýðýnda oluþan '\n' (satýr sonu) karakterini oku. */
    ch = getchar();
    
    /* Eðer okunan ikinci karakter '\n' deðilse, kullanýcý tek rakamdan fazlasýný girmiþtir. */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata olduðunu belirten çýkýþ kodu
    }


    // ÝKÝNCÝ RAKAM GÝRÝÞÝ
    // ===================================

    /* Kullanýcýdan ikinci rakamý iste */
    printf("ikinci rakami (0-9) girin: ");
    
    /* Ýkinci karakteri oku */
    ascii2 = (char)getchar();
    
    /* Ýkinci giriþten kalan '\n' karakterini oku */
    ch = getchar();
    
    /* Ýkinci giriþte de birden fazla karakter varsa hata ver */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata çýkýþ kodu
    }


    // KONTROL VE TOPLAMA
    // ===================================

    /* Karakteri sayýsal deðerine çevir. 
       Örneðin, '7' karakteri (ASCII 55), '0' karakteri (ASCII 48) çýkarýlarak 7 olur. */
    int num1 = ascii1 - '0';
    int num2 = ascii2 - '0';

    /* Çevrilen sayýlarýn 0 ile 9 aralýðýnda olup olmadýðýný kontrol et. */
    if (num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9) {
             
        
        /* Eðer her þey doðruysa, sayýsal toplamý hesapla. */
        int toplam = num1 + num2;
        
        /* Sonucu yazdýr */
        printf("Birinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii1, num1);
        printf("Ikinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii2, num2);
        printf("\nToplam (sayisal deger): %d\n ", toplam);
        getchar();
        return 0;    // Program hatasýz bitti
    }
    
    // YANLIÞ KARAKTER GÝRÝÞ HATASI
    // ===================================

    /* Eðer yukarýdaki kontrol baþarýsýz olursa (Örn: kullanýcý 'a' veya '@' girerse) */
    printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi rakam girin.\n ");
    getchar();
    return 1;    // Hata ile sonlan
}
