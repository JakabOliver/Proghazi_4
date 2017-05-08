#include<iostream>


#ifdef MEMTRACE
#include "memtrace.h"
#endif
#include"Sajat_string.h"


#ifndef TELEFONSZAM_H
#define TELEFONSZAM_H

class Telefonszam
{
	int eloHivo;		//A telefonszam osztály három részben tárolja el a számot.
	int szolgaltato;	//Külön az ország azonosítóját, a szolgáltató-ét majd külön magát a számot.
	int szam;
public:
	Telefonszam();							
	Telefonszam(long long int telefonszam);
	int getElo() { return eloHivo; }
	int getSzolg() { return szolgaltato; }
	int getSzam() { return szam; }
	void setElo(int);
	void setSzolg(int);
	void setSzam(int);
	bool operator==(Telefonszam& masik);
	bool operator!=(Telefonszam masik);
	
};

std::ostream& operator<<(std::ostream& os, Telefonszam szam);
std::istream& operator>>(std::istream& is, Telefonszam& szam);


#endif // !TELEFONSZAM_H
