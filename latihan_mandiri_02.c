#include <stdio.h>

#define MAX_BARIS 10
#define MAX_KOLOM 10

int main(void)
{
    int data[MAX_BARIS][MAX_KOLOM];
    int jumlah_baris;
    int jumlah_kolom;
    int baris;
    int kolom;
    int total_kolom;

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

    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("Data[%d][%d]: ", baris, kolom);
            scanf("%d", &data[baris][kolom]);
        }
    }

    printf("\nDATA:\n");
    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            printf("%5d", data[baris][kolom]);
        }

        printf("\n");
    }

    printf("\n");
    for (kolom = 0; kolom < jumlah_kolom; kolom++)
    {
        total_kolom = 0;

        for (baris = 0; baris < jumlah_baris; baris++)
        {
            total_kolom += data[baris][kolom];
        }

        printf("Total kolom %d: %d\n", kolom + 1, total_kolom);
    }

    return 0;
}
