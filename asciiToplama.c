#include <stdio.h>    // printf ve getchar gibi temel giri�/��k�� fonksiyonlar� i�in
#include <stdlib.h>   // Genel ama�l� i�levler i�in (bu kodda �art de�il)
#include <windows.h>  // Windows'ta program� bekletmek i�in kullan�lan Sleep fonksiyonu i�in

int main() {
    /* Kullan�c�n�n girdi�i '0' ile '9' aras�ndaki rakam karakterlerini tutar. */
    char ascii1, ascii2;
    
    /* getchar() fonksiyonunun d�n�� de�erini (veya tampon kontrol�n�) tutmak i�in int kullan�r�z. 
       ��nk� getchar() �zel bir de�er olan EOF'u (dosya sonu) da d�nd�rebilir. */
    int ch;
    
    
    // B�R�NC� RAKAM G�R���
    // ===================================

    /* Kullan�c�ya ne yapmas� gerekti�ini s�yle */
    printf("ilk rakami (0-9) girin: ");
    
    /* Konsoldan tek bir karakteri oku ve ascii1'e kaydet. */
    ascii1 = (char)getchar();
    
    /* Kullan�c� rakam� girip Enter'a bast���nda olu�an '\n' (sat�r sonu) karakterini oku. */
    ch = getchar();
    
    /* E�er okunan ikinci karakter '\n' de�ilse, kullan�c� tek rakamdan fazlas�n� girmi�tir. */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata oldu�unu belirten ��k�� kodu
    }


    // �K�NC� RAKAM G�R���
    // ===================================

    /* Kullan�c�dan ikinci rakam� iste */
    printf("ikinci rakami (0-9) girin: ");
    
    /* �kinci karakteri oku */
    ascii2 = (char)getchar();
    
    /* �kinci giri�ten kalan '\n' karakterini oku */
    ch = getchar();
    
    /* �kinci giri�te de birden fazla karakter varsa hata ver */
    if (ch != '\n') {
        printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi tek rakam girin.\n");
        getchar();getchar();
        return 1;    // Hata ��k�� kodu
    }


    // KONTROL VE TOPLAMA
    // ===================================

    /* Karakteri say�sal de�erine �evir. 
       �rne�in, '7' karakteri (ASCII 55), '0' karakteri (ASCII 48) ��kar�larak 7 olur. */
    int num1 = ascii1 - '0';
    int num2 = ascii2 - '0';

    /* �evrilen say�lar�n 0 ile 9 aral���nda olup olmad���n� kontrol et. */
    if (num1 >= 0 && num1 <= 9 && num2 >= 0 && num2 <= 9) {
             
        
        /* E�er her �ey do�ruysa, say�sal toplam� hesapla. */
        int toplam = num1 + num2;
        
        /* Sonucu yazd�r */
        printf("Birinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii1, num1);
        printf("Ikinci girdinin ascii degeri %d => %d rakamina cevirildi.\n" , ascii2, num2);
        printf("\nToplam (sayisal deger): %d\n ", toplam);
        getchar();
        return 0;    // Program hatas�z bitti
    }
    
    // YANLI� KARAKTER G�R�� HATASI
    // ===================================

    /* E�er yukar�daki kontrol ba�ar�s�z olursa (�rn: kullan�c� 'a' veya '@' girerse) */
    printf("\n=> HATALI INPUT GIRISI! Lutfen sadece 0-9 arasi rakam girin.\n ");
    getchar();
    return 1;    // Hata ile sonlan
}
