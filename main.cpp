#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <vector>
#include <stack>
#include <string>
#include "talia.h"
#include "wystawienie_kart.h"
#include "wyswietlanie_planszy.h"
#include "warunki_ruchow.h"
#include "zwyciestwo.h"
#include "przenoszenie_kart.h"
#include "glowna_petla.h"

using namespace std;

int main()
{
	srand(time(NULL));
	HANDLE kolor_napisow;
	kolor_napisow=GetStdHandle(STD_OUTPUT_HANDLE);
	talia karta;
	stack <talia> pole;
	vector <talia> pudelko;
	vector <stack <talia> > pola_pomocnicze_i_docelowe;
	vector <stack <talia> > pola_poczatkowe;
	vector <stack <talia> > dodatkowe;
	generowanie_talii(karta, pudelko);
	rozstawianie_pol(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, pole);
	rozstawianie_kart(pudelko, pola_poczatkowe);
	glowna_petla(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, pudelko, kolor_napisow);
	return 0;
}
