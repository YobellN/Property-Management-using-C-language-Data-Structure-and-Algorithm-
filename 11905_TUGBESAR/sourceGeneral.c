#include "header.h"
void createEmpty(Multilist *l){
	l->firstSales = NULL;
}

bool isEmpty(Multilist l){
	return l.firstSales==NULL;
}

bool haveProperti(AddressSales sales){
	return sales->firstProperti != NULL;
}

bool hanyaSatuSales(Multilist l){
	return l.firstSales->next == NULL;
}

bool cekProperti(Multilist l){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		if(haveProperti(temp)){
			return true;
		}
		temp=temp->next;
	}
	return false;
}


bool isUnique(Multilist l, string nip){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		if(strcmp(temp->dataSales.nip,nip)==0){
			return false;
		}
		temp=temp->next;
	}
	return true;
}

bool isUniqueTelepon(Multilist l, string notelp){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		if(strcmp(temp->dataSales.notelp,notelp)==0){
			return false;
		}
		temp=temp->next;
	}
	return true;
}

bool isUniqueProperti(Multilist l, string noprop){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		AddressProperti temp2 = temp->firstProperti;
		while(temp2!=NULL){
			if(strcmp(temp2->dataProperti.nomor,noprop)==0){
				return false;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
	return true;
}

bool cekDigit(string cek){
	int panjang = strlen(cek);
	int i=0;
    while (i<panjang) {
        if (!isdigit(cek[i])) {
            return false;  
        }
        i++;
    }
    return true;  
}

bool cekHuruf(string cek){
	int panjang = strlen(cek);
	int i=0;
    while (i<panjang) {
        if (isdigit(cek[i])) {
            return false;  
        }
        i++;
    }
    return true;  
}

bool cekResign(Multilist l){
	AddressSales temp = l.firstSales;
	
	while(temp!=NULL){
		if(strcmpi(temp->dataSales.status,"Resign")==0){
			return true;
		}
		temp=temp->next;
	}
	return false;
}

int hitungProperti(Multilist l, string jenis){
	AddressSales temp = l.firstSales;
	int i=0;
	
	while(temp!=NULL){
		AddressProperti temp2 = temp->firstProperti;
		while(temp2!=NULL){
			if(strcmpi(temp2->dataProperti.jenis,jenis)==0){
				i++;
			}
			temp2=temp2->next;
		}
		temp=temp->next;
	}
	return i;
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void loadingAnimation(int duration, int delay) {
    int i;
	
	

    for (i = 0; i < 20; ++i) {
    	
        printf("%c", i % 4 == 0 ? '-' : (i % 4 == 1 ? '\\' : (i % 4 == 2 ? '|' : '/')));
        Sleep(delay);
        fflush(stdout);  

        
        printf("\b");
    }
	printf("\n\n\t\t\t\t\t");
    printf("Berhasil Masuk..!\n");

    // Introduce an additional delay at the end (optional)
    Sleep(duration);
}
