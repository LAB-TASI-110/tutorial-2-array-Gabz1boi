#include <stdio.h>   // Untuk fungsi input/output seperti scanf dan printf
#include <limits.h>  // Untuk konstanta INT_MAX dan INT_MIN
#include <float.h>   // Untuk konstanta DBL_MAX dan DBL_MIN

int main() {
    int n;          // Jumlah bilangan yang akan dimasukkan
    int prev_num;   // Menyimpan bilangan sebelumnya untuk menghitung rata-rata berurutan
    int current_num; // Menyimpan bilangan yang sedang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum
    int max_val = INT_MIN; // Inisialisasi nilai maksimum
    
    double min_avg_consecutive = DBL_MAX; // Inisialisasi rata-rata minimum berurutan
    double max_avg_consecutive = DBL_MIN; // Inisialisasi rata-rata maksimum berurutan
    
    // --- Langkah 1: Membaca input untuk 'n' (jumlah baris berikutnya) ---
    // Hapus printf prompt "Masukkan jumlah bilangan..."
    if (scanf("%d", &n) != 1 || n <= 0) {
        // Karena ini tes otomatis, output error di stderr atau return saja tanpa printf
        // Untuk tujuan debugging lokal, bisa saja ditambahkan printf ke stderr
        return 1; // Keluar dengan kode error
    }

    // Kita perlu setidaknya dua angka untuk bisa menghitung rata-rata berurutan
    // Hapus printf prompt "Untuk menghitung rata-rata..."
    
    // --- Langkah 2: Membaca 'n' bilangan bulat dan mencari min/max/rata-rata terendah/tertinggi ---
    // Hapus printf prompt "Masukkan %d bilangan bulat..."
    for (int i = 0; i < n; i++) {
        // Hapus printf prompt "Bilangan ke-%d: "
        if (scanf("%d", &current_num) != 1) { // Memeriksa apakah input adalah integer yang valid
            // Hapus printf prompt error
            return 1;
        }

        // Memeriksa apakah bilangan yang diinput berada dalam rentang yang ditentukan
        if (current_num < -100 || current_num > 100) {
            // Hapus printf prompt error
            return 1;
        }

        // Memperbarui nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Jika ini bukan bilangan pertama, hitung rata-rata dengan bilangan sebelumnya
        if (i > 0) {
            double current_avg = (double)(prev_num + current_num) / 2.0;
            
            // Perbarui rata-rata minimum
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            
            // Perbarui rata-rata maksimum
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
        
        // Simpan bilangan saat ini sebagai 'prev_num' untuk iterasi berikutnya
        prev_num = current_num;
    }

    // --- Langkah 3: Menampilkan hasil sesuai format yang diharapkan ---
    printf("%d\n", min_val);
    // PERBAIKAN: Menghapus "%d: " yang berlebihan
    printf("%d\n", max_val); 
    
    // Hanya tampilkan rata-rata terendah dan tertinggi jika ada setidaknya 2 bilangan yang diproses
    if (n >= 2) {
        printf("%.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    } 
    // Jika n < 2, tidak ada output tambahan untuk rata-rata,
    // sesuai dengan "Expected" output yang hanya menampilkan min/max jika n=1.

    return 0; // Program berhasil dieksekusi
}
