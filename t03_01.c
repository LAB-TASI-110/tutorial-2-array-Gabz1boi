#include <stdio.h> // Header ini diperlukan untuk fungsi input/output seperti printf dan scanf
#include <limits.h> // Header ini menyediakan konstanta seperti INT_MAX dan INT_MIN

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num; // Variabel sementara untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar.
                           // Tujuannya agar setiap bilangan yang dimasukkan pasti lebih kecil
                           // dari INT_MAX pada perbandingan pertama.
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil.
                           // Tujuannya agar setiap bilangan yang dimasukkan pasti lebih besar
                           // dari INT_MIN pada perbandingan pertama.

    // --- Langkah 1: Meminta input untuk 'n' (jumlah baris berikutnya) ---
    printf("Masukkan jumlah bilangan yang akan diproses (n): ");
    // Menggunakan scanf untuk membaca input integer dari keyboard
    // Kita juga memeriksa apakah scanf berhasil membaca integer (%d) dan apakah nilai n positif
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Masukan n harus bilangan bulat positif. Program berhenti.\n");
        return 1; // Mengembalikan 1 menandakan program berakhir dengan error
    }

    // --- Langkah 2: Meminta 'n' bilangan bulat dan mencari min/max ---
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        // Membaca setiap bilangan
        if (scanf("%d", &num) != 1) { // Memeriksa apakah input adalah integer yang valid
            printf("Error: Masukan bukan bilangan bulat. Program berhenti.\n");
            return 1;
        }

        // Memeriksa apakah bilangan yang diinput berada dalam rentang yang ditentukan
        if (num < -100 || num > 100) {
            printf("Error: Bilangan harus dalam rentang -100 hingga 100. Program berhenti.\n");
            return 1;
        }

        // Memperbarui nilai minimum jika 'num' lebih kecil dari 'min_val' saat ini
        if (num < min_val) {
            min_val = num;
        }

        // Memperbarui nilai maksimum jika 'num' lebih besar dari 'max_val' saat ini
        if (num > max_val) {
            max_val = num;
        }
    }

    // --- Langkah 3: Menampilkan hasil nilai terkecil dan terbesar ---
    printf("\nNilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);

    return 0; // Mengembalikan 0 menandakan program berakhir dengan sukses
}
