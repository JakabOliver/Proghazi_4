#ifndef SAJAT_STRING_H
#define SAJAT_STRING_H


#include <iostream>
#ifdef MEMTRACE
#include "memtrace.h"
#endif
	

/** <summary>
 * Ez az oszt�ly <see cref="String"/>
 * 
 *</summary>
*/
class String
{
	char *pData;        // pointer az adatra
	unsigned int len;   /*hossz lez�r� nulla n�lk�l*/
public:
	/*default konstruktor*/
	String() :pData(0),len(0) {}
	String(char betu);
	String(const char* p);
	String(const String& szo);
	unsigned int getHossz() { return len; }									//Megadja a sz� hossz�t
	unsigned int  getHossz()const { return len; }							//Megadja a sz� hossz�t
	const char* adat() const { if (pData) return pData; else return ""; }	//Igaz�b�l egy getter a pDat�ra.
	//operator[] egy adott elem�t adja vissza a sztringnek.
	char operator[] (unsigned int i);
	char operator[]  (unsigned int i)const;
	
	String operator+ (char betu) const { return *this + String(betu); } //Egy bet�t hozz�f�z a Stringhez.
	String operator+ (const String& szo) const;
	String& operator= (const String& szo);
	String& operator+=(const String& szo) 	{	*this = *this + szo;		return *this;} //A += ugye defin�ci�ja
	bool operator==(String masik);
	bool operator!=(String masik);
	bool operator>(String masik);
	~String() {	delete[] pData; }
};


std::ostream& operator<<(std::ostream& os, String szo);
std::istream& operator>>(std::istream& is, String& szo);

#endif // !SAJAT_STRING_H
