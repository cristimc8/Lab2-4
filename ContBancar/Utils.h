#ifndef UTILS_H_
#define UTILS_H_
#include "Tranzactie.h"


/// <summary>
/// Generic element. Can be anything
/// </summary>
typedef void* Element;

int compareDay(Tranzactie* e1, Tranzactie* e2);

int compareSum(Tranzactie* e1, Tranzactie* e2);

#endif // !UTILS_H_
