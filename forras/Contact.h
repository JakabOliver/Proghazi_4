#ifdef MEMTRACE
#include "memtrace.h"
#endif
#include "Sajat_string.h"
#include "Telefonszam.h"
#ifndef CONTACT_H
#define CONTACT_H
//a Kapcsolat osztály
//Képes tárolni: Vezeték nevet, Keresztnevet, Becenevet, Lakcímet, Mobil számot és Privát telefonszámot is mindenkihez.
class Contact
{
	String vNev;
	String kNev;
	String bNev;
	String Cim;
	Telefonszam mSzam;
	Telefonszam pSzam;
public:
	Contact *kov;
	Contact();
	Contact(String vezNev, String kerNev, String becNev, String lakCim, Telefonszam mobSzam, Telefonszam priSzam);
	Contact(const Contact& kapcsolat);
	void operator=(Contact& kapcsolat);
	bool operator==(Contact& masik);
	bool operator!=(Contact masik);
	bool operator>(Contact& masik);
	String getvNev() const;
	String getkNev() const;
	String getbNev() const;
	String getCim() const;
	Telefonszam getmSzam() const;
	Telefonszam getpSzam() const;
	void setvNev(String vezNev);
	void setkNev(String kerNev);
	void setbNev(String becNev);
	void setCim(String lakCim);
	void setmSzam(Telefonszam mobSzam);
	void setpSzam(Telefonszam priSzam);

};

std::ostream& operator<<(std::ostream& os, Contact& kapcsolat);


#endif // !CONTACT_H
