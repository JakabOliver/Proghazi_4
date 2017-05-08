#ifdef MEMTRACE
#include "memtrace.h"
#endif

#include "Sajat_string.h"
#include "lista.h"

#ifndef JATEK

void kapcsolatotbetolt(Lista& lista);
//A Játék osztály maga a Telefonkonyv mûködésének az összefogása.
//Ez az ami össze fog mindent és mondhatni õ az aki dolgozik 
//három adattagja van:
//isRunning: Fut-e még a telefonkönyv, ez néhány helyen hasznos, illetve a fõ függvény újra és újra meghívja a menu függvényt amig ezt hamisra nem állítjuk
//menupontok: Ez csak annyi, hogy milyen menupontok vannak.
//lista, ami egy egyszerû láncolt lista, ami az adatokra mutató pointert tárolja.
struct Jatek
{
	bool isRunning;
	String menupontok;
	Lista lista;
	//nincs default konstruktora, csak az egyparaméteres, hiszen létrehozáskor meg kell adni neki, hogy milyen menupontokkal rendelkezik
	Jatek(String menupont) :isRunning(true), menupontok(menupont)
	{
		//Egy kis köszöntés
		std::cout << "Üdvözöllek Olivér telefonkönyvében!" << std::endl;
	}
	void menu(void);
	void uj(void);
	void vegigjar(void);
	void modosit(Contact&);

};

#endif // !JATEK

