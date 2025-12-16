#include <stdio.h>
#include <math.h>

int main() {
    char namaRestoran[100];
    int jumlahItem, harga[100];
    int i, jumlahOrang, metode;
    float subtotal = 0, service, pajak, total;
    float perOrang, pembulatan;

    printf("=== BILL SPLITTER ===\n");
    printf("Nama Restoran: ");
    scanf(" %[^\n]", namaRestoran);

    printf("\nJumlah item: ");
    scanf("%d", &jumlahItem);

    for (i = 0; i < jumlahItem; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &harga[i]);
        subtotal += harga[i];
    }

    service = subtotal * 0.05;
    pajak = subtotal * 0.10;
    total = subtotal + service + pajak;

    printf("\nSubtotal         : Rp %.0f\n", subtotal);
    printf("Service (5%%)     : Rp %.0f\n", service);
    printf("Pajak (10%%)      : Rp %.0f\n", pajak);
    printf("--------------------------\n");
    printf("Total            : Rp %.0f\n", total);

    printf("\nJumlah orang: ");
    scanf("%d", &jumlahOrang);

    printf("\nMetode pembagian:\n");
    printf("1. Rata (sama rata)\n");
    printf("2. Custom (bayar custom)\n");
    printf("Pilih: ");
    scanf("%d", &metode);

    printf("\n=== PEMBAGIAN BILL ===\n\n");

    if (metode == 1) {
        perOrang = total / jumlahOrang;

        printf("Total        : Rp %.0f\n", total);
        printf("Jumlah orang : %d orang\n", jumlahOrang);
        printf("Per orang    : Rp %.3f\n\n", perOrang);

        printf("Pembulatan:\n");

        pembulatan = floor(perOrang / 1000) * 1000;

        for (i = 1; i <= jumlahOrang; i++) {
            if (i < jumlahOrang) {
                printf("Orang %d      : Rp %.0f\n", i, pembulatan);
            } else {
                float totalDibulatkan = pembulatan * (jumlahOrang - 1);
                float sisa = total - totalDibulatkan;
                printf("Orang %d      : Rp %.0f\n", i, ceil(sisa / 1000) * 1000);
                printf("(Selisih dibebankan ke orang terakhir)\n");
            }
        }
    } 
    else if (metode == 2) {
        float customBayar[100];
        float totalCustom = 0;
        
        printf("\n--- CUSTOM SPLIT BILL ---\n");
        printf("Masukkan jumlah yang dibayar setiap orang:\n");
        
        for (i = 0; i < jumlahOrang; i++) {
            printf("Orang %d bayar: Rp ", i + 1);
            scanf("%f", &customBayar[i]);
            totalCustom += customBayar[i];
        }

        printf("\n=== HASIL CUSTOM SPLIT ===\n");
        for (i = 0; i < jumlahOrang; i++) {
            printf("Orang %d      : Rp %.0f\n", i + 1, customBayar[i]);
        }
        printf("Total Custom : Rp %.0f\n", totalCustom);
        printf("Total Bill   : Rp %.0f\n", total);
        
        float selisih = total - totalCustom;
        if (selisih > 0) {
            printf("\n Kurang bayar: Rp %.0f\n", selisih);
        } else if (selisih < 0) {
            printf("\n Kelebihan bayar: Rp %.0f\n", -selisih);
        } else {
            printf("\n Pembagian tepat!\n");
        }
    }
    else {
        printf("Pilihan tidak valid!\n");
    }

    printf("\nTerima kasih telah menggunakan Bill Splitter!\n");
    return 0;
}