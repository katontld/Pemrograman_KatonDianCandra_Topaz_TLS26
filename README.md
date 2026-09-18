# Pemrograman_KatonDianCandra_Topaz_TLS26

**Luminous Quest: Pemrograman Dasar TLS 2026**  
Departemen Teknik Elektro dan Teknologi Informasi (DTETI)  
Fakultas Teknik, Universitas Gadjah Mada  

---

## 📌 Data Peserta

| Data | Informasi |
| :--- | :--- |
| **Nama Lengkap** | Katon Dian Candra |
| **NIM** | 26/576803/TK/65606 |
| **Program Studi** | S1 Teknik Elektro |
| **Kelompok** | Topaz (Kelompok 7) |
| **Nama Repositori** | `Pemrograman_KatonDianCandra_Topaz_TLS26` |
| **Tautan Repositori** | [katontld/Pemrograman_KatonDianCandra_Topaz_TLS26](https://github.com/katontld/Pemrograman_KatonDianCandra_Topaz_TLS26) |

---

## 🗂️ Struktur Direktori Repositori

Penyusunan berkas mematuhi pedoman baku pengumpulan penugasan TLS 2026:

```text
Pemrograman_KatonDianCandra_Topaz_TLS26/
├── Katon Dian Candra_Fase1.pdf   # Laporan Perancangan Fase 1 (Pseudocode & Flowchart)
├── problem1.cpp                  # Program C++ Solusi Problem 1 (The Last Astronaut)
├── problem2.cpp                  # Program C++ Solusi Problem 2 (Alien-In-The-Middle)
└── README.md                     # Dokumentasi Resmi & Panduan Eksekusi
```

---

## 💡 Deskripsi & Metodologi Solusi

### 1. Problem 1: The Last Astronaut (Simulasi Josephus Dinamis)
- **Ringkasan Kasus**:  
  Sebanyak $N$ astronot berbaris melingkar dengan nomor identitas $1$ sampai $N$. Eliminasi dilakukan berkala dengan panjang langkah awal $K$. Setiap astronot ke-$K$ yang terhitung akan tereliminasi, dan hitungan putaran selanjutnya dilanjutkan tepat dari posisi astronot berikutnya.
- **Logika Adaptif Langkah $K$**:  
  Nilai langkah eliminasi bersifat dinamis mengikuti nomor astronot yang gugur pada ronde berjalan:
  - Nomor **Genap**: $K \leftarrow K + 2$
  - Nomor **Ganjil**: $K \leftarrow K - 1$
  - Pembatas Bawah (*Lower Bound*): Jika $K < 2$, nilai $K$ dipatok ke nilai minimum $K = 2$.
- **Formula Penentuan Target**:  
  $$\text{Indeks Target} = (\text{Posisi Mulai} + K - 1) \pmod{\text{Sisa Astronot}}$$
- **Desain Interaksi CLI**:  
  Program menampilkan visualisasi susunan lingkaran astronot yang bertahan secara bertahap ronde demi ronde, mempermudah inspeksi langkah eliminasi dan pergeseran indeks.
- **Kepatuhan Batasan Fase 2**:  
  - **Hanya menggunakan `#include <iostream>`**.
  - Manajemen array dinamis dikelola manual (`new` dan `delete[]`) tanpa pustaka `<vector>`.
  - Operasi pergeseran array (*array compaction*) dan modular arithmetic diimplementasikan secara independen.

---

### 2. Problem 2: Alien-In-The-Middle (Autokey Substitution Cipher)
- **Ringkasan Kasus**:  
  Mekanisme kriptografi autokey untuk memverifikasi identitas astronot dari penyusupan alien. Setiap alfabet dipetakan ke nilai ordinalnya ($A=1, B=2, \dots, Z=26$).
- **Sistem Penyandian (Enkripsi & Dekripsi)**:
  - Karakter pertama pesan tidak mengalami transformasi ($C_0 = P_0$).
  - Untuk karakter ke-$i$ ($i \ge 1$), pergeseran dihitung berdasarkan karakter pesan asli sebelumnya ($P_{i-1}$):
    $$\text{Enkripsi: } C_i = ((P_i - 1 + P_{i-1}) \pmod{26}) + 1$$
    $$\text{Dekripsi: } P_i = ((C_i - 1 - P_{i-1}) \pmod{26} + 26) \pmod{26} + 1$$
  - Karakter di luar alfabet (spasi, angka, simbol) dipertahankan tanpa modifikasi.
- **Desain Interaksi CLI**:
  Program menyediakan 3 mode operasi:
  1. **Mode Enkripsi**: Mengonversi teks biasa menjadi teks sandi.
  2. **Mode Dekripsi**: Membantu alien memecahkan pesan sandi kembali ke teks asli.
  3. **Simulasi Siklus Penuh Dua Arah**: Pengguna dapat memasukkan kalimat bebas secara interaktif untuk menguji proses enkripsi sekaligus dekripsi balik secara langsung (dengan pembuktian kesamaan hasil 100%).
- **Kepatuhan Batasan Fase 2**:  
  - **Hanya menggunakan `#include <iostream>`**.
  - Seluruh manipulasi string, deteksi kapital, konversi nilai, hingga pembacaan baris masukan (`char[]`) dibangun secara manual tanpa bantuan `<string>`, `<cstring>`, ataupun `<cctype>`.

---

## ⚙️ Kompilasi & Pengujian

Program dapat dikompilasi pada sistem operasi macOS / Linux / Windows menggunakan `clang++` atau `g++`:

### 1. Menjalankan Problem 1
```bash
# Kompilasi
clang++ -std=c++11 -Wall -Wextra problem1.cpp -o problem1

# Eksekusi
./problem1
```
*Contoh masukan pengujian:*
- Jumlah astronot ($N$): `5`
- Langkah awal ($K$): `3`
- *Hasil simulasi:* Urutan gugur `[3, 5, 2, 1]` | Pemenang: `Astronot #4`.

### 2. Menjalankan Problem 2
```bash
# Kompilasi
clang++ -std=c++11 -Wall -Wextra problem2.cpp -o problem2

# Eksekusi
./problem2
```
*Pilihan menu:*
- Pilih `1` untuk menguji enkripsi.
- Pilih `2` untuk menguji dekripsi.
- Pilih `3` untuk pengujian interaktif dua arah (masukkan teks bebas seperti `EXPLORE THE GALAXY 2026` atau tekan Enter langsung untuk menguji kasus bawaan `ALIENS`).

---

## 📋 Verifikasi Kebutuhan Pengumpulan

- [x] Laporan Fase 1: `Katon Dian Candra_Fase1.pdf` tersedia dan terhubung.
- [x] Kode Sumber C++: `problem1.cpp` dan `problem2.cpp` memenuhi batasan ketat pustaka dasar.
- [x] Repositori Publik: Siap dinilai sesuai standarisasi penamaan TLS 2026.
