#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include "talia.h"

using namespace std;

void wyswietlanie_kart(vector <stack <talia> > &pola_pierwotne, vector <stack <talia> > &pola_tymczasowe, HANDLE kolor_napisow, bool ster)
{
	int ster2=1;
	while(ster2)
	{
		for(int i=0; i<8; i++)
		{
			if(!pola_pierwotne[i].empty())
			{
				if(ster)
				{
					if(pola_pierwotne[i].top().kolor=="czerwony")
						SetConsoleTextAttribute(kolor_napisow, FOREGROUND_RED | FOREGROUND_INTENSITY);
					else
						SetConsoleTextAttribute(kolor_napisow, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					pola_pierwotne[i].top().drukowanie_karty();
				}
				pola_tymczasowe[i].push(pola_pierwotne[i].top());
				pola_pierwotne[i].pop();
			}
			else if(ster)
				cout<<"\t";
		}
		for(int j=0; j<8; j++)
		{
			if((pola_pierwotne[j].empty()) && (j==7))
				ster2=0;
			else if(pola_pierwotne[j].empty())
				continue;
			else break;
		}
		if(ster)
            cout<<endl;
	}
}


void plansza(vector <stack <talia> > &pola_pomocnicze_i_docelowe, vector <stack <talia> > &pola_poczatkowe,
             vector <stack <talia> > &dodatkowe                 , HANDLE kolor_napisow)
{
	SetConsoleTextAttribute(kolor_napisow, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"    POLA POMOCNICZE\t\t      POLA DOCELOWE"<<endl;
	cout<<"1\t2\t3\t4\t5\t6\t7\t8"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	wyswietlanie_kart(pola_pomocnicze_i_docelowe, dodatkowe, kolor_napisow, 0);
	wyswietlanie_kart(dodatkowe, pola_pomocnicze_i_docelowe, kolor_napisow, 1);
	SetConsoleTextAttribute(kolor_napisow, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"\t\t      POLA POCZATKOWE"<<endl;
	cout<<"9\t10\t11\t12\t13\t14\t15\t16"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	wyswietlanie_kart(pola_poczatkowe, dodatkowe, kolor_napisow, 0);
	wyswietlanie_kart(dodatkowe, pola_poczatkowe, kolor_napisow, 1);
	SetConsoleTextAttribute(kolor_napisow, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"-----------------------------------------------------------"<<endl;
}


void komunikaty(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <stack <talia> > &dodatkowe,
                HANDLE kolor_napisow, string kom_o_zab)
{
    cin.clear();
    cin.ignore(256, '\n');
    system("cls");
    plansza(p_p_i_d, p_p, dodatkowe, kolor_napisow);
    cout<<kom_o_zab;
}
