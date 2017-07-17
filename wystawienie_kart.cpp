#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#include <stack>
#include <string>
#include "talia.h"

using namespace std;

void pakowanie_do_pudelka(talia karta, string ikon, string kol, vector <talia> &pudelko)
{
	for(int i=1; i<14; i++)
	{
		karta.wartosc   =i;
		karta.ikona     =ikon;
		karta.kolor     =kol;
		karta.wystawiona=0;
		pudelko.push_back(karta);
	}
}


void generowanie_talii(talia karta, vector <talia> &pudelko)
{
	string ikona=("h");
	string kolor=("czerwony");
	pakowanie_do_pudelka(karta, ikona, kolor, pudelko);
	ikona=("d");
	pakowanie_do_pudelka(karta, ikona, kolor, pudelko);
	ikona=("s");
	kolor=("czarny");
	pakowanie_do_pudelka(karta, ikona, kolor, pudelko);
	ikona=("c");
	pakowanie_do_pudelka(karta, ikona, kolor, pudelko);
}


void rozstawianie_pol(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
                      vector <stack <talia> > &dodatkowe                 , stack <talia> &pole)
{
	for(int i=0; i<8; i++)
	{
		pola_pomocnicze_i_docelowe.push_back(pole);
		pola_poczatkowe.push_back(pole);
		dodatkowe.push_back(pole);
	}
}


void rozstawianie_kart(vector <talia> &pudelko, vector <stack <talia> > &pola_poczatkowe)
{
    for(int i=0; i<52; i++)
        pudelko[i].wystawiona=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<7; j++)
		{
			int indeks = rand()%52;
			if (!pudelko[indeks].wystawiona)
			{
				pudelko[indeks].wystawiona=1;
				pola_poczatkowe[i].push(pudelko[indeks]);
			}
			else j--;
		}
		for(int j=0; j<6; j++)
		{
			int indeks=rand()%52;
			if (!pudelko[indeks].wystawiona)
			{
				pudelko[indeks].wystawiona=1;
				pola_poczatkowe[i+4].push(pudelko[indeks]);
			}
			else j--;
		}
	}
}
