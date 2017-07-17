#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>

using namespace std;

void wyswietlanie_kart(vector <stack <talia> > &pola_pierwotne, vector <stack <talia> > &pola_tymczasowe, HANDLE kolor_napisow, bool ster);
void plansza(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
             vector <stack <talia> > &dodatkowe                 , HANDLE kolor_napisow);
void komunikaty(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <stack <talia> > &dodatkowe,
                HANDLE kolor_napisow, string kom_o_zab);
