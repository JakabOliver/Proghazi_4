#include "Telefonszam.h"

//Ha �resen j�n l�tre, akkor mindenhova b�rjuk, hogy 0. �gy biztos nem keletkezik kiv�tel, mert ezzel hasonl�tjuk �ssze a t�bbit.
Telefonszam::Telefonszam()
{
	eloHivo = 0;		
	szolgaltato = 0;
	szam = 0;
}

Telefonszam::Telefonszam(long long int telefonszam)
{
	setlocale(LC_ALL, "");			// ez be�ll�tja az op.rendszer �ltal haszn�lt
									// nyelvi k�rnyezetet, amit felt�telez�nk, hogy magyar
									// Windows alatt a konzol ablak bet�k�szlet�t �ll�tsa "Lucida Console"-ra!
	//std::cout << "Telefonszam=" << telefonszam << std::endl;
	/*fel kell darabolni h�rom r�szre. Orsz�g+Szolg�ltat�+sz�m
	*Alapesetben feltessz�k, hogy az els� k�t sz�mjegy az orsz�g
	* megn�zz�k, hogy h�nyjegy� a sz�m.
	*/
	if (telefonszam / 100000000 == 0)
	{
		//06-1- t�pus� sz�mr�l van sz�
		eloHivo = telefonszam / 10000000;
		//ha 10n�l kisebb, akkor 0+elohivo
		telefonszam = telefonszam % 10000000;
		szolgaltato = telefonszam / 1000000;
		telefonszam = telefonszam % 1000000;
		szam = telefonszam;
	}
	else
	{
		//06-30- t�pus� sz�mr�l van sz�
		eloHivo = telefonszam / 1000000000;
		//ha 10n�l kisebb, akkor 0+elohivo
		telefonszam = telefonszam % 1000000000;
		szolgaltato = telefonszam / 10000000;
		telefonszam = telefonszam % 10000000;
		szam = telefonszam;
	}
}

//Az orsz�g be�ll�t�sa
void Telefonszam::setElo(int sz=6)
{
	eloHivo = sz;
}
//A szolg�ltat� be�ll�t�sa
void Telefonszam::setSzolg(int sz=0)
{
	szolgaltato = sz;
}
// A sz�m be�ll�t�sa
void Telefonszam::setSzam(int sz=0)
{
	szam = sz;
}
//K�t telefonsz�m �sszehasonl�t�sa.
bool Telefonszam::operator==(Telefonszam& masik)
{
	//Sorba v�gig n�zi egyes�vel, �s ha b�rmelyik r�sze nem egyenl�, akkor �k sem azonosak. Ha mindegyik egyenl�, akkor azonosak.
	if (getElo() != masik.getElo())			return false;
	if (getSzolg() != masik.getSzolg())		return false;
	if (getSzam() != masik.getSzam())		return false;
	return true;
}
//A nem egyenl� �gy �ll ell�, hogy megn�zi, hogy nem egyenl�ek-e
bool Telefonszam::operator!=(Telefonszam masik)
{
	return !(*this==masik);
}

//A kiir�s �gy n�z ki, hogy ha a sz�m 0, akkor nem l�tezik a sz�m, �gy nincs mit kiirni
//Ha az orsz�g 10n�l kisebb, akkor kap egy 0-st az elej�re. 
//ut�na pedig megy ki az adott s�mra: 06 20-5821847
std::ostream& operator<<(std::ostream & os, Telefonszam szam)
{
	if (szam.getSzam()==0)
		return os;
	if (szam.getElo() < 10)
		os << "0";
	os << szam.getElo() <<" "<< szam.getSzolg() <<"-"<< szam.getSzam();
	return os;
}
//A beolvas�s pedig �gy m�k�dik, hogy addig olvas, am�g sz�mot olvas, addig hozz�adja a v�g�hez.
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

