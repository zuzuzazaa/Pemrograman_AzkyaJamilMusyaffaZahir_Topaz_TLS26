#include <iostream>
using namespace std;

int main() {
    char pesan[100];
    char hasil[100];

    cout << "Masukkan pesan (huruf kapital): ";
    cin >> pesan;

    int i = 0;
    while (pesan[i] != '\0') {
        i++;
    }

    int panjang = i;

    if (panjang == 0) {
        cout << "Pesan tidak boleh kosong." << endl;
        return 0;
    }

    hasil[0] = pesan[0];

    for (i = 1; i < panjang; i++) {

        int nilaiSekarang = pesan[i] - 'A' + 1;
        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

        int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

        while (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }
    
        hasil[i] = 'A' + nilaiBaru - 1;
    }
    hasil[panjang] = '\0';
    cout << "Pesan asli   : " << pesan << endl;
    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}