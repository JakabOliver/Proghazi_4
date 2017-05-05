#include "Jatek.h"



void Jatek::menu(void)
{
	char ch;
	std::cout << "K�rlek v�lassz az al�bbi men�pontok k�z�l:\n";
	std::cout << menupontok;
	ch = _getch();
	while (ch - '0' < 0 || ch - '0' >9)
	{
		system("cls");
		std::cout << "K�rlek az al�bbi men�pontok k�z�l v�lassz:\n";
		std::cout << menupontok;
		ch = _getch();

	}
	system("cls");
	int c = ch - '0';
	switch (c)
	{
		//onyv("1. �sszes kapcsolat kilist�z�sa\n2. Kapcsolatok egyes�vel\n9. kil�p�s\n");
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
	std::cout << " �j kapcsolat megad�sa" << std::endl;
	std::cout << "K�rlek add meg az al�bbi adatokat:" << std::endl;
	std::cout << "Vezet�k n�v: ";					std::cin >> s;		kapcsolat.setvNev(s);
	std::cout << "Kereszt n�v: ";					std::cin >> s;		kapcsolat.setkNev(s);
	std::cout << "(opcion�lis)Becen�v: ";			std::cin >> s;		kapcsolat.setbNev(s);
	std::cout << "Lakc�m: ";						std::cin >> s;		kapcsolat.setCim(s);
	std::cout << "Telefonszam:\n" << "\tmobil: \n";
	std::cout << "\t\tOrsz�g:";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	else
		sz = 0;
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolg�ltat�: ";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSz�m: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)
		sz = sz * 10 + s[i] - '0';
	mobil.setSzam(sz);
	kapcsolat.setmSzam(mobil);
	std::cout << "\tprivat: \n";
	std::cout << "\t\tOrsz�g:";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	else
		sz = 0;
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolg�ltat�: ";
	std::cin >> s;
	if (s.getHossz() > 0)
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSz�m: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)
		sz = sz * 10 + s[i] - '0';
	mobil.setSzam(sz);
	kapcsolat.setpSzam(mobil);
	if(kapcsolat!=Contact() && !lista.szerepele(kapcsolat)) //Hogy ha nem �res a kontakt �s m�g nem szerepel a n�vjegyz�kben, akkor besz�rja
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
			std::cout << "Nincs kapcsolat a n�vjegyz�kben. K�rlek adj hozz�" << std::endl;

		std::cout << "K�rlek a WASD gombokkal navig�lj!" << std::endl;
		std::cout << "A: El�z�; D: K�vetkez�; S: T�rl�s; W: �j besz�r�sa." << std::endl;
		std::cout << "Kil�p�shez nyomd meg a 9-es gombot" << std::endl;
		c = _getch();
		if (c == 'a' && akt != NULL)
		{
			//Az a billenyt� hat�s�ra h�tra l�p�nk egyet
			if (akt != lista.Elso)
			{
				//egyszeresen l�ncolt list�ban ez nem olyan egyszer�. 
				Contact* i = lista.Elso; //Ez�rt v�gig j�rjuk az elej�r�l 
				while (i->kov != akt) { i = i->kov; } //Am�g k�zvetlen�l nem az aktu�lis el�tt lesz az i
				akt = i; //majd "vissza l�p�nk"
			}
		}
		else if (c == 'd' && akt != NULL)
		{
			//El�re l�pni k�nny� hiszen egyszeresen l�ncolt list�val dolgozunk
			if (akt->kov != NULL) //Ha m�r az utols� elemen �llunk, akkor maradunk
				akt = akt->kov; //k�l�nben a k�vetkez�re l�p�nk
		}
		else if (c == 's' && akt != NULL)
		{
			//ha t�r�lni szeretn�nk az m�r nem olyan egyszer�
			if (akt == lista.Elso) //Ha az els� elemet szeretn�nk t�r�lni, 
			{
				Contact* kovetkezo = akt->kov; //akkor a k�vetkez�t elt�roljuk, hogy tudjuk, hogy legk�zelebb m�r � lesz az els�
				delete akt; //t�rlj�k
				akt = kovetkezo; //majd a mentett �ll�sra �llunk. 
				lista.Elso = akt; //k�zben figyelve arra, hogy a lista objektumunkban tal�lhat� Els� pointert is �ll�tsuk
			}
			else //Ha nem az els� akkor k�nyebb dolgunk van
			{
				Contact* elozo = lista.Elso; //gyorsan megkeress�k, hogy melyik az el�z�
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
	k1.setkNev("Oliv�r");
	k1.setbNev("Oli");
	k1.setCim("1117 Budapest, Szer�mi sor 12/B 7. 29");
	k1.setmSzam(6205821847);
	String vezetek("Jakab");
	String kereszt("Gergo");
	String bece("Geri");
	String lak�hely("2000 Szentendre, kadarka u. 48");
	Telefonszam telefon(6205821848);
	Contact k2(vezetek, kereszt, bece, lak�hely, telefon, Telefonszam());
	Contact k3(String("Jakab"), String("Simon"), String(""), String("szte"), Telefonszam(6205821849), Telefonszam());
	lista.beszur(k1);
	lista.beszur(k2);
	lista.beszur(k3);
	k3.setkNev(String("P�ter"));
	lista.beszur(k3);
}


