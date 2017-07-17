#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <stack>

using namespace std;

void rysunek();
void warunek_zwyciestwa(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
                        vector <stack <talia> > &dodatkowe                 , HANDLE kolor_napisow)
