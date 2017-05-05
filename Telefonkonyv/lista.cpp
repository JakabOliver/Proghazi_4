#include "lista.h"


/// <summary>
///Ez itt a Lista oszt�ly
/// Finalizes an instance of the <see cref="Lista"/> class.
/// </summary>
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
void Lista::beszur(Contact& kapcsolat)
{
	//Mi lenne ha nem a legv�g�re sz�rn� be, hanem "a hely�re" �s az eg�sz ABC sorrendben lenne
	if (Elso == NULL)
	{
		Elso = new Contact;
		*Elso = kapcsolat;
	}
	else
	{
		Contact* i;
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
void Lista::listaz(void)
{
	Contact* i;
	for (i = Elso; i != NULL; i = i->kov)
		std::cout << *i;
}
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

bool Lista::szerepele(Contact & kapcsolat)
{
	if (Elso == NULL)
		return false;
	for (Contact* i = Elso; i != NULL; i = i->kov)
		if (*i == kapcsolat)
			return true;
	return false;
}


void Lista::sorbarendez(void)
{
	//fogja �s sorba rendezi a benne tal�lhat� kapcsolatokat.
}

std::ostream& Lista::write(std::ostream&os) const
{
	os << "Lista" << std::endl;
	Contact* i = Elso;
	while (i != NULL)
	{
		os << "Kapcsolat:" << std::endl << ",.,";
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

std::istream& Lista::read(std::istream& is)
{
	urit();
	Contact kapcsolat;
	String tmp;
	Telefonszam temp;
	(is >> tmp); //Beolvasom, hogy j� f�jlt olvasok-e
	if (tmp != "Lista:") throw std::out_of_range("Hib�s olvas�s");
	while ((is >> tmp).ignore(3))
	{
		(is >> tmp).ignore(3);
		kapcsolat.setvNev(tmp);								//Vezet�kn�v
		(is >> tmp).ignore(3);
		kapcsolat.setkNev(tmp);								//Keresztn�v
		(is >> tmp).ignore(3);
		kapcsolat.setbNev(tmp);								//Becen�v
		(is >> tmp).ignore(3);
		kapcsolat.setCim(tmp);								//Lakc�m
		(is >> tmp).ignore(3);
		//if >0
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
		kapcsolat.setpSzam(temp);

		beszur(kapcsolat);
	}
	return is;
}