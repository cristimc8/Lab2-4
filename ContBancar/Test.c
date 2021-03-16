#include "Test.h"
#include "Tranzactie.h"
#include "Vector.h"
#include <stdio.h>
#include "Repo.h"
#include "Service.h"
#include "Utils.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

void runAll(){
	runTranzactieTests();
	runVectorTests();
	runRepoTests();
	runServiceTests();
}

void runTranzactieTests(){
	Tranzactie tranzactie;
	unsigned int zi = 5, suma = 4;
	char tip[50] = "lol", descriere[50] = "descrierer";
	tranzactie_init(&tranzactie, zi, suma, tip, descriere);
	assert(tranzactie_getsuma(&tranzactie) == suma);
	assert(strcmp(tranzactie_getdescriere(&tranzactie), descriere) == 0);
	assert(strcmp(tranzactie_getTip(&tranzactie), tip) == 0);
	assert(tranzactie_getZi(&tranzactie) == zi);

	tranzactie_destroy(&tranzactie);
}

void runVectorTests() {
	Vector vector;
	vector_init(&vector);
	vector_pushback(&vector, "capac");
	vector_pushback(&vector, "xxxx");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	vector_pushback(&vector, "yyyy");
	assert(vector_getlen(&vector) == 11);
	assert(strcmp(vector_getat(&vector, 0), "capac") == 0);
	assert((int)vector_getat(&vector, 20) == -1);
	vector_removeat(&vector, 20);
	vector_removeat(&vector, 1);
	vector_removeat(&vector, 0);

	vector_destroy(&vector);
}

void runRepoTests() {
	Repo* repo = (Repo*)malloc(sizeof(Repo));
	repo_init(repo);

	Tranzactie* tranzactie = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie, 5, 4, "intrare", "descrierer");

	Tranzactie* tranzactie2 = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie2, 5, 20, "iesire", "descr");

	repo_addtranzactie(repo, tranzactie);
	assert(repo_getsize(repo) == 1);

	assert(tranzactie_getsuma(repo_getbyposition(repo, 0)) == 4);

	repo_modificatranzactie(repo, 5, tranzactie2);
	repo_deletetranzactie(repo, 5, 0);

	tranzactie_destroy(tranzactie2);
	free(tranzactie2);

	assert(repo_getsize(repo) == 0);

	repo_destroy(repo);
	free(repo);
}

void runServiceTests() {
	Repo* repo = (Repo*)malloc(sizeof(Repo));
	repo_init(repo);

	Service* service = (Service*)malloc(sizeof(Service));
	service_init(service, repo);

	Tranzactie* tranzactie = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie, 5, 4, "intrare", "descrierer");

	Tranzactie* tranzactie2 = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie2, 3, 6, "iesire", "xx");

	adauga_tranzactie(service, tranzactie);
	assert(repo_getsize(service_getRepo(service)) == 1);

	adauga_tranzactie(service, tranzactie2);
	assert(repo_getsize(service_getRepo(service)) == 2);

	//Filtre

	Vector* v;
	v = service_vizualizare_tranzactii_tip(service, "intrare");
	assert(vector_getlen(v) == 1);

	vector_destroy(v);
	free(v);

	v = service_vizualizare_tranzactii_tip(service, "iesire");
	assert(vector_getlen(v) == 1);

	vector_destroy(v);
	free(v);

	v = service_vizualizare_tranzactii_suma(service, (short int)0, 6);
	assert(vector_getlen(v) == 0);

	vector_destroy(v);
	free(v);

	v = service_vizualizare_tranzactii_suma(service, (short int)0, 5);
	assert(vector_getlen(v) == 1);

	vector_destroy(v);
	free(v);

	v = service_vizualizare_tranzactii_suma(service, (short int)1, 7);
	assert(vector_getlen(v) == 2);

	vector_destroy(v);
	free(v);

	//modifica&sterge

	Tranzactie* tranzactie3 = (Tranzactie*)malloc(sizeof(Tranzactie));
	tranzactie_init(tranzactie3, 4, 20, "iesire", "yy");

	adauga_tranzactie(service, tranzactie3);
	assert(repo_getsize(service_getRepo(service)) == 3);

	modificare_tranzactie(service, 4, 3, "intrare", "zz");

	assert(strcmp(tranzactie_getTip(repo_getbyposition(repo, 2)), "intrare") == 0);

	sterge_tranzactie(service, 4);

	// Sortari
	v = service_getRepo(service)->tranzactii;

	Vector* sorted;
	sorted = sortBySum(v, 0);
	assert(tranzactie_getsuma(vector_getat(sorted, 0)) == 4);

	vector_destroy(sorted);
	free(sorted);

	sorted = sortBySum(v, 1);
	assert(tranzactie_getsuma(vector_getat(sorted, 0)) == 6);
	
	vector_destroy(sorted);
	free(sorted);

	sorted = sortByDay(v, 0);
	assert(tranzactie_getZi(vector_getat(sorted, 0)) == 3);

	vector_destroy(sorted);
	free(sorted);

	sorted = sortByDay(v, 1);
	assert(tranzactie_getZi(vector_getat(sorted, 0)) == 5);

	vector_destroy(sorted);
	free(sorted);



	// Dealocari

	service_destroy(service);
	free(service);
	free(repo);
}
