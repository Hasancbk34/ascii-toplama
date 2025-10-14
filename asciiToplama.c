#include <stdio.h>    
#include <stdlib.h>   
#include <windows.h> // Sleep fonksiyonu i�in bu k�t�phaneyi ekliyoruz (Windows'a �zel).

int main() {
    
    // --- Ba�lang��: De�i�kenler ---
    
    // Girilen ham karakterleri tutacak de�i�kenler. Klavyeden gelen her �ey karakterdir (char).
    char ascii1, ascii2;
    
    // Toplama i�lemi i�in kullanaca��m tamsay�lar ve sonu� de�i�keni.
    int num1, num2, toplam; 

    // --- 1. Girdi Alma ve Buffer Sorunu ---
    
    printf("ilk rakami (0-9) girin: ");
    ascii1 = getchar(); // �lk karakteri al ve ascii1'e kaydet.

    // Girdi tamponunu temizlemek gerekiyor. Enter tu�u (\n) bir sonraki girdiye kar��mas�n diye.
    getchar(); 

    printf("ikinci rakami (0-9) girin: ");
    ascii2 = getchar(); // �kinci karakteri al ve ascii2'ye kaydet.

    // Yine Enter'� yutmak i�in.
    getchar(); 
    
    // --- D�n���m: Karakterden Say�ya Ge�i� ---
    
    // ASCII hilesi: Karakterin ASCII de�erinden '0' karakterinin ASCII de�erini ��kararak 
    // ger�ek tamsay� kar��l���n� elde ediyorum. Sonucu 'num1' ve 'num2' de�i�kenlerine at�yorum.
    // �rnek: ascii1 = '4' (ASCII 52) -> num1 = 52 - 48 = 4.
    num1 = ascii1 - '0';
    num2 = ascii2 - '0';

    // --- Kontrol: Rakam m� De�il mi? ---
    
    // En �nemli kontrol: num1 ve num2 ger�ekten 0 ile 9 aras�nda m�? (Yani ge�erli bir rakam m�?)
    // Mant�ksal VE (&&) kullan�yorum, her iki ko�ul da do�ruysa devam edebiliriz.
    if( (num1 >= 0 && num1 <= 9) && (num2 >= 0 && num2 <= 9) )
    {
        
        // --- Her �ey Yolunda ---
        
        toplam = num1 + num2;
        
        printf("\nToplam %d olarak bulundu.\n", toplam);
        
        // Sonucu hemen kaybolmas�n diye 3 saniye (3000ms) bekletiyorum.
        Sleep(3000); 
        
        return 0; // Ba�ar�l� biti�.
        
    } 
    else 
    {
        // --- Hata Durumu: Ge�ersiz Girdi ---
        
        printf("\n=> HATALI INPUT GIRISI \n");
        
        Sleep(3000); // Hata mesaj�n� g�rmeleri i�in bekleme.
        return 0; // Programdan ��k��.
    }
}
