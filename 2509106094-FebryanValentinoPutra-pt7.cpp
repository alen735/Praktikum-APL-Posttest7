#include <iostream>
#include <string>
#include <limits>
#include "perpus_lib.h" 

using namespace std;

void tampilkanHeader() {
    cout << "========================================" << endl;
    cout << "    Febryan Valentino_2509106094.     " << endl;
    cout << "========================================" << endl;
}

int main() {
    Buku inventaris[] = {
        {101, "Buku_Sejarah"},
        {105, "Buku_Cerpen"},
        {110, "Buku_Anak"},
        {120, "Buku_Novel"},
        {150, "Buku_Sains"}
    };
    int jumlahBuku = sizeof(inventaris) / sizeof(inventaris[0]);
    int pilihan;

    while (true) {
        tampilkanHeader();
        cout << " 1. Cari Nama (Linear Search)" << endl;
        cout << " 2. Cari ID (Binary Search)" << endl;
        cout << " 3. Keluar" << endl;
        cout << "----------------------------------------" << endl;
        cout << " Pilih Menu: ";

        try {
            if (!(cin >> pilihan)) {
                throw "Waduh, masukan harus angka ya!";
            }

            if (pilihan == 3) break;

            if (pilihan == 1) {
                string cariNama;
                cout << " Masukkan nama buku: ";
                cin >> cariNama;
                int hasil = linearSearch(inventaris, jumlahBuku, &cariNama);
                if (hasil != -1) 
                    cout << " [HASIL] Ditemukan! ID Buku: " << inventaris[hasil].idBuku << endl;
                else 
                    cout << " [HASIL] Judul buku tidak ditemukan." << endl;
            } 
            else if (pilihan == 2) {
                int cariID;
                cout << " Masukkan ID buku: ";
                if (!(cin >> cariID)) throw "ID Buku nggak boleh pakai huruf!";
                
                int hasil = binarySearch(inventaris, jumlahBuku, &cariID);
                if (hasil != -1) 
                    cout << " [HASIL] Nama bukunya: " << inventaris[hasil].namaBuku << endl;
                else 
                    cout << " [HASIL] ID tidak ada di sistem." << endl;
            } 
            else {
                throw pilihan;
            }

        } 
        catch (const char* pesanError) {
            cout << "\n [ERROR]: " << pesanError << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } 
        catch (int angkaInput) {
            cout << "\n [ERROR]: Pilihan " << angkaInput << " tidak valid!" << endl;
        }
        cout << endl;
    }

    cout << " Program selesai. Mantap Febryan!" << endl;
    return 0;
}