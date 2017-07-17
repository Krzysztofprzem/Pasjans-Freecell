#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include <string>
#include "talia.h"
#include "wystawienie_kart.h"
#include "wyswietlanie_planszy.h"
#include "warunki_ruchow.h"

using namespace std;

void czyszczenie_pol(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, int i)
{
    while(!((p_p[i].empty()) && (p_p_i_d[i].empty())))
    {
        if(!p_p[i].empty())
            p_p[i].pop();
        if(!p_p_i_d[i].empty())
            p_p_i_d[i].pop();
    }
}


void wyciaganie_asa_z_rekawa(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <talia> &rekaw)
{
    for(int i=0 ; i<8; i++)
        czyszczenie_pol(p_p_i_d, p_p, i);
    for(int j=0 ; j<52; j++)
        if(j==12)
            p_p_i_d[0].push(rekaw[j]);
        else
            p_p_i_d[(j/13)+4].push(rekaw[j]);
}


void reset(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <talia> &rekaw)
{
    for(int i=0 ; i<8; i++)
        czyszczenie_pol(p_p_i_d, p_p, i);
    rozstawianie_kart(rekaw, p_p);
}



void transfer(vector <stack <talia> > &zrodlowy, vector <stack <talia> > &docelowy, int zrodlo, int cel)
{
    docelowy[cel].push(zrodlowy[zrodlo].top());
    zrodlowy[zrodlo].pop();
}


void zerowanie(int &zrodlo, int &cel, int &licznik)
{
    zrodlo =0;
    cel    =0;
    licznik=0;
}


void wybor_pol(vector <stack <talia> > p_p_i_d, vector <stack <talia> > p_p, vector <stack <talia> > dodatkowe,
               HANDLE kolor_napisow           , int &zrodlo                , int &cel                         ,
               string kom_o_zab               , string kom_o_wrz)
{
    int licznik;
    do{
        system("cls");
        plansza(p_p_i_d, p_p, dodatkowe, kolor_napisow);
        zerowanie(zrodlo, cel, licznik);
        cout<<kom_o_zab;
        while(warunki_zrodlo(p_p_i_d , p_p, zrodlo))
            komunikaty(p_p_i_d, p_p, dodatkowe, kolor_napisow, kom_o_zab);
        if((zrodlo==50) || (zrodlo==60))
            break;
        cout<<kom_o_wrz;
        if(!(cin>>cel) || ((cel<=0) || (cel>16)))
            continue;
        licznik++;
	}while(licznik!=1);
}


void przenoszenie_kart(vector <stack <talia> > &p_p_i_d  , vector <stack <talia> > &p_p,
                       vector <stack <talia> > &dodatkowe, vector <talia> &rekaw       ,
                       HANDLE kolor_napisow)
{
        int zrodlo=0;
        int cel=0;
        string kom_o_zab=("Wybierz stos z ktorego chcesz zabrac karte: ");
        string kom_o_wrz=("Wybierz stos na ktory chcesz wrzucic karte: ");
        wybor_pol(p_p_i_d, p_p, dodatkowe, kolor_napisow, zrodlo, cel, kom_o_zab, kom_o_wrz);
        if(zrodlo==50)       //CHEATOWANIE :)
        {
            wyciaganie_asa_z_rekawa(p_p_i_d, p_p, rekaw);
        }
        else if(zrodlo==60)  //RESETOWANIE POLA
        {
            reset(p_p_i_d, p_p, rekaw);
        }
        else if ((zrodlo<=4) && (cel>4) && (cel<=8))                     //Z POLA POMOCNICZEGO NA DOCELOWE
        {
            if(warunki_z_p_pocz_n_d_I_z_p_pom_n_d(p_p_i_d, p_p_i_d, zrodlo-1, cel-1))
                transfer(p_p_i_d, p_p_i_d, zrodlo-1, cel-1);
        }
        else if ((zrodlo>8) && (cel>4) && (cel<=8))                       //Z POLA POCZATKOWEGO NA DOCELOWE
        {
            if(warunki_z_p_pocz_n_d_I_z_p_pom_n_d(p_p_i_d, p_p, zrodlo-9, cel-1))
                transfer(p_p, p_p_i_d, zrodlo-9, cel-1);
        }
        else if((zrodlo<=4) && (cel>8))                                   //Z POLA POMOCNICZEGO NA POCZATKOWE
        {
            if(warunki_z_p_pom_n_pocz(p_p_i_d, p_p, zrodlo, cel))
                transfer(p_p_i_d, p_p, zrodlo-1, cel-9);
        }
        else if((zrodlo!=cel) && (zrodlo>8) && (cel>8))                  //Z POLA POCZATKOWEGO NA POCZATKOWE
        {
            if(warunki_z_p_pocz_n_pocz(p_p, zrodlo, cel))
                transfer(p_p, p_p, zrodlo-9, cel-9);
        }
        else if((zrodlo>8) && (cel<=4))                                  //Z POLA POCZATKOWEGO NA POMOCNICZE
        {
            if((!p_p[zrodlo-9].empty()) && (p_p_i_d[cel-1].empty()))
                transfer(p_p, p_p_i_d, zrodlo-9, cel-1);
        }
        else if((zrodlo!=cel) && (zrodlo<=4) && (cel<=4))               //Z POLA POMOCNICZEGO NA POMOCNICZE
        {
            if((!p_p_i_d[zrodlo-1].empty()) && (p_p_i_d[cel-1].empty()))
                transfer(p_p_i_d, p_p_i_d, zrodlo-1, cel-1);
        }
}
