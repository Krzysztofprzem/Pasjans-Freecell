#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
;
using namespace std;

void czyszczenie_pol(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, int i);
void wyciaganie_asa_z_rekawa(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <talia> &rekaw);
void reset(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, vector <talia> &rekaw);
void transfer(vector <stack <talia> > &zrodlowy, vector <stack <talia> > &docelowy, int zrodlo, int cel);
void zerowanie(int &zrodlo, int &cel, int &licznik);
void wybor_pol(vector <stack <talia> > p_p_i_d, vector <stack <talia> > p_p, vector <stack <talia> > dodatkowe,
               HANDLE kolor_napisow           , int &zrodlo                , int &cel                         ,
               string kom_o_zab               , string kom_o_wrz);
void przenoszenie_kart(vector <stack <talia> > &p_p_i_d  , vector <stack <talia> > &p_p,
                       vector <stack <talia> > &dodatkowe, vector <talia> &rekaw       ,
                       HANDLE kolor_napisow);
