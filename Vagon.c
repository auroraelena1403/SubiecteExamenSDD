//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//struct Vagon {
//	int nrVagon;
//	char* firmaTransport;
//	int numarBilete;
//	int capacitateVagon;
//};
//typedef struct Vagon Vagon;
//struct Node{
//	Vagon info;
//	struct Node* prev;
//	struct Node* next;
//};
//typedef struct Node Node;
//struct ListaDubla {
//	Node* cap;
//	Node* coada;
//};
//typedef struct ListaDubla ListaDubla;
//Vagon initV(int nrVagon, const char* firmaTransport, int nrBilete, int capacitateVagon) {
//	Vagon v;
//	v.nrVagon = nrVagon;
//	v.firmaTransport = (char*)malloc(sizeof(char) * (strlen(nrVagon) + 1));
//	v.numarBilete = nrBilete;
//	v.capacitateVagon = capacitateVagon;
//	return v;
//}
//void inserareInceputLD(ListaDubla* ld, Vagon v) {
//	Node* nou = (Node*)malloc(sizeof(Node));
//	
//	nou->prev = NULL;
//	nou->info = v;
//	nou->next = ld->cap;
//	if (ld->cap == NULL) {
//		ld->coada = nou;
//	}
//	else {
//		ld->cap->prev = nou;
//	}
//	ld->cap = nou;
//	
//}