#include "Jatek.h"



void Jatek::menu(void)
{
	char ch;
	std::cout << "Kérlek válassz az alábbi menüpontok közül:\n";
	std::cout << menupontok;
	ch = _getch();
	while (ch - '0' < 0 || ch - '0' >9)
	{
		system("cls");
		std::cout << "Kérlek az alábbi menüpontok közül válassz:\n";
		std::cout << menupontok;
		ch = _getch();

	}
	system("cls");
	int c = ch - '0';
	switch (c)
	{
		//onyv("1. összes kapcsolat kilistázása\n2. Kapcsolatok egyesével\n9. kilépés\n");
	case 1:	listaz(); break;
	case 2: vegigjar(); break;
	case 3: kapcsolatotbetolt(lista); break;
	case 9:
		isRunning = false;	
		std::ofstream outfile("Lista.txt");
		lista.write(outfile);
		break;
	}
}

void Jatek::uj(void)
{
	Contact kapcsolat;
	String s("");
	Telefonszam mobil;
	int sz;
	std::cout << " Új kapcsolat megadása" << std::endl;
	std::cout << "Kérlek add meg az alábbi adatokat:" << std::endl;
	std::cout << "Vezeték név: ";					std::cin >> s;		kapcsolat.setvNev(s);
	std::cout << "Kereszt név: ";					std::cin >> s;		kapcsolat.setkNev(s);
	std::cout << "(opcionális)Becenév: ";			std::cin >> s;		kapcsolat.setbNev(s);
	std::cout << "Lakcím: ";						std::cin >> s;		kapcsolat.setCim(s);
	std::cout << "Telefonszam:\n" << "\tmobil: \n";
	std::cout << "\t\tOrszág:";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	else
		sz = 0;
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolgáltató: ";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSzám: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)
		sz = sz * 10 + s[i] - '0';
	mobil.setSzam(sz);
	kapcsolat.setmSzam(mobil);
	std::cout << "\tprivat: \n";
	std::cout << "\t\tOrszág:";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	else
		sz = 0;
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolgáltató: ";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSzám: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)
		sz = sz * 10 + s[i] - '0';
	mobil.setSzam(sz);
	kapcsolat.setpSzam(mobil);
	if(kapcsolat!=Contact() && !lista.szerepele(kapcsolat)) //Hogy ha nem üres a kontakt és még nem szerepel a névjegyzékben, akkor beszúrja
		lista.beszur(kapcsolat);
	system("cls");
}
void Jatek::listaz(void)
{
	lista.listaz();
	system("PAUSE");
	system("cls");
}

void Jatek::vegigjar(void)
{
	Contact* akt = lista.Elso;
	char c;
	do
	{
		system("cls");
		if (akt != NULL)
			std::cout << *akt;
		else if (lista.Elso != NULL)
		{
			akt = lista.Elso;
			std::cout << *akt;
		}
		else	
			std::cout << "Nincs kapcsolat a névjegyzékben. Kérlek adj hozzá" << std::endl;

		std::cout << "Kérlek a WASD gombokkal navigálj!" << std::endl;
		std::cout << "A: Elõzõ; D: Következõ; S: Törlés; W: Új beszúrása." << std::endl;
		std::cout << "Kilépéshez nyomd meg a 9-es gombot" << std::endl;
		c = _getch();
		if (c == 'a' && akt != NULL)
		{
			//Az a billenytû hatására hátra lépünk egyet
			if (akt != lista.Elso)
			{
				//egyszeresen láncolt listában ez nem olyan egyszerû. 
				Contact* i = lista.Elso; //Ezért végig járjuk az elejérõl 
				while (i->kov != akt) { i = i->kov; } //Amíg közvetlenül nem az aktuális elõtt lesz az i
				akt = i; //majd "vissza lépünk"
			}
		}
		else if (c == 'd' && akt != NULL)
		{
			//Elõre lépni könnyû hiszen egyszeresen láncolt listával dolgozunk
			if (akt->kov != NULL) //Ha már az utolsó elemen állunk, akkor maradunk
				akt = akt->kov; //különben a következõre lépünk
		}
		else if (c == 's' && akt != NULL)
		{
			//ha törölni szeretnénk az már nem olyan egyszerû
			if (akt == lista.Elso) //Ha az elsõ elemet szeretnénk törölni, 
			{
				Contact* kovetkezo = akt->kov; //akkor a következõt eltároljuk, hogy tudjuk, hogy legközelebb már õ lesz az elsõ
				delete akt; //törljük
				akt = kovetkezo; //majd a mentett állásra állunk. 
				lista.Elso = akt; //közben figyelve arra, hogy a lista objektumunkban található Elsõ pointert is állítsuk
			}
			else //Ha nem az elsõ akkor könyebb dolgunk van
			{
				Contact* elozo = lista.Elso; //gyorsan megkeressük, hogy melyik az elõzõ
				while (elozo->kov != akt) { elozo = elozo->kov; }
				Contact *kovetkezo = akt->kov;
				delete akt;
				if (kovetkezo == NULL)
					akt = elozo;
				else
					akt = kovetkezo;
				elozo->kov = kovetkezo;
			}
		}
		else if (c == 'w')
		{
			system("cls");
			uj();
		}
	} while (c != '9');
	system("cls");
}

void kapcsolatotbetolt(Lista& lista)
{
	Contact k1;
	k1.setvNev("Jakab");
	k1.setkNev("Olivér");
	k1.setbNev("Oli");
	k1.setCim("1117 Budapest, Szerémi sor 12/B 7. 29");
	k1.setmSzam(6205821847);
	String vezetek("Jakab");
	String kereszt("Gergo");
	String bece("Geri");
	String lakóhely("2000 Szentendre, kadarka u. 48");
	Telefonszam telefon(6205821848);
	Contact k2(vezetek, kereszt, bece, lakóhely, telefon, Telefonszam());
	Contact k3(String("Jakab"), String("Simon"), String(""), String("szte"), Telefonszam(6205821849), Telefonszam());
	lista.beszur(k1);
	lista.beszur(k2);
	lista.beszur(k3);
	k3.setkNev(String("Péter"));
	lista.beszur(k3);
}


