#include<iostream>
#include<fstream>
#include<chrono>
#include<thread>
#include<string>
#include<stdio.h> //buat clear output

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
void pinjambuku();// peminjaman buku
void lanjut(void ya());

//config program (db/logika)
User user[64];
Buku buku[64];
int totalregis = 0; //total register di struct
int totalbuku = 1;
bool run = true;
int menu;
int submenu;
int tanya;
int funcpilihan;



int main() {
	buku[0].judul = "Pemuda Solo Yang Baik Hati";
	buku[0].pengarang = "Pria Oslo";
	buku[0].rak = "2b Sejarah Lt.2";
	buku[0].stok = 200;

	while (run) {
		cout << "=============== MENU UTAMA ================" << endl;
		cout << "1. Menu Mahasiswa" << endl;
		cout << "2. Admin Perpustakaan" << endl;
		cout << "===========================================" << endl;
		cout << "Masukan Pilihan Mu : ";
		cin >> menu;

		system("cls"); //bersihkan output
		switch (menu) {
		case 1:
			cout << "Selamat Datang dimenu Mahasiswa!" << endl;
			cout << "1. Pembuatan Akun Perpustakaan" << endl;
			cout << "2. Cek Akun Anda" << endl;
			cout << "3. Peminjaman Buku" << endl;
			cout << "4. Pengembalian Buku" << endl;
			cout << "Masukan Pilihan kamu : ";
			cin >> submenu;
			system("cls"); //bersihkan output
			switch (submenu) {
			case 1:
				registrasi();
				break;
			case 2:
				cekregistrasi();
				break;
			case 3:
				cekbuku();
				break;

		}
	}
}
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
	cout << "Berhasil Registrasi Akun!" << endl << endl;
	
	lanjut(registrasi);

};


//cek registrasi funct
void cekregistrasi() {


	if (totalregis > 0) {
		for (int i = 0; i < totalregis; i++) {
			cout << "\n====Data Registrasi ke - " << i + 1 << "====" << endl;
			cout << "Nama : " << user[i].nama << endl;
			cout << "Jurusan : " << user[i].jurusan << endl;
			cout << "Kelas : " << user[i].kelas << endl;
			cout << "NIM : " << user[i].nim << endl;
			cout << "=================================" << endl;
		}
	} else {
		cout << "Data registrasi masih kosong!" << endl;
		}
	lanjut(cekregistrasi);
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
	lanjut(tambahbuku);
};

//funct cek buku didatabase
void cekbuku() {
	if (totalbuku > 0) {

		for (int i = 0; i < totalbuku; i++) {
			cout << "\n====Data Buku ke - " << i + 1 << " ====" << endl;
			cout << "Judul Buku : " << buku[i].judul << endl;
			cout << "Nama Pengarang Buku : " << buku[i].pengarang << endl;
			cout << "Tempat Buku : " << buku[i].rak << endl;
			cout << "Stok yang ada : " << buku[i].stok << endl;
			cout << "=================================" << endl;
		}
	}
	else {
		cout << "Data Buku DiPerpustakaan Masih Kosong!" << endl;
	}
	lanjut(cekbuku);

};

void pinjambuku() {
	cout << "Proses";
}


//loading func
void loading() {
	cout << "Processing";
	for (int i = 0; i <= 20; i++) {
		cout << "." << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	cout << endl;
};

//func lanjut atau tidak
void lanjut(void ya()) {
	cout << "Masih Mau Lanjut ? (1/0) : ";
	cin >> funcpilihan;
	if (funcpilihan == 1) {
		ya();
	}
	system("cls");
}