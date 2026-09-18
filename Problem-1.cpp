#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan N: ";
    cin >> N;
    cout << "Masukkan K: ";
    cin >> K;

    if (N <= 0) {
        cout << "Error: N harus lebih dari 0." << endl;
        return 0;
    }

    if (K < 2) {
        cout << "Error: K minimal adalah 2." << endl;
        return 0;
    }

    if (K > N) {
        cout << "Error: K tidak boleh lebih besar dari N." << endl;
        return 0;
    }

    bool *hidup = new bool[N + 1];

    for (int i = 1; i <= N; i++) {
        hidup[i] = true;
    }

    int jumlah = N;
    int posisi = 1;

    while (jumlah > 1) {

        int hitung = 0;
        
        while (hitung < K) {

            if (hidup[posisi] == true) {
                hitung++;
            }

            if (hitung < K) {
                posisi++;

                if (posisi > N) {
                    posisi = 1;
                }
            }
        }

        cout << "Astronot ke-" << posisi << " dieliminasi" << endl;

        hidup[posisi] = false;
        jumlah--;
    
        if (posisi % 2 == 0) {
            K = K + 2;
        }
        else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }

        posisi++;

        if (posisi > N) {
            posisi = 1;
        }

        while (hidup[posisi] == false) {
            posisi++;

            if (posisi > N) {
                posisi = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (hidup[i] == true) {
            cout << "Astronot terakhir: " << i << endl;
            break;
        }
    }
    delete[] hidup;

    return 0;
}