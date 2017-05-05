#include "Sajat_string.h"
#include "lista.h"


#include <windows.h>
#include <conio.h>

#ifndef JATEK

void kapcsolatotbetolt(Lista& lista);


struct Jatek
{
	bool isRunning;
	String menupontok;
	Lista lista;
	Jatek(String menupont) :isRunning(true), menupontok(menupont)
	{
		std::cout << "Üdvözöllek Olivér telefonkönyvében!" << std::endl;
	}
	void menu(void);
	void uj(void);
	void listaz(void);
	void vegigjar(void);

};


#endif // !JATEK

