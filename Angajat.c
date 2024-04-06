//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//
//struct Angajat {
//	char* nume;
//	int varsta;
//	float greutate;
//	
//};
//typedef struct Angajat Angajat;
//typedef struct Node Node;
////Node si ListaDubla
//struct Node {
//	Angajat info;
//	Node* prev;
//	Node* next;
//	
//};
//struct ListaDubla {
//	Node* cap;
//	Node* coada;
//};
//typedef struct ListaDubla ListaDubla;
//Angajat initializareAngajat(const char* nume, int varsta, float greutate) {
//	Angajat angajat;
//	angajat.nume = (char*)malloc(sizeof(char)* (strlen(nume) + 1));
//	strcpy(angajat.nume, nume);
//	angajat.varsta = varsta;
//	angajat.greutate = greutate;
//	
//	return angajat;
//}
//void afisareAngajat(Angajat a) {
//	printf("Angajatul %s are varsta de %d ani, greutatea de %f kg", a.nume, a.varsta, a.greutate);
//}
//void inserareInceputLD(ListaDubla* listaDubla, Angajat angajat) {
//	Node* nodNou = (Node*)malloc(sizeof(Node));
//	nodNou->prev = NULL;
//	nodNou->info = angajat;
//	nodNou->next = listaDubla->cap;
//	if (listaDubla->cap != NULL) {
//		listaDubla->cap->prev = nodNou;
//	}
//	else {
//		listaDubla->coada = nodNou;
//	}
//	listaDubla->cap = nodNou;
//}
//void afisareListaInceputSpreSf(ListaDubla lista) {
//	Node* nou = lista.cap;
//	while (nou) {
//		afisareAngajat(nou->info);
//		nou = nou->next;
//	}
//		
//}
//void citireFisier(const char* numeF, ListaDubla* lista) {
//	if (numeF != NULL) {
//		FILE* f = fopen(numeF, "r");
//		if (f != NULL) {
//			char buffer[100];
//			
//			char* delimitator = ",\n";
//			while (fgets(buffer, sizeof(buffer), f) != NULL) {
//				char* token = strtok(buffer, delimitator);
//				char* nume = (char*)malloc(strlen(token) + 1);
//				strcpy(nume, token);
//				token = strtok(NULL, delimitator);
//				int varsta = atoi(token);
//				token = strtok(NULL, delimitator);
//				float greutate = atof(token);
//				
//				
//				Angajat angajatFisier = initializareAngajat(nume, varsta, greutate);
//				
//				inserareInceputLD(lista, angajatFisier);
//			}
//			fclose(f);
//		}
//		
//	}
//	
//}
////void stergereAngajatDupaVarsta(ListaDubla* lista, const char* nume) {
////	Node* aux = lista->cap;
////	while (aux != NULL && strcmp(aux->info.nume, nume) != 0) {
////		aux = aux->next;
////	}
////	//se opreste cautarea la angajatul cautat
////	//facem verificarile necesare
////	if (aux != NULL) {
////		//verificam daca e primul element => capul se va modifica in elementul urm
////		if (aux->prev == NULL) {
////			lista->cap = aux->next;
////		}
////		else if (aux->next = NULL) {
////			lista->coada = aux->prev;
////			lista->coada->next = NULL;
////		}
////		else {
////			//daca elem este undeva in mijloc
////			(aux->prev)->next = aux->next;
////			aux->next->prev = aux->prev;
////		}
////	}
////	free(aux->info.nume);
////	free(aux);
////}
//ListaDubla stergeCafeneaDupaNume(ListaDubla listaDubla, const char* nume){
//    if (nume == NULL) {
//        return listaDubla;
//    }
//    Node* nod = listaDubla.cap;
//
//    while (nod && strcmp(nod->info.nume, nume) != 0) {
//        nod = nod->next;
//    }
//    if (nod != NULL) {
//        if (nod->next == NULL && nod->prev == NULL) {
//            listaDubla.cap = NULL;
//            listaDubla.coada = NULL;
//        }
//        else {
//            if (nod->prev == NULL) {
//                listaDubla.cap = nod->next;
//                listaDubla.cap->prev = NULL;
//            }
//            else if (nod->next == NULL) {
//                listaDubla.coada = nod->prev;
//                listaDubla.coada->next = NULL;
//            }
//            else {
//                nod->prev->next = nod->next;
//                nod->next->prev = nod->prev;
//            }
//        }
//        free(nod->info.nume);
//        free(nod);
//    }
//    return(listaDubla);
//}
//void main() {
//	ListaDubla ld;
//	ld.cap = NULL;
//	ld.coada = NULL;
//	Angajat a1 = initializareAngajat("sd", 1, 1);
//	inserareInceputLD(&ld, a1);
//	citireFisier("Angajati.txt", &ld);
//	afisareListaInceputSpreSf(ld);
//	stergeCafeneaDupaNume(ld, "Angajat1");
//	afisareListaInceputSpreSf(ld);
//
//}