#ifdef MEMTRACE
#include "memtrace.h"
#endif

#include "Sajat_string.h"
#include "lista.h"

#ifndef JATEK

void kapcsolatotbetolt(Lista& lista);
//A J�t�k oszt�ly maga a Telefonkonyv m�k�d�s�nek az �sszefog�sa.
//Ez az ami �ssze fog mindent �s mondhatni � az aki dolgozik 
//h�rom adattagja van:
//isRunning: Fut-e m�g a telefonk�nyv, ez n�h�ny helyen hasznos, illetve a f� f�ggv�ny �jra �s �jra megh�vja a menu f�ggv�nyt amig ezt hamisra nem �ll�tjuk
//menupontok: Ez csak annyi, hogy milyen menupontok vannak.
//lista, ami egy egyszer� l�ncolt lista, ami az adatokra mutat� pointert t�rolja.
struct Jatek
{
	bool isRunning;
	String menupontok;
	Lista lista;
	//nincs default konstruktora, csak az egyparam�teres, hiszen l�trehoz�skor meg kell adni neki, hogy milyen menupontokkal rendelkezik
	Jatek(String menupont) :isRunning(true), menupontok(menupont)
	{
		//Egy kis k�sz�nt�s
		std::cout << "�dv�z�llek Oliv�r telefonk�nyv�ben!" << std::endl;
	}
	void menu(void);
	void uj(void);
	void vegigjar(void);
	void modosit(Contact&);

};

#endif // !JATEK

