#include <stdio.h>   // Untuk fungsi input/output seperti scanf dan printf
#include <limits.h>  // Untuk konstanta INT_MAX dan INT_MIN
#include <float.h>   // Untuk konstanta DBL_MAX

int main() {
    int n;           // Jumlah bilangan yang akan dimasukkan
    int prev_num;    // Menyimpan bilangan sebelumnya
    int current_num; // Menyimpan bilangan yang sedang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum
    
    double min_avg_consecutive = DBL_MAX; // Inisialisasi rata-rata minimum berurutan
    
    // Membaca input untuk 'n'. Menghapus prompt.
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1; // Keluar dengan kode error
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

        // Jika ini bukan bilangan pertama, hitung rata-rata berurutan
        if (i > 0) {
            double current_avg = (double)(prev_num + current_num) / 2.0;
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
        }
        
        prev_num = current_num; // Simpan bilangan saat ini untuk iterasi berikutnya
    }

    // Menampilkan hasil sesuai format yang diharapkan
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    // Hanya tampilkan rata-rata terendah jika ada setidaknya 2 bilangan untuk membentuk pasangan
    if (n >= 2) {
        printf("%.2f\n", min_avg_consecutive);
    }

    return 0; // Program berhasil dieksekusi
}
