#include "Jatek.h"

//menu:
//A Telefonkonyv f�men�je
void Jatek::menu(void)
{
	char ch;
	std::cout << "K�rlek v�lassz az al�bbi men�pontok k�z�l:\n";
	std::cout << menupontok;
	//Az EOF lekezel�se
	if (!(std::cin >> ch))
	{
		//Ha EOF-t kapunk v�ge a j�t�knak :(
		isRunning = false;
		return;
	}
	//Ha els�re nem siker�lt a felsorol men�pontok k�z�l v�lasztani, 
	//vagy valami�rt nem egy egyjegy� sz�mot adott meg a felhaszn�l�, akkor �jra k�rj�k.
	while (ch - '0' < 0 || ch - '0' >9)
	{
		system("cls");
		std::cout << "K�rlek az al�bbi men�pontok k�z�l v�lassz:\n";
		std::cout << menupontok;	
		if (!(std::cin >> ch))
		{
			isRunning = false;
			return;
		}
	}
	system("cls");
	//a karakterb�l sz�mot sz�m�tunk :) 
	int c = ch - '0';
	switch (c)
	{
	case 1:	lista.listaz();	system("cls");break;						//az �sszes ki�r�sa egym�s al�
	case 2: vegigjar(); break;					//az �n. keres�s, itt lehet t�r�lni vagy m�dos�tani is egy adott kapcsolatot.
	case 3: kapcsolatotbetolt(lista); break;	//secret feature a felhaszn�l�nak nem mondjuk meg, hogy van ilyen, de ha baj t�rt�nne a beolvas�ssal, akkor ez k�nnyen haszn�lhat� teszt adatokhoz
	case 9: //A kil�p�s
		isRunning = false;	
		std::fstream outfile("Lista.txt");
		lista.write(outfile);
		break;
	}
}
//Uj kapcsolat felv�tele:
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
	if (s.getHossz() > 0)		//Ha egyjegy� sz�mot ad meg a felhasn�l�
		sz = s[0] - '0';
	else						//Ha nem ad meg semmit, akkor a 0-t adjuk �t, mint default param�ter
		sz = 0;
	if (s.getHossz()>1)			//Ha k�tjegy� sz�mot ad meg a felhaszn�l�
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolg�ltat�: ";
	std::cin >> s;
	if (s.getHossz() > 0)				//hasonl�an az orsz�ghoz.
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSz�m: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)		//Nagyon hasonl�t az el�z�h�z, de a sz�m ugye sokkal hosszabb lehet, mint a szolg�ltat�.
		sz = sz * 10 + s[i] - '0';						//Ez�rt a beolvasott Sztring hossz�ig vizsg�ljuk a sz�mokat. 
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
	if(kapcsolat!=Contact() && !lista.szerepele(kapcsolat)) //Hogy ha nem �res a kontakt vagy m�g nem szerepel a n�vjegyz�kben, akkor besz�rja
		lista.beszur(kapcsolat);
	system("cls");
}
//Az kapcsolatok v�gigj�r�sa
void Jatek::vegigjar(void)
{
	//fogunk egy iter�tort akt n�ven
	Contact* akt = lista.Elso;
	char c;
	do
	{
		system("cls");
		if (akt != NULL)		//Ha az akt pointer nem NULL (ha az Elso nem NULL)
			std::cout << *akt;	//ki�rjuk
		else if (lista.Elso != NULL) //Ha valahogy az aktu�list NULL de az Els� elem nem, 
		{
			akt = lista.Elso; //akkor azt aktu�list a helyre tessz�k
			std::cout << *akt; //majd ki�rjuk �t
		}
		else	//Ha az Els� elem NULL akkor �res a lista
			std::cout << "Nincs kapcsolat a n�vjegyz�kben. K�rlek adj hozz�" << std::endl;
		std::cout << "K�rlek a WASD gombokkal navig�lj!" << std::endl;
		std::cout << "A: El�z�; D: K�vetkez�; S: T�rl�s; W: �j besz�r�sa; Q: m�dos�t�s." << std::endl;
		std::cout << "Kil�p�shez nyomd meg a 9-es gombot" << std::endl;
		if (!(std::cin >> c)) //Figyelmes beolvas�s
		{
			isRunning = false;
			return;
		}
		if (c == 'a' && akt != NULL)
		{
			//Az 'a' billenyt� hat�s�ra h�tra l�p�nk egyet
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
				if (kovetkezo == NULL) //Ha a legv�g�n �llunk, akkor az el�z�re �ll�tjuk az akt-ot
					akt = elozo;
				else //ha nem akkor sim�n a k�vetkez�re
					akt = kovetkezo;
				elozo->kov = kovetkezo; //majd az el�z� kov pointer�t a kovetkezore �ll�tjuk. a kovetkezo lehet akar NULL is, hiszen abban az esetben pont az kell
			}
		}
		else if (c == 'w')
		{
			system("cls");
			uj();
		}
		else if (c == 'q' && akt != NULL)
		{
			system("cls");
			modosit(*akt);
		}
	} while (c != '9');
	system("cls");
}

//Az adott kapcsolat m�dos�t�sa
//Ki�rom, hogy mit volt eredetileg, majd helyet adok egy �j adat megad�s�ra.
//ha �resen hagyja, akkor az eredeti marad meg
void Jatek::modosit(Contact &kapcsolat)
{
	//Ha nem ad meg semmit, akkor marad az eredeti
	std::cout << kapcsolat.getvNev() << " " << kapcsolat.getkNev() << " modos�t�sa" << std::endl;
	std::cout << "Ha b�rmit is be�rsz az �j: sz� ut�n, akkkor az fel�l�rja a r�git. Ha �resen hagyod, akkor megtartja a r�git" << std::endl;
	String s("");
	std::cout << "(r�gi)Vezet�k n�v: " << kapcsolat.getvNev() << " �j:";
	std::cin >> s; if (s != String("")) { kapcsolat.setvNev(s); }
	s = "";
	std::cout << "(r�gi)Kereszt n�v: " << kapcsolat.getkNev() << " �j:";
	std::cin >> s; if (s != String("")) { kapcsolat.setkNev(s); }
	s = "";
	std::cout << "(r�gi)Becen�v: " << kapcsolat.getbNev() << " �j:";
	std::cin >> s; if (s != String("")) { kapcsolat.setbNev(s); }
	s = "";
	std::cout << "(r�gi)Lakc�m: " << kapcsolat.getCim() << " �j:";
	std::cin >> s; if (s != String("")) { kapcsolat.setCim(s); }
	Telefonszam szam;
	std::cout << "(r�gi)Mobil: " << kapcsolat.getmSzam() << " �j:";
	std::cin >> szam; if (szam != Telefonszam()) { kapcsolat.setmSzam(szam); }
	szam = 0;
	std::cout << "(r�gi)Privat: " << kapcsolat.getpSzam() << " �j:";
	std::cin >> szam; if (szam != Telefonszam()) { kapcsolat.setpSzam(szam); }
}
//A secret feature
//Tesztel�shez nagyon hasznos, illetve ha v�letlen�l egy olyan linux alap� rendszeren k�ne futtatni a k�dot
//akit nem �rdekel, hogy te mit szeretn�l �s nem nyitja meg az �ltalad mell�kelt f�jlt.
//akkor hasznos lehet, ha van be�getve a k�dba n�h�ny adat. :)
// I <3 JPorta
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
	String lakohely("2000 Szentendre, kadarka u. 48");
	Telefonszam telefon(6205821848);
	Contact k2(vezetek, kereszt, bece, lakohely, telefon, Telefonszam());
	Contact k3(String("Jakab"), String("Simon"), String(""), String("szte"), Telefonszam(6205821849), Telefonszam());
	lista.beszur(k1);
	lista.beszur(k2);
	lista.beszur(k3);
	k3.setkNev(String("P�ter"));
	lista.beszur(k3);
}


