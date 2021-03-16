#ifndef REPO_H_
#define REPO_H_

#include "Vector.h"
#include "Tranzactie.h"
#include "Utils.h"

typedef struct {
	Vector* tranzactii;
}Repo;

/// <summary>
/// Init function for repo
/// </summary>
/// <param name="repo">Type Repo</param>
void repo_init(Repo* repo);

/// <summary>
/// Destroyer for repo
/// </summary>
/// <param name="repo">Type repo</param>
void repo_destroy(Repo* repo);

/// <summary>
/// Function to modify transaction
/// </summary>
/// <param name="repo">Type Repo</param>
/// <param name="zi">Type unsigned Int</param>
/// <param name="tranzactie">type Tranzaction</param>
void repo_modificatranzactie(Repo* repo, unsigned int zi, Tranzactie* tranzactie);

/// <summary>
/// Function to add transaction to the repo.
/// </summary>
/// <param name="repo">Type Repo</param>
/// <param name="tranzactie">type Transaction</param>
void repo_addtranzactie(Repo* repo, Tranzactie* tranzactie);

/// <summary>
/// Function to delete transaction from the repo.
/// </summary>
/// <param name="repo">type repo</param>
/// <param name="zi">type unsigned int</param>
/// <param name="dynamicallyAllocated">type int, 0 for Statically allocated and 1 dynamically.</param>
void repo_deletetranzactie(Repo* repo, unsigned int zi, int dynamicallyAllocated);

/// <summary>
/// Function that returns the size of the repo(number of elemnets in the repo)
/// </summary>
/// <param name="repo">type repo</param>
/// <returns>Integer (number of elements in repo)</returns>
unsigned int repo_getsize(Repo* repo);

/// <summary>
/// Function that returns Transaction on specified position.
/// </summary>
/// <param name="repo">Type repo</param>
/// <param name="position">Unsigned int</param>
/// <returns>Element (In our case Tranzaction)</returns>
Element repo_getbyposition(Repo* repo, int position);

#endif // !REPO_H_
