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

//param�terezett konstruktor. A kapott param�terketet be�ll�tja az adattagjainak 
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
//Copy konstruktor. A param�terk�nt kapott Contact �sszes adat�t �tm�solja a saj�tj�ba azok getter f�ggv�nyeit haszn�lva
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
//oper�tor = lem�solja a kapott Contact adatait a saj�tj�ba. 
//(mivel nincs dinamikus mem�ria foglal�s, ez�rt nem sz�m�t, ha a saj�t adatait pr�b�lja meg bem�solni)
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
//Eld�nti, hogy k�t Contact azonos-e
bool Contact::operator==(Contact & masik)
{
	//Ehhez �ssze kell hasonl�tani minden tulajdons�g�t, �s ha b�rmelyik is k�l�nb�zik, akkor hamissal kell vissza t�rni.
	if (getvNev() != masik.getvNev())	return false;
	if (getkNev() != masik.getkNev())	return false;
	if (getbNev() != masik.getbNev())	return false;
	if (getCim() != masik.getCim()) return false;
	if (getmSzam() != masik.getmSzam()) return false;
	if (getpSzam() != masik.getpSzam()) return false;
	return true;
}
//A nem egyenl� operator azt vizsg�lja, hogy nem egyenl�-e a kett�.
bool Contact::operator!=(Contact  masik)
{
	return !(*this==masik);
}
//operator > azt n�zi, hogy a param�terk�nt kapott Contact neve ABC-ben el�r�bb van-e
bool Contact::operator>(Contact& masik)
{
	//Azt vizsg�lja, hogy kisebb-e a m�sik, mint az adott kontakt. 
	if (getvNev() > masik.getvNev()) return true;
	else if (getvNev() == masik.getvNev())
	{
		if (getkNev() > masik.getkNev()) return true;
		if (getbNev() > masik.getbNev()) return true;
		//Csak a nevet hasonl�tom �ssze 
	}
	return false;
}
//Getter f�ggv�nyek
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
//Setter f�ggv�nyek
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
//Ki�r� operator
//Ki�rja a vezet�k n�v+ keresztn�v komb�t
//Ha becen�v nem �res, akkor azt is. 
//Ezek ut�n meg ki�rja mind a k�t telefonsz�mot egysorba (ha valamelyik nincs, akkor annak a ki�r� f�ggv�nye semmit nem �r ki) 
std::ostream & operator<<(std::ostream & os, Contact& kapcsolat)
{
	os << "N�v: " << kapcsolat.getvNev() << " " << kapcsolat.getkNev();
	if (kapcsolat.getbNev() != String(""))
		os << "/" << kapcsolat.getbNev();
	os<< std::endl;
	os << "\tC�m: " << kapcsolat.getCim() << std::endl << "\tTelefonszam:" << std::endl;
	os << "\t"<< kapcsolat.getmSzam() << "\t" << kapcsolat.getpSzam() << std::endl;
	return os;
}
