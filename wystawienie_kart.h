#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void pakowanie_do_pudelka(talia karta, string ikon, string kol, vector <talia> &pudelko);
void generowanie_talii(talia karta, vector <talia> &pudelko);
void rozstawianie_pol(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
                      vector <stack <talia> > &dodatkowe                 , stack <talia> &pole);
void rozstawianie_kart(vector <talia> &pudelko, vector <stack <talia> > &pola_poczatkowe);
