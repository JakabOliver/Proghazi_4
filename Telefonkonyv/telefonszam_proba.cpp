#include "Telefonszam.h"
#include <iostream>

#ifdef TELEFONSZAM

int main(void)
{
	long long int alma = 61582184; //06-1-582-184
	long long int korte = 6205821847; //06-20-582-1847
	Telefonszam tel(alma);
	Telefonszam tel2(korte);
	Telefonszam tel3;
	std::cin >> tel3;
	return 0;
}

#endif // TELEFONSZAM

