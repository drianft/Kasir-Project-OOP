#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Barang{
    private:
        int id;
        string nama;
        long harga;
        
    public:
        Barang(int id, string nama, long harga){
            this->nama=nama;
            this->id=id;
            this->harga=harga;
        }

        void inventory(){
            ofstream file("inventory.txt", ios::app);
            if(file.is_open()){
                file << id << " " << nama << " " << harga << endl;
                file.close();
                cout << "Barang berhasil ditambahkan ke file. " << endl;
            }
            else{
                cout << "Gagal membuka file" << endl;
            }
        }

        //Cetak list file barang yg ada di file TXT setelah ditambahkan
        void cetakBarang(){
            cout << id << endl
                << nama << endl
                << harga << endl;

            inventory();
        }

};

class Kasir{
    private:
        vector<Barang> dataBarang;
        string userName;
        string namaUser;
    public:
        Kasir(){}

        bool isAdmin(string id){
            this->userName=id;

            ifstream file("akun.txt");
            string line;
            while(getline(file, line)){
                int batas = line.find("|");
                if(batas != string::npos){
                    string idKasir = line.substr(0, batas);
                    string namaKasir = line.substr(batas + 1);

                    if(idKasir == id||namaKasir == id){
                        namaUser = namaKasir;
                        return true;
                    }
                }
            }
            return false
        }

        void gameAdmin(){
            cout << "1. Lihat Stok Barang" << endl;
            cout << "2. Tambahkan Barang" << endl;
        }

        void login(){
            cout << "Masukkan id atau nama lengkap kamu yang terdaftar: ";
            cin >> userName;
            if(isAdmin(userName)){
                cout << "Selamat datang, " << namaUser << endl;
                gameAdmin();
            }


};


int main(){
    Barang b1(1, "Laptop", 200000000);

    b1.cetakBarang();
}