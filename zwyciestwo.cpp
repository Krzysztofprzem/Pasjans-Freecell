#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <stack>
#include <string>
#include "talia.h"
#include "wyswietlanie_planszy.h"

using namespace std;

void rysunek()
{
    fstream plik;
    string linia;
    plik.open("Rysunek_ASCII.txt", ios::in);
    if(!plik)
        exit(0);
    cout<<"GRATULACJE!"<<endl;
    while(!plik.eof())
    {
        getline(plik, linia);
        cout<<linia<<endl;
    }
    plik.close();
}


void warunek_zwyciestwa(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
                        vector <stack <talia> > &dodatkowe                 , HANDLE kolor_napisow)
{
	for (int j=4; j<8; j++)
		if (!(pola_pomocnicze_i_docelowe[j].empty()) && (pola_pomocnicze_i_docelowe[j].top().wartosc==13))
		{
			if(j==7)
            {
                system("cls");
                plansza(pola_pomocnicze_i_docelowe, pola_poczatkowe, dodatkowe, kolor_napisow);
                system("pause");
                system("cls");
                rysunek();
                exit(0);
            }
		}
		else break;
}
