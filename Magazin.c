//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//#define _CRT_SECURE_NO_WARNINGS
//struct Magazin {
//	int id;
//	char* denumire;
//	char* localitate;
//	float suprafata;
//	int nrAng;
//};
//typedef struct Magazin Magazin;
//struct Node {
//	Magazin info;
//	struct Node* next;
//};
//typedef struct Node Node;
//Magazin initMagazin(int id, const char* denumire, const char* localitate, float supr, int nrAng) {
//	Magazin m;
//	m.id = id;
//	m.denumire= (char*)malloc(sizeof(char) * (strlen(denumire) + 1));
//	strcpy(m.denumire, denumire);
//	m.localitate = (char*)malloc(sizeof(char) * (strlen(localitate) + 1));
//	strcpy(m.localitate, localitate);
//	m.suprafata = supr;
//	m.nrAng = nrAng;
//	return m;
//}
//struct HashTable {
//	int dim;
//	Node** vector;
//};
//typedef struct HashTable HashTable;
//
//void inserareFinalLS(Node** cap, Magazin m) {
//	Node* nou = (Node*)malloc(sizeof(Node));
//	nou->info = m;
//	nou->next = NULL;
//	Node* aux = NULL;
//	if ((*cap) != NULL) {
//		aux = *cap;
//		while (aux->next != NULL) {
//			//se opreste la penultimul element
//			aux = aux->next;
//		}
//		aux->next = nou;
//	}
//	else {
//		*cap = nou;
//	}
//}
//HashTable initHT(int dim) {
//	HashTable ht;
//	ht.dim = dim;
//	ht.vector = (Node**)malloc(sizeof(Node*) * dim);
//		
//	for (int i = 0; i < dim; i++) {
//			ht.vector[i] = NULL;
//	}
//
//	
//	
//	return ht;
//}
//int calculHash(int cod, const char* localitate, int dim) {
//	if (dim > 0) {
//		int pozitie = cod * strlen(localitate)/cod;
//		pozitie = pozitie % dim;
//		return pozitie;
//	}
//	else {
//		return -1;
//	}
//}
//void modificareMagazin(int cod,const char* nume, const char* loc, HashTable ht, const char* denumireNoua) {
//	int pozitie = calculHash(cod, loc, ht.dim);
//	//calculam pozitia in ht unde se afla apoi facem cautarea in lista respectiva
//	if (pozitie >= 0 && pozitie < ht.dim) {
//		Node* contor = ht.vector[pozitie];
//		while (contor && strcmp(contor->info.localitate, loc) != 0 && strcmp(contor->info.denumire, nume) != 0) {
//			contor = contor->next;
//		}
//		if (contor) {
//			//ajunge la elementul cautat si returneaza magazinul respectiv pe care il modifica
//			contor->info.denumire = denumireNoua;
//		}
//		else {
//			printf("Elementul nu a fost gasit");
//		}
//	}
//	else {
//		printf("Elementul nu a fost gasit");
//	}
//}
//void inserareTabelaDispersie(HashTable ht, Magazin magazin) {
//	if (ht.dim > 0) {
//		int pozitie = calculHash(magazin.id, magazin.localitate, ht.dim);
//		if (ht.vector[pozitie]!=NULL) {
//			inserareFinalLS(&(ht.vector[pozitie]), magazin);
//		}
//		else {
//			inserareFinalLS(&(ht.vector[pozitie]), magazin);
//		}
//	}
//}
//void citireFisier(const char* numeF, HashTable ht) {
//	if (numeF != NULL) {
//		FILE* f = fopen(numeF, "r");
//		if (f != NULL) {
//			char buffer[100];
//			char* delimitator = ",\n";
//			while (fgets(buffer, sizeof(buffer), f) != 0) {
//				char* token = strtok(buffer, delimitator);
//				int id = atoi(token);
//				token = strtok(NULL, delimitator);
//				char* denumire = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//				strcpy(denumire,token);
//				token = strtok(NULL, delimitator);
//				char* localitate = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//				strcpy(localitate, token);
//				token = strtok(NULL, delimitator);
//				float supr = atof(token);
//				token = strtok(NULL, delimitator);
//				int nrAng = atoi(token);
//				Magazin m = initMagazin(id, denumire, localitate, supr, nrAng);
//				inserareTabelaDispersie(ht, m);
//
//
//			}
//		}
//		fclose(f);
//	}
//}
//void afisMag(Magazin magazin) {
//	printf("%d, %s, %s, %.2f, %d\n", magazin.id, magazin.denumire, magazin.localitate, magazin.suprafata, magazin.nrAng);
//}
//void afisLista(Node* cap) {
//	while (cap) {
//		afisMag(cap->info);
//		cap = cap->next;
//	}
//}
//void afisareHt(HashTable ht) {
//	if (ht.dim != 0) {
//		for (int i = 0; i < ht.dim; i++) {
//			printf("\nElementele clusterului %d\n", i + 1);
//			afisLista(ht.vector[i]);
//		}
//	}
//}
//float nrMediuAng(HashTable ht, const char* localitateCautata) {
//	int nrElementeGasite=0;
//	int nrAng=0;
//	float  nrMediu=0;
//	for (int i = 0; i < ht.dim; i++) {
//		Node* contor = ht.vector[i];
//		while (contor != NULL) {
//			if(strcmp(contor->info.localitate, localitateCautata) == 0) {
//				nrElementeGasite += 1;
//				nrAng += contor->info.nrAng;
//			}
//			contor = contor->next;
//		}
//	}
//	nrMediu = nrAng / nrElementeGasite;
//	return nrMediu;
//}
//
//void main() {
//	HashTable ht = initHT(10);
//	citireFisier("Magazine.txt", ht);
//	afisareHt(ht);
//	modificareMagazin(1, "Alimentara", "Oras1", ht, "Denumire Noua");
//	printf("\nDupa modificare----------------------\n");
//	afisareHt(ht);
//	float nrMediu = nrMediuAng(ht, "Oras1");
//	printf("\n%f", nrMediu);
//}
