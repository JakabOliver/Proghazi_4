#include <iostream>
#include <stdlib.h>
#include <string>   
#ifdef MEMTRACE
#include "memtrace.h"
#endif

#include "Sajat_string.h"
#include "Contact.h"
#include "lista.h"
#include "Telefonszam.h"
#include "Jatek.h"


#define DEBUG
#ifdef DEBUG



int main(void)
{
	setbuf(stdin, 0);
	setlocale(LC_ALL, "");
	Jatek telefonkonyv("1. �sszes kapcsolat kilist�z�sa\n2. Kapcsolatok egyes�vel\n9. kil�p�s\n");
	try
	{
		std::ifstream infile("Lista.txt");
		Lista *ref = &telefonkonyv.lista;
		ref->read(infile);
	}
	catch(...)
	{/*Nem l�tezik a Lista.txt*/ }
	while (telefonkonyv.isRunning)
	{
		telefonkonyv.menu();
	}
	return 0;
}


#endif // DEBUG
