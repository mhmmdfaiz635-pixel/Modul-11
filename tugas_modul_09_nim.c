/*
Nama        : Muhammad Faiz Qodri Muslim
NIM         : 2610511179
Kelas       : E
Modul       : 9
Deskripsi   : Program menyimpan dan mengolah nilai beberapa
              mahasiswa dan mata kuliah menggunakan array
              dua dimensi.
*/

#include <stdio.h>
#include <math.h>

#define MAX_MAHASISWA 30
#define MAX_MATA_KULIAH 10
#define BATAS_LULUS 60.0
#define EPSILON 0.000001

int baca_jumlah_dalam_rentang(int minimum, int maksimum);
void baca_nilai(
    double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
void tampilkan_tabel_nilai(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
double hitung_total_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
);
double hitung_rata_rata_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
);
double hitung_total_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
);
double hitung_rata_rata_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
);
double hitung_total_keseluruhan(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
int hitung_jumlah_lulus(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
int cari_mahasiswa_rata_rata_tertinggi(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
int cari_mata_kuliah_rata_rata_tertinggi(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
int hitung_frekuensi_target(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double target
);
void tampilkan_posisi_target(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double target
);
double cari_nilai_tertinggi_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
);
double cari_nilai_terendah_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
);
int hitung_lulus_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
);
double cari_nilai_tertinggi_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
);
double cari_nilai_terendah_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
);
int hitung_lulus_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
);
void cari_minimum_dan_maksimum(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double *minimum,
    double *maksimum,
    int *baris_minimum,
    int *kolom_minimum,
    int *baris_maksimum,
    int *kolom_maksimum
);
void tampilkan_rekap_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);
void tampilkan_rekap_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
);

int main(void)
{
    double nilai[MAX_MAHASISWA][MAX_MATA_KULIAH];
    int jumlah_mahasiswa;
    int jumlah_mata_kuliah;
    int mahasiswa_terbaik;
    int mata_kuliah_terbaik;
    int jumlah_lulus;
    int jumlah_elemen;
    int frekuensi;
    double total_keseluruhan;
    double rata_rata_keseluruhan;
    double persentase_lulus;
    double target;
    double minimum;
    double maksimum;
    int baris_minimum;
    int kolom_minimum;
    int baris_maksimum;
    int kolom_maksimum;

    printf("====================================================\n");
    printf("         PENGELOLAAN NILAI MAHASISWA DAN MK\n");
    printf("====================================================\n");

    printf("Masukkan jumlah mahasiswa 1-%d: ", MAX_MAHASISWA);
    jumlah_mahasiswa =
        baca_jumlah_dalam_rentang(1, MAX_MAHASISWA);

    printf("Masukkan jumlah mata kuliah 1-%d: ", MAX_MATA_KULIAH);
    jumlah_mata_kuliah =
        baca_jumlah_dalam_rentang(1, MAX_MATA_KULIAH);

    baca_nilai(nilai, jumlah_mahasiswa, jumlah_mata_kuliah);
    tampilkan_tabel_nilai(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah
    );

    tampilkan_rekap_mahasiswa(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah
    );

    tampilkan_rekap_mata_kuliah(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah
    );

    total_keseluruhan = hitung_total_keseluruhan(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah
    );
    jumlah_elemen = jumlah_mahasiswa * jumlah_mata_kuliah;
    rata_rata_keseluruhan =
        total_keseluruhan / jumlah_elemen;

    jumlah_lulus = hitung_jumlah_lulus(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah
    );
    persentase_lulus =
        ((double) jumlah_lulus / jumlah_elemen) * 100.0;

    mahasiswa_terbaik =
        cari_mahasiswa_rata_rata_tertinggi(
            nilai,
            jumlah_mahasiswa,
            jumlah_mata_kuliah
        );
    mata_kuliah_terbaik =
        cari_mata_kuliah_rata_rata_tertinggi(
            nilai,
            jumlah_mahasiswa,
            jumlah_mata_kuliah
        );

    cari_minimum_dan_maksimum(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah,
        &minimum,
        &maksimum,
        &baris_minimum,
        &kolom_minimum,
        &baris_maksimum,
        &kolom_maksimum
    );

    printf("\nREKAP KESELURUHAN\n");
    printf("----------------------------------------------------\n");
    printf("Total seluruh nilai      : %.2f\n", total_keseluruhan);
    printf("Rata-rata seluruh nilai  : %.2f\n",
           rata_rata_keseluruhan);
    printf("Nilai tertinggi          : %.2f\n", maksimum);
    printf("Posisi tertinggi         : Mahasiswa %d, MK %d\n",
           baris_maksimum + 1, kolom_maksimum + 1);
    printf("Nilai terendah           : %.2f\n", minimum);
    printf("Posisi terendah          : Mahasiswa %d, MK %d\n",
           baris_minimum + 1, kolom_minimum + 1);
    printf("Jumlah nilai lulus       : %d dari %d\n",
           jumlah_lulus, jumlah_elemen);
    printf("Persentase kelulusan     : %.2f%%\n",
           persentase_lulus);
    printf("Mahasiswa rata-rata terbaik: Mahasiswa %d (%.2f)\n",
           mahasiswa_terbaik + 1,
           hitung_rata_rata_mahasiswa(
               nilai,
               mahasiswa_terbaik,
               jumlah_mata_kuliah
           ));
    printf("Mata kuliah rata-rata terbaik: MK %d (%.2f)\n",
           mata_kuliah_terbaik + 1,
           hitung_rata_rata_mata_kuliah(
               nilai,
               jumlah_mahasiswa,
               mata_kuliah_terbaik
           ));

    printf("\nMasukkan nilai yang dicari: ");
    scanf("%lf", &target);

    frekuensi = hitung_frekuensi_target(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah,
        target
    );

    printf("\nHASIL PENCARIAN\n");
    printf("----------------------------------------------------\n");
    printf("Jumlah kemunculan: %d\n", frekuensi);

    tampilkan_posisi_target(
        nilai,
        jumlah_mahasiswa,
        jumlah_mata_kuliah,
        target
    );

    printf("====================================================\n");

    return 0;
}

int baca_jumlah_dalam_rentang(int minimum, int maksimum)
{
    int nilai;

    do
    {
        scanf("%d", &nilai);

        if ((nilai < minimum) || (nilai > maksimum))
        {
            printf(
                "Input tidak valid. Masukkan nilai %d-%d: ",
                minimum,
                maksimum
            );
        }
    }
    while ((nilai < minimum) || (nilai > maksimum));

    return nilai;
}

void baca_nilai(
    double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mahasiswa;
    int mata_kuliah;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        printf("\nMAHASISWA KE-%d\n", mahasiswa + 1);

        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            do
            {
                printf(
                    "Nilai mata kuliah ke-%d: ",
                    mata_kuliah + 1
                );
                scanf(
                    "%lf",
                    &nilai[mahasiswa][mata_kuliah]
                );

                if ((nilai[mahasiswa][mata_kuliah] < 0.0) ||
                    (nilai[mahasiswa][mata_kuliah] > 100.0))
                {
                    printf(
                        "Nilai harus berada pada rentang 0-100.\n"
                    );
                }
            }
            while ((nilai[mahasiswa][mata_kuliah] < 0.0) ||
                   (nilai[mahasiswa][mata_kuliah] > 100.0));
        }
    }
}

void tampilkan_tabel_nilai(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mahasiswa;
    int mata_kuliah;
    char label[16];

    printf("\nTABEL NILAI\n");
    printf("----------------------------------------------------\n");
    printf("%-9s", "Mahasiswa");

    for (mata_kuliah = 0;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        sprintf(label, "MK-%d", mata_kuliah + 1);
        printf("%8s", label);
    }

    printf("\n");

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        printf("%9d", mahasiswa + 1);

        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            printf(
                "%8.2f",
                nilai[mahasiswa][mata_kuliah]
            );
        }

        printf("\n");
    }
}

double hitung_total_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
)
{
    double total = 0.0;
    int mata_kuliah;

    for (mata_kuliah = 0;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        total += nilai[indeks_mahasiswa][mata_kuliah];
    }

    return total;
}

double hitung_rata_rata_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
)
{
    return hitung_total_mahasiswa(
               nilai,
               indeks_mahasiswa,
               jumlah_mata_kuliah
           ) / jumlah_mata_kuliah;
}

double hitung_total_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
)
{
    double total = 0.0;
    int mahasiswa;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        total += nilai[mahasiswa][indeks_mata_kuliah];
    }

    return total;
}

double hitung_rata_rata_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
)
{
    return hitung_total_mata_kuliah(
               nilai,
               jumlah_mahasiswa,
               indeks_mata_kuliah
           ) / jumlah_mahasiswa;
}

double hitung_total_keseluruhan(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    double total = 0.0;
    int mahasiswa;
    int mata_kuliah;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            total += nilai[mahasiswa][mata_kuliah];
        }
    }

    return total;
}

int hitung_jumlah_lulus(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int jumlah = 0;
    int mahasiswa;
    int mata_kuliah;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            if (nilai[mahasiswa][mata_kuliah] >= BATAS_LULUS)
            {
                jumlah++;
            }
        }
    }

    return jumlah;
}

int cari_mahasiswa_rata_rata_tertinggi(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mahasiswa;
    int terbaik = 0;
    double rata_rata_terbaik;

    rata_rata_terbaik = hitung_rata_rata_mahasiswa(
        nilai,
        terbaik,
        jumlah_mata_kuliah
    );

    for (mahasiswa = 1;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        double rata_rata = hitung_rata_rata_mahasiswa(
            nilai,
            mahasiswa,
            jumlah_mata_kuliah
        );

        if (rata_rata > rata_rata_terbaik)
        {
            rata_rata_terbaik = rata_rata;
            terbaik = mahasiswa;
        }
    }

    return terbaik;
}

int cari_mata_kuliah_rata_rata_tertinggi(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mata_kuliah;
    int terbaik = 0;
    double rata_rata_terbaik;

    rata_rata_terbaik = hitung_rata_rata_mata_kuliah(
        nilai,
        jumlah_mahasiswa,
        terbaik
    );

    for (mata_kuliah = 1;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        double rata_rata = hitung_rata_rata_mata_kuliah(
            nilai,
            jumlah_mahasiswa,
            mata_kuliah
        );

        if (rata_rata > rata_rata_terbaik)
        {
            rata_rata_terbaik = rata_rata;
            terbaik = mata_kuliah;
        }
    }

    return terbaik;
}

int hitung_frekuensi_target(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double target
)
{
    int frekuensi = 0;
    int mahasiswa;
    int mata_kuliah;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            if (fabs(
                    nilai[mahasiswa][mata_kuliah] - target
                ) < EPSILON)
            {
                frekuensi++;
            }
        }
    }

    return frekuensi;
}

void tampilkan_posisi_target(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double target
)
{
    int ditemukan = 0;
    int mahasiswa;
    int mata_kuliah;

    printf("Posisi:\n");

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            if (fabs(
                    nilai[mahasiswa][mata_kuliah] - target
                ) < EPSILON)
            {
                printf(
                    "Mahasiswa %d, MK %d\n",
                    mahasiswa + 1,
                    mata_kuliah + 1
                );
                ditemukan = 1;
            }
        }
    }

    if (ditemukan == 0)
    {
        printf("Tidak ditemukan.\n");
    }
}

double cari_nilai_tertinggi_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
)
{
    double tertinggi = nilai[indeks_mahasiswa][0];
    int mata_kuliah;

    for (mata_kuliah = 1;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        if (nilai[indeks_mahasiswa][mata_kuliah] > tertinggi)
        {
            tertinggi = nilai[indeks_mahasiswa][mata_kuliah];
        }
    }

    return tertinggi;
}

double cari_nilai_terendah_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
)
{
    double terendah = nilai[indeks_mahasiswa][0];
    int mata_kuliah;

    for (mata_kuliah = 1;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        if (nilai[indeks_mahasiswa][mata_kuliah] < terendah)
        {
            terendah = nilai[indeks_mahasiswa][mata_kuliah];
        }
    }

    return terendah;
}

int hitung_lulus_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int indeks_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int jumlah = 0;
    int mata_kuliah;

    for (mata_kuliah = 0;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        if (nilai[indeks_mahasiswa][mata_kuliah] >=
            BATAS_LULUS)
        {
            jumlah++;
        }
    }

    return jumlah;
}

double cari_nilai_tertinggi_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
)
{
    double tertinggi = nilai[0][indeks_mata_kuliah];
    int mahasiswa;

    for (mahasiswa = 1;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        if (nilai[mahasiswa][indeks_mata_kuliah] > tertinggi)
        {
            tertinggi = nilai[mahasiswa][indeks_mata_kuliah];
        }
    }

    return tertinggi;
}

double cari_nilai_terendah_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
)
{
    double terendah = nilai[0][indeks_mata_kuliah];
    int mahasiswa;

    for (mahasiswa = 1;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        if (nilai[mahasiswa][indeks_mata_kuliah] < terendah)
        {
            terendah = nilai[mahasiswa][indeks_mata_kuliah];
        }
    }

    return terendah;
}

int hitung_lulus_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int indeks_mata_kuliah
)
{
    int jumlah = 0;
    int mahasiswa;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        if (nilai[mahasiswa][indeks_mata_kuliah] >=
            BATAS_LULUS)
        {
            jumlah++;
        }
    }

    return jumlah;
}

void cari_minimum_dan_maksimum(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah,
    double *minimum,
    double *maksimum,
    int *baris_minimum,
    int *kolom_minimum,
    int *baris_maksimum,
    int *kolom_maksimum
)
{
    int mahasiswa;
    int mata_kuliah;

    *minimum = nilai[0][0];
    *maksimum = nilai[0][0];
    *baris_minimum = 0;
    *kolom_minimum = 0;
    *baris_maksimum = 0;
    *kolom_maksimum = 0;

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        for (mata_kuliah = 0;
             mata_kuliah < jumlah_mata_kuliah;
             mata_kuliah++)
        {
            if (nilai[mahasiswa][mata_kuliah] < *minimum)
            {
                *minimum = nilai[mahasiswa][mata_kuliah];
                *baris_minimum = mahasiswa;
                *kolom_minimum = mata_kuliah;
            }

            if (nilai[mahasiswa][mata_kuliah] > *maksimum)
            {
                *maksimum = nilai[mahasiswa][mata_kuliah];
                *baris_maksimum = mahasiswa;
                *kolom_maksimum = mata_kuliah;
            }
        }
    }
}

void tampilkan_rekap_mahasiswa(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mahasiswa;

    printf("\nREKAP PER MAHASISWA\n");
    printf("----------------------------------------------------\n");

    for (mahasiswa = 0;
         mahasiswa < jumlah_mahasiswa;
         mahasiswa++)
    {
        printf(
            "Mahasiswa %d | Total %.2f | Rata-rata %.2f\n",
            mahasiswa + 1,
            hitung_total_mahasiswa(
                nilai,
                mahasiswa,
                jumlah_mata_kuliah
            ),
            hitung_rata_rata_mahasiswa(
                nilai,
                mahasiswa,
                jumlah_mata_kuliah
            )
        );
        printf(
            "  Tertinggi %.2f | Terendah %.2f | MK lulus %d dari %d\n",
            cari_nilai_tertinggi_mahasiswa(
                nilai,
                mahasiswa,
                jumlah_mata_kuliah
            ),
            cari_nilai_terendah_mahasiswa(
                nilai,
                mahasiswa,
                jumlah_mata_kuliah
            ),
            hitung_lulus_mahasiswa(
                nilai,
                mahasiswa,
                jumlah_mata_kuliah
            ),
            jumlah_mata_kuliah
        );
    }
}

void tampilkan_rekap_mata_kuliah(
    const double nilai[][MAX_MATA_KULIAH],
    int jumlah_mahasiswa,
    int jumlah_mata_kuliah
)
{
    int mata_kuliah;

    printf("\nREKAP PER MATA KULIAH\n");
    printf("----------------------------------------------------\n");

    for (mata_kuliah = 0;
         mata_kuliah < jumlah_mata_kuliah;
         mata_kuliah++)
    {
        printf(
            "MK-%d | Total %.2f | Rata-rata %.2f\n",
            mata_kuliah + 1,
            hitung_total_mata_kuliah(
                nilai,
                jumlah_mahasiswa,
                mata_kuliah
            ),
            hitung_rata_rata_mata_kuliah(
                nilai,
                jumlah_mahasiswa,
                mata_kuliah
            )
        );
        printf(
            "  Tertinggi %.2f | Terendah %.2f | Mahasiswa lulus %d dari %d\n",
            cari_nilai_tertinggi_mata_kuliah(
                nilai,
                jumlah_mahasiswa,
                mata_kuliah
            ),
            cari_nilai_terendah_mata_kuliah(
                nilai,
                jumlah_mahasiswa,
                mata_kuliah
            ),
            hitung_lulus_mata_kuliah(
                nilai,
                jumlah_mahasiswa,
                mata_kuliah
            ),
            jumlah_mahasiswa
        );
    }
}
