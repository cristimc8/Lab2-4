#include "Service.h"
#include "Vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void service_init(Service* service, Repo* repo){
	service_setrepo(service, repo);
}

void service_destroy(Service* service){
	repo_destroy(service->repo);
}

void service_setrepo(Service* service, Repo* repo){
	service->repo = repo;
}

void adauga_tranzactie(Service* service, Tranzactie* tranzactie){
	repo_addtranzactie(service->repo, tranzactie);
}

void modificare_tranzactie(Service* service, unsigned int zi, unsigned int suma, char* tip, char* descriere){
	Tranzactie* tranzactie = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie, zi, suma, tip, descriere);
	repo_modificatranzactie(service->repo, zi, tranzactie);
	//tranzactie_destroy(tranzactie);
	//free(tranzactie);
}

void sterge_tranzactie(Service* service, unsigned int zi){
	repo_deletetranzactie(service->repo, zi, 1);
}

Repo* service_getRepo(Service* service){
	return service->repo;
}

Vector* service_vizualizare_tranzactii_tip(Service* service, char* tip){
	unsigned int i;
	/*Vector v;
	vector_init(&v);*/
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	vector_init(vector);
	for (i = 0; i < repo_getsize(service_getRepo(service)); i++) {
		if (strcmp(tranzactie_getTip(repo_getbyposition(service_getRepo(service), i)), tip) == 0) {
			//If transaction type is the same as the passed argument, we add it to the vector to return.
			vector_pushback(vector, repo_getbyposition(service_getRepo(service), i));
		}
	}
	return vector;
}

Vector* service_vizualizare_tranzactii_suma(Service* service, short int mod, unsigned int suma){
	unsigned int i;
	Vector* vector = (Vector*)malloc(sizeof(Vector));
	vector_init(vector);
	for (i = 0; i < repo_getsize(service_getRepo(service)); i++) {
		if (mod == 0) { // mod = 0 inseamna unde suma data ca al 3lea parametru este mai mica decat suma din tranzactie.
			if (tranzactie_getsuma(repo_getbyposition(service_getRepo(service), i)) > suma) {
				vector_pushback(vector, repo_getbyposition(service_getRepo(service), i));
			}
		}
		else {
			if (tranzactie_getsuma(repo_getbyposition(service_getRepo(service), i)) < suma) {
				vector_pushback(vector, repo_getbyposition(service_getRepo(service), i));
			}
		}
	}
	return vector;
}
