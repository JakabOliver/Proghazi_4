#include "lista.h"

/// <summary>
///Ez itt a Lista oszt�ly
/// Finalizes an instance of the <see cref="Lista"/> class.
/// </summary>
//A destruktor v�gig s�t�l a list�n, �s amig a v�g�re nem �r, addig minden elemet felszabad�t
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
//A besz�r f�ggv�ny megkeresi a "hely�t" a kapcsolatnak �s oda sz�rja be
void Lista::beszur(Contact& kapcsolat)
{
	//Ha �res a lista, akkor egyszer�en a legelej�re teszi be
	if (Elso == NULL)
	{
		Elso = new Contact;
		*Elso = kapcsolat;
	}
	//Ha nem �res, akkor megkeresi a hely�t
	else
	{
		Contact* i;
		//Helyet foglalunk neki
		Contact *tmp = new Contact;
		*tmp = kapcsolat;
		//El�sz�r azt vizsg�ljuk meg, hogy legel�re ker�l-e
		if (*Elso > kapcsolat)
		{
			Contact *temp = Elso;
			Elso = tmp;
			Elso->kov = temp;
			return;
		}
		//Ha nem a legels�, akkor megkeress�k a hely�t. (oda ker�l, ahol az el�tte l�v� "kisebb vagy egyenl�" de a k�vetkez� m�r nagyobb.
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
		//Ha v�gig �rt�nk, �s egyik kontakt sem "nagyobb" n�la akkor a v�g�re ker�l
		i->kov = tmp;
		tmp->kov = NULL;
	}
}
//A list�ban tal�lhat� �sszes kapcsolatot ki�rja standard kimenetre
void Lista::listaz(void)
{
	Contact* i;
	for (i = Elso; i != NULL; i = i->kov)
		std::cout << *i;
}
//v�gig megy a list�n minden adatot kit�r�l bel�le 
//Akkor van �rtelme, ha f�jlbol olvasunk be, de nincs sz�ks�g�nk semmire, ami addig a list�ban volt.
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
//Mivel ugyanazat a n�vjegyet nem lehet k�tszer besz�rni a Telefonkonyvbe, ez�rt ez a f�ggv�ny
//megvizsg�lja, hogy az adott kapcsolat szerepele m�r a telefonkonyvben
bool Lista::szerepele(Contact & kapcsolat)
{
	//Ha �res a lista, akkor biztosan nem szerepel benne
	if (Elso == NULL)
		return false;
	//Ha nem, akkor v�gig j�rjuk �s az �sszessel �sszehasonl�tjuk
	for (Contact* i = Elso; i != NULL; i = i->kov)
		if (*i == kapcsolat)		//Ha b�rmelyik egyezik vele akkor szerepel benne
			return true;
	return false; //ha v�gig �r�nk �s m�g nem t�rt�nk vissza igazzal, akkor nem szerepel m�g benne.
}
//F�jlba �r�s 
//Mikor a programb�l kil�p�nk, akkor � a benne tal�lhat� kapcsolatokat ki�rja a kapott ostream-re
//jelen felhasn�l�s eset�n ez egy f�jl.
std::ostream& Lista::write(std::ostream&os) const
{
	//Azzal kezdj�k, hogy adunk neki egy egyedi azonos�t�t, hogy tudjuk amikor legk�zelebb meg akarjuk nyitni, hogy j� f�jlt olvasunk
	os << "Lista:" << std::endl;
	Contact* i = Elso;
	while (i != NULL)		//majd v�gig megy�nk �s minden kapcsolatot k�l�n egyes�vel ki�runk
	{
		os << "Kapcsolat:" << std::endl << ",.,"; //minden sor elej�re ker�l egy egyedi szepar�tor.
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
//Az olvas�s f�ggv�ny az adott istreamr�l olvassa be a list�ba az ott tal�lhat� adatokat
std::istream& Lista::read(std::istream& is)
{
	urit();		//El�sz�r mindent kit�r�l a list�b�l
	Contact kapcsolat;
	String tmp;
	Telefonszam temp;
	(is >> tmp); //Beolvasom, hogy j� f�jlt olvasok-e
	if (tmp != String("Lista:")) throw std::out_of_range("Hib�s olvas�s");
	while ((is >> tmp).ignore(3))
	{														//Beolvasom az adatokat. Itt m�r nem foglalkozom vele, hogy mi van ha hib�s, 
		(is >> tmp).ignore(3);								//hiszen az elej�n m�r meggy�z�dtem r�la, hogy j� f�jlt olvasok
		kapcsolat.setvNev(tmp);								//Vezet�kn�v
		(is >> tmp).ignore(3);
		kapcsolat.setkNev(tmp);								//Keresztn�v
		(is >> tmp).ignore(3);
		kapcsolat.setbNev(tmp);								//Becen�v
		(is >> tmp).ignore(3);
		kapcsolat.setCim(tmp);								//Lakc�m
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
		kapcsolat.setmSzam(temp);								//MobilSz�m

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