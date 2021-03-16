#include <stdio.h>
#include "Repo.h"
#include <stdlib.h>

void repo_init(Repo* repo){
	repo->tranzactii = (Vector*)malloc(sizeof(Vector));
	vector_init(repo->tranzactii);
}

void repo_destroy(Repo* repo){
	unsigned int i;
	for (i = 0; i < repo_getsize(repo); i++) {
		tranzactie_destroy(vector_getat(repo->tranzactii, i));
		free(vector_getat(repo->tranzactii, i));
		//repo_deletetranzactie(repo, tranzactie_getZi(vector_getat(repo->tranzactii, i)), 1);
	}
	vector_destroy(repo->tranzactii);
	free(repo->tranzactii);
}

unsigned int repo_getsize(Repo* repo) {
	return vector_getlen(repo->tranzactii);
}

Element repo_getbyposition(Repo* repo, int position)
{
	return vector_getat(repo->tranzactii, position);
}

void repo_modificatranzactie(Repo* repo, unsigned int zi, Tranzactie* tranzactie){
	repo_deletetranzactie(repo, zi, 1);
	repo_addtranzactie(repo, tranzactie);
	/*for (i = 0; i < vector_getlen(repo->tranzactii); i++) {
		if (tranzactie_getZi(vector_getat(repo->tranzactii, i)) == zi) {
			tranzactie_settip(vector_getat(repo->tranzactii, i), tranzactie->tip);
			tranzactie_setdescriere(vector_getat(repo->tranzactii, i), tranzactie->descriere);
			tranzactie_setsuma(vector_getat(repo->tranzactii, i), tranzactie->suma);
			break;
		}
	}*/
}

void repo_addtranzactie(Repo* repo, Tranzactie* tranzactie){
	vector_pushback(repo->tranzactii, tranzactie);
}

void repo_deletetranzactie(Repo* repo, unsigned int zi, int dynamicallyAllocated){
	unsigned int i;
	for (i = 0; i < vector_getlen(repo->tranzactii); i++) {
		//repo -> tranzactii -> elements [i] -> zi
		if (tranzactie_getZi(vector_getat(repo->tranzactii, i)) == zi) {
			if (dynamicallyAllocated == 1) {
				tranzactie_destroy(vector_getat(repo->tranzactii, i));
				free(vector_getat(repo->tranzactii, i));
			}
			vector_removeat(repo->tranzactii, i);
			break;
		}
	}
}
