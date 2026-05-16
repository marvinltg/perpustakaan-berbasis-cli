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
	string peminjamanbuku;
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
void cekdata(string p); //fix
void hapusdata(string p);
void pengembalianbuku();
void riwayatpeminjaman();



//config program (db/logika)
User user[64];
Buku buku[64];
int totalregis = 0; //total register di struct
int totalbuku = 2;
bool run = true;
int menu;
int submenu;
int tanya;
int funcpilihan;
string query;

int main() {

	buku[0].judul = "kancil baik hati";
	buku[0].pengarang = "Rahimsyah";
	buku[0].rak = "2b Dongeng Lt.2";
	buku[0].stok = 2;

	buku[1].judul = "cara kaya diumur 20tahun";
	buku[1].pengarang = "Timothy";
	buku[1].rak = "21b Social Lt.2";
	buku[1].stok = 1;

	while (run) {

		cout << "========== LOGIN MENU ==========" << endl;
		cout << "1. Mahasiswa" << endl;
		cout << "2. Admin" << endl;
		cout << "0. Keluar" << endl;
		cout << "================================" << endl;
		cout << "Pilih Login : ";
		cin >> menu;
		cin.ignore();

		system("cls");

		if (menu == 1) {
			cout << "========== MENU MAHASISWA ==========" << endl;
			cout << "1. Registrasi Mahasiswa" << endl;
			cout << "2. Cek Buku yang tersedia" << endl;
			cout << "3. Pinjam Buku" << endl;
			cout << "4. Pengembalian Buku" << endl;
			cout << "0. Kembali" << endl;
			cout << "====================================" << endl;
			cout << "Pilih Menu : ";
			cin >> submenu;
			cin.ignore();

			switch (submenu) {
			case 1:
				system("cls");
				registrasi();
				break;
			case 2:
				system("cls");
				cekbuku();
				break;
			case 3:
				system("cls");
				pinjambuku();
				break;
			case 4:
				system("cls");
				pengembalianbuku();
				break;
			case 0:
				system("cls");
				break;
			default:
				cout << "Menu tidak valid!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		else if (menu == 2) {
			cout << "========== MENU ADMIN ==========" << endl;
			cout << "1. Cek Data Registrasi" << endl;
			cout << "2. Tambah Buku" << endl;
			cout << "3. Cek Data Buku" << endl;
			cout << "4. Hapus Data" << endl;
			cout << "0. Kembali" << endl;
			cout << "===============================" << endl;
			cout << "Pilih Menu : ";
			cin >> submenu;
			cin.ignore();

			switch (submenu) {
			case 1:
				system("cls");
				cekregistrasi();
				break;
			case 2:
				system("cls");
				tambahbuku();
				break;
			case 3:
				system("cls");
				cekbuku();
				break;
			case 4:
				system("cls");
				cout << "Masukan Data yang ingin dihapus (user/buku) : ";
				getline(cin, query);
				hapusdata(query);
				cekdata(query);
				system("pause");
				system("cls");
				break;
			case 0:
				system("cls");
				break;
			default:
				cout << "Menu tidak valid!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		else if (menu == 0) {
			run = false;
			cout << "Program selesai. Terima kasih!" << endl;
		}
		else {
			cout << "Pilihan login tidak valid!" << endl;
			system("pause");
			system("cls");
		}
	}
	

	return 0;
}


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
					cout << "Stok Buku tidak tersedia"<< endl;
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


void cekdata(string p) {
	int mode;
	cout << "\n========== Semua Data " << p << " Yang Ada ===========" << endl;
	if (p == "user") {
		mode = totalregis;
		for (int i = 0; i < mode; i++) {
			cout << "Nama : " << user[i].nama << endl;
			cout << "Kelas : " << user[i].kelas << endl;
			cout << "Jurusan : " << user[i].jurusan << endl;
			cout << "NIM : " << user[i].nim << endl << endl;
		}
		cout << "==================================================" << endl;
	}
	else if (p == "buku") {
		mode = totalbuku;
		for (int i = 0; i < mode; i++) {
			cout << "Judul Buku : " << buku[i].judul << endl;
			cout << "Pengarang Buku : " << buku[i].pengarang << endl;
			cout << "Tempat Buku berada : " << buku[i].rak << endl;
			cout << "Total Stok : " << buku[i].stok << endl << endl;
	
		}
		cout << "==================================================" << endl;
	}
	else {
		cout << "Jenis Tidak Valid!" << endl;
		clearterminal();
	}

	}


void hapusdata(string p) {
	string target;
	bool found = false;
	if (p == "user") {
		cout << "Masukan Nama Mahasiswa : ";
		getline(cin, target);
		//baris
		for (int i = 0; i < totalregis; i++) { 
			if (user[i].nama == target) {
				//kolom ke -> kiri 
				for (int j = 0; j < totalregis -1; j++) {
					user[j] = user[j + 1];
				}
				totalregis--;
				found = true;
			}
			if (!found) {
				cout << "User " << target << " Tidak Ditemukakn!"<<endl;
			}
		}
	}
	else if (p == "buku") {
		cout << "Masukan Judul Buku : ";
		for (int i = 0; i < totalbuku; i++) {
			if (buku[i].judul == target) {
				for (int j = 0; j < totalbuku; j++) {
					buku[j] = buku[j + 1];
				}
				totalbuku--;
				found = true;
			}
			if (!found) {
				cout << "Judul Buku " << target << " Tidak Ditemukakn!" << endl;
			}
		}
	}
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


void pengembalianbuku() {
	string judul;
	int jumlah;
	bool found = false;

	cout << "========== PENGEMBALIAN BUKU ==========" << endl;
	cout << "Masukan Judul Buku : ";
	getline(cin, judul);

	for (int i = 0; i < totalbuku; i++) {

		if (judul == buku[i].judul) {
			found = true;

			cout << "Judul Buku : " << buku[i].judul << endl;
			cout << "Stok Saat Ini : " << buku[i].stok << endl;

			cout << "Jumlah Buku Yang Dikembalikan : ";
			cin >> jumlah;

			buku[i].stok += jumlah;

			loading();

			cout << "Buku berhasil dikembalikan!" << endl;
			cout << "Total stok sekarang : " << buku[i].stok << endl;

			system("pause");
			system("cls");
			break;
		}
	}

	if (!found) {
		cout << "Judul Buku Tidak Ditemukan!" << endl;
		system("pause");
		system("cls");
	}
}



//biar bersih ocdringan soalnya :D
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

