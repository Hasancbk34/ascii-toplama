#include <stdio.h>    
#include <stdlib.h>   
#include <windows.h> // Sleep fonksiyonu için bu kütüphaneyi ekliyoruz (Windows'a özel).

int main() {
    
    // --- Baþlangýç: Deðiþkenler ---
    
    // Girilen ham karakterleri tutacak deðiþkenler. Klavyeden gelen her þey karakterdir (char).
    char ascii1, ascii2;
    
    // Toplama iþlemi için kullanacaðým tamsayýlar ve sonuç deðiþkeni.
    int num1, num2, toplam; 

    // --- 1. Girdi Alma ve Buffer Sorunu ---
    
    printf("ilk rakami (0-9) girin: ");
    ascii1 = getchar(); // Ýlk karakteri al ve ascii1'e kaydet.

    // Girdi tamponunu temizlemek gerekiyor. Enter tuþu (\n) bir sonraki girdiye karýþmasýn diye.
    getchar(); 

    printf("ikinci rakami (0-9) girin: ");
    ascii2 = getchar(); // Ýkinci karakteri al ve ascii2'ye kaydet.

    // Yine Enter'ý yutmak için.
    getchar(); 
    
    // --- Dönüþüm: Karakterden Sayýya Geçiþ ---
    
    // ASCII hilesi: Karakterin ASCII deðerinden '0' karakterinin ASCII deðerini çýkararak 
    // gerçek tamsayý karþýlýðýný elde ediyorum. Sonucu 'num1' ve 'num2' deðiþkenlerine atýyorum.
    // Örnek: ascii1 = '4' (ASCII 52) -> num1 = 52 - 48 = 4.
    num1 = ascii1 - '0';
    num2 = ascii2 - '0';

    // --- Kontrol: Rakam mý Deðil mi? ---
    
    // En önemli kontrol: num1 ve num2 gerçekten 0 ile 9 arasýnda mý? (Yani geçerli bir rakam mý?)
    // Mantýksal VE (&&) kullanýyorum, her iki koþul da doðruysa devam edebiliriz.
    if( (num1 >= 0 && num1 <= 9) && (num2 >= 0 && num2 <= 9) )
    {
        
        // --- Her Þey Yolunda ---
        
        toplam = num1 + num2;
        
        printf("\nToplam %d olarak bulundu.\n", toplam);
        
        // Sonucu hemen kaybolmasýn diye 3 saniye (3000ms) bekletiyorum.
        Sleep(3000); 
        
        return 0; // Baþarýlý bitiþ.
        
    } 
    else 
    {
        // --- Hata Durumu: Geçersiz Girdi ---
        
        printf("\n=> HATALI INPUT GIRISI \n");
        
        Sleep(3000); // Hata mesajýný görmeleri için bekleme.
        return 0; // Programdan çýkýþ.
    }
}
