#include <iostream>
#include <string>

using namespace std;

struct barang {
    string nama;
    string kode;
    float harga;
    int jumlah;
    barang* next; 
};

void input(barang*& head) {
    int jumlah;
    cout << "======================================" << endl;
    cout << "       INPUT STOK BARANG GUDANG       " << endl;
    cout << "======================================" << endl;
    cout << "Jumlah barang yang akan ditambahkan: ";
    cin >> jumlah;
    cout << endl;

    for (int i = 0; i < jumlah; i++) {
        barang* baru = new barang;
        cout << "Barang ke-" << i + 1 << endl;
        cout << "Nama Barang    : ";
        cin >> baru->nama;
        cout << "Harga Barang   : ";
        cin >> baru->harga;
        cout << "Kode Barang    : ";
        cin >> baru->kode;
        cout << "Jumlah Stok    : ";
        cin >> baru->jumlah;
        baru->next = head;
        head = baru;
        cout << endl;
    }
    cout << "Data barang berhasil ditambahkan" << endl;
    cout << endl;
}

void lihat(barang* head, bool urutharga) {
    if (head == nullptr) {
        cout << "Tidak ada barang dalam stok" << endl;
        return;
    }

    barang* arr[100];
    int gudang = 0;

    for (barang* temp = head; temp != nullptr; temp = temp->next) {
        arr[gudang++] = temp;
    }

    for (int i = 0; i < gudang - 1; i++) {
        for (int j = 0; j < gudang - i - 1; j++) {
            if ((urutharga && arr[j]->harga > arr[j + 1]->harga) || 
                (!urutharga && arr[j]->harga < arr[j + 1]->harga)) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "===============================================================================" << endl;
    cout << "|Kode          |Nama Barang                    |Harga          |Stok          |" << endl;
    cout << "===============================================================================" << endl;
    for (int i = 0; i < gudang; i++) {
        cout << "|" << arr[i]->kode << "          |" << arr[i]->nama << "          |" << arr[i]->harga << "          |" << arr[i]->jumlah << "          |" << endl;
    }
    cout << "===============================================================================" << endl;
}

void hapus(barang*& head) {
    string nama;
    cout << "Masukkan Nama Barang yang ingin dihapus: ";
    cin >> nama;

    barang* curr = head;
    barang* prev = nullptr;

    while (curr != nullptr && curr->nama != nama) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Barang tidak ditemukan" << endl;
        return;
    }

    if (prev == nullptr) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    cout << "Barang berhasil dihapus" << endl;
}

int main(){
    barang* head = nullptr;
    int pilih;

    do {
        cout << "================================" << endl;
        cout << "| SISTEM MANAJEMEN STOK GUDANG |" << endl;
        cout << "================================" << endl;
        cout << "| 1. Input Stok Barang         |" << endl;
        cout << "| 2. Lihat Daftar Stok         |" << endl;
        cout << "|    a. Termurah               |" << endl;
        cout << "|    b. Termahal               |" << endl;
        cout << "| 3. Hapus barang dari stok    |" << endl;
        cout << "| 4. Keluar                    |" << endl;
        cout << "================================" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;
        cout << endl;

        switch (pilih) {
            case 1:
                input(head);
                break;
            case 2: {
                char urutan;
                cout << "Pilih urutan (a/b): ";
                cin >> urutan;
                lihat(head, urutan == 'a');
                break;
            }
            case 3:
                hapus(head);
                break;
            case 4:
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
        }
    } while (pilih != 4);

    return 0;
}
