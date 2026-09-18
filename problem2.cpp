// Tugas Pemrograman Dasar TLS 2026 - Problem 2 (Alien-In-The-Middle)
// Nama     : Katon Dian Candra
// NIM      : 26/576803/TK/65606
// Kelompok : Topaz (Kelompok 7)

#include <iostream>

int panjangString(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

bool cekHuruf(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char toKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int nilaiHuruf(char c) {
    char h = toKapital(c);
    if (h >= 'A' && h <= 'Z') {
        return h - 'A' + 1;
    }
    return 0;
}

char hurufDariNilai(int val) {
    return (char)('A' + (val - 1));
}

void inputKalimat(char buffer[], int batas) {
    int idx = 0;
    char c;
    while (std::cin.peek() == '\n' || std::cin.peek() == '\r') {
        std::cin.get(c);
    }
    while (idx < batas - 1 && std::cin.get(c) && c != '\n' && c != '\r') {
        buffer[idx++] = c;
    }
    buffer[idx] = '\0';
}

void enkripsi(const char teks[], char hasil[]) {
    int len = panjangString(teks);
    if (len == 0) {
        hasil[0] = '\0';
        return;
    }

    char prev = '\0';
    for (int i = 0; i < len; i++) {
        char cur = teks[i];
        if (cekHuruf(cur)) {
            char capCur = toKapital(cur);
            if (prev == '\0') {
                hasil[i] = capCur;
            } else {
                int vCur = nilaiHuruf(capCur);
                int vPrev = nilaiHuruf(prev);
                int vBaru = ((vCur - 1 + vPrev) % 26) + 1;
                hasil[i] = hurufDariNilai(vBaru);
            }
            prev = capCur;
        } else {
            hasil[i] = cur;
        }
    }
    hasil[len] = '\0';
}

void dekripsi(const char sandi[], char hasil[]) {
    int len = panjangString(sandi);
    if (len == 0) {
        hasil[0] = '\0';
        return;
    }

    char prevAsli = '\0';
    for (int i = 0; i < len; i++) {
        char cur = sandi[i];
        if (cekHuruf(cur)) {
            char capCur = toKapital(cur);
            if (prevAsli == '\0') {
                hasil[i] = capCur;
                prevAsli = capCur;
            } else {
                int vCipher = nilaiHuruf(capCur);
                int vPrevAsli = nilaiHuruf(prevAsli);
                int diff = (vCipher - 1 - vPrevAsli) % 26;
                if (diff < 0) {
                    diff += 26;
                }
                char asli = hurufDariNilai(diff + 1);
                hasil[i] = asli;
                prevAsli = asli;
            }
        } else {
            hasil[i] = cur;
        }
    }
    hasil[len] = '\0';
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "        SISTEM SANDI ALIEN-IN-THE-MIDDLE            \n";
    std::cout << "====================================================\n";
    std::cout << "1. Enkripsi Pesan (Asli -> Sandi)\n";
    std::cout << "2. Dekripsi Pesan (Sandi -> Asli)\n";
    std::cout << "3. Simulasi Siklus Lengkap (Enkripsi -> Dekripsi Langsung)\n";
    std::cout << "Pilihan (1/2/3): ";

    int opsi;
    if (!(std::cin >> opsi)) {
        std::cout << "Input tidak valid!\n";
        return 1;
    }

    char input[512];
    char output[512];

    if (opsi == 1) {
        std::cout << "\nMasukkan teks asli: ";
        inputKalimat(input, 512);
        enkripsi(input, output);
        std::cout << "Hasil Teks Sandi  : " << output << "\n";
    } else if (opsi == 2) {
        std::cout << "\nMasukkan teks sandi: ";
        inputKalimat(input, 512);
        dekripsi(input, output);
        std::cout << "Hasil Teks Asli    : " << output << "\n";
    } else if (opsi == 3) {
        std::cout << "\nMasukkan teks uji bebas: ";
        inputKalimat(input, 512);

        if (input[0] == '\0') {
            const char defaultText[] = "ALIENS";
            int idx = 0;
            while (defaultText[idx] != '\0') {
                input[idx] = defaultText[idx];
                idx++;
            }
            input[idx] = '\0';
            std::cout << "(Input kosong, otomatis menggunakan default: ALIENS)\n";
        }

        char enc[512];
        char dec[512];

        enkripsi(input, enc);
        dekripsi(enc, dec);

        std::cout << "\n--- HASIL SIMULASI DUA ARAH ---\n";
        std::cout << "• Pesan Asli      : " << input << "\n";
        std::cout << "• Teks Tersandi   : " << enc << "\n";
        std::cout << "• Hasil Dekripsi  : " << dec << "\n";

        bool cocok = true;
        int len = panjangString(input);
        for (int i = 0; i < len; i++) {
            char c1 = input[i];
            char c2 = dec[i];
            if (cekHuruf(c1)) {
                c1 = toKapital(c1);
            }
            if (c1 != c2) {
                cocok = false;
                break;
            }
        }

        std::cout << "\nStatus Pengujian  : "
                  << (cocok ? "BERHASIL! (100% konsisten kembali ke pesan semula)" : "Terdapat ketidakcocokan karakter")
                  << "\n";
    } else {
        std::cout << "Pilihan tidak valid.\n";
    }
    std::cout << "====================================================\n";

    return 0;
}
