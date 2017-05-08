#include<iostream>


#ifdef MEMTRACE
#include "memtrace.h"
#endif
#include"Sajat_string.h"


#ifndef TELEFONSZAM_H
#define TELEFONSZAM_H

class Telefonszam
{
	int eloHivo;		//A telefonszam oszt�ly h�rom r�szben t�rolja el a sz�mot.
	int szolgaltato;	//K�l�n az orsz�g azonos�t�j�t, a szolg�ltat�-�t majd k�l�n mag�t a sz�mot.
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
