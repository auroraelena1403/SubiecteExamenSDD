//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//
//struct Voucher {
//	int nrVoucher;
//	char* nume;
//	char* dataExp;
//	float valoare;
//};
//typedef struct Voucher Voucher;
//struct Node {
//	Voucher info;
//	struct Node* prev;
//	struct Node* next;
//};
//typedef struct Node Node;
//struct ListaDubla {
//	Node* coada;
//	Node* cap;
//};
//typedef struct ListaDubla ListaDubla;
//Voucher initV(int nrVoucher, const char* nume, const char* dataExp, float valoare) {
//	Voucher v;
//	v.nrVoucher = nrVoucher;
//	v.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
//	strcpy(v.nume, nume);
//	v.dataExp = (char*)malloc(sizeof(char) * (strlen(dataExp) + 1));
//	strcpy(v.dataExp, dataExp);
//	v.valoare = valoare;
//	return v;
//}
//void afisareV(Voucher v) {
//	printf("Voucherul cu nr. %d, numele %s, data expirarii %s si valoarea de %f\n", v.nrVoucher, v.nume, v.dataExp, v.valoare);
//}
//void inserareInceputLD(ListaDubla* lista, Voucher v) {
//	Node* aux = (Node*)malloc(sizeof(Node));
//	aux->prev = NULL;
//	aux->info = v;
//	aux->next = lista->cap;
//	if (lista->cap!= NULL) {
//		lista->cap->prev = aux;
//	}
//	else  {
//		lista->coada = aux;
//	}
//	
//	lista->cap = aux;
//}
//void afisareListaDB(ListaDubla lista) {
//	if (lista.cap != NULL) {
//		while (lista.cap != NULL) {
//			afisareV(lista.cap->info);
//			lista.cap = lista.cap->next;
//		}
//	}
//}
//void citireFisier(const char* numeF, ListaDubla* ld) {
//	if (numeF != NULL) {
//		FILE* f = fopen(numeF, "r");
//		char buffer[100];
//		char* token;
//		char* delimitator = ",\n";
//		if (f != NULL) {
//			while (fgets(buffer, sizeof(buffer), f) != 0) {
//				token = strtok(buffer, delimitator);
//				int nrV = atoi(token);
//				token = strtok(NULL, delimitator);
//				char* nume = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//				strcpy(nume, token);
//				token = strtok(NULL, delimitator);
//				char* data = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//				strcpy(data, token);
//				token = strtok(NULL, delimitator);
//				float val = atof(token);
//				Voucher v = initV(nrV, nume, data, val);
//				
//				inserareInceputLD(ld, v);
//			}
//		}
//		fclose(f);
//		
//	}
//}
//
//float valoareLunaParametru(ListaDubla lista, const char* nume) {
//	float valoareTotalaLunaRespectiva = 0.0;
//	if (nume != NULL) {
//		while (lista.cap != NULL) {
//			if (strstr(lista.cap->info.dataExp, nume)!=NULL) {
//				//contine
//				valoareTotalaLunaRespectiva += lista.cap->info.valoare;
//			}
//			lista.cap = lista.cap->next;
//		}
//	}
//	return valoareTotalaLunaRespectiva;
//}
//
//int nrBeneficiariMultiplii(ListaDubla lista) {
//	int nrBeneficiariDupl = 0;
//	if (lista.cap != NULL) {
//		Node* curent = lista.cap;
//		Node* aux = NULL;
//		while (curent != NULL) {
//			aux = curent->next;
//			while (aux != NULL) {
//				if (strcmp(curent->info.nume, aux->info.nume) == 0) {
//					nrBeneficiariDupl++;
//					break;
//				}
//				aux = aux->next;
//			}
//			curent = curent->next;
//		}
//		
//	}
//	return nrBeneficiariDupl;
//}
//Voucher* adaugaInVector(ListaDubla ld, int valoarePrag) {
//	int nrVouchee = 0;
//	Node* aux = ld.cap;
//	Voucher* vouchere = NULL;
//	if (valoarePrag > 0) {
//		while (aux != NULL) {
//			if (aux->info.valoare > valoarePrag) {
//				nrVouchee++;
//				
//			}
//			aux =aux->next;
//		}
//		printf("%d", nrVouchee);
//		vouchere = (Voucher*)malloc(sizeof(Voucher) * nrVouchee);
//		while (ld.cap != NULL) {
//			for (int i = 0; i < nrVouchee-2; i++) {
//				if (ld.cap->info.valoare > valoarePrag) {
//					vouchere[i] = ld.cap->info;
//					afisareV(ld.cap->info);
//				}
//				i++;
//				ld.cap = ld.cap->next;
//			}
//		}
//		
//	}
//	return vouchere;
//}
//
//
//void main() {
//	Voucher v = initV(1, "-", "-", 1);
//	ListaDubla ld;
//	ld.cap = NULL;
//	ld.coada = NULL;
//	inserareInceputLD(&ld, v);
//	printf("\nIninate de citirea din fisier--------------------------\n");
//	afisareListaDB(ld);
//	citireFisier("Vouchere.txt", &ld);
//	printf("\Dupa citirea din fisier--------------------------\n");
//	afisareListaDB(ld);
//	float val = valoareLunaParametru(ld, "ianuarie");
//	printf("\n %f \n", val);
//	int nr = nrBeneficiariMultiplii(ld);
//	printf("\n %d", nr);
//	Voucher* vouchere = adaugaInVector(ld, 300);
//	
//	
//
//}