#include "Telefonszam.h"

//Ha üresen jön létre, akkor mindenhova bírjuk, hogy 0. Így biztos nem keletkezik kivétel, mert ezzel hasonlítjuk össze a többit.
Telefonszam::Telefonszam()
{
	eloHivo = 0;		
	szolgaltato = 0;
	szam = 0;
}

Telefonszam::Telefonszam(long long int telefonszam)
{
	setlocale(LC_ALL, "");			// ez beállítja az op.rendszer által használt
									// nyelvi környezetet, amit feltételezünk, hogy magyar
									// Windows alatt a konzol ablak betûkészletét állítsa "Lucida Console"-ra!
	//std::cout << "Telefonszam=" << telefonszam << std::endl;
	/*fel kell darabolni három részre. Ország+Szolgáltató+szám
	*Alapesetben feltesszük, hogy az elsõ két számjegy az ország
	* megnézzük, hogy hányjegyû a szám.
	*/
	if (telefonszam / 100000000 == 0)
	{
		//06-1- típusú számról van szó
		eloHivo = telefonszam / 10000000;
		//ha 10nél kisebb, akkor 0+elohivo
		telefonszam = telefonszam % 10000000;
		szolgaltato = telefonszam / 1000000;
		telefonszam = telefonszam % 1000000;
		szam = telefonszam;
	}
	else
	{
		//06-30- típusú számról van szó
		eloHivo = telefonszam / 1000000000;
		//ha 10nél kisebb, akkor 0+elohivo
		telefonszam = telefonszam % 1000000000;
		szolgaltato = telefonszam / 10000000;
		telefonszam = telefonszam % 10000000;
		szam = telefonszam;
	}
}

//Az ország beállítása
void Telefonszam::setElo(int sz=6)
{
	eloHivo = sz;
}
//A szolgáltató beállítása
void Telefonszam::setSzolg(int sz=0)
{
	szolgaltato = sz;
}
// A szám beállítása
void Telefonszam::setSzam(int sz=0)
{
	szam = sz;
}
//Két telefonszám összehasonlítása.
bool Telefonszam::operator==(Telefonszam& masik)
{
	//Sorba végig nézi egyesével, és ha bármelyik része nem egyenlõ, akkor õk sem azonosak. Ha mindegyik egyenlõ, akkor azonosak.
	if (getElo() != masik.getElo())			return false;
	if (getSzolg() != masik.getSzolg())		return false;
	if (getSzam() != masik.getSzam())		return false;
	return true;
}
//A nem egyenlõ úgy áll ellõ, hogy megnézi, hogy nem egyenlõek-e
bool Telefonszam::operator!=(Telefonszam masik)
{
	return !(*this==masik);
}

//A kiirás úgy néz ki, hogy ha a szám 0, akkor nem létezik a szám, így nincs mit kiirni
//Ha az ország 10nél kisebb, akkor kap egy 0-st az elejére. 
//utána pedig megy ki az adott sémra: 06 20-5821847
std::ostream& operator<<(std::ostream & os, Telefonszam szam)
{
	if (szam.getSzam()==0)
		return os;
	if (szam.getElo() < 10)
		os << "0";
	os << szam.getElo() <<" "<< szam.getSzolg() <<"-"<< szam.getSzam();
	return os;
}
//A beolvasás pedig úgy mûködik, hogy addig olvas, amíg számot olvas, addig hozzáadja a végéhez.
std::istream & operator>>(std::istream & is, Telefonszam& szam)
{
	long long int sz = 0;
	char b;
	while (is >> b)
	{
		if (isspace(b)|| !isdigit(b))
			break;
		sz *= 10;
		sz+= (b - '0');
	}
	Telefonszam szam2 = sz;
	szam = szam2;
	return is;
}

