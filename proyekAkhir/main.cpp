#include <iostream>
#include <string>
#include <vector>

struct Produk{
	std::string nama;
	float harga;
};

struct Pesanan{
	std::vector<Produk> isi;
};

Produk menuMakanan[1]; // ganti dengan jumlah produk dalam menu makanan
Produk menuMinuman[1]; // ganti dengan jumlah produk dalam menu makanan

std::string konversiKeRupiah(float nilai);
void tampilMenuMakanan();
void tampilMenuMinuman();

Pesanan mintaIsiPesanan();
float kalkulasiTotalHargaPesanan(Pesanan pesanan);
void tampilPesanan(Pesanan pesanan);
void tampilTotalHargaPesanan();


int main()
{
    return 0;
}


std::string konversiKeRupiah(float nilai)
{
    return ("Rp" + std::to_string(nilai));
}

void tampilMenuMakanan()
{

}

void tampilMenuMinuman()
{

}

Pesanan mintaIsiPesanan()
{
    Pesanan pesanan;
    return pesanan;
}

float kalkulasiTotalHargaPesanan(Pesanan pesanan)
{
    return (-1.0);
}

void tampilPesanan(Pesanan pesanan)
{

}

void tampilTotalHargaPesanan()
{

}
