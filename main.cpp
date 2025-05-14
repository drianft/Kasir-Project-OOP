#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>

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
            cout << "========== Inventori ==========" << endl;
            cout << setw(2) << id << setw(9) << nama << right << setw(15) << harga << endl;
            cout << "===============================" << endl;

            inventory();
        }

};

class Kasir{
    private:
        vector<Barang> dataBarang;
        string userName;
        string namaUser;
        int nextId = 1;
    public:
        Kasir(){}

        void inputBarang(){
            string pilih;
            do
            {
                cout << "Masukkan nama barang: ";
                string nama;
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan harga barang: ";
                long harga;
                cin >> harga;
                int id = nextId++;
                tambahBarang(id, nama, harga);
                cout << "Masih mau tambahin barang? ";
                cin >> pilih;
            } while (pilih == "ya");
            
        }

        void tambahBarang(int id, string nama, long harga){
            Barang barang(id, nama, harga);
            barang.cetakBarang();
            dataBarang.push_back(barang);
        }

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
            return false;
        }

        void gameAdmin(){
            string loop = "yes";
            int inp;
                    do{
                // cin.ignore();
                cout << "1. Tambah Item\n2. Hapus Item\n3. Cari Item\n4. Tampilkan Semua\nPilih: ";
                cin >> inp;
                switch (inp){
                    case 1:{
                    inputBarang();
                    
                    break;
                    }
                    case 2:{
                    cout << "Tambahin barang";
                    break;
                    }
                    case 3:{
                    cout << "";
                    break;
                    }
                    case 4:{
                    cout << "";
                    break;
                    }
                
                default:
                    break;
                }
            cout << "Continue? (yes/no) :";
            cin >> loop;
            }
            while (loop != "no");
            // x.inputInventory();
            // x.deleteItem();
            // x.searchItem();
        }

        void readInventory(){

        }

        void gameUser(){
            int pilihan;
            cout << "1. Tambahkan Barang Belanjaan\n2. Lihat isi Keranjang\n3. Checkout";
            cin >> pilihan;
            switch(pilihan){
                case 1:{
                    
                }
            }
        }

        void login(){
            cout << "Masukkan id atau nama lengkap kamu yang terdaftar: ";
            cin >> userName;
            if(isAdmin(userName)){
                cout << "Selamat datang, " << namaUser << endl;
                gameAdmin();
            }
            else{
                cout <<"Selamat datang, " << namaUser << endl;
                gameUser();
            }

        }
    };

class Transaksi{
    private:
        struct itemTransaksi{
            int id;
            string nama;
            long harga;
            int jumlah;
        };
        vector<itemTransaksi> keranjang;
        long totalHarga;
    public:
        void tambahKeranjang(int idBarang, const string& nama, long harga, int jumlah){
            
        }
        void tampilkanKeranjang(){}
        void checkout(){}

};



int main(){
    Kasir x;

    x.login();


    return 0;

}