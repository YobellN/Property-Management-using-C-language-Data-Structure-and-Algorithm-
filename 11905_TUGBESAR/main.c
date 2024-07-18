#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char menu, submenu=1, subsubmenu;
	string username, nip, nama, notelp, temp, confirm, noprop, jenis, alamat, password;
	int cek=0, cek2=0;
	float harga;
	Multilist l;
	AddressSales sales;
	
	createEmpty(&l);

	do{
		system("color E4"); 
		system("cls");
		printf("\n\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
		printf("\n\t\t\t\t\t Perusahaan RealEstate XYZ\n");
		printf("\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
		printf("\n\n\t\t\t1. Masuk Sebagai Owner "); 
		printf("\n\n\t\t\t2. Masuk Sebagai Sales ");
		printf("\n\n\t\t\t>>> ");menu=getche();
		switch(menu){
			//MENU OWNER
			case '1':
				//Username : OwnerXYZ Password : OwnerXYZ
				
				system("cls");
				printf("\n\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
				printf("\n\t\t\t\t\t     Login Sebagai Owner\n");
				printf("\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
				printf("\n\n\t\t\t Masukkan Username     : ");fflush(stdin);gets(username);
				while(strcmp(username,"OwnerXYZ")!=0){
					printf("\n\n\t\t\t\t [!] Username Salah");
					printf("\n\n\t\t\t Masukkan Username     : ");fflush(stdin);gets(username);
				}
				printf("\n\n\t\t\t Masukan Password      : ");fflush(stdin);gets(password);
				while(strcmp(password,"OwnerXYZ")!=0){
					printf("\n\n\t\t\t\t [!] Password Salah");
					printf("\n\n\t\t\t Masukan Password      : ");fflush(stdin);gets(password);
				}
				printf("\n\n\t\t\t\t\t");
   				printf("Loading ");loadingAnimation(1000,100);
				do{
					system("color E5"); 
					cek=0;
					system("cls");
                    printf("===========================================\n");
                    printf("\t\t    Owner\n");
                    printf("===========================================\n");

                    printf("===========================================\n");
                    printf("\t\t Menu Sales\n");
                    printf("===========================================\n");
                    printf("[1] Kontak Sales\n");
                    printf("[2] Edit Sales\n");
                    printf("[3] Laporan Pengunduran Diri\n");

                    printf("===========================================\n");
                    printf("\t\tMenu Properti\n");
                    printf("===========================================\n");
                    printf("[4] Terima Properti\n");
                    printf("[5] Edit Properti\n");
                    printf("[6] Hapus Properti\n");

                    printf("===========================================\n");
                    printf("\t\t Menu Laporan\n");
                    printf("===========================================\n");
                    printf("[7] Tampil Semua Sales dan Propertinya\n");
                    printf("[8] Tampil Properti yang Belum Terjual\n");
                    printf("[9] Jumlah Properti Berdasarkan Jenisnya\n");
                    printf("===========================================\n");
                    printf("[0] Kembali ke Menu Login");
					
					printf("\n\n>> ");submenu=getche();
					
					switch(submenu){
						//KONTAK SALES
						case '1':
							do{
								system("cls");
								printf("===========================================");
                                printf("\n\t       [KONTAK SALES]");
                                printf("\n===========================================");
                                printf("\n\nMasukan nip sales\t    : ");fflush(stdin);gets(nip);
								while(strlen(nip)!=5||strcmp(nip,"")==0||strcmp(nip,"-")==0||!isUnique(l,nip)||!cekDigit(nip)){
									if(strcmp(nip,"")==0||strcmp(nip,"-")==0){
										printf("\n\t [!] NIP tidak boleh kosong atau - ");
										printf("\n\nMasukan nip sales\t    : ");fflush(stdin);gets(nip);
									}else if(strlen(nip)<5){
										printf("\n\t [!] NIP harus 5 digit");
										printf("\n\nMasukan nip sales\t    : ");fflush(stdin);gets(nip);
									}else if(!cekDigit(nip)){
										printf("\n\t [!] NIP harus berupa angka");
										printf("\n\nMasukan nip sales\t    : ");fflush(stdin);gets(nip);
									}else{
										printf("\n\t [!] NIP sudah terdaftar");
										printf("\n\nMasukan nip sales\t    : ");fflush(stdin);gets(nip);
									}
								}
								printf("\nMasukan nama sales\t    : ");fflush(stdin);gets(nama);
								while(strcmp(nama,"")==0||strcmp(nama,"-")==0||!cekHuruf(nama)||nama[0]<'A'||nama[0]>'Z'){
									if(!cekHuruf(nama)){
										printf("\n\t[!] Nama harus berupa huruf");
										printf("\n\nMasukan nama sales\t    : ");fflush(stdin);gets(nama);
									}else if(strcmp(nama,"")==0||strcmp(nama,"-")==0){
										printf("\n\t[!] Nama tidak boleh kosong atau - ");
										printf("\n\nMasukan nama sales\t    : ");fflush(stdin);gets(nama);
									}else{
										printf("\n\t[!] Nama harus diawali dengan huruf kapital");
										printf("\n\nMasukan nama sales\t    : ");fflush(stdin);gets(nama);
									}
								}
								printf("\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
								while(strcmp(notelp,"")==0||strcmp(notelp,"-")==0||!cekDigit(notelp)||strlen(notelp)<5||notelp[0]!='0'||!isUniqueTelepon(l,notelp)){
									if(!cekDigit(notelp)){
										printf("\n\t[!] Nomor telepon harus berupa angka");
										printf("\n\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
									}else if(strcmp(notelp,"")==0||strcmp(notelp,"-")==0){
										printf("\n\t[!] Nomor telepon tidak boleh kosong atau - ");
										printf("\n\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
									}else if(strlen(notelp)<5){
										printf("\n\t[!] Nomor telepon minimal 5 digit");
										printf("\n\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
									}else if(!isUniqueTelepon(l,notelp)){
										printf("\n\t[!] Nomor telepon sudah digunakan oleh sales lain");
										printf("\n\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
									}else{
										printf("\n\t[!] Nomor telepon harus diawali dengan 0");
										printf("\n\nMasukan nomor telepon sales : ");fflush(stdin);gets(notelp);
									}
								}
								do{
									system("cls");
									printf("===========================================");
                                	printf("\n\t      [Masukan Data]");
                                	printf("\n===========================================\n");
									printf("\n[1] Pada bagian awal");
									printf("\n[2] Setelah data sales tertentu");
									printf("\n[3] Pada bagian akhir");
									printf("\n\n>> ");subsubmenu=getche();
									switch(subsubmenu){
										case '1':
											insertFirstSales(&l,makeDataSales(nip,notelp,nama,0.0));
											printf("\n\t[+] Data sales dimasukkan pada bagian awal");
											cek2=1;
											cek=1;
										break;
										
										case '2':
											printf("\nMasukan data setelah sales dengan nip : ");fflush(stdin);gets(temp);
											if(findSales(l,temp)==NULL){
												printf("\n\t[!] Sales dengan nip %s tidak ditemukan",temp);
											}else{
												insertAfterSales(&l,temp,makeDataSales(nip,notelp,nama,0.0));
												printf("\n\t[+] Data sales dimasukkan setelah sales dengan nip %s",temp);
												cek2=1;
												cek=1;
											}
										break;
						
										case '3':
											insertLastSales(&l,makeDataSales(nip,notelp,nama,0.0));
											printf("\n\t[+] Data sales dimasukkan pada bagian akhir");
											cek2=1;
											cek=1;
										break;
										
										default:
											printf("\n\t[!] Pilihan Tidak Tersedia");
										break;
									}getch();
								}while(cek2!=1);
								cek2=0;
								printf("\n\t[+] Berhasil kontak sales");
							}while(cek!=1);
						break;
						
						//EDIT SALES
						case '2':
							if(isEmpty(l)){
								printf("\n\t[!] Data sales masih kosong");
							}else{
								do{
									system("cls");
									printf("===========================================");
                                	printf("\n\t       [Edit Sales]");
                                	printf("\n===========================================");
									printf("\n\nMasukan NIP sales yang ingin di-edit : ");fflush(stdin);gets(nip);
									if(findSales(l,nip)==NULL){
										printf("\n\t[!] Sales dengan nip %s tidak ditemukan",nip);
										cek=1;
									}else{
										sales=findSales(l,nip);
										system("cls");
										printf("===========================================");
										printf("\n\t       [Edit Sales]");
										printf("\n===========================================");
	                                	printSales(findSales(l,nip));
	                                	printf("\n===========================================\n");
										printf("\nMasukan nama sales yang baru\t      : ");fflush(stdin);gets(nama);
										while(strcmp(nama,"")==0||strcmp(nama,"-")==0||!cekHuruf(nama)||nama[0]<'A'||nama[0]>'Z'||strcmp(sales->dataSales.nama,nama)==0){
											if(!cekHuruf(nama)){
												printf("\n\t[!] Nama harus berupa huruf");
												printf("\n\nMasukan nama sales yang baru\t      : ");fflush(stdin);gets(nama);
											}else if(strcmp(nama,"")==0||strcmp(nama,"-")==0){
												printf("\n\t[!] Nama tidak boleh kosong atau - ");
												printf("\n\nMasukan nama sales yang baru\t      : ");fflush(stdin);gets(nama);
											}else if(nama[0]<'A'||nama[0]>'Z'){
												printf("\n\t[!] Nama harus diawali dengan huruf kapital");
												printf("\n\nMasukan nama sales yang baru\t      : ");fflush(stdin);gets(nama);
											}else{
												printf("\n\t[!] Nama baru tidak boleh sama");
												printf("\n\nMasukan nama sales yang baru\t      : ");fflush(stdin);gets(nama);
											}
										}
										printf("\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
										while(strcmp(notelp,"")==0||strcmp(notelp,"-")==0||!cekDigit(notelp)||strlen(notelp)<5||notelp[0]!='0'||!isUniqueTelepon(l,notelp)||strcmp(sales->dataSales.notelp,notelp)==0){
											if(!cekDigit(notelp)){
												printf("\n\t[!] Nomor telepon harus berupa angka");
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}else if(strcmp(notelp,"")==0||strcmp(notelp,"-")==0){
												printf("\n\t[!] Nomor telepon tidak boleh kosong atau - ");
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}else if(strlen(notelp)<5){
												printf("\n\t[!] Nomor telepon minimal 5 digit");
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}else if(strcmp(sales->dataSales.notelp,notelp)==0){
												printf("\n\t[!] Nomor telepon baru tidak boleh sama");
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}else if(notelp[0]!='0'){
												printf("\n\t[!] Nomor telepon harus diawali dengan 0");
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}else{
												printf("\n\t[!] Nomor telepon sudah digunakan oleh sales lain");		
												printf("\n\nMasukan nomor telepon sales yang baru : ");fflush(stdin);gets(notelp);
											}
										}
										system("cls");
										printSalesUpdate(findSales(l,nip),nama,notelp);
										printf("\n\n\tApakah Anda ingin mengupdate sales? [yes/no] : ");fflush(stdin);gets(confirm);
										if(strcmpi(confirm,"Yes")==0){
											updateSales(&l,nama,notelp,findSales(l,nip));
											printf("\n\t[+]Berhasil update sales");
											printf("\n\t[~]Kembali ke menu utama...");
										}else{
											printf("\n\t[-]Gagal update sales");
											printf("\n\t[~]Kembali ke menu utama...");
										}
										getch();
										cek=1;
									}
								}while(cek!=1);	
							}							
						break;
						
						case '3':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini tidak ada sales yang bekerja");
							}else if(!cekResign(l)){
								printf("\n\t[!] Saat ini tidak ada sales yang mengundurkan diri");
							}else{
								system("cls");
								printf("===========================================");
                                printf("\n\t [Daftar Sales yang Resign]");
                                printf("\n===========================================\n");
								printSalesStatus(l,"Resign");
								printf("\nMasukkan nip sales yang ingin dipindah propertinya :  ");fflush(stdin);gets(temp);
								if(findSalesStatus(l,temp,"Resign")==NULL){
									printf("\n\t[!] NIP sales tidak ditemukan");
									break;
								}else{
									system("cls");
									printf("===========================================");
	                                printf("\n\t [Pindah Tanggungan Properti]");
	                                printf("\n===========================================\n");
	                                if(hanyaSatuSales(l)){
										printf("\n[!] Tidak ada sales lain yang dapat menerima properti");
										break;
									}else{
										printf("\t\t[Daftar Sales Lain]");
										printSalesStatus(l,"Bekerja");
										printf("\nMasukkan nip sales yang ingin diberi tanggungan properti : ");fflush(stdin);gets(nip);
										if(findSalesStatus(l,nip,"Bekerja")==NULL){
											printf("\n\t[!] NIP sales tidak ditemukan");
											break;
										}else{
											pindahProperti(findSales(l,temp),findSales(l,nip));
											
											deleteAtSales(&l,temp);
											printf("\n\t[*] Berhasil pindah properti");
										}
									}						
								}
							}
						break;
						
						case '4':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini belum bisa menerima properti karena tidak ada sales yang bekerja");
							}else{
								do{
									system("cls");
									printf("===========================================");
                                	printf("\n\t     [Terima Properti]");
                                	printf("\n===========================================\n");
									printf("\nMasukan nomor properti\t\t     : ");fflush(stdin);gets(noprop);
									while(strcmp(noprop,"")==0||strcmp(noprop,"-")==0||!cekDigit(noprop)||!isUniqueProperti(l,noprop)){
										if(strcmp(noprop,"")==0||strcmp(noprop,"-")==0){
											printf("\n\t[!] Nomor properti tidak boleh kosong atau -");
											printf("\n\nMasukan nomor properti\t\t     : ");fflush(stdin);gets(noprop);
										}else if(!cekDigit(noprop)){
											printf("\n\t[!] Nomor properti harus berupa angka");
											printf("\n\nMasukan nomor properti\t\t     : ");fflush(stdin);gets(noprop);						
										}else{
											printf("\n\t[!] Nomor properti sudah terdaftar");
											printf("\n\nMasukan nomor properti\t\t     : ");fflush(stdin);gets(noprop);	
										}
									}
									printf("\nMasukan jenis proporti (tanah/rumah) : ");fflush(stdin);gets(jenis);
									while(strcmpi(jenis,"Tanah")!=0&&strcmpi(jenis,"Rumah")!=0){
										printf("\n\t[!] Jenis properti hanya boleh 'Tanah' atau 'Rumah'");
										printf("\n\nMasukan jenis proporti (tanah/rumah) : ");fflush(stdin);gets(jenis);
									}
									printf("\nMasukan alamat properti\t\t     : ");fflush(stdin);gets(alamat);
									while(strcmp(alamat,"")==0||strcmp(alamat,"-")==0){
										printf("\n\t[!] Alamat properti tidak boleh kosong");
										printf("\n\nMasukan alamat properti\t\t     : ");fflush(stdin);gets(alamat);
									}
									printf("\nMasukan harga properti\t\t     : ");scanf("%f",&harga);
									while(harga<300000){
										printf("\n\t[!] Harga properti tidak boleh kurang dari Rp. 300000");
										printf("\n\nMasukan harga properti\t\t     : Rp. ");scanf("%f",&harga);
									}
									system("cls");
									printf("===========================================");
                                	printf("\n\t       [Daftar Sales]");
                                	printf("\n===========================================\n");
									printAllSales(l);
									printf("\nMasukan nip sales yang akan menjual properti : ");fflush(stdin);gets(nip);
									while(findSales(l,nip)==NULL){
										printf("\n\t[!] Sales dengan nip %s tidak ditemukan",nip);
										printf("\nMasukan nip sales yang akan menjual properti : ");fflush(stdin);gets(nip);
									}
									insertFirstProperti(l,nip,makeDataProperti(noprop,jenis,alamat,harga));
									printf("\n\t[+]Berhasil menambahkan properti kepada sales %s",nip);
									printf("\n\t[~]Kembali ke menu utama....");
									cek=1;
								}while(cek!=1);
							}
							
						break;
						
						case '5':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini belum bisa mengedit properti karena tidak ada sales yang bekerja");
							}else if(!cekProperti(l)){
								printf("\n\t[!] Saat ini belum terdapat properti yang bisa diedit");
							}else{
								system("cls");
								printf("===========================================");
                               	printf("\n\t      [Edit Properti]");
                               	printf("\n===========================================\n");
								printf("\nMasukan NIP sales yang ingin diedit propertinya : ");fflush(stdin);gets(nip);
								if(findSales(l,nip)==NULL){
									printf("\n\t[!] Sales dengan nip %s tidak ditemukan",temp);
									break;
								}else{
									if(!haveProperti(findSales(l,nip))){
										printf("\n\t[!] Sales dengan nip %s tidak mempunyai tanggungan properti",findSales(l,nip));
									}else{
										system("cls");
										printf("===========================================");
		                               	printf("\n\t      [Edit Properti]");
		                               	printf("\n===========================================\n");
										printSales(findSales(l,nip));
										printf("\n\t[*] Daftar Tanggungan Properti Sales %s [*]\n",findSales(l,nip));
										printAllProperti(findSales(l,nip));
										printf("\nMasukan nomor properti yang ingin diedit : ");fflush(stdin);gets(noprop);
										while(findProperti(findSales(l,nip),noprop)==NULL){
											printf("\n\t[!] Properti dengan nomor %s tidak ditemukan pada sales %s",noprop,nip);
											printf("\n\nMasukan nomor properti yang ingin diedit : ");fflush(stdin);gets(noprop);
										}
										printf("\nMasukan jenis proporti (tanah/rumah) : ");fflush(stdin);gets(jenis);
										while(strcmpi(jenis,"Tanah")!=0&&strcmpi(jenis,"Rumah")!=0){
											printf("\n\t[!] Jenis properti hanya boleh 'Tanah' atau 'Rumah'");
											printf("\n\nMasukan jenis proporti (tanah/rumah) : ");fflush(stdin);gets(jenis);
										}
										printf("\nMasukan alamat properti\t\t     : ");fflush(stdin);gets(alamat);
										while(strcmp(alamat,"")==0||strcmp(alamat,"-")==0){
											printf("\n\t[!] Alamat properti tidak boleh kosong");
											printf("\n\nMasukan alamat properti\t\t     : ");fflush(stdin);gets(alamat);
										}
										printf("\nMasukan harga properti\t\t     : ");scanf("%f",&harga);
										while(harga<300000){
											printf("\n\t[!] Harga properti tidak boleh kurang dari Rp. 300000");
											printf("\n\nMasukan harga properti\t\t     : Rp. ");scanf("%f",&harga);
										}
										system("cls");
										printf("===========================================");
		                               	printf("\n\t      [Edit Properti]");
		                               	printf("\n===========================================\n");
										printUpdateProperti(findProperti(findSales(l,nip),noprop),jenis,alamat,harga);
										printf("\n\nApakah Anda ingin mengupdate properti? [yes/no] : ");fflush(stdin);gets(confirm);
										if(strcmpi(confirm,"Yes")==0){
											updateProperti(findProperti(findSales(l,nip),noprop), jenis, alamat, harga);
											printf("\n\t[+]Berhasil update properti");
											printf("\n\t[~]Kembali ke menu utama...");
										}else{
											printf("\n\t[-]Gagal update properti");
											printf("\n\t[~]Kembali ke menu utama...");
										}
									}								
								}									
							}
						break;
						
						case '6':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini belum bisa menghapus properti karena tidak ada sales yang bekerja");
							}else if(!cekProperti(l)){
								printf("\n\t[!] Saat ini belum terdapat properti yang bisa dihapus");
							}else{
								system("cls");
								printf("===========================================");
                               	printf("\n\t     [Hapus Properti]");
                               	printf("\n===========================================\n");
								printf("\nMasukan NIP sales yang ingin dihapus propertinya : ");fflush(stdin);gets(nip);
								if(findSales(l,nip)==NULL){
									printf("\n\t[!] Sales dengan nip %s tidak ditemukan",nip);
									break;
								}else{
									if(!haveProperti(findSales(l,nip))){
										printf("\n\t[+] Sales dengan nip %s tidak mempunyai tanggungan properti",findSales(l,nip));
									}else{
										system("cls");
										printf("===========================================");
		                               	printf("\n\t     [Hapus Properti]");
		                               	printf("\n===========================================\n");
										printSales(findSales(l,nip));
										printf("\n\n\t[*] Daftar Tanggungan Properti Sales %s [*]\n",findSales(l,nip));
										printAllProperti(findSales(l,nip));
										printf("\n\tMasukan nomor properti yang ingin dihapus : ");fflush(stdin);gets(noprop);
										while(findProperti(findSales(l,nip),noprop)==NULL){
											printf("\n\t[!] Properti dengan nomor %s tidak ditemukan pada sales %s",noprop,nip);
											printf("\n\tMasukan nomor properti yang ingin dihapus : ");fflush(stdin);gets(noprop);
										}
										system("cls");
										
										printf("===================================================================");
										printf("\n\t\t\t  [Hapus Properti]");
										printf("\n===================================================================\n");
		                               	
										printHapusProperti(findProperti(findSales(l,nip),noprop));
										printf("\n\nApakah Anda ingin menghapus properti? [yes/no] : ");fflush(stdin);gets(confirm);
										if(strcmpi(confirm,"Yes")==0){
											deleteAtProperti(findSales(l,nip),findProperti(findSales(l,nip),noprop));
											printf("\n\t[+]Berhasil menghapus properti");
											printf("\n\t[~]Kembali ke menu utama...");
										}else{
											printf("\n\t[-]Gagal menghapus properti");
											printf("\n\t[~]Kembali ke menu utama...");
										}
									}
				
								}
							}
						break;
							
						case '7':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini tidak ada sales atau properti yang terdata");
							}else{
								system("cls");
								printf("===========================================");
                                printf("\n\t[Tampil Sales dan Properti]");
                                printf("\n===========================================\n");
								printAll(l);
							}
						break;
						
						case '8':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini tidak ada sales atau properti yang terdata");
							}else{
								system("cls");
								printf("===========================================");
                                printf("\n\t     [Tampil Data Properti]");
                                printf("\n===========================================\n");
								printf("\nMasukan NIP sales yang ingin dilihat propertinya : ");fflush(stdin);gets(nip);
								if(findSales(l,nip)==NULL){
									printf("\n\t[!] Sales dengan nip %s tidak ditemukan",temp);
									break;
								}else{
									if(!haveProperti(findSales(l,nip))){
										printf("\n\t[+] Sales dengan nip %s tidak mempunyai tanggungan properti",findSales(l,nip));
									}else{
										printf("\nTampil properti berdasarkan jenisnya (tanah/rumah) : ");fflush(stdin);gets(jenis);
										while(strcmpi(jenis,"Tanah")!=0&&strcmpi(jenis,"Rumah")!=0){
											printf("\n\t[!] Jenis properti hanya boleh 'Tanah' atau 'Rumah'");
											printf("\nTampil properti berdasarkan jenisnya (tanah/rumah) : ");fflush(stdin);gets(jenis);
										}
										system("cls");
										printf("===================================================================");
										printf("\n\tTampil Data Properti Sales %s dengan Jenis %s",nip,jenis);
										printf("\n===================================================================\n");
										printJenisProperti(findSales(l,nip),jenis);
									}
								}
							}
						break;
						
						case '9':
							if(isEmpty(l)){
								printf("\n\t[!] Saat ini tidak ada sales atau properti yang terdata");
							}else{
								system("cls");
								printf("===========================================");
                                printf("\n\t     [Jumlah Properti]");
                                printf("\n===========================================\n");
								
								printf("\nTerdapat sebanyak %d properti dengan jenis Tanah",hitungProperti(l,"Tanah"));
								printf("\nTerdapat sebanyak %d properti dengan jenis Rumah",hitungProperti(l,"Rumah"));
							}
						break;
						
						case '0':
							printf("\n\t[~] Kembali ke menu login....");
						break;
						
						default:
							printf("\n\t[!] Menu tidak ada");
						break;
						
					}getch();
				}while(submenu!='0');
			break;
			
			//MENU SALES
			case '2':
				if(isEmpty(l)){
					printf("\n\n\t\t\t\t[!] Saat ini belum terdapat sales yang bekerja");
				}else{
					system("cls");
					printf("\n\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
					printf("\n\t\t\t\t\t     Login Sebagai Sales\n");
					printf("\n\t\t\t===== ===== ===== ===== ===== ===== ===== ===== ===== =====\n");
					printf("\n\n\t\t\t Masukkan NIP     : ");fflush(stdin);gets(nip);
					while(findSales(l,nip)==NULL){
						printf("\n\n\t\t\t[!] NIP Sales tidak ditemukan");
						printf("\n\n\t\t\t Masukkan NIP      : ");fflush(stdin);gets(nip);
					}
					printf("\n\n\t\t\t Masukan Password : ");fflush(stdin);gets(password);
					while(strcmp(password,nip)!=0){
						printf("\n\n\t\t\t\t [!] Password Salah");
						printf("\n\n\t\t\t Masukan Password : ");fflush(stdin);gets(password);
					}
					printf("\n\n\t\t\t\t\t");
   					printf("Loading ");loadingAnimation(1000,100);
					sales = findSales(l,nip);
					do{
						system("color E5"); 
						cek=0;
						system("cls");
						printf("===========================================\n");
					    printf("\tSelamat Datang  %s\n",sales->dataSales.nama);
					    printf("\n\tNIP\t\t: %s",sales->dataSales.nip);
					    printf("\n\tNomor Telepon\t: %s",sales->dataSales.notelp);
					    printf("\n\tTotal Penjualan\t: %.2f",sales->dataSales.totalPenjualan);
					    printf("\n===========================================\n");
					    printf("===========================================\n");
	                    printf("\t\t Menu Utama \n");
	                    printf("===========================================\n");
						printf("[1] Tampil Properti\n");
					    printf("[2] Jual Properti\n");
					    printf("[3] Ajukan Resign\n");
					    printf("===========================================\n");
					  	printf("[0] Kembali ke Menu Login");
						printf("\n\n>> ");submenu=getche();
						
						switch(submenu){
							case '1':
								if(!haveProperti(sales)){
									printf("\n\t[!] Saat ini belum ada tanggungan properti");
								}else{
									system("cls");
									printf("\t\t===========================================");
	                                printf("\n\t\t\t  [Tampil Data Properti]");
	                                printf("\n\t\t===========================================\n");
									printAllProperti(sales);
								}
							break;
							
							case '2':
								if(!haveProperti(sales)){
									printf("\n\t[!] Saat ini belum ada properti yang dapat dijual");
								}else{
									system("cls");
									printf("\t\t===========================================");
	                                printf("\n\t\t     [Data Properti yang Dapat Dijual]");
	                                printf("\n\t\t===========================================\n");
									printAllProperti(sales);
									printf("\n\t\tMasukan nomor properti yang ingin dijual : ");fflush(stdin);gets(noprop);
									if(findProperti(sales,noprop)==NULL){
										printf("\n\t\t\t[!] Nomor properti tidak ditemukan");
									}else{
										system("cls");
										printf("\t\t===========================================");
		                                printf("\n\t\t\t      [Jual Properti]");
		                                printf("\n\t\t===========================================\n");
										printProperti(findProperti(sales,noprop));
										printf("\n\n\t\tApakah Anda ingin menjual properti ini [yes/no] : ");fflush(stdin);gets(confirm);
										if(strcmpi(confirm,"Yes")==0){
											jualProperti(&sales,findProperti(sales,noprop));
											printf("\n\t[+]Berhasil menjual properti");
											printf("\n\t[~]Kembali ke menu utama...");
										}else{
											printf("\n\t\t\t[-]Gagal menjual properti");
											printf("\n\t\t\t[~]Kembali ke menu utama...");
										}
									}							
								}
							break;
							
							case '3':
								if(strcmpi(sales->dataSales.status,"Resign")==0){
									printf("\n\t[!] Anda sudah mengajukan resign");
								}else{
									system("cls");
									printf("===========================================");
		                            printf("\n\t      [Ajukan Resign]");
		                            printf("\n===========================================\n");
		                            
									printf("\nApakah Anda ingin mengajukan resign [yes/no] : ");fflush(stdin);gets(confirm);
									if(strcmpi(confirm,"Yes")==0){
										strcpy(sales->dataSales.status,"Resign");	
										printf("\n\t[+] Pengajuan resign berhasil");
										printf("\n\t[~] Kembali ke menu utama...");
									}else{
										printf("\n\t[-] Pengajuan resign dibatalkan");
										printf("\n\t[~] Kembali ke menu utama...");
									}	
								}
									
							break;
							
							case '0':
								printf("\nkembali ke menu login");
							break;
							
							default:
								printf("\n\tmenu tidak ada");
							break;
								
						}getch();
					}while(submenu!='0');			
				}
			break;
			
			case '0':
				printf("\n\n\t\t\t\tBersama ajeng, liat paus. Hi abang ganteng, bolehkah dapet bonus??");
				printf("\n\n\t\t\t\tDibuat oleh Yobel Nugroho - 220711905 - ISD D");					
			break;
			
			default :
				printf("\n\n\t\t\t\t[!] Menu tidak tersedia");
			break;
		}getch();
		
	}while(menu!='0');
	return 0;
}

