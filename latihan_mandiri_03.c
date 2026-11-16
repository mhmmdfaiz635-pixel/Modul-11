#include <stdio.h>

#define MAX_BARIS 10
#define MAX_KOLOM 10

int main(void)
{
    int matriks_a[MAX_BARIS][MAX_KOLOM];
    int matriks_b[MAX_BARIS][MAX_KOLOM];
    int hasil[MAX_BARIS][MAX_KOLOM];
    int jumlah_baris;
    int jumlah_kolom;
    int baris;
    int kolom;

    do
    {
        printf("Masukkan jumlah baris 1-%d: ", MAX_BARIS);
        scanf("%d", &jumlah_baris);
    }
    while ((jumlah_baris < 1) || (jumlah_baris > MAX_BARIS));

    do
    {
        printf("Masukkan jumlah kolom 1-%d: ", MAX_KOLOM);
        scanf("%d", &jumlah_kolom);
    }
    while ((jumlah_kolom < 1) || (jumlah_kolom > MAX_KOLOM));

    printf("\nMATRIKS A\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("A[%d][%d]: ", baris, kolom);
            scanf("%d", &matriks_a[baris][kolom]);
        }
    }

    printf("\nMATRIKS B\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("B[%d][%d]: ", baris, kolom);
            scanf("%d", &matriks_b[baris][kolom]);
        }
    }

    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            hasil[baris][kolom] =
                matriks_a[baris][kolom] +
                matriks_b[baris][kolom];
        }
    }

    printf("\nMATRIKS A\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("%5d", matriks_a[baris][kolom]);
        }

        printf("\n");
    }

    printf("\nMATRIKS B\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("%5d", matriks_b[baris][kolom]);
        }

        printf("\n");
    }

    printf("\nHASIL PENJUMLAHAN\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("%5d", hasil[baris][kolom]);
        }

        printf("\n");
    }

    return 0;
}
