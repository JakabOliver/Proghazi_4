#ifndef SAJAT_STRING_H
#define SAJAT_STRING_H


#include <iostream>

	

/** <summary>
 * Ez az osztály <see cref="String"/>
 * 
 *</summary>
*/
class String
{
	char *pData;        /// pointer az adatra
	unsigned int len;   /// hossz lezáró nulla nélkül
public:
	//default konstruktor
	String() :len(0), pData(0) {}
	String(char betu);
	String(const char* p);
	String(const String& szo);
	unsigned int getHossz() { return len; }
	unsigned int  getHossz()const { return len; }
	const char* adat() const { if (pData) return pData; else return ""; }
	//operator[] egy adott elemét adja vissza a sztringnek.
	char& operator[] (unsigned int i);
	char& operator[]  (unsigned int i)const;
	
	String operator+ (char betu) const { return *this + String(betu); }
	String operator+ (const String& szo) const;
	String& operator= (const String& szo);
	String& operator+=(const String& szo) 	{	*this = *this + szo;		return *this;}
	bool operator!=(char* szo);
	bool operator==(String& masik);
	bool operator!=(String& masik);
	bool operator>(String& masik);
	~String() {	delete[] pData; }
};


std::ostream& operator<<(std::ostream& os, String szo);
std::istream& operator>>(std::istream& is, String& szo);

#endif // !SAJAT_STRING_H
