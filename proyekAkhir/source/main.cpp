#include <conio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;


/* Definisi makanan dan minuman */
struct Hidangan
{
	std::string jenis;
	int jumlah;
	int harga;
};


struct Pesanan
{
	std::string namaPemesan;
	int jumlah;
	std::vector<Hidangan> hidangan;
	float totalHarga;
	float uangDiberikan;
	float kembalian;
};


void tetapkanPosisiKursor(const int x, const int y);
void daftarMenu();
Pesanan mintaPesanan();
std::vector<Hidangan> mintaPesananHidangan(const int jumlah);
void buktiPemesanan();


int main()
{
	/*
	TODO:
	- Modularisasi setiap bagian program ini
	- Kemudahan skalabilitas jumlahMenu dan output jumlahMenu
	- Ganti setiap instansi 'endl' dengan '\n' (lebih bagus guna '\n' daripada 'endl' untuk efesiensi)
	*/

	char lagi;
	int jumlahMenu = 6, harga[10], porsi[10], bayar, kode;

	atas:
	system("cls");


	daftarMenu();
	Pesanan pesanan = mintaPesanan();
	pesanan.hidangan = mintaPesananHidangan(pesanan.jumlah);

	system("cls");

	cout << "                       Bukti Pemesanan Makanan                         " << endl;
	cout << "                    Kantin UPN VETERAN JAKARTA"                          << endl;
	cout << "                 Kampus Pondok Labu, Jakarta Selatan"					  << endl;
	cout << "=*********************************************************************=" << endl;
	cout << "Nama Pemesan  : " << pesanan.namaPemesan << '\n';
	cout << "=======================================================================" << endl;
	cout << "No.       Nama          Harga        Jumlah      Subtotal             "  << endl;
	cout << "          Makanan       Makanan      Pesan                            "  << endl;
	cout << "=======================================================================" << endl;

	/* v ini apaan v */
	//12345678901234567890123456789012345678901234567890123456789012345678901234567890
	//            1         2         3         4         5         6         7         8

	float totalHargaHidangan = 0;
	for(int indeksHidangan = 0; indeksHidangan < pesanan.jumlah; ++indeksHidangan)
	{
		tetapkanPosisiKursor(1, indeksHidangan + 10);
		cout << indeksHidangan + 1;
		tetapkanPosisiKursor(5, indeksHidangan + 10);
		cout << pesanan.hidangan[indeksHidangan].jenis;
		tetapkanPosisiKursor(25, indeksHidangan + 10);
		cout << pesanan.hidangan[indeksHidangan].harga;
		tetapkanPosisiKursor(39, indeksHidangan + 10);
		cout << pesanan.hidangan[indeksHidangan].jumlah;

		totalHargaHidangan = pesanan.hidangan[indeksHidangan].jumlah * pesanan.hidangan[indeksHidangan].harga;

		tetapkanPosisiKursor(51, indeksHidangan + 10);
		cout << totalHargaHidangan << '\n';

		pesanan.totalHarga += totalHargaHidangan;
	}

	cout << "\n====================================================================\n" << endl;
	cout << "                                Total Bayar     :Rp. " << pesanan.totalHarga << endl;
	cout << "                                Uang Bayar      :Rp. ";
	cin >> pesanan.uangDiberikan;

	pesanan.kembalian = pesanan.uangDiberikan - pesanan.totalHarga;

	cout << "                                Uang Kembali    :Rp. " << pesanan.kembalian << endl;
	cout << "_______________________________________________________________________ " << endl;
	cout << "======================================================================= " << endl;
	cout << "                               Terimakasih                              " << endl;
	cout << "======================================================================= " << endl;


	cout << "Input data lagi [Ya]/[Tidak]? jika iya tekan y/Y:";
	cin >> lagi;

	if(std::tolower(lagi) == 'y')
	{
		goto atas;
	}
	else
	{
		system("cls");
	}
}


/* Menetapkan posisi kursor dalam Windows */
void tetapkanPosisiKursor(const int x, const int y){
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}


void daftarMenu()
{
	cout	<< "                 DAFTAR MENU HARGA MAKANAN DAN MINUMAN\n"
			<< "                      Kantin UPN VETERAN JAKARTA\n"
			<< "                  Kampus Pondok Labu, Jakarta Selatan\n"
			<< "+*******************************************************************+\n"
			<< "|| MAKANAN :                       || MINUMAN :                    ||\n"
			<< "|| 1. Nasi Goreng       Rp.10000,- || 4. Es Teh          Rp.4000,- ||\n"
			<< "|| 2. Bakso             Rp.10000,- || 5. Jus Jeruk       Rp.7000,- ||\n"
			<< "|| 3. Mie Ayam          Rp.10000,- || 6. Cappucino       Rp.5000,- ||\n"
			<< "+*******************************************************************+\n";
}


Pesanan mintaPesanan()
{
	Pesanan pesanan;

	cout << "\nNama Pemesanan\t\t: ";
	cin >> pesanan.namaPemesan;
	cout << "Banyak Pesanan\t\t: ";
	cin >> pesanan.jumlah;

	return pesanan;
}


std::vector<Hidangan> mintaPesananHidangan(const int jumlah)
{
	std::vector<Hidangan> hidanganHidangan;
	Hidangan hidangan;
	int kodeHidangan;


	for(int hidanganKe = 1; hidanganKe <= jumlah; ++hidanganKe)
	{
		cout << "\n=******************=" << endl;
		cout << "Pesanan Ke " << hidanganKe << endl;
		cout << "=******************=\n" << endl;

		cout << "Masukkan Nomor Makanan/Minuman : ";
		cin >> kodeHidangan;
		cout << "Jumlah Pesan                   : ";
		cin>> hidangan.jumlah;



		/* Perlu referensi untuk jenis makakan dan harga */
		switch(kodeHidangan)
		{
			case 1: /* Nasi Goreng */
				hidangan.jenis =  "Nasi goreng";
				hidangan.harga = 10000;
				break;

			case 2: /* Bakso */
				hidangan.jenis = "Bakso";
				hidangan.harga  = 10000;
				break;

			case 3: /* Mie Ayam*/
				hidangan.jenis = "Mie Ayam";
				hidangan.harga = 10000;
				break;

			case 4: /* Es Teh */
				hidangan.jenis = "Es Teh";
				hidangan.harga  = 4000;
				break;

			case 5: /* Jus Jeruk */
				hidangan.jenis = "Jus Jeruk";
				hidangan.harga  = 7000;
				break;

			case 6: /* Cappucino */
				hidangan.jenis = "Cappucino";
				hidangan.harga  = 5000;
				break;

			default: /* Hidangan Tidak Ditemukan */
				cout << "Salah! Input Kode Lagi!\n";
				/* Untuk sementara belum ada error handle here */
		}

		hidanganHidangan.push_back(hidangan);
	}


	return hidanganHidangan;
}
