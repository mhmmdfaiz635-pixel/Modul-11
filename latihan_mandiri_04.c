#include <stdio.h>

#define MAX_UKURAN 10

int main(void)
{
    int ukuran;
    int baris;
    int kolom;
    char karakter;

    do
    {
        printf("Masukkan ukuran tabel 1-%d: ", MAX_UKURAN);
        scanf("%d", &ukuran);
    }
    while ((ukuran < 1) || (ukuran > MAX_UKURAN));

    for (baris = 0; baris < ukuran; baris++)
    {
        for (kolom = 0; kolom < ukuran; kolom++)
        {
            if ((baris == 0) ||
                (baris == ukuran - 1) ||
                (kolom == 0) ||
                (kolom == ukuran - 1))
            {
                karakter = '#';
            }
            else if (baris == kolom)
            {
                karakter = 'X';
            }
            else
            {
                karakter = '.';
            }

            printf("%c ", karakter);
        }

        printf("\n");
    }

    return 0;
}
