#include "Telefonszam.h"
#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <cctype>
//komment
using namespace std;

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
		//std::cout << "vezet�kes:" << std::endl;
		//std::cout << "Telefonszam="<<telefonszam << std::endl;
		//06-1- t�pus� sz�mr�l van sz�
		eloHivo = telefonszam / 10000000;
		//ha 10n�l kisebb, akkor 0+elohivo
		//std::cout << "el�h�v� :" << eloHivo << std::endl;
		telefonszam = telefonszam % 10000000;
		szolgaltato = telefonszam / 1000000;
		//std::cout << "szolg�ltat�:" << szolgaltato << std::endl;
		telefonszam = telefonszam % 1000000;
		//std::cout << "Telefonszam=" << telefonszam << std::endl;
		szam = telefonszam;
	}
	else
	{
		//std::cout << "mobil" << std::endl;

		//std::cout << "Telefonszam=" << telefonszam << std::endl;
		//06-30- t�pus� sz�mr�l van sz�
		eloHivo = telefonszam / 1000000000;
		//ha 10n�l kisebb, akkor 0+elohivo
		//std::cout << "el�h�v� :" << eloHivo << std::endl;
		telefonszam = telefonszam % 1000000000;
		//std::cout << "Telefonszam=" << telefonszam << std::endl;
		szolgaltato = telefonszam / 10000000;
		//std::cout << "szolg�ltat�:" << szolgaltato << std::endl;
		telefonszam = telefonszam % 10000000;
		//std::cout << "Telefonszam=" << telefonszam << std::endl;
		szam = telefonszam;
	}
}


void Telefonszam::setElo(int sz=6)
{
	eloHivo = sz;
}
void Telefonszam::setSzolg(int sz=0)
{
	szolgaltato = sz;
}
void Telefonszam::setSzam(int sz=0)
{
	szam = sz;
}

bool Telefonszam::operator==(Telefonszam & masik)
{
	if (getElo() != masik.getElo())			return false;
	if (getSzolg() != masik.getSzolg())		return false;
	if (getSzam() != masik.getSzam())		return false;
	return true;
}

bool Telefonszam::operator!=(Telefonszam & masik)
{
	return !(*this==masik);
}


std::ostream& operator<<(std::ostream & os, Telefonszam szam)
{
	if (szam.getSzam()==0)
		return os;
	if (szam.getElo() < 10)
		os << "0";
	os << szam.getElo() <<" "<< szam.getSzolg() <<"-"<< szam.getSzam();
	return os;
}

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
