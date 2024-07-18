
/*
Yobel Nugroho - 220711905
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

typedef char string[100];

typedef struct Properti*AddressProperti;
typedef struct Sales*AddressSales;

typedef struct DataProperti{
	string nomor;
	string jenis;
	string alamat;
	float harga;
}DataProperti;

typedef struct DataSales{
	string nip;
	string notelp;
	string nama;
	float totalPenjualan;
	string status;
}DataSales;

typedef struct Properti{
	DataProperti dataProperti;
	AddressProperti next;
}NodeProperti;

typedef struct Sales{
	DataSales dataSales;
	AddressSales next;
	
	AddressProperti firstProperti;
}NodeSales;

typedef struct{
	AddressSales firstSales;
}Multilist;

//source Parent (Sales)
DataSales makeDataSales(string nip, string notelp, string nama, float totalPenjualan);

void createEmpty(Multilist *l);

AddressSales alokasiSales(DataSales data);
AddressSales findSales(Multilist l, string nip);
AddressSales findSalesStatus(Multilist l, string nip, string status);

void insertFirstSales(Multilist *l, DataSales data);
void insertAfterSales(Multilist *l, string nip, DataSales data);
void insertLastSales(Multilist *l, DataSales data);

void deleteFirstSales(Multilist *l);
void deleteAtSales(Multilist *l, string nip);

void deleteAllProperti(AddressSales sales);

void printSales(AddressSales sales);
void printAll(Multilist l);
void printAllSales(Multilist l);
void printSalesStatus(Multilist l, string status);

void updateSales(Multilist *l, string nama, string notelp, AddressSales sales);
void printSalesUpdate(AddressSales sales, string nama, string notelp);

void pindahProperti(AddressSales asal, AddressSales tujuan);


//source Child (Properti)
DataProperti makeDataProperti(string nomor, string jenis, string alamat, float harga);

AddressProperti alokasiProperti(DataProperti data);
AddressProperti findProperti(AddressSales sales, string noprop);

void insertFirstProperti(Multilist l, string nip, DataProperti data);
void insertLastProperti(Multilist l, string nip, DataProperti data);

void deleteFirstProperti(Multilist l, string nip);
void deleteAtProperti(AddressSales sales, AddressProperti properti);

void printProperti(AddressProperti properti);
void printAllProperti(AddressSales sales);
void printUpdateProperti(AddressProperti properti, string jenis, string alamat, float harga);
void printHapusProperti(AddressProperti properti);
void printJenisProperti(AddressSales sales, string jenis);

void updateProperti(AddressProperti properti, string jenis, string alamat, float harga);

void jualProperti(AddressSales *sales, AddressProperti properti);

//Fungsi Umum
bool isEmpty(Multilist l);
bool hanyaSatuSales(Multilist l);
bool haveProperti(AddressSales sales);
bool cekProperti(Multilist l);
bool isUniqueProperti(Multilist l, string noprop);
bool isUnique(Multilist l, string nip);
bool isUniqueTelepon(Multilist l, string notelp);
bool cekDigit(string cek);
bool cekHuruf(string cek);
bool cekResign(Multilist l);
int hitungProperti(Multilist l, string jenis);
void loadingAnimation(int duration, int delay);
