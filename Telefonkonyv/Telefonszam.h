#include<iostream>
#include"Sajat_string.h"

#ifndef TELEFONSZAM_H
#define TELEFONSZAM_H

class Telefonszam
{
	int eloHivo;
	int szolgaltato;
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
	bool operator!=(Telefonszam& masik);
	
};

std::ostream& operator<<(std::ostream& os, Telefonszam szam);
std::istream& operator>>(std::istream& is, Telefonszam& szam);


#endif // !TELEFONSZAM_H
