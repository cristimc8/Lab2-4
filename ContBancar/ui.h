#ifndef UI_H_
#define UI_H_
#include "Service.h"

typedef struct {
	Service* service;
}UI;


void ui_init(UI* ui, Service* service);

void ui_destroy(UI* ui);

void start_loop(UI* ui);

void show_options();

void ui_display_tranzactie(Tranzactie* tranzactie);

void ui_display_vector_of_transactions(Vector* tranzactii);

void ui_display_tranzactie_show(Tranzactie* tranzactie);

#endif // !UI_H_
