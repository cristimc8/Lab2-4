#include "ui.h"
#include "Tranzactie.h"
#include "Vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void start_loop(UI* ui){
	int input = 0;
	int bad = 0;
	while (input != -1) {
		bad = 0;
		show_options();
		scanf("%d", &input);
		if (input == 1) {
			unsigned int zi, suma;
			char tip[50], descriere[150];
			printf("Zi(Int): ");
			scanf("%d", &zi);

			printf("Suma(Int): ");
			scanf("%d", &suma);
			printf("Tipul('intrare/iesire'): ");
			scanf("%s", tip);
			printf("Descriere(String): ");
			scanf("%s", descriere);

			if (zi <= 0 || zi >= 31) {
				bad = 1;
				printf("Ziua sa fie intre 1 si 31!\n");
			}
			if (suma <= 0) {
				bad = 1;
				printf("Suma sa fie pozitiva!\n");
			}

			if (strcmp(tip, "intrare") != 0 && strcmp(tip, "iesire") != 0) {
				bad = 1;
				printf("Tipul poate fi doar intrare sau iesire!\n");
			}

			if (bad == 0) {
				Tranzactie* tranzactie = (Tranzactie*)malloc(sizeof(Tranzactie));
				tranzactie_init(tranzactie, zi, suma, tip, descriere);
				adauga_tranzactie(ui->service, tranzactie);
				ui_display_tranzactie(tranzactie);
			}
		}
		else if (input == 2) {
			unsigned int zi, suma;
			char tip[50], descriere[150];
			printf("ziua tranzactiei pe care vrei sa o modifici: ");
			scanf("%d", &zi);
			printf("Suma noua: ");
			scanf("%d", &suma);
			printf("Tipul nou: ");
			scanf("%s", tip);
			printf("Descrierea noua: ");
			scanf("%s", descriere);

			modificare_tranzactie(ui->service, zi, suma, tip, descriere);
			printf("Succes!\n");
		}
		else if (input == 3) {
			printf("Ziua tranzactiei pe care vrei sa o stergi: ");
			unsigned int zi;
			scanf("%d", &zi);
			sterge_tranzactie(ui->service, zi);
			printf("succes!");
		}
		else if (input == 4) {
			char tipN[50];
			printf("Ce tip doriti sa vizualizati (intrare / iesire): ");
			scanf("%s", tipN);
			Vector* tranzactii;
			tranzactii = service_vizualizare_tranzactii_tip(ui->service, tipN);
			ui_display_vector_of_transactions(tranzactii);

			vector_destroy(tranzactii);
			free(tranzactii);
		}
		else if (input == 5) {
			int mod, suma;
			printf("Tranzactii cu suma mai mare (0) / Mai mica (1) decat suma pe care urmeaza sa o dai: ");
			scanf("%d", &mod);
			printf("Suma: ");
			scanf("%d", &suma);

			Vector* tranzactii;
			tranzactii = service_vizualizare_tranzactii_suma(ui->service, (short int)mod, suma);
			ui_display_vector_of_transactions(tranzactii);

			vector_destroy(tranzactii);
			free(tranzactii);
		}
		else if (input == 6) {
			int mod;
			printf("Modul de ordonare: Crescator (0) / Descrescator (1): ");
			scanf("%d", &mod);

			Vector* tranzactii = (Vector*)malloc(sizeof(Vector));
			vector_init(tranzactii);
			unsigned int i;
			//We're basically forming the entire repo in this Vector, so we can sort on it and return it.
			//This way we are not modifying the original Repository.
			//Also, we are return a Vector object, not a reference, so no dangers here.
			for (i = 0; i < repo_getsize(service_getRepo(ui->service)); i++) {
				vector_pushback(tranzactii, repo_getbyposition(service_getRepo(ui->service), i));
			}

			Vector* tranzactii2;
			tranzactii2 = sortByDay(tranzactii, (int)mod);
			ui_display_vector_of_transactions(tranzactii2);

			vector_destroy(tranzactii);
			free(tranzactii);
			
			vector_destroy(tranzactii2);
			free(tranzactii2);

		}
		else if (input == 7) {
			int mod;
			printf("Modul de ordonare: Crescator (0) / Descrescator (1): ");
			scanf("%d", &mod);

			Vector* tranzactii = (Vector*)malloc(sizeof(Vector));
			vector_init(tranzactii);
			unsigned int i;
			//We're basically forming the entire repo in this Vector, so we can sort on it and return it.
			//This way we are not modifying the original Repository.
			for (i = 0; i < repo_getsize(service_getRepo(ui->service)); i++) {
				vector_pushback(tranzactii, repo_getbyposition(service_getRepo(ui->service), i));
			}

			Vector* tranzactii2;
			tranzactii2 = sortBySum(tranzactii, mod);
			ui_display_vector_of_transactions(tranzactii2);

			vector_destroy(tranzactii);
			free(tranzactii);

			vector_destroy(tranzactii2);
			free(tranzactii2);
		}
	}
}

void ui_display_vector_of_transactions(Vector* tranzactii) {
	unsigned int i;
	for (i = 0; i < vector_getlen(tranzactii); i++) {
		ui_display_tranzactie_show(vector_getat(tranzactii, i));
	}
}

void ui_display_tranzactie(Tranzactie* tranzactie) {
	printf("\nAi adaugat tranzactia cu ziua: %d si suma: %d si tipul: %s si descrierea: %s\n", tranzactie->zi, tranzactie->suma, tranzactie->tip, tranzactie->descriere);
}

void ui_display_tranzactie_show(Tranzactie* tranzactie) {
	printf("\nTranzactia:\nZiua: %d -- Suma: %d -- tip: %s -- descriere %s\n", tranzactie_getZi(tranzactie), tranzactie_getsuma(tranzactie), tranzactie_getTip(tranzactie), tranzactie_getdescriere(tranzactie));
}

void ui_init(UI* ui, Service* service){
	ui->service = service;
}

void ui_destroy(UI* ui){
	service_destroy(ui->service);
}

void show_options(){
	printf("Buna siua!\n");
	printf("1 -> Adauga tranzactie\n");
	printf("2 -> Modifica tranzactie\n");
	printf("3 -> Sterge tranzactie\n");
	printf("4 -> Vizualizare tranzactii dupa tip\n");
	printf("5 -> Vizualizare tranzactii dupa suma\n");
	printf("6 -> Vizualizare tranzactii ordonat dupa zi\n");
	printf("7 -> Vizualizare tranzactii ordonat dupa suma\n");
	printf("-1 -> Iesire!\n");
}
