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
void clearterminal();
void pinjambuku();// peminjaman buku
void bukti(string nama, string buku, int totbuku);
void lanjut(void ya());
int cekuser(string nama); //cek user

//config program (db/logika)
User user[64];
Buku buku[64];
int totalregis = 3; //total register di struct
int totalbuku = 2;
bool run = true;
int menu;
int submenu;
int tanya;
int funcpilihan;
string query;

int main() {

	buku[0].judul = "Pemuda Solo Yang Baik Hati";
	buku[0].pengarang = "Pria Oslo";
	buku[0].rak = "2b Sejarah Lt.2";
	buku[0].stok = 0;

	buku[1].judul = "Sejarah Rapper Lil bah";
	buku[1].pengarang = "Wobo Senja";
	buku[1].rak = "21b Social Lt.2";
	buku[1].stok = 1;

	user[0].nama = "Marvin Letunaung";
	user[0].jurusan = "Teknik Elektro";
	user[0].kelas = "2 teknik informatika 5";
	user[0].nim = 25024128;

	user[1].nama = "Christian Mandalika";
	user[1].jurusan = "Teknik Elektro";
	user[1].kelas = "2 teknik informatika 5";
	user[1].nim = 25024126;

	user[2].nama = "Jefrael Dalos";
	user[2].jurusan = "Teknik Elektro";
	user[2].kelas = "2 teknik informatika 5";
	user[2].nim = 25024127;

	while (run) {

	pinjambuku();
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
	string nama;
	string judulbuku;
	int totbuku;
	int index;
	int indexbuku;


	cout << "\nSelamat datang di menu peminjaman buku!" << endl;
	cout << "Masukan Nama : ";
	getline(cin, nama);

	index = cekuser(nama);

	if (index != -1) {
		cout << "Hallo " << nama << endl;
		cout << "Masukan Judul Buku : ";
		getline(cin, judulbuku);

		// cek buku
		indexbuku = -1;
		for (int i = 0; i < totalbuku; i++) {
			if (judulbuku == buku[i].judul) {
				indexbuku = i;
				cout << "=====================================" << endl;
				cout << "Judul Buku : " << buku[i].judul << endl;
				cout << "Pengarang Buku : " << buku[i].pengarang << endl;
				cout << "Tempat Buku berada : " << buku[i].rak << endl;
				cout << "Total Stok : " << buku[i].stok << endl;
				cout << "=====================================" << endl;
				break;
			}
		}

		if (indexbuku != -1) {

			while (true) {
				cout << "Jumlah Buku : ";
				cin >> totbuku;

				if (buku[indexbuku].stok <= 0) {
					cout << "Stok Buku sudah habis"<< endl;
					clearterminal();
					break;
				}

				if (totbuku <= buku[indexbuku].stok) {

					buku[indexbuku].stok -= totbuku;

					loading();
					cout << "Buku berhasil dipinjam!\n";

					bukti(nama, judulbuku, totbuku);
					break;
				}
				else {
					cout << "Stok Buku Tidak Cukup! Masukan ulang.\n";
				}
			}

			}
			else {
				cout << "Judul Buku Tidak Ditemukan!" << endl;
				clearterminal();
			}

		}
		else {
			cout << "User dengan Nama tersebut tidak ada!" << endl;
			clearterminal();
		}
	}



//bukti pinjam buku
void bukti(string nama, string buku, int totbuku) {
	cout << "======== BUKTI PEMINJAMAN BUKU =======" << endl;
	cout << "Nama :" << nama << endl;
	cout << "Judul Buku :" << buku << endl;
	cout << "Total Buku Yang diPinjam : " << totbuku << endl;
	cout << "======================================" << endl;
	system("pause");

}

//cekuser didb
int cekuser(string nama) {
	for (int i = 0; i <= totalregis; i++) {
		if (nama == user[i].nama) {
			return i;
		}
		
	}
	return -1;
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

void clearterminal() {
	cout << "clear";
	for (int i = 0; i <= 20; i++) {
		cout << "." << flush;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	system("cls");
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

