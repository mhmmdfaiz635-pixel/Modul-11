/*
Nama        : Muhammad Faiz Qodri Muslim
NIM         : 2610511179
Kelas       : E
Modul       : 9
Deskripsi   : Program mencari frekuensi kemunculan dan posisi
              pertama sebuah target pada matriks bertipe double
              menggunakan perbandingan bertoleransi EPSILON.
*/

#include <stdio.h>
#include <math.h>

#define MAX_BARIS 10
#define MAX_KOLOM 10
#define EPSILON 0.000001

int main(void)
{
    double data[MAX_BARIS][MAX_KOLOM];
    int jumlah_baris;
    int jumlah_kolom;
    int baris;
    int kolom;
    double target;
    int frekuensi = 0;
    int baris_ditemukan = -1;
    int kolom_ditemukan = -1;

    scanf("%d %d", &jumlah_baris, &jumlah_kolom);

    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            scanf("%lf", &data[baris][kolom]);
        }
    }

    scanf("%lf", &target);

    for (baris = 0; baris < jumlah_baris; baris++)
    {
        for (kolom = 0; kolom < jumlah_kolom; kolom++)
        {
            if (fabs(data[baris][kolom] - target) < EPSILON)
            {
                frekuensi++;

                if (baris_ditemukan == -1)
                {
                    baris_ditemukan = baris;
                    kolom_ditemukan = kolom;
                }
            }
        }
    }

    printf("========================================\n");
    printf("  FREKUENSI DAN POSISI DENGAN TOLERANSI \n");
    printf("========================================\n");
    printf("Target           : %.2f\n", target);
    printf("----------------------------------------\n");
    printf("Frekuensi        : %d\n", frekuensi);

    if (baris_ditemukan == -1)
    {
        printf("Baris ditemukan  : -1\n");
        printf("Kolom ditemukan  : -1\n");
    }
    else
    {
        printf("Baris ditemukan  : %d\n", baris_ditemukan + 1);
        printf("Kolom ditemukan  : %d\n", kolom_ditemukan + 1);
    }

    printf("========================================\n");

    return 0;
}
