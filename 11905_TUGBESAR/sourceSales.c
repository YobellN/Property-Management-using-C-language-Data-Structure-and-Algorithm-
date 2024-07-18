#include "header.h"

DataSales makeDataSales(string nip, string notelp, string nama, float totalPenjualan){
	DataSales data;
	
	strcpy(data.nip, nip);
	strcpy(data.notelp, notelp);
	strcpy(data.nama, nama);
	data.totalPenjualan=totalPenjualan;
	strcpy(data.status, "Bekerja");
	
	return data;
}

AddressSales alokasiSales(DataSales data){
	AddressSales sales;
	
	sales=(AddressSales) malloc(sizeof(NodeSales));
	
	sales->next = NULL;
	sales->firstProperti = NULL;
	sales->dataSales = data;
	
	return sales;
}

AddressSales findSales(Multilist l, string nip){
	AddressSales temp = NULL;
	
	temp = l.firstSales;
	
	while(temp!=NULL){
		while(temp!=NULL){
			if(strcmp(temp->dataSales.nip, nip)==0){
				return temp;
			}
			temp=temp->next;
		}
		return NULL;
	}
}

AddressSales findSalesStatus(Multilist l, string nip, string status){
	AddressSales temp = NULL;
	
	temp = l.firstSales;
	
	while(temp!=NULL){
		while(temp!=NULL){
			if(strcmp(temp->dataSales.nip, nip)==0&&strcmpi(temp->dataSales.status,status)==0){
				return temp;
			}
			temp=temp->next;
		}
		return NULL;
	}
}

void insertFirstSales(Multilist *l, DataSales data){
	AddressSales temp = alokasiSales(data);
	
	temp->next = l->firstSales;
	l->firstSales=temp;
}

void insertAfterSales(Multilist *l, string nip, DataSales data){
	AddressSales dataBaru = alokasiSales(data);
	
	if(!isEmpty(*l)){
		AddressSales temp = findSales (*l, nip);
		
		if(temp!=NULL){
			dataBaru->next = temp->next;
			temp->next = dataBaru;
		}
	}
}


void insertLastSales(Multilist *l, DataSales data){
	AddressSales dataBaru = alokasiSales(data);
	
	if(isEmpty(*l)){
		insertFirstSales(l, data);
	}else{
		AddressSales temp = l->firstSales;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=dataBaru;
	}
}

void deleteFirstSales(Multilist *l){
	AddressSales temp = l->firstSales;
	
	if(!isEmpty(*l)){
		l->firstSales = l->firstSales->next;
		free(temp);
	}
}

void deleteAtSales(Multilist *l, string nip){
	AddressSales temp = l->firstSales;
	AddressSales prev = NULL;
	
	if(!isEmpty(*l)){
		if(strcmp(temp->dataSales.nip,nip)==0){
			deleteFirstSales(&(*l));
		}else{
			while (temp != NULL && strcmp(temp->dataSales.nip, nip) != 0) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL) {
                prev->next = temp->next;
                free(temp);
            }
		}
	}
}

void deleteAllProperti(AddressSales sales){
	AddressProperti temp;
	while(haveProperti(sales)){
		temp=sales->firstProperti;
		sales->firstProperti=sales->firstProperti->next;
		
		free(temp);
	}
}

void updateSales(Multilist *l, string nama, string notelp, AddressSales sales){

	if(!isEmpty(*l)){
		strcpy(sales->dataSales.nama, nama);
		strcpy(sales->dataSales.notelp, notelp);
	}
}

void printSales(AddressSales sales){
	printf("\n\t     === Data Sales ===");
	printf("\n\n\t[-] NIP              : %s", sales->dataSales.nip);
	printf("\n\t[-] Nama             : %s", sales->dataSales.nama);
	printf("\n\t[-] Nomor telepon    : %s", sales->dataSales.notelp);
	printf("\n\t[-] Total penjualan  : %.2f", sales->dataSales.totalPenjualan);
}

void printSalesUpdate(AddressSales sales, string nama, string notelp){
	printf("\t===================================================================");
	printf("\n\t\t\t\t  [Update Sales]");
	printf("\n\t===================================================================");
	printf("\n\n\t[-] NIP              : %s\t>>>     NIP              : %s", sales->dataSales.nip, sales->dataSales.nip);
	printf("\n\t[-] Nama             : %s\t>>>     Nama             : %s", sales->dataSales.nama,nama);
	printf("\n\t[-] Nomor telepon    : %s\t>>>     Nomor telepon    : %s", sales->dataSales.notelp,notelp);
	printf("\n\t[-] Total penjualan  : %.2f\t>>>     Total penjualan  : %.2f", sales->dataSales.totalPenjualan,sales->dataSales.totalPenjualan);
}

void printAllSales(Multilist l){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		printSales(temp);
		printf("\n");
		temp=temp->next;
	}
}

void printAll(Multilist l){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		printSales(temp);
		if(!haveProperti(temp)){
			printf("\n\t[-] Properti\t     : -\n");
		}else{
			printf("\n\t[-] Properti\t     :\n");
		}
		
		
		printAllProperti(temp);
		printf("\n");
		
		temp=temp->next;
	}
}

void printSalesStatus(Multilist l, string status){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		if(strcmpi(temp->dataSales.status,status)==0){
			printSales(temp);
			printf("\n");
		}
		temp=temp->next;
	}
}

void pindahProperti(AddressSales asal, AddressSales tujuan){
	AddressProperti proptujuan = tujuan->firstProperti;
	AddressProperti propasal = asal->firstProperti;
	
	if(tujuan->firstProperti==NULL){
		tujuan->firstProperti= propasal;
	}else{
		while(proptujuan->next!=NULL){
			proptujuan=proptujuan->next;
		}
		proptujuan->next=propasal;
	}
}

