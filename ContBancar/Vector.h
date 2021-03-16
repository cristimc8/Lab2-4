#ifndef VECTOR_H_
#define VECTOR_H_
#include "Utils.h"
#define CAPACITY 10

typedef struct {
	Element* elements;
	int length;
	int capacity;
}Vector;

/// <summary>
/// Function that increases the length of vector
/// </summary>
/// <param name="vector">Type vector</param>
void vector__inclen(Vector* vector);

/// <summary>
/// Function that sets the capacity of the vector
/// </summary>
/// <param name="vector">Type Vector</param>
/// <param name="capacity">Type int</param>
void vector__setcapacity(Vector* vector, int capacity);

/// <summary>
/// Function that returns the capacity of the Vector.
/// </summary>
/// <param name="vector">Type Vector</param>
/// <returns>Int</returns>
int vector__getcapacity(Vector* vector);

/// <summary>
/// Function that sets the length of the vector.
/// </summary>
/// <param name="vector">type vector</param>
/// <param name="len">type int</param>
void vector__setlen(Vector* vector, unsigned int len);

/// <summary>
/// Function that initializes the vector element.
/// </summary>
/// <param name="vector">type vector</param>
void vector_init(Vector* vector);

/// <summary>
/// Function that destrys the vector element.
/// </summary>
/// <param name="vector">type vector</param>
void vector_destroy(Vector* vector);

/// <summary>
/// Function that pushes an element at the end of the vector.
/// </summary>
/// <param name="vector">type vector</param>
/// <param name="element">type Element (anything!)</param>
void vector_pushback(Vector* vector, Element element);

/// <summary>
/// Function that removes an element on specified position from the vector.
/// </summary>
/// <param name="vector">type vector.</param>
/// <param name="pos">type unsigned int</param>
void vector_removeat(Vector* vector, unsigned int pos);

/// <summary>
/// Function that gets the length of the vector(number of elements!)
/// </summary>
/// <param name="vector">type vector!</param>
/// <returns>Int length of vector</returns>
unsigned int vector_getlen(Vector* vector);

/// <summary>
/// Function that returns the element on specified position
/// </summary>
/// <param name="vector">type vector</param>
/// <param name="pos">type Unsigned int</param>
/// <returns>The Element type from specified position (can be anything!)</returns>
Element vector_getat(Vector* vector, unsigned int pos);

/// <summary>
/// Function that swaps 2 Elements inside a Vector.
/// </summary>
/// <param name="vector">Vector*</param>
/// <param name="pos1">Unsigned int -> position of 1st element in Vector</param>
/// <param name="pos2">Unsigned int -> position of 2nd element in Vector</param>
/// <returns>-1 in case of error, 0 if all good.</returns>
int vector_swap(Vector* vector, unsigned int pos1, unsigned int pos2);

void bubbleSort(Vector* vector, int(*compareFunction)(void*, void*), int ascending);

Vector* sortByDay(Vector* vector, int ascending);

Vector* sortBySum(Vector* vector, int ascending);
#endif // !VECTOR_H_
