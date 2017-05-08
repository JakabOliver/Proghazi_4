
#include <fstream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif
#include "Contact.h"

#ifndef LISTA_H
#define LISTA_H


struct Lista
{
	Contact *Elso;
	//default konstruktor - Az pointert NULL-ra állítja
	Lista() { Elso = NULL; }
	//Copy konstruktor - A kapott paraméternek helyet foglal, és az Elsõ pointert arra állítja.
	Lista(Contact& Uj) { Elso = new Contact;		*Elso =Uj; }
	~Lista();
	void beszur(Contact& kapcsolat);
	void listaz(void);
	void urit(void);
	bool szerepele(Contact& kapcsolat);
	std::ostream& write(std::ostream&os) const;
	std::istream& read(std::istream& is);
};

#endif // !LISTA_H
