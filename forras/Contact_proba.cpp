#include "Contact.h"
#include "Sajat_string.h"
//#include "Lista.h"

#ifdef CONTACT

//void Oliver(Lista& lista);

int main(void)
{
	//Lista uj;
	//Oliver(uj);
	String vezetek("Jakab");
	String kereszt("Gergo");
	String bece("Geri");
	String lakohely("2000 Szentendre, kadarka u. 48");
	Telefonszam telefon(6205821848);
	Contact k2(vezetek, kereszt, bece, lakohely, telefon,Telefonszam());
	//uj.beszur(k2);
	//uj.listaz();
}

/*
void Oliver(Lista& lista)
{
	Contact k1;
	k1.setvNev("Jakab");
	k1.setkNev("Olivér");
	k1.setbNev("Oli");
	k1.setCim("1117 Budapest, Szerémi sor 12/B 7. 29");
	k1.setmSzam(6205821847);
	lista.beszur(k1);
}
*/
#endif // CONTACT
