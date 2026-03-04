#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Untuk konstanta INT_MAX dan INT_MIN
#include <float.h>   // Untuk konstanta DBL_MAX, digunakan untuk inisialisasi rata-rata minimum

int main() {
    int n;          // Jumlah bilangan yang akan dimasukkan
    int prev_num;   // Menyimpan bilangan sebelumnya untuk menghitung rata-rata berurutan
    int current_num; // Menyimpan bilangan yang sedang diinput
    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil
    
    // Inisialisasi rata-rata minimum dengan nilai double terbesar,
    // agar rata-rata pertama yang dihitung pasti akan lebih kecil.
    double min_avg_consecutive = DBL_MAX; 
    
    // --- Langkah 1: Meminta input untuk 'n' (jumlah baris berikutnya) ---
    printf("Masukkan jumlah bilangan yang akan diproses (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Masukan n harus bilangan bulat positif. Program berhenti.\n");
        return 1; // Keluar dengan kode error
    }

    // --- Langkah 2: Meminta 'n' bilangan bulat dan mencari min/max/rata-rata terendah ---
    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);
    
    // Kita perlu setidaknya dua angka untuk bisa menghitung rata-rata berurutan
    if (n < 2) {
        printf("Untuk menghitung rata-rata dua bilangan berurutan, setidaknya perlu 2 bilangan.\n");
        printf("Jika hanya ada satu bilangan, program akan menampilkan min/max saja.\n");
    }

    // Loop untuk membaca semua 'n' bilangan
    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        if (scanf("%d", &current_num) != 1) { // Memeriksa apakah input adalah integer yang valid
            printf("Error: Masukan bukan bilangan bulat. Program berhenti.\n");
            return 1;
        }

        // Memeriksa apakah bilangan yang diinput berada dalam rentang yang ditentukan
        if (current_num < -100 || current_num > 100) {
            printf("Error: Bilangan harus dalam rentang -100 hingga 100. Program berhenti.\n");
            return 1;
        }

        // Memperbarui nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Jika ini bukan bilangan pertama (yaitu, ada bilangan sebelumnya),
        // hitung rata-rata dengan bilangan sebelumnya
        if (i > 0) {
            double current_avg = (double)(prev_num + current_num) / 2.0;
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
        }
        
        // Simpan bilangan saat ini sebagai 'prev_num' untuk iterasi berikutnya
        prev_num = current_num;
    }

    // --- Langkah 3: Menampilkan hasil nilai terkecil, terbesar, dan rata-rata terendah ---
    printf("\nNilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d: %d\n", max_val);
    
    // Hanya tampilkan rata-rata terendah jika ada setidaknya 2 bilangan yang diproses
    if (n >= 2) {
        printf("Rata-rata terendah dari dua bilangan berurutan: %.2f\n", min_avg_consecutive);
    } else {
        printf("Tidak ada rata-rata dua bilangan berurutan yang dapat dihitung (kurang dari 2 bilangan).\n");
    }

    return 0; // Program berhasil dieksekusi
}
