#include "Contact.h"



Contact::Contact()
{
	vNev = "";
	kNev = "";
	bNev = "";
	Cim = "";
	mSzam = Telefonszam();
	pSzam = Telefonszam();
	kov = NULL;
}


Contact::Contact(String VezNev, String kerNev, String becNev, String lakCim, Telefonszam mobSzam, Telefonszam priSzam)
{
	vNev = VezNev;
	kNev = kerNev;
	bNev = becNev;
	Cim = lakCim;
	mSzam = mobSzam;
	pSzam = priSzam;
	kov = NULL;
}

Contact::Contact(const Contact & kapcsolat)
{
	vNev = kapcsolat.getvNev();
	kNev = kapcsolat.getkNev();
	bNev = kapcsolat.getbNev();
	Cim = kapcsolat.getCim();
	mSzam = kapcsolat.getmSzam();
	pSzam = kapcsolat.getpSzam();
	kov = NULL;
}

Contact::~Contact()
{
}

void Contact::operator=(Contact& kapcsolat)
{
	vNev = kapcsolat.getvNev();
	kNev = kapcsolat.getkNev();
	bNev = kapcsolat.getbNev();
	Cim = kapcsolat.getCim();
	mSzam = kapcsolat.getmSzam();
	pSzam = kapcsolat.getpSzam();
	kov = NULL;
}

bool Contact::operator==(Contact & masik)
{
	//össze kell hasonlítani minden tulajdonságát, és ha bármelyik is különbözik, akkor hamissal kell vissza térni.
	if (getvNev() != masik.getvNev())	return false;
	if (getkNev() != masik.getbNev())	return false;
	if (getbNev() != masik.getbNev())	return false;
	if (getCim() != masik.getCim()) return false;
	if (getmSzam() != masik.getmSzam()) return false;
	if (getpSzam() != masik.getpSzam()) return false;
	return true;
}

bool Contact::operator!=(Contact & masik)
{
	return !(*this==masik);
}

bool Contact::operator>(Contact & masik)
{
	//Azt vizsgálja, hogy kisebb-e a másik, mint az adott kontakt. 
	if (getvNev() > masik.getvNev()) return true;
	else if (getvNev() == masik.getvNev())
	{
		if (getkNev() > masik.getkNev()) return true;
		if (getbNev() > masik.getbNev()) return true;
		//Csak a nevet hasonlítom össze 
	}
	return false;
}

String Contact::getvNev() const
{
	return vNev;
}

String Contact::getkNev() const
{
	return kNev;
}

String Contact::getbNev() const
{
	return bNev;
}

String Contact::getCim() const
{
	return Cim;
}

Telefonszam Contact::getmSzam() const
{
	return mSzam;
}

Telefonszam Contact::getpSzam() const
{
	return pSzam;
}

void Contact::setvNev(String vezNev)
{
	vNev = vezNev;
}

void Contact::setkNev(String kerNev)
{
	kNev = kerNev;
}

void Contact::setbNev(String becNev)
{
	bNev = becNev;
}

void Contact::setCim(String lakCim)
{
	Cim = lakCim;
}

void Contact::setmSzam(Telefonszam mobSzam)
{
	mSzam = mobSzam;
}

void Contact::setpSzam(Telefonszam priSzam)
{
	pSzam = priSzam;
}

std::ostream & operator<<(std::ostream & os, Contact& kapcsolat)
{

	os << "Név: " << kapcsolat.getvNev() << " " << kapcsolat.getkNev();
	if (kapcsolat.getbNev() != "")
		os << "/" << kapcsolat.getbNev();
	os<< std::endl;
	os << "\tCím: " << kapcsolat.getCim() << std::endl << "\tTelefonszam:" << std::endl;
	os << "\t"<< kapcsolat.getmSzam() << "\t" << kapcsolat.getpSzam() << std::endl;
	// TODO: insert return statement here
	return os;
}
