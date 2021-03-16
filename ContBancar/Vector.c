#include <stdio.h>
#include "Vector.h"
#include "Tranzactie.h"
#include <stdlib.h>


void vector_init(Vector* vector) {
	vector__setlen(vector, 0);
	vector__setcapacity(vector, CAPACITY);
	vector->elements = malloc(vector__getcapacity(vector) * sizeof(Element));
}

void vector_destroy(Vector* vector) {
	free(vector->elements);
}

void vector_pushback(Vector* vector, Element element) {
	if (vector_getlen(vector) == CAPACITY - 1) {
		vector__setcapacity(vector, vector__getcapacity(vector) * 2);
		vector->elements = (Element*)realloc(vector->elements, (vector__getcapacity(vector)) * sizeof(Element));
	}
	vector->elements[vector_getlen(vector)] = element;
	vector__inclen(vector);
}

Element vector_getat(Vector* vector, unsigned int pos)
{
	unsigned int len = vector_getlen(vector);
	if (pos > len - 1) {
		//throwInvalidMem();
		return (Element)-1;
	}
	return vector->elements[pos];
}

void vector_removeat(Vector* vector, unsigned int pos) {
	unsigned int len = vector_getlen(vector);
	if (pos > vector_getlen(vector)) {
		//throwInvalidMem();
		return;
	}
	unsigned int i;
	for (i = pos; i < len - 1; i++) {
		vector->elements[i] = vector->elements[i + 1];
	}
	//vector->elements[i] = NULL;
	vector__setlen(vector, len - 1);
}

int vector_swap(Vector* vector, unsigned int pos1, unsigned int pos2) {
	/*if (pos1 > vector_getlen(vector) || pos2 > vector_getlen(vector)) {
		printf("Error while swapping Vector Elements -> Position cannot be greater than Vector's length!");
		return -1;
	}*/
	Element aux;
	aux = (Element)malloc(sizeof(Element));
	aux = vector->elements[pos1];
	vector->elements[pos1] = vector->elements[pos2];
	vector->elements[pos2] = aux;
	return 0;
}

unsigned int vector_getlen(Vector* vector) {
	return vector->length;
}

void vector__setlen(Vector* vector, unsigned int len) {
	vector->length = len;
}

void vector__inclen(Vector* vector) {
	vector->length++;
}

void vector__setcapacity(Vector* vector, int capacity){
	vector->capacity = capacity;
}

int vector__getcapacity(Vector* vector){
	return vector->capacity;
}


void bubbleSort(Vector* vector, int(*compareFunction)(void*, void*), int ascending) {
	unsigned int i, j;
	short int sorted;

	do {
		sorted = 1;
		for (i = 0; i < vector_getlen(vector) - 1; i++) {
			for (j = i + 1; j < vector_getlen(vector); j++) {
				if ((compareFunction(vector_getat(vector, i), vector_getat(vector, j)) == -1 && ascending == 0) || (compareFunction(vector_getat(vector, i), vector_getat(vector, j)) == 1 && ascending == 1)) {
					vector_swap(vector, i, j);
					sorted = 0;
				}
			}
		}
	} while (sorted == 0);
	//return tranzactii;
}

Vector* sortByDay(Vector* vector, int ascending) {
	Vector* v = (Vector*)malloc(sizeof(Vector));
	vector_init(v);
	unsigned int i;

	for (i = 0; i < vector_getlen(vector); i++) {
		vector_pushback(v, vector_getat(vector, i));
	}

	bubbleSort(v, compareDay, ascending);
	return v;
}

Vector* sortBySum(Vector* vector, int ascending)
{
	Vector* v = (Vector*)malloc(sizeof(Vector));
	vector_init(v);
	unsigned int i;

	for (i = 0; i < vector_getlen(vector); i++) {
		vector_pushback(v, vector_getat(vector, i));
	}

	bubbleSort(v, compareSum, ascending);
	return v;
}
