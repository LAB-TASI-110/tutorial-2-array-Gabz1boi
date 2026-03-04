#include <stdio.h>   // Untuk fungsi input/output seperti scanf dan printf
#include <limits.h>  // Untuk konstanta INT_MAX dan INT_MIN

int main() {
    int n;           // Jumlah bilangan yang akan dimasukkan
    int current_num; // Menyimpan bilangan yang sedang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum

    // Membaca input untuk 'n'. Menghapus prompt.
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Keluar dengan kode error jika input tidak valid
    }

    // Loop untuk membaca semua 'n' bilangan
    for (int i = 0; i < n; i++) {
        // Membaca bilangan. Menghapus prompt.
        if (scanf("%d", &current_num) != 1) {
            return 1; // Keluar dengan kode error
        }

        // Memeriksa rentang. Menghapus prompt error.
        if (current_num < -100 || current_num > 100) {
            return 1; // Keluar dengan kode error
        }

        // Memperbarui nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }
    }

    // Menampilkan hasil sesuai format yang diharapkan
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Program berhasil dieksekusi
}
