#include "Sajat_string.h"
#include <string.h>

String::String(char betu) 
{
	len = 1;
	pData = new char[len + 1];
	pData[0] = betu;
	pData[1] = '\0';
}

String::String(const char* p)
{
	len = strlen(p);					// Meghatározzuk a hosszát
	pData = new char[len+1];			// Helyet foglalunk
	strcpy(pData,p);
}

String::String(const String& szo)
{
	len = szo.len;						// Meghatározzuk a hosszát
	pData = new char[len+1];			//helyet foglalunk
	strcpy(pData, szo.pData);
}


/// <summary>
/// Operator[]s the specified i.
/// </summary>
///<excepction cref="const char*">Túl indexelés esetén</exception>
/// <param name="i">A kívánt index</param>
/// <returns>Az adott indexû elemmel</returns>

char& String::operator[] (unsigned int i)
{
	if (i >= len)		throw "túl indexelés";
	else				return pData[i];
}
char& String::operator[]  (unsigned int i) const
{
	if (i >= len)		throw "túl indexelés";
	else				return pData[i];
}

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

bool String::operator!=(char * szo)
{
	return szo[0]!=pData[0];
}

bool String::operator==(String & masik)
{
	if (getHossz() != masik.getHossz())
		return false;
	for (unsigned int i = 0; i < getHossz(); i++)
		if (pData[i] != masik[i])
			return false;
	return true;
}

bool String::operator!=(String & masik)
{
	return !(*this == masik);
}

bool String::operator>(String & masik)
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


std::ostream& operator<<(std::ostream& os, String szo)
{
	os << szo.adat();
	return os;
}


#include <cstring>              // Stringmûveletekhez

std::istream& operator>>(std::istream& is, String& szo)
{
	char b;
	szo = "";
	while (is >> b)
	{
		is.unsetf(std::ios_base::skipws);	// utána pedig már nem
		if(b=='\n')
		//if (isspace(b))
			break;
		else 
		{
			szo = szo + b;               // végére fûzzük a karaktert
		}
	}
	return is;
}