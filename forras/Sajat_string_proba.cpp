#include "Sajat_string.h"



#ifdef SAJAT_STRING


int main(void)
{
	setlocale(LC_ALL, "");
	try
	{
		String alma('a');
		String korte("Sz�veg");
		String korte2("SS�veg");
		String barack = alma;
		char a = korte[1];
		String narancs = korte + alma+a;
		if (narancs != korte)
			std::cout << "�sszead�s sikeres\n";
		if (korte != korte2)
			std::cout << "A nem egyenl� f�ggv�ny is j�l m�k�dik\n";
		if (korte > korte2)
			std::cout << "proba\n";
		if (korte> narancs)
			std::cout << "fenn all a rend\n";
		String olvas;
		std::cout << "�rj valamit: ";
		std::cin >> olvas;
		std::cout << "Ezt �rtad be?: " << olvas;

	}

	catch (...)
	{
		std::cout << "Baj van \n";
	}
	std::cout << "M�k�dik";
}


#endif // SAJAT_STRING
