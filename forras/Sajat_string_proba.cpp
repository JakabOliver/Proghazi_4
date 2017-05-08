#include "Sajat_string.h"



#ifdef SAJAT_STRING


int main(void)
{
	setlocale(LC_ALL, "");
	try
	{
		String alma('a');
		String korte("Szöveg");
		String korte2("SSöveg");
		String barack = alma;
		char a = korte[1];
		String narancs = korte + alma+a;
		if (narancs != korte)
			std::cout << "összeadás sikeres\n";
		if (korte != korte2)
			std::cout << "A nem egyenlõ függvény is jól mûködik\n";
		if (korte > korte2)
			std::cout << "proba\n";
		if (korte> narancs)
			std::cout << "fenn all a rend\n";
		String olvas;
		std::cout << "Írj valamit: ";
		std::cin >> olvas;
		std::cout << "Ezt írtad be?: " << olvas;

	}

	catch (...)
	{
		std::cout << "Baj van \n";
	}
	std::cout << "Mûködik";
}


#endif // SAJAT_STRING
