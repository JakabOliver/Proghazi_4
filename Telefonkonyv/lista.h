#include "Contact.h"
#include <fstream>

#ifndef LISTA_H
#define LISTA_H


struct Lista
{
	Contact *Elso;
	Lista() { Elso = NULL; }
	Lista(Contact& Uj) { Elso = new Contact;		*Elso =Uj; }
	~Lista();
	void beszur(Contact& kapcsolat);
	void listaz(void);
	void urit(void);
	bool szerepele(Contact& kapcsolat);
	void sorbarendez(void);
	std::ostream& write(std::ostream&os) const;
	std::istream& read(std::istream& is);
};

#endif // !LISTA_H
