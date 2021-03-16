#ifndef TRANZACTIE_H_
#define TRANZACTIE_H_

typedef struct{
	unsigned int zi;
	unsigned int suma;
	char* tip;
	char* descriere;

}Tranzactie;

/// <summary>
/// Function that initialisez the transaction element;
/// </summary>
/// <param name="tranzactie">Type transaction</param>
/// <param name="zi">type int</param>
/// <param name="suma">type int</param>
/// <param name="tip">type String</param>
/// <param name="descriere">type String</param>
void tranzactie_init(Tranzactie* tranzactie, unsigned int zi, unsigned int suma, char* tip, char* descriere);

/// <summary>
/// Function that destroyes the transaction element
/// </summary>
/// <param name="tranzactie"></param>
void tranzactie_destroy(Tranzactie* tranzactie);

/// <summary>
/// Functipn that gets the day from transaction
/// </summary>
/// <param name="tranzactie"></param>
/// <returns></returns>
unsigned int tranzactie_getZi(Tranzactie* tranzactie);

/// <summary>
/// Function that gets the type.
/// </summary>
/// <param name="tranzactie"></param>
/// <returns></returns>
char* tranzactie_getTip(Tranzactie* tranzactie);

/// <summary>
/// Function that returns the sum.
/// </summary>
/// <param name="tranzactie"></param>
/// <returns>Integer</returns>
unsigned int tranzactie_getsuma(Tranzactie* tranzactie);

/// <summary>
/// Function that returns the description.
/// </summary>
/// <param name="tranzactie"></param>
/// <returns>Char*</returns>
char* tranzactie_getdescriere(Tranzactie* tranzactie);

/// <summary>
/// Function that sets the description to the transaction.
/// </summary>
/// <param name="tranzactie"></param>
/// <param name="descriere"></param>
void tranzactie_setdescriere(Tranzactie* tranzactie, char* descriere);

/// <summary>
/// Function that sets the type. to the transaction
/// </summary>
/// <param name="tranzactie"></param>
/// <param name="tip"></param>
void tranzactie_settip(Tranzactie* tranzactie, char* tip);

/// <summary>
/// Function that sets the sum of the tramsaction.
/// </summary>
/// <param name="tranzactie"></param>
/// <param name="suma"></param>
void tranzactie_setsuma(Tranzactie* tranzactie, unsigned int suma);

/// <summary>
/// Function that sets the day of the transaction
/// </summary>
/// <param name="tranzactie"></param>
/// <param name="zi"></param>
void tranzactie_setzi(Tranzactie* tranzactie, unsigned int zi);


#endif // !TRANZACTIE_H_
