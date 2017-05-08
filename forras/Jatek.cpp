#include "Jatek.h"

//menu:
//A Telefonkonyv fõmenüje
void Jatek::menu(void)
{
	char ch;
	std::cout << "Kérlek válassz az alábbi menüpontok közül:\n";
	std::cout << menupontok;
	//Az EOF lekezelése
	if (!(std::cin >> ch))
	{
		//Ha EOF-t kapunk vége a játéknak :(
		isRunning = false;
		return;
	}
	//Ha elsõre nem sikerült a felsorol menüpontok közül választani, 
	//vagy valamiért nem egy egyjegyû számot adott meg a felhasználó, akkor újra kérjük.
	while (ch - '0' < 0 || ch - '0' >9)
	{
		system("cls");
		std::cout << "Kérlek az alábbi menüpontok közül válassz:\n";
		std::cout << menupontok;	
		if (!(std::cin >> ch))
		{
			isRunning = false;
			return;
		}
	}
	system("cls");
	//a karakterbõl számot számítunk :) 
	int c = ch - '0';
	switch (c)
	{
	case 1:	lista.listaz();	system("cls");break;						//az összes kiírása egymás alá
	case 2: vegigjar(); break;					//az ún. keresés, itt lehet törölni vagy módosítani is egy adott kapcsolatot.
	case 3: kapcsolatotbetolt(lista); break;	//secret feature a felhasználónak nem mondjuk meg, hogy van ilyen, de ha baj történne a beolvasással, akkor ez könnyen használható teszt adatokhoz
	case 9: //A kilépés
		isRunning = false;	
		std::fstream outfile("Lista.txt");
		lista.write(outfile);
		break;
	}
}
//Uj kapcsolat felvétele:
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
	if (s.getHossz() > 0)		//Ha egyjegyû számot ad meg a felhasnáló
		sz = s[0] - '0';
	else						//Ha nem ad meg semmit, akkor a 0-t adjuk át, mint default paraméter
		sz = 0;
	if (s.getHossz()>1)			//Ha kétjegyû számot ad meg a felhasználó
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setElo(sz);
	std::cout << "\t\tSzolgáltató: ";
	std::cin >> s;
	if (s.getHossz() > 0)				//hasonlóan az országhoz.
		sz = s[0] - '0';
	if (s.getHossz()>1)
		sz = (s[0] - '0') * 10 + (s[1] - '0');
	mobil.setSzolg(sz);
	std::cout << "\t\tSzám: ";
	std::cin >> s;
	if (s.getHossz()>0)
		sz = s[0] - '0';
	for (unsigned int i = 1; i < s.getHossz(); i++)		//Nagyon hasonlít az elõzõhöz, de a szám ugye sokkal hosszabb lehet, mint a szolgáltató.
		sz = sz * 10 + s[i] - '0';						//Ezért a beolvasott Sztring hosszáig vizsgáljuk a számokat. 
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
	if(kapcsolat!=Contact() && !lista.szerepele(kapcsolat)) //Hogy ha nem üres a kontakt vagy még nem szerepel a névjegyzékben, akkor beszúrja
		lista.beszur(kapcsolat);
	system("cls");
}
//Az kapcsolatok végigjárása
void Jatek::vegigjar(void)
{
	//fogunk egy iterátort akt néven
	Contact* akt = lista.Elso;
	char c;
	do
	{
		system("cls");
		if (akt != NULL)		//Ha az akt pointer nem NULL (ha az Elso nem NULL)
			std::cout << *akt;	//kiírjuk
		else if (lista.Elso != NULL) //Ha valahogy az aktuálist NULL de az Elsõ elem nem, 
		{
			akt = lista.Elso; //akkor azt aktuálist a helyre tesszük
			std::cout << *akt; //majd kiírjuk õt
		}
		else	//Ha az Elsõ elem NULL akkor üres a lista
			std::cout << "Nincs kapcsolat a névjegyzékben. Kérlek adj hozzá" << std::endl;
		std::cout << "Kérlek a WASD gombokkal navigálj!" << std::endl;
		std::cout << "A: Elõzõ; D: Következõ; S: Törlés; W: Új beszúrása; Q: módosítás." << std::endl;
		std::cout << "Kilépéshez nyomd meg a 9-es gombot" << std::endl;
		if (!(std::cin >> c)) //Figyelmes beolvasás
		{
			isRunning = false;
			return;
		}
		if (c == 'a' && akt != NULL)
		{
			//Az 'a' billenytû hatására hátra lépünk egyet
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
				if (kovetkezo == NULL) //Ha a legvégén állunk, akkor az elõzõre állítjuk az akt-ot
					akt = elozo;
				else //ha nem akkor simán a következõre
					akt = kovetkezo;
				elozo->kov = kovetkezo; //majd az elõzõ kov pointerét a kovetkezore állítjuk. a kovetkezo lehet akar NULL is, hiszen abban az esetben pont az kell
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

//Az adott kapcsolat módosítása
//Kiírom, hogy mit volt eredetileg, majd helyet adok egy új adat megadására.
//ha üresen hagyja, akkor az eredeti marad meg
void Jatek::modosit(Contact &kapcsolat)
{
	//Ha nem ad meg semmit, akkor marad az eredeti
	std::cout << kapcsolat.getvNev() << " " << kapcsolat.getkNev() << " modosítása" << std::endl;
	std::cout << "Ha bármit is beírsz az új: szó után, akkkor az felülírja a régit. Ha üresen hagyod, akkor megtartja a régit" << std::endl;
	String s("");
	std::cout << "(régi)Vezeték név: " << kapcsolat.getvNev() << " új:";
	std::cin >> s; if (s != String("")) { kapcsolat.setvNev(s); }
	s = "";
	std::cout << "(régi)Kereszt név: " << kapcsolat.getkNev() << " új:";
	std::cin >> s; if (s != String("")) { kapcsolat.setkNev(s); }
	s = "";
	std::cout << "(régi)Becenév: " << kapcsolat.getbNev() << " új:";
	std::cin >> s; if (s != String("")) { kapcsolat.setbNev(s); }
	s = "";
	std::cout << "(régi)Lakcím: " << kapcsolat.getCim() << " új:";
	std::cin >> s; if (s != String("")) { kapcsolat.setCim(s); }
	Telefonszam szam;
	std::cout << "(régi)Mobil: " << kapcsolat.getmSzam() << " új:";
	std::cin >> szam; if (szam != Telefonszam()) { kapcsolat.setmSzam(szam); }
	szam = 0;
	std::cout << "(régi)Privat: " << kapcsolat.getpSzam() << " új:";
	std::cin >> szam; if (szam != Telefonszam()) { kapcsolat.setpSzam(szam); }
}
//A secret feature
//Teszteléshez nagyon hasznos, illetve ha véletlenül egy olyan linux alapú rendszeren kéne futtatni a kódot
//akit nem érdekel, hogy te mit szeretnél és nem nyitja meg az általad mellékelt fájlt.
//akkor hasznos lehet, ha van beégetve a kódba néhány adat. :)
// I <3 JPorta
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
	String lakohely("2000 Szentendre, kadarka u. 48");
	Telefonszam telefon(6205821848);
	Contact k2(vezetek, kereszt, bece, lakohely, telefon, Telefonszam());
	Contact k3(String("Jakab"), String("Simon"), String(""), String("szte"), Telefonszam(6205821849), Telefonszam());
	lista.beszur(k1);
	lista.beszur(k2);
	lista.beszur(k3);
	k3.setkNev(String("Péter"));
	lista.beszur(k3);
}


