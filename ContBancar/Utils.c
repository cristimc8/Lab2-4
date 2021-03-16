#include "Utils.h"

int compareDay(Tranzactie* e1, Tranzactie* e2) {
	if (tranzactie_getZi(e1) > tranzactie_getZi(e2)) return -1;
	return 1;
}

int compareSum(Tranzactie* e1, Tranzactie* e2) {
	if(tranzactie_getsuma(e1) > tranzactie_getsuma(e2)) return -1;
	return 1;
}