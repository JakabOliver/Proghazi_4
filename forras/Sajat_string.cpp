#include "Sajat_string.h"
#include <string.h>
#include <cstring>
//String el��ll�t�sa bet�b�l.
String::String(char betu) 
{
	len = 1;
	pData = new char[len + 1];
	pData[0] = betu;
	pData[1] = '\0';
}
//String el��ll�t�sa C t�pus� stringb�l.
String::String(const char* p)
{
	len = strlen(p);					// Meghat�rozzuk a hossz�t
	pData = new char[len+1];			// Helyet foglalunk
	strcpy(pData,p);
}
//Copy Konstruktor. 
String::String(const String& szo)
{
	len = szo.len;						// Meghat�rozzuk a hossz�t
	pData = new char[len+1];			//helyet foglalunk
	strcpy(pData, szo.pData);
}


/// <summary>
/// Operator[]s the specified i.
/// </summary>
///<excepction cref="const char*">T�l indexel�s eset�n</exception>
/// <param name="i">A k�v�nt index</param>
/// <returns>Az adott index� elemmel</returns>
char String::operator[] (unsigned int i)
{
	if (i >= len)		throw "t�l indexel�s";
	else				return pData[i];
}
char String::operator[]  (unsigned int i) const
{
	if (i >= len)		throw "t�l indexel�s";
	else				return pData[i];
}
//�sszad� operator:
//A f�ggv�nyen bel�l l�trehoz egy stringet amibe egym�s ut�n bem�solja a k�t string adat�t, majd azzal visszat�r.
String String::operator+ (const String& szo) const
{
	String temp;		
	temp.len = len + szo.len;
	delete[] temp.pData;
	temp.pData = new char[temp.len + 1];
	strcpy(temp.pData, pData);
	strcat(temp.pData, szo.pData);
	return temp;
}
//Egyenl�s�g operator
//Ha nem saj�t mag�t adjuk meg a k�t v�g�hez, akkor kit�rli a saj�t adat�t �s a hely�re be�rja, param�ter adatait.
String& String::operator= (const String& szo)
{
	if (this!=&szo)
	{
		delete[] pData;
		len= szo.len;
		pData = new char[len + 1];
		strcpy(pData, szo.pData);
	}
	return *this;
}

//Eld�nti, hogy a param�terk�nt kapott String tartalma megegyezik-e a saj�tj�val. 
//Ha a kett� hossza k�l�nb�zik, akkor biztosan nem lehet azonos a tartalmuk
//majd v�gig n�zi a kett� mindegyik bet�j�t, �s ha van olyan ahol nem egyezik, akkor hamissal t�r vissza.
//De ha v�gig �r, akkor igazat ad vissza
bool String::operator==(String  masik)
{
	if (getHossz() != masik.getHossz())
		return false;
	for (unsigned int i = 0; i < getHossz(); i++)
		if (pData[i] != masik[i])
			return false;
	return true;
}
//A nem egyeln� operator azt vizsg�lja, hogy a kett� nem egyenl�-e
bool String::operator!=(String masik)
{
	return !(*this == masik);
}
//Nagyobb-e operator:
//Azt vizsg�lja, hogy a param�terk�nt kapott String 
//ABC rendben el�r�bb van-e, mint a saj�t adata. 
//Ehhez nem k�l�nb�zteti meg a kis �s nagybet�ket.
bool String::operator>(String masik)
{
	if (getHossz() < masik.getHossz())
		for (unsigned int i = 0; i < getHossz(); i++)
		{
			if (tolower(pData[i]) >tolower( masik[i]))
				return true;
			else if (tolower(pData[i]) < tolower(masik[i]))
				return false;
		}
	else
	{
		for (unsigned int i = 0; i < masik.getHossz(); i++)
		{
			if (tolower(pData[i]) >tolower(masik[i]))
				return true;
			else if (tolower(pData[i]) < tolower(masik[i]))
				return false;
		}
	}
	return false;
}

//A kiir� operator, egyszer�en kiirja a pDat�t.
std::ostream& operator<<(std::ostream& os, String szo)
{
	os << szo.adat();
	return os;
}

//A beolvas�s oper�tor, '\n' (sorv�ge jel)-ig olvas
//Minden amit addig olvas (egy�b whitespac-ekkel egy�tt) beker�l a param�terk�nt kapott sz�ba.
std::istream& operator>>(std::istream& is, String& szo)
{
	char b;
	szo = "";
	while (is >> b)
	{
		is.unsetf(std::ios_base::skipws);	// ut�na pedig m�r nem
		if (b == '\n')
			//if (isspace(b))
			break;
		else 
		{
			szo = szo + b;               // v�g�re f�zz�k a karaktert
		}
	}
	return is;
}