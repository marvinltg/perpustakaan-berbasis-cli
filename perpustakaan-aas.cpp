#include<iostream>
#include<fstream>
#include<chrono>
#include<thread>
#include<string>

using namespace std;

struct User {
	string nama;
	string kelas;
	string jurusan;
	int nim;
};

struct Buku {
	string judul;
	string pengarang;
	string rak;
	int stok;

};

//config funct
void registrasi(); //registrasi mahasiswa (selesai)
void cekregistrasi(); //cek apakah mahasiswa sudah mempunyai account (belum)
void tambahbuku(); //tambah buku ke database (belum)
void cekbuku(); //cek status buku (belum)
void loading(); //loading animasi (selesai)

//config db
User user[64];
Buku buku[64];
int totalregis = 0; //total register di struct
int totalbuku = 0;

int main() {

	registrasi();
	tambahbuku();
	cout << "\nTotal Register yang ada : " << totalregis << endl;
	cout << "Total Buku yang ada : " << totalbuku << endl;

	cekbuku();
	cekregistrasi();



	return 0;
};

//registrasi account
void registrasi() {

	cout << "====== REGISTRASI MENU =======" << endl;
	cin.ignore();
	cout << "Masukan Nama : ";
	getline(cin, user[totalregis].nama);
	cout << "Masukan Jurusan : ";
	getline(cin, user[totalregis].jurusan);
	cout << "Masukan Kelas : ";
	getline(cin, user[totalregis].kelas);
	cout << "Masukan NIM : ";
	cin >> user[totalregis].nim;
	totalregis++; //trigger +1
	loading();
	cout << "Berhasil Memasukan ke database!" << endl;
};


//cek registrasi funct
void cekregistrasi() {
	for (int i = 0; i < totalregis; i++) {
		cout << "\n====Data Registrasi ke - " << i + 1 << "====" << endl;
		cout << "Nama : " << user[i].nama << endl;
		cout << "Jurusan : " << user[i].jurusan << endl;
		cout << "Kelas : " << user[i].kelas << endl;
		cout << "NIM : " << user[i].nim << endl;
		cout << "=================================" << endl;
	}
};



//tambah buku kedatabase
void tambahbuku() {

	cout << "Welcome Admin!" << endl;
	cin.ignore();
	cout << "Masukan Judul Buku : ";
	getline(cin, buku[totalbuku].judul);
	cout << "Masukan Nama Pengarang : ";
	getline(cin, buku[totalbuku].pengarang);
	cout << "Tempat Buku diTaruh (RAK) : ";
	getline(cin, buku[totalbuku].rak);
	cout << "Masukan Jumlah Stok buku : ";
	cin >> buku[totalbuku].stok;
	totalbuku++;
	loading();
	cout << "Success memasukan buku ke database!" << endl;
};

//funct cek buku didatabase
void cekbuku() {
	for (int i = 0; i < totalbuku; i++) {
		cout << "\n====Data Buku ke - " << i + 1 << "====" << endl;
		cout << "Judul Buku : " << buku[i].judul << endl;
		cout << "Nama Pengarang Buku : " << buku[i].pengarang << endl;
		cout << "Tempat Buku : " << buku[i].rak << endl;
		cout << "Stok yang ada : " << buku[i].stok << endl;
		cout << "=================================" << endl;
	}

};


//loading func
void loading() {
	cout << "Processing";
	for (int i = 0; i <= 20; i++) {
		cout << "." << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	cout << endl;
};