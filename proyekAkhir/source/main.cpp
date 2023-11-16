#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

/* Menetapkan posisi kursor dalam Windows */
void tetapkanPosisiKursor(int x, int y){
	COORD koordinat;
	koordinat.X = x;
	koordinat.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

int main()
{
	/*
	TODO:
	- Modularisasi setiap bagian program ini
	- Kemudahan skalabilitas menu dan output menu 
	- Ganti setiap instansi 'endl' dengan '\n' (lebih bagus guna '\n' daripada 'endl' untuk efesiensi)
	*/
	
	char nama[10], lagi;
	string jenis[10];
	int a, menu, harga[10], porsi[10], bayar, kode;
	float totalharga, total, uang, kembalian;

	atas:
	system("cls");
	
	cout << "                 DAFTAR MENU HARGA MAKANAN DAN MINUMAN"<< endl;
	cout << "                      Kantin UPN VETERAN JAKARTA" << endl;
	cout << "                  Kampus Pondok Labu, Jakarta Selatan"<< endl;
	cout << "+*******************************************************************+" << endl;
	cout << "|| MAKANAN :                       || MINUMAN :                    || \n";
	cout << "|| 1. Nasi Goreng       Rp.10000,- || 4. Es Teh          Rp.4000,- || \n";
	cout << "|| 2. Bakso             Rp.10000,- || 5. Jus Jeruk       Rp.7000,- || \n";
	cout << "|| 3. Mie Ayam          Rp.10000,- || 6. Cappucino       Rp.5000,- || \n";
	cout << "+*******************************************************************+" << endl;

	cout << "\nNama Pemesanan          : "; 
	cin >> nama;
	cout << "\nBanyak Pesanan           : "; 
	cin >> menu;
	
	for(a = 1; a <= menu; ++a)
	{
		cout << "\n=******************=" << endl;
		cout << "Pesanan Ke " <<a << endl;
		cout << "=******************=\n" << endl;
		
		cout << "Masukkan Nomor Makanan/Minuman : ";
		cin >> kode;
		cout << "Jumlah Pesan                   : ";
		cin >> porsi[a];

		if (kode==1)
		{
			cout << "Nasi goreng\n";
			jenis[a] =  "Nasi goreng";
			harga[a] = 10000;
		}
		else if (kode == 2)
		{
			jenis[a] = "Bakso";
			harga[a] = 10000;
		}
		else if (kode == 3)
		{
			jenis[a] = "Mie Ayam";
			harga[a] = 10000;
		}
		else if (kode == 4)
		{
			jenis[a] = "Es Teh";
			harga[a] = 4000;
		}
		else if (kode == 5)
		{
			jenis[a] = "Jus Jeruk";
			harga[a] = 7000;
		}
		else if (kode == 6)
		{
			jenis[a] = "Cappucino";
			harga[a] = 5000;
		}
		else
		{
			cout << "Salah!!,Input Kode Lagi!!" << endl; /* OoO - oh no */
			goto atas;
		}
	}
	
	system("cls");
	
	cout << "                       Bukti Pemesanan Makanan                         " << endl;
	cout << "                    Kantin UPN VETERAN JAKARTA"                          << endl;
	cout << "                 Kampus Pondok Labu, Jakarta Selatan"					  << endl;
	cout << "=*********************************************************************=" << endl;
	cout << "Nama Pemesan  : " << nama << endl;
	cout << "=======================================================================" << endl;
	cout << "No.       Nama          Harga        Jumlah      Subtotal             "  << endl;
	cout << "          Makanan       Makanan      Pesan                            "  << endl;
	cout << "=======================================================================" << endl;
	
	/* v ini apaan v */
	//12345678901234567890123456789012345678901234567890123456789012345678901234567890
	//            1         2         3         4         5         6         7         8
	
	totalharga = 0;
	for(a = 1; a <= menu; ++a)
	{
		tetapkanPosisiKursor(1, a + 10); 
		cout << a;
		tetapkanPosisiKursor(5, a + 10);  
		cout << jenis[a];
		tetapkanPosisiKursor(25, a + 10); 
		cout << harga[a];
		tetapkanPosisiKursor(39, a + 10); 
		cout << porsi[a];
		
		total = porsi[a] * harga[a];
		
		tetapkanPosisiKursor(51,a + 10); 
		cout << total;
		cout << endl;
		
		totalharga = totalharga + total;
	}
	
	cout << "\n====================================================================\n" << endl;
	cout << "                                Total Bayar     :Rp. " << totalharga << endl;
	cout << "                                Uang Bayar      :Rp. ";
	cin >> uang;
	
	kembalian = uang - totalharga;
	
	cout << "                                Uang Kembali    :Rp. " << kembalian << endl;
	cout << "_______________________________________________________________________ " << endl;
	cout << "======================================================================= " << endl;
	cout << "                               Terimakasih                              " << endl;
	cout << "======================================================================= " << endl;


	cout<<"Input data lagi [Ya]/[Tidak]? jika iya tekan y/Y:";
	cin>>lagi;
	
	if(lagi=='Y'||lagi=='y')
	{
		goto atas;
	}
	else
	{
		system("cls");
	}
}
