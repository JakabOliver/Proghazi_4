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
	setbuf(stdout, 0);
	setlocale(LC_ALL, "");
	Jatek telefonkonyv("1. összes kapcsolat kilistázása\n2. Kapcsolatok egyesével\n9. kilépés\n");
	try
	{
		std::cout << "Itt nyitjuk meg a listát" << std::endl;
		std::fstream infile;
		infile.open("Lista.txt");
		telefonkonyv.lista.read(infile);
	}
	catch(...)
	{/*Nem létezik a Lista.txt*/ }
	while (telefonkonyv.isRunning)
	{
		telefonkonyv.menu();
	}
	return 0;
}


#endif // DEBUG
