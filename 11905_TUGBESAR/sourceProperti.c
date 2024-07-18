#include "header.h"

DataProperti makeDataProperti(string nomor, string jenis, string alamat, float harga){
	DataProperti data;
	
	strcpy(data.nomor, nomor);
	strcpy(data.jenis, jenis);
	strcpy(data.alamat, alamat);
	data.harga=harga;
	
	return data;
}

AddressProperti alokasiProperti(DataProperti data){
	AddressProperti properti;
	properti=(AddressProperti) malloc(sizeof(NodeProperti));
	
	properti->next=NULL;
	properti->dataProperti=data;
	
	return properti;
}

AddressProperti findProperti(AddressSales sales, string noprop){
	AddressProperti temp = sales->firstProperti;
	
	while(temp!=NULL){
		if(strcmp(temp->dataProperti.nomor, noprop)==0){
				return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

void insertFirstProperti(Multilist l, string nip, DataProperti data){
	AddressSales sales = findSales(l, nip);
	
	if(sales!=NULL){
		AddressProperti dataBaru = alokasiProperti(data);
		dataBaru->next = sales->firstProperti;
		
		sales->firstProperti = dataBaru;
	}
}

void deleteFirstProperti(Multilist l, string nip){
	AddressSales sales = findSales(l, nip);
	
	if(sales!=NULL){
		if(haveProperti(sales)){
			AddressProperti temp = sales->firstProperti;
			sales->firstProperti = sales->firstProperti->next;
		
			free(temp);
		}
	}
}

void deleteAtProperti(AddressSales sales, AddressProperti properti){
	AddressProperti temp = sales->firstProperti;
	
	if (sales->firstProperti == properti) {
        
        sales->firstProperti = properti->next;
        free(properti);
        return;
    }	
		
	while (temp != NULL && temp->next != properti) {
        temp = temp->next;
    }
    
	temp->next = properti->next;
    free(properti);			
}

void printProperti(AddressProperti properti){
	printf("\n\t\t\t===  Data Properti ===\n");
	printf("\n\t\t[+] Nomor Properti       : %s", properti->dataProperti.nomor);
	printf("\n\t\t[+] Jenis                : %s", properti->dataProperti.jenis);
	printf("\n\t\t[+] Alamat               : %s", properti->dataProperti.alamat);
	printf("\n\t\t[+] Harga                : %.2f", properti->dataProperti.harga);
}

void printAllProperti(AddressSales sales){
	AddressProperti temp = sales->firstProperti;
	
	while(temp!=NULL){
			printProperti(temp);
			printf("\n");
			temp=temp->next;
	}
}

void printUpdateProperti(AddressProperti properti, string jenis, string alamat, float harga){
	printf("\n\t===  Data Properti ===\n");
	printf("\n[+] Nomor Properti       : %s", properti->dataProperti.nomor);
	printf("\n[+] Jenis                : %s", properti->dataProperti.jenis);
	printf("\n[+] Alamat               : %s", properti->dataProperti.alamat);
	printf("\n[+] Harga                : %.2f", properti->dataProperti.harga);
	printf("\n\t\t|||||");
	printf("\n\t\tVVVVV");
	printf("\n");
	printf("\n[+] Nomor Properti       : %s", properti->dataProperti.nomor);
	printf("\n[+] Jenis                : %s", jenis);
	printf("\n[+] Alamat               : %s", alamat);
	printf("\n[+] Harga                : %.2f",harga);
}

void printHapusProperti(AddressProperti properti){
	printf("\n\t\t===  Data Properti ===\n");
	printf("\n\t[+] Nomor Properti       : %s", properti->dataProperti.nomor);
	printf("\n\t[+] Jenis                : %s", properti->dataProperti.jenis);
	printf("\n\t[+] Alamat               : %s", properti->dataProperti.alamat);
	printf("\n\t[+] Harga                : %.2f", properti->dataProperti.harga);
}

void printJenisProperti(AddressSales sales, string jenis){
	AddressProperti temp = sales->firstProperti;
	
	while(temp!=NULL){
		if(strcmpi(temp->dataProperti.jenis,jenis)==0){
			printProperti(temp);
			printf("\n");
		}
		temp=temp->next;
	}
}

void updateProperti(AddressProperti properti, string jenis, string alamat, float harga){

	strcpy(properti->dataProperti.jenis, jenis);
	strcpy(properti->dataProperti.alamat, alamat);
	properti->dataProperti.harga=harga;
}

void jualProperti(AddressSales *sales, AddressProperti properti){
	AddressProperti temp = (*sales)->firstProperti;
	
	if ((*sales)->firstProperti == properti) {
        (*sales)->dataSales.totalPenjualan+=temp->dataProperti.harga;
        (*sales)->firstProperti = properti->next;
        free(properti);
        return;
    }	
		
	while (temp != NULL && temp->next != properti) {
        temp = temp->next;
    }
    (*sales)->dataSales.totalPenjualan+=temp->dataProperti.harga;
    
	temp->next = properti->next;
    free(properti);	
}

