#ifndef PERPUS_LIB_H
#define PERPUS_LIB_H

#include <iostream>
#include <string>

using namespace std;

struct Buku {
    int idBuku;
    string namaBuku;
};

int linearSearch(Buku* daftar, int ukuran, string* target) {
    for (int i = 0; i < ukuran; i++) {
        if ((daftar + i)->namaBuku == *target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(Buku* daftar, int ukuran, int* targetID) {
    int awal = 0;
    int akhir = ukuran - 1;
    while (awal <= akhir) {
        int tengah = awal + (akhir - awal) / 2;
        if ((daftar + tengah)->idBuku == *targetID) {
            return tengah;
        }
        if ((daftar + tengah)->idBuku < *targetID) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    return -1;
}

#endif