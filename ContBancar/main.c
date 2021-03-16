#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 


#include "Repo.h"
#include "Tranzactie.h"
#include "Service.h"
#include "ui.h"
#include "Test.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
	runAll();

	//init repo
	Repo* repo = (Repo*)malloc(sizeof(Repo));
	repo_init(repo);


	//init service
	Service* service = (Service*)malloc(sizeof(Service));
	service_init(service, repo);

	UI* ui = (UI*)malloc(sizeof(UI));
	ui_init(ui, service);

	start_loop(ui);

	service_destroy(service);
	free(service);
	free(repo);
	free(ui);

	_CrtDumpMemoryLeaks();
	//printf("%d", _CrtDumpMemoryLeaks());
	
	return 0;
}