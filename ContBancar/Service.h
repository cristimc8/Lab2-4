#ifndef SERVICE_H_
#define SERVICE_H_
#include "Repo.h"
#include "Vector.h"

typedef struct {
	Repo* repo;
}Service;


/// <summary>
/// Funuction that initializes the service
/// </summary>
/// <param name="service">type service</param>
/// <param name="repo">type Repo</param>
void service_init(Service* service, Repo* repo);

/// <summary>
/// Function that destroys the service.
/// </summary>
/// <param name="service">Service to be destoryed</param>
void service_destroy(Service* service);

/// <summary>
/// Function that sets the Repo for the Service.
/// </summary>
/// <param name="service">Type service</param>
/// <param name="repo">Type Repo</param>
void service_setrepo(Service* service, Repo* repo);

/// <summary>
/// Function that adds the transaction to the Repo of the Service.
/// </summary>
/// <param name="service">Type Serice</param>
/// <param name="tranzactie">Type Repo</param>
void adauga_tranzactie(Service* service, Tranzactie* tranzactie);

/// <summary>
/// Function that modifies a transaction from the repo inside the Service.
/// </summary>
/// <param name="service">Type Service</param>
/// <param name="zi">Type int</param>
/// <param name="suma">type int</param>
/// <param name="tip">type String</param>
/// <param name="descriere">type String</param>
void modificare_tranzactie(Service* service, unsigned int zi, unsigned int suma, char* tip, char* descriere);

/// <summary>
/// Function that removes a transaction from the repo inside the service.
/// </summary>
/// <param name="service">type service.</param>
/// <param name="zi">type int</param>
void sterge_tranzactie(Service* service, unsigned int zi);

/// <summary>
/// Function that returns the Repo for the Service.
/// </summary>
/// <param name="service">type service</param>
/// <returns>Repo element, From the service.</returns>
Repo* service_getRepo(Service* service); 

/// <summary>
/// Function that returns an array of transactions based on input criteria of tip.
/// </summary>
/// <param name="service">Service*</param>
/// <param name="tip">char*</param>
/// <returns>Vector[Transaction]</returns>
Vector* service_vizualizare_tranzactii_tip(Service* service, char* tip);

/// <summary>
/// Function that returns ann array of transactions based on input criteria of suma.
/// </summary>
/// <param name="service">Service*</param>
/// <param name="suma">Unsigned int</param>
/// <param name="mod">Short Int (0 means elements with sum bigger than third parameter and 1 is lesser)</param>
/// <returns>Vector[Transaction]</returns>
Vector* service_vizualizare_tranzactii_suma(Service* service, short int mod, unsigned int suma);

/// <summary>
/// Function that returns a Vector of transactions ordered mod (0 asc. and 1 desc.) by day.
/// </summary>
/// <param name="service">Service*</param>
/// <param name="mod">Short Int, 0 asc. and 1 desc.</param>
/// <returns>Ordered Vector[Transaction]</returns>
Vector service_ordonare_tranzactii_zi(Service* service, short int mod);

/// <summary>
/// Function that returns a Vector of transactions ordered mod (0 asc. and 1 desc.) by day.
/// </summary>
/// <param name="service">Service*</param>
/// <param name="mod">Short Int, 0 asc. and 1 desc.</param>
/// <returns>Ordered Vector[Transaction]</returns>
Vector service_ordonare_tranzactii_suma(Service* service, short int mod);

void bubbleSort(Vector* vector, int(*compareFunction)(void*, void*), int ascending);

#endif // !SERVICE_H_
