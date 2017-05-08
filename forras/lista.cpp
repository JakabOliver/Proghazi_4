#include "lista.h"

/// <summary>
///Ez itt a Lista osztály
/// Finalizes an instance of the <see cref="Lista"/> class.
/// </summary>
//A destruktor végig sétál a listán, és amig a végére nem ér, addig minden elemet felszabadít
Lista::~Lista()
{
	Contact* i = Elso; ;
	while (i != NULL)
	{
		Contact* tmp = i->kov;
		delete i;
		i = tmp;
	}
}
//A beszúr függvény megkeresi a "helyét" a kapcsolatnak és oda szúrja be
void Lista::beszur(Contact& kapcsolat)
{
	//Ha üres a lista, akkor egyszerûen a legelejére teszi be
	if (Elso == NULL)
	{
		Elso = new Contact;
		*Elso = kapcsolat;
	}
	//Ha nem üres, akkor megkeresi a helyét
	else
	{
		Contact* i;
		//Helyet foglalunk neki
		Contact *tmp = new Contact;
		*tmp = kapcsolat;
		//Elõször azt vizsgáljuk meg, hogy legelõre kerül-e
		if (*Elso > kapcsolat)
		{
			Contact *temp = Elso;
			Elso = tmp;
			Elso->kov = temp;
			return;
		}
		//Ha nem a legelsõ, akkor megkeressük a helyét. (oda kerül, ahol az elõtte lévõ "kisebb vagy egyenlõ" de a következõ már nagyobb.
		for (i = Elso; i->kov != NULL; i = i->kov)
		{
			if(*(i->kov)>kapcsolat)
			{
				Contact *temp = i->kov;
				i->kov = tmp;
				tmp->kov = temp;
				return;
			}
		}
		//Ha végig értünk, és egyik kontakt sem "nagyobb" nála akkor a végére kerül
		i->kov = tmp;
		tmp->kov = NULL;
	}
}
//A listában található összes kapcsolatot kiírja standard kimenetre
void Lista::listaz(void)
{
	Contact* i;
	for (i = Elso; i != NULL; i = i->kov)
		std::cout << *i;
}
//végig megy a listán minden adatot kitöröl belõle 
//Akkor van értelme, ha fájlbol olvasunk be, de nincs szükségünk semmire, ami addig a listában volt.
void Lista::urit(void)
{
	Contact* i = Elso; ;
	while (i != NULL)
	{
		Contact* tmp = i->kov;
		delete i;
		i = tmp;
	}
	Elso = NULL;
}
//Mivel ugyanazat a névjegyet nem lehet kétszer beszúrni a Telefonkonyvbe, ezért ez a függvény
//megvizsgálja, hogy az adott kapcsolat szerepele már a telefonkonyvben
bool Lista::szerepele(Contact & kapcsolat)
{
	//Ha üres a lista, akkor biztosan nem szerepel benne
	if (Elso == NULL)
		return false;
	//Ha nem, akkor végig járjuk és az összessel összehasonlítjuk
	for (Contact* i = Elso; i != NULL; i = i->kov)
		if (*i == kapcsolat)		//Ha bármelyik egyezik vele akkor szerepel benne
			return true;
	return false; //ha végig érünk és még nem tértünk vissza igazzal, akkor nem szerepel még benne.
}
//Fájlba írás 
//Mikor a programból kilépünk, akkor õ a benne található kapcsolatokat kiírja a kapott ostream-re
//jelen felhasnálás esetén ez egy fájl.
std::ostream& Lista::write(std::ostream&os) const
{
	//Azzal kezdjük, hogy adunk neki egy egyedi azonosítót, hogy tudjuk amikor legközelebb meg akarjuk nyitni, hogy jó fájlt olvasunk
	os << "Lista:" << std::endl;
	Contact* i = Elso;
	while (i != NULL)		//majd végig megyünk és minden kapcsolatot külön egyesével kiírunk
	{
		os << "Kapcsolat:" << std::endl << ",.,"; //minden sor elejére kerül egy egyedi szeparátor.
		os << i->getvNev() << std::endl << ",.,";
		os << i->getkNev() << std::endl << ",.,";
		os << i->getbNev() << std::endl << ",.,";
		os << i->getCim() << std::endl << ",.,";
		os << i->getmSzam() << std::endl << ",.,";
		os << i->getpSzam() << std::endl << ",.,";
		i = i->kov;
	}
	return os;
}
//Az olvasás függvény az adott istreamrõl olvassa be a listába az ott található adatokat
std::istream& Lista::read(std::istream& is)
{
	urit();		//Elõször mindent kitöröl a listából
	Contact kapcsolat;
	String tmp;
	Telefonszam temp;
	(is >> tmp); //Beolvasom, hogy jó fájlt olvasok-e
	if (tmp != String("Lista:")) throw std::out_of_range("Hibás olvasás");
	while ((is >> tmp).ignore(3))
	{														//Beolvasom az adatokat. Itt már nem foglalkozom vele, hogy mi van ha hibás, 
		(is >> tmp).ignore(3);								//hiszen az elején már meggyõzõdtem róla, hogy jó fájlt olvasok
		kapcsolat.setvNev(tmp);								//Vezetéknév
		(is >> tmp).ignore(3);
		kapcsolat.setkNev(tmp);								//Keresztnév
		(is >> tmp).ignore(3);
		kapcsolat.setbNev(tmp);								//Becenév
		(is >> tmp).ignore(3);
		kapcsolat.setCim(tmp);								//Lakcím
		(is >> tmp).ignore(3);
		int elo = 0;
		if (tmp.getHossz() > 0)
			elo = tmp[0] - '0';
		if (tmp.getHossz() > 1)
			elo = (tmp[0] - '0') * 10 + (tmp[1] - '0');
		temp.setElo(elo);
		int szolg = 0;
		if (tmp.getHossz() > 3)
			szolg = tmp[3] - '0';
		if (tmp.getHossz()>4)
			szolg = (tmp[3] - '0') * 10 + (tmp[4] - '0');
		temp.setSzolg(szolg);
		int szam = 0;
		if (tmp.getHossz()>6)
			szam = tmp[6] - '0';
		for (unsigned int i = 7; i < tmp.getHossz(); i++)
		{
			szam *= 10;
			szam += (tmp[i] - '0');

		}
		temp.setSzam(szam);
		kapcsolat.setmSzam(temp);								//MobilSzám

		(is >> tmp).ignore(3);
		elo = 0;
		if (tmp.getHossz() > 0)
			elo = tmp[0] - '0';
		if (tmp.getHossz() > 1)
			elo = (tmp[0] - '0') * 10 + (tmp[1] - '0');
		temp.setElo(elo);
		szolg = 0;
		if (tmp.getHossz() > 3)
			szolg = tmp[3] - '0';
		if (tmp.getHossz()>4)
			szolg = (tmp[3] - '0') * 10 + (tmp[4] - '0');
		temp.setSzolg(szolg);
		szam = 0;
		if (tmp.getHossz()>6)
			szam = tmp[6] - '0';
		for (unsigned int i = 7; i < tmp.getHossz(); i++)
		{
			szam *= 10;
			szam += (tmp[i] - '0');

		}
		temp.setSzam(szam);
		kapcsolat.setpSzam(temp);								//privat szam
		beszur(kapcsolat);
	}
	return is;
}