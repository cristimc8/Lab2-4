#include <string.h>
#include "Tranzactie.h"
#include <stdlib.h>

void tranzactie_init(Tranzactie* tranzactie, unsigned int zi, unsigned int suma, char* tip, char* descriere) {
	tranzactie_settip(tranzactie, tip);
	tranzactie_setdescriere(tranzactie, descriere);
	tranzactie_setsuma(tranzactie, suma);
	tranzactie_setzi(tranzactie, zi);
}

void tranzactie_destroy(Tranzactie* tranzactie) {
	free(tranzactie->tip);
	free(tranzactie->descriere);
}

unsigned int tranzactie_getZi(Tranzactie* tranzactie) {
	return tranzactie->zi;
}

char* tranzactie_getTip(Tranzactie* tranzactie) {
	return tranzactie->tip;
}

unsigned int tranzactie_getsuma(Tranzactie* tranzactie)
{
	return tranzactie->suma;
}

char* tranzactie_getdescriere(Tranzactie* tranzactie)
{
	return tranzactie->descriere;
}

void tranzactie_setzi(Tranzactie* tranzactie, unsigned int zi) {
	tranzactie->zi = zi;
}

void tranzactie_settip(Tranzactie* tranzactie, char* tip) {
	tranzactie->tip = (char*)malloc(sizeof(char) * (strlen(tip) + 1));
	strcpy(tranzactie->tip, tip);
}

void tranzactie_setsuma(Tranzactie* tranzactie, unsigned int suma){
	tranzactie->suma = suma;
}

void tranzactie_setdescriere(Tranzactie* tranzactie, char* descriere) {
	tranzactie->descriere = (char*)malloc(sizeof(char) * strlen(descriere) + 1);
	strcpy(tranzactie->descriere, descriere);
}