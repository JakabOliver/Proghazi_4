#include "Sajat_string.h"



#ifdef SAJAT_STRING


int main(void)
{

	setlocale(LC_ALL, "");
	try
	{
		String alma("Szöveg");
	}

	catch (...)
	{
		std::cout << "Van baj\n";
	}
	std::cout << "Mûködik";
	while (true);
}


#endif // SAJAT_STRING
