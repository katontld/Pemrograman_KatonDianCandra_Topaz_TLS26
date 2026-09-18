// Tugas Pemrograman Dasar TLS 2026 - Problem 1 (The Last Astronaut)
// Nama     : Katon Dian Candra
// NIM      : 26/576803/TK/65606
// Kelompok : Topaz (Kelompok 7)

#include <iostream>

int hitungPosisiTarget(int posAwal, int langkah, int sisa) {
    return (posAwal + langkah - 1) % sisa;
}

int perbaruiLangkah(int kLama, int nomor) {
    int kBaru = (nomor % 2 == 0) ? (kLama + 2) : (kLama - 1);
    return (kBaru < 2) ? 2 : kBaru;
}

void geserLingkaran(int arr[], int &ukuran, int target) {
    for (int i = target; i < ukuran - 1; i++) {
        arr[i] = arr[i + 1];
    }
    ukuran--;
}

void cetakLingkaran(const int arr[], int ukuran) {
    std::cout << "[";
    for (int i = 0; i < ukuran; i++) {
        std::cout << arr[i];
        if (i < ukuran - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "        SIMULASI THE LAST ASTRONAUT - TLS 2026      \n";
    std::cout << "====================================================\n";

    int N, K;
    std::cout << "Masukkan jumlah astronot (N)    : ";
    if (!(std::cin >> N) || N <= 0) {
        std::cout << "Input N tidak valid!\n";
        return 1;
    }

    std::cout << "Masukkan nilai hitungan awal (K): ";
    if (!(std::cin >> K) || K <= 0) {
        std::cout << "Input K tidak valid!\n";
        return 1;
    }

    int *peserta = new int[N];
    for (int i = 0; i < N; i++) {
        peserta[i] = i + 1;
    }

    int *riwayatEliminasi = new int[N];
    int sisaPeserta = N;
    int posSekarang = 0;
    int kAktif = K;
    int ronde = 0;

    std::cout << "\nSusunan awal lingkaran : ";
    cetakLingkaran(peserta, sisaPeserta);
    std::cout << "\nHitungan awal dimulai  : Astronot #" << peserta[posSekarang] << "\n";

    std::cout << "\n--- PROSES SIMULASI SETIAP RONDE ---\n";
    while (sisaPeserta > 1) {
        int targetIdx = hitungPosisiTarget(posSekarang, kAktif, sisaPeserta);
        int astronotGugur = peserta[targetIdx];
        int kBerikutnya = perbaruiLangkah(kAktif, astronotGugur);

        riwayatEliminasi[ronde++] = astronotGugur;

        std::cout << "\n[Ronde " << ronde << "]\n";
        std::cout << "  - Mulai hitung : Astronot #" << peserta[posSekarang] << "\n";
        std::cout << "  - Langkah (K)  : " << kAktif << " langkah\n";
        std::cout << "  - Tereliminasi : Astronot #" << astronotGugur << " ("
                  << (astronotGugur % 2 == 0 ? "Genap -> K + 2 = " : "Ganjil -> K - 1 = ")
                  << kBerikutnya << ")\n";

        geserLingkaran(peserta, sisaPeserta, targetIdx);
        kAktif = kBerikutnya;

        std::cout << "  - Sisa astronot: ";
        cetakLingkaran(peserta, sisaPeserta);
        std::cout << "\n";

        if (sisaPeserta > 0) {
            posSekarang = targetIdx % sisaPeserta;
        }
    }

    std::cout << "\n====================================================\n";
    std::cout << "                    HASIL AKHIR                     \n";
    std::cout << "====================================================\n";
    std::cout << "Total ronde eliminasi  : " << ronde << " ronde\n";
    std::cout << "Urutan astronot gugur  : ";
    cetakLingkaran(riwayatEliminasi, ronde);
    std::cout << "\nAstronot yang bertahan : Astronot #" << peserta[0] << " (Pemenang!)\n";
    std::cout << "====================================================\n";

    delete[] peserta;
    delete[] riwayatEliminasi;

    return 0;
}
