#include <cctype>
#include <conio.h>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

const string PEMBATAS_HORISONTAL = string(89, '-');
const int PANJANG_MAKSIMUM_NAMA_HIDANGAN = 25;
const int PANJANG_MAKSIMUM_HARGA_HIDANGAN = 12;
const int PANJANG_MAKSIMUM_TAMPILAN_HIDANGAN =
	PANJANG_MAKSIMUM_NAMA_HIDANGAN + PANJANG_MAKSIMUM_HARGA_HIDANGAN;

/* Struktur data untuk menyimpan informasi hidangan dalam menu */
class HidanganMenu {
	public:
		string nama;
		float harga;

		HidanganMenu(const string& namaHidangan = "", const float hargaHidangan = 0)
		: nama(namaHidangan), harga(hargaHidangan) {}
};

/* Struktur data untuk menyimpan pesanan pelanggan untuk satu hidangan */
class PesananHidangan {
	public:
		HidanganMenu hidangan;
		int jumlah;
		float total = 0;

		void kalkulasiTotal();
};

/* Struktur data untuk menyimpan pesanan pelanggan */
class Pesanan
{
	public:
		string namaPemesan;
		vector<PesananHidangan> pesananHidangan;
		float total = 0;
		float pembayaran;
		float kembalian;

		void kalkulasiTotal();
		void kalkulasiKembalian();
};

/* Struktur data untuk menyimpan menu restoran */
class Menu {
	public:
		vector<HidanganMenu> makanan;
		vector<HidanganMenu> minuman;
};


void tetapkanPosisiKursor(const int x, const int y);
template <typename tipeData>
	void inputDenganKondisi(
		tipeData* nilai,
		const string& pesanInput,
		const string& pesanError,
		const function<bool(tipeData)> kondisi
	);

std::string konversiKeRupiah(const float nilai);
void tampilHidanganMenu(HidanganMenu hidangan);
void tampilMenu(const Menu menu);

Pesanan ambilPesanan(const Menu menu);
PesananHidangan ambilPesananHidangan(const Menu menu);
void tampilBuktiPesanan(Pesanan pesanan);


int main() {
	/* Inisialisasi menu */
	Menu menu;
	menu.makanan = {
		HidanganMenu("Ayam Goreng Cabe Ijo", 15000),
		HidanganMenu("Ayam Bakar", 17000),
		HidanganMenu("Ayam Crispy Dada", 12000),
		HidanganMenu("Ayam Crispy Paha Atas", 15000),
		HidanganMenu("Ayam Crispy Sayap", 8000),
		HidanganMenu("Ayam Crispy Paha Bawah", 8000),
		HidanganMenu("Ayam Crispy Saus Keju", 18000),
		HidanganMenu("Ayam Crispy Sambel Pedas", 18000),
		HidanganMenu("Ayam Geprek", 17000),
		HidanganMenu("Lele Goreng", 12000),
		HidanganMenu("Lele Crispy", 12000),
		HidanganMenu("Nasi Goreng", 20000),
		HidanganMenu("Mie Gacoan", 15000),
		HidanganMenu("Pempek", 20000),
		HidanganMenu("Tahu", 5000),
		HidanganMenu("Tempe", 5000),
		HidanganMenu("Telur Crispy", 8000),
		HidanganMenu("Nasi Putih", 5000),
		HidanganMenu("Sambal Ijo", 3000),
		HidanganMenu("Sambal Geprek", 3000),
		HidanganMenu("Mie Instan Soto Ayam", 6000),
		HidanganMenu("Mie Instan Kari Ayam", 6000),
		HidanganMenu("Mie Instan Ayam Bawang", 6000),
		HidanganMenu("Mie Instan Kaldu Ayam", 6000),
		HidanganMenu("Mie Instan Goreng", 6000),
		HidanganMenu("Mie Instan Rendang", 6000),
		HidanganMenu("Mie Instan Kriuk", 6000),
		HidanganMenu("Mie Instan Super Pedas", 6000),
		HidanganMenu("Telur Ceplok", 3000),
		HidanganMenu("Telur Dadar", 3000),
		HidanganMenu("Kornet", 5000),
		HidanganMenu("Sosis", 5000)
	};

	menu.minuman = {
		HidanganMenu("Kopi Hitam", 15000),
		HidanganMenu("Kopi Vietnam", 15000),
		HidanganMenu("Kopi Dalgona", 10000),
		HidanganMenu("Cappucino", 15000),
		HidanganMenu("Americano", 15000),
		HidanganMenu("Espresso", 15000),
		HidanganMenu("Jus Mangga", 10000),
		HidanganMenu("Jus Jeruk", 10000),
		HidanganMenu("Jus Alpukat", 20000),
		HidanganMenu("Es Teh Manis", 5000),
		HidanganMenu("Es Teh Leci", 15000),
		HidanganMenu("Es Teh Strawberry", 15000),
		HidanganMenu("Es Teh Mangga", 15000),
		HidanganMenu("Es Teh Lemon", 15000),
		HidanganMenu("Cafe Latte", 15000),
		HidanganMenu("Matcha Latte", 16000),
		HidanganMenu("Caramel Latte", 17000),
		HidanganMenu("Hazelnut Latte", 17000),
		HidanganMenu("Mocha Latte", 19000),
		HidanganMenu("Vanilla Latte", 19000),
		HidanganMenu("Matcha", 18000),
		HidanganMenu("Taro", 18000),
		HidanganMenu("Red Velvet", 18000),
		HidanganMenu("Cookies and Cream", 18000),
		HidanganMenu("Charcoal", 18000),
		HidanganMenu("Vanilla Manggo", 18000),
		HidanganMenu("Chocolate Vanilla", 20000),
		HidanganMenu("Ice Cream Cone", 5000),
		HidanganMenu("Ice Cream Waffle", 8000),
		HidanganMenu("Ice Cream Sundae", 12000),
		HidanganMenu("Air Mineral", 5000),
		HidanganMenu("Jus Sirsak", 10000)
	};

	/* Inisialisasi pengulangan program */
    char ulang;
    atas: /* label untuk perintah goto */

    system("cls");
    tampilMenu(menu);
    std::cout << '\n';

    Pesanan pesanan = ambilPesanan(menu);
    system("cls");

    tampilBuktiPesanan(pesanan);
    std::cout << "\n\n";

    std::cout << "Input data lagi [Y]/[N]? ";
    std::cin >> ulang;
    if (tolower(ulang) == 'y') {
        goto atas;
    } else {
        system("cls");
    }

    return 0;
}


/*
   Fungsi untuk mengkalkulasi total harga suatu pesanan hidangan
   yang merupakan hasil dari perkalian harga hidangan dengan jumlah pesanan.
*/
void PesananHidangan::kalkulasiTotal() {
	total = hidangan.harga * jumlah;
}


/*
   Fungsi untuk mengkalkulasi total harga keseluruhan pesanan
   dengan menjumlahkan total harga masing-masing pesanan hidangan.
*/
void Pesanan::kalkulasiTotal() {
	for (size_t indeks = 0; indeks < pesananHidangan.size(); ++indeks) {
		total += pesananHidangan[indeks].total;
	}
}


/*
   Fungsi untuk mengkalkulasi uang kembalian dari suatu pesanan
   dengan mengurangkan total harga pesanan dari jumlah uang pembayaran.
*/
void Pesanan::kalkulasiKembalian() {
	kembalian = pembayaran - total;
}


/* Menetapkan posisi kursor dalam Windows */
void tetapkanPosisiKursor(const int x, const int y) {
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}


/* Fungsi untuk meminta input dengan kondisi tertentu */
template <typename tipeData>
	void inputDenganKondisi(
		tipeData* nilai,
		const string& pesanInput,
		const string& pesanError,
		const function<bool(tipeData)> kondisi
	) {
		while (true) {
			cout << pesanInput;
			if ((cin >> *nilai) && kondisi(*nilai)) {
				break; /* Jika input memenuhi kondisi, keluar dari pengulangan */
			} else {
				cout << pesanError << "\n";
				cin.clear(); /* Bersihkan buffer input untuk mengembalikan cin ke kondisi yang dapat digunakan */
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* Abaikan input terakhir */
			}
		}
	}


/* Fungsi untuk mengkonversi nilai float apapun ke format mata uang Rupiah */
std::string konversiKeRupiah(const float nilai) {
	std::stringstream stringStream;
    stringStream 	<< "Rp. "
					<< nilai
					<< ",--";
    return stringStream.str();
}


/* Fungsi untuk menampilkan sebuah hidangan dalam menu (nama dan harga) */
void tampilHidanganMenu(HidanganMenu hidangan) {
	string hargaRupiah = konversiKeRupiah(hidangan.harga);
	cout 	<< setw(PANJANG_MAKSIMUM_NAMA_HIDANGAN)
			<< left << hidangan.nama
			<< setw(PANJANG_MAKSIMUM_HARGA_HIDANGAN)
			<< hargaRupiah;
}


/* Fungsi untuk menampilkan menu makanan dan minuman */
void tampilMenu(const Menu menu) {
	cout << "                 DAFTAR MENU HARGA MAKANAN DAN MINUMAN\n"
	     << "                      Kantin UPN VETERAN JAKARTA\n"
	     << "                  Kampus Pondok Labu, Jakarta Selatan\n"
	     << PEMBATAS_HORISONTAL
	     << "\n|                 MAKANAN                   |                  MINUMAN                  |\n"
	     << "| " << string(PANJANG_MAKSIMUM_TAMPILAN_HIDANGAN + 4, ' ')
	     << " | " << string(PANJANG_MAKSIMUM_TAMPILAN_HIDANGAN + 4, ' ') << " |\n";

	/* Menghitung panjang menu makanan dan minuman */
    const size_t panjangMenuMakanan = menu.makanan.size();
    const size_t panjangMenuMinuman = menu.minuman.size();
    const size_t panjangMenuMaksimum = std::max(panjangMenuMakanan, panjangMenuMinuman);

    /* Menampilkan setiap hidangan makanan dan minuman dalam menu */
	for (size_t indeks = 0; indeks < panjangMenuMaksimum; ++indeks) {
		cout << "| ";

		/* Tampil hidangan makanan */
		if (indeks < panjangMenuMakanan) {
			cout << setw(2) << (indeks + 1) << ". ";
			tampilHidanganMenu(menu.makanan[indeks]);
		} else {
			cout << string(PANJANG_MAKSIMUM_TAMPILAN_HIDANGAN + 4, ' ');
		}

		cout << " | ";

		/* Tampil hidangan minuman */
		if (indeks < panjangMenuMinuman) {
			cout << setw(2) << (panjangMenuMakanan + indeks + 1) << ". ";
			tampilHidanganMenu(menu.minuman[indeks]);
		} else {
			cout << string(PANJANG_MAKSIMUM_TAMPILAN_HIDANGAN + 4, ' ');
		}

		cout << " |\n";
	}

	cout << PEMBATAS_HORISONTAL << "\n";
}


/* Fungsi untuk mengambil pesanan dari pelanggan */
Pesanan ambilPesanan(const Menu menu) {
	/* Deklarasi pesanan */
	Pesanan pesanan;

	/* Meminta nama pemesan */
	int jumlahPesananHidangan;

	cout << PEMBATAS_HORISONTAL
	     << "\nNama Pemesan\t\t: ";
	cin >> pesanan.namaPemesan;

	/* Validasi input untuk jumlah pesanan hidangan */
	auto isIntegerPositif = []( int nilai ) -> bool { return nilai > 0; };
	inputDenganKondisi(
		&jumlahPesananHidangan,
		"Banyak Pesanan\t\t: ",
		"Input tidak benar. Tolong input integer positif!\n",
		function<bool(int)>(isIntegerPositif)
	);

	cout 	<< PEMBATAS_HORISONTAL << "\n\n";

	/* Meminta hidangan apa yang dipesan dan berapa */
	for (int indeks = 0; indeks < jumlahPesananHidangan; ++indeks) {
		cout << PEMBATAS_HORISONTAL
		     << "\nPesanan Ke-" << indeks << "\n";
		pesanan.pesananHidangan.push_back(ambilPesananHidangan(menu));
		cout << PEMBATAS_HORISONTAL;
	}

	return pesanan;
}


/* Fungsi untuk mengambil pesanan hidangan */
PesananHidangan ambilPesananHidangan(const Menu menu) {
	/* Inisialisasi pesanan hidangan */
	PesananHidangan pesananHidangan;
	int kodeHidangan;

	/* Menghitung panjang menu makanan dan minuman */
	const size_t panjangMenuMakanan = menu.makanan.size();
	const size_t panjangMenuMinuman = menu.minuman.size();
	const size_t panjangMenu = panjangMenuMakanan + panjangMenuMinuman;

	/* Validasi input untuk hidangan yang ingin dipesan */
	auto isKodeHidangan = [panjangMenu](int kode) -> bool {
		return (
			(kode > 0) &&
			(kode < (panjangMenu + 1))
		);
	};
	inputDenganKondisi(
		&kodeHidangan,
		"Masukkan Nomor Makanan/Minuman : ",
		"Input tidak benar. Tolong input angka daftar dari menu!\n",
		function<bool(int)>(isKodeHidangan)
	);

	/* Validasi input untuk jumlah porsi hidangan yang ingin dipesan */
	auto isIntegerPositif = []( int nilai ) -> bool { return nilai > 0; };
	inputDenganKondisi(
		&(pesananHidangan.jumlah),
		"Jumlah Pesan                   : ",
		"Input tidak benar. Tolong input integer positif!\n",
		function<bool(int)>(isIntegerPositif)
	);

	/* Menyetor hidangan yang dipilih ke dalam pesanan hidangan */
	if (kodeHidangan > panjangMenuMakanan) { /* Hidangan Minuman */
		pesananHidangan.hidangan = menu.minuman[kodeHidangan - 1 - panjangMenuMakanan];
	} else { /* Hidangan Makanan */
		pesananHidangan.hidangan = menu.makanan[kodeHidangan - 1];
	}

	return pesananHidangan;
}


/* Fungsi untuk menampilkan bukti pesanan */
void tampilBuktiPesanan(Pesanan pesanan) {
	/* Inisialiasasi */
	float totalHargaHidangan = 0;

	cout << "                       Bukti Pemesanan Makanan"
	     << "\n                    Kantin UPN VETERAN JAKARTA"
	     << "\n                 Kampus Pondok Labu, Jakarta Selatan"
	     << "\n" << PEMBATAS_HORISONTAL
	     << "\nNama Pemesan  : " << pesanan.namaPemesan
	     << "\n" << PEMBATAS_HORISONTAL
	     << "\nNo.       Nama          Harga        Jumlah      Subtotal             "
	     << "\n          Makanan       Makanan      Pesan                            "
	     << "\n" << PEMBATAS_HORISONTAL;

	for (
		int indeks = 0;
		indeks < static_cast<int>(pesanan.pesananHidangan.size());
		++indeks
	) {
		tetapkanPosisiKursor(1, indeks + 10);
		cout << indeks + 1;
		tetapkanPosisiKursor(5, indeks + 10);
		cout << pesanan.pesananHidangan[indeks].hidangan.nama;
		tetapkanPosisiKursor(5 + PANJANG_MAKSIMUM_NAMA_HIDANGAN, indeks + 10);
		cout << pesanan.pesananHidangan[indeks].hidangan.harga;
		tetapkanPosisiKursor(
			5 +
			PANJANG_MAKSIMUM_NAMA_HIDANGAN +
			PANJANG_MAKSIMUM_HARGA_HIDANGAN,
			indeks + 10
		);
		cout << pesanan.pesananHidangan[indeks].jumlah;

		/* Menghitung total harga pesanan untuk suatu hidangan */
		pesanan.pesananHidangan[indeks].kalkulasiTotal();

		tetapkanPosisiKursor(51, indeks + 10);
		cout << pesanan.pesananHidangan[indeks].total << '\n';
	}

	/* Menghitung total harga pesanan secara keseluruhan */
	pesanan.kalkulasiTotal();

	cout 	<< "\n" << PEMBATAS_HORISONTAL
			<< "\n                                Total Bayar     :Rp. "
			<< pesanan.total << '\n';

	/* Validasi nilai uang pembayaran */
	while (true) {
		cout << "                                Uang Bayar      :Rp. ";
        if (
			(cin >> pesanan.pembayaran) &&
			(pesanan.pembayaran > 0)
		) {
            break; /* Jika input valid, keluar dari while */
        } else {
            cout << "Input tidak benar. Tolong input integer positif!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    /* Menghitung uang kembalian dari pesanan */
	pesanan.kalkulasiKembalian();

	cout 	<< "                                Uang Kembali    :Rp. "
			<< pesanan.kembalian
			<< "\n" << PEMBATAS_HORISONTAL
			<< "\n" << PEMBATAS_HORISONTAL
			<< "\n                               Terimakasih                             "
			<< "\n" << PEMBATAS_HORISONTAL;
}
