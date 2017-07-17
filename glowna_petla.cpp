#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include "talia.h"
#include "wyswietlanie_planszy.h"
#include "zwyciestwo.h"
#include "przenoszenie_kart.h"

using namespace std;

void glowna_petla(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
                  vector <stack <talia> > &dodatkowe                 , vector <talia> &rekaw                   ,
                  HANDLE kolor_napisow)
{
	while(1)
	{
		system("cls");
		plansza(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, kolor_napisow);
		przenoszenie_kart(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, rekaw, kolor_napisow);
		warunek_zwyciestwa(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, kolor_napisow);
	}
}
