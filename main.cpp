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
    public:
        Kasir(){}
        void login(){

        }
};


int main(){
    Barang b1(1, "Laptop", 200000000);

    b1.cetakBarang();
}