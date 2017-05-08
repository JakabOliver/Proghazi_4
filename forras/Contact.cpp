#include "Contact.h"
#include "Sajat_string.h"


//default konstruktor
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

//paraméterezett konstruktor. A kapott paraméterketet beállítja az adattagjainak 
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
//Copy konstruktor. A paraméterként kapott Contact összes adatát átmásolja a sajátjába azok getter függvényeit használva
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
//operátor = lemásolja a kapott Contact adatait a sajátjába. 
//(mivel nincs dinamikus memória foglalás, ezért nem számít, ha a saját adatait próbálja meg bemásolni)
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
//operator==:
//Eldönti, hogy két Contact azonos-e
bool Contact::operator==(Contact & masik)
{
	//Ehhez össze kell hasonlítani minden tulajdonságát, és ha bármelyik is különbözik, akkor hamissal kell vissza térni.
	if (getvNev() != masik.getvNev())	return false;
	if (getkNev() != masik.getkNev())	return false;
	if (getbNev() != masik.getbNev())	return false;
	if (getCim() != masik.getCim()) return false;
	if (getmSzam() != masik.getmSzam()) return false;
	if (getpSzam() != masik.getpSzam()) return false;
	return true;
}
//A nem egyenlõ operator azt vizsgálja, hogy nem egyenlõ-e a kettõ.
bool Contact::operator!=(Contact  masik)
{
	return !(*this==masik);
}
//operator > azt nézi, hogy a paraméterként kapott Contact neve ABC-ben elõrébb van-e
bool Contact::operator>(Contact& masik)
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
//Getter függvények
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
//Setter függvények
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
//Kiíró operator
//Kiírja a vezeték név+ keresztnév kombót
//Ha becenév nem üres, akkor azt is. 
//Ezek után meg kiírja mind a két telefonszámot egysorba (ha valamelyik nincs, akkor annak a kiíró függvénye semmit nem ír ki) 
std::ostream & operator<<(std::ostream & os, Contact& kapcsolat)
{
	os << "Név: " << kapcsolat.getvNev() << " " << kapcsolat.getkNev();
	if (kapcsolat.getbNev() != String(""))
		os << "/" << kapcsolat.getbNev();
	os<< std::endl;
	os << "\tCím: " << kapcsolat.getCim() << std::endl << "\tTelefonszam:" << std::endl;
	os << "\t"<< kapcsolat.getmSzam() << "\t" << kapcsolat.getpSzam() << std::endl;
	return os;
}
