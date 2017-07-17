#include <iostream>
#include <vector>
#include <stack>
#include "talia.h"

using namespace std;

bool warunki_z_p_pocz_n_d_I_z_p_pom_n_d(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p_i_d_L_p_p, int ind_zrodlo, int ind_cel)
{
    return (!(p_p_i_d_L_p_p[ind_zrodlo].empty()) &&
           (((p_p_i_d[ind_cel].empty())          && (p_p_i_d_L_p_p[ind_zrodlo].top().wartosc==1)) ||
           !((p_p_i_d[ind_cel].empty())          && (p_p_i_d_L_p_p[ind_zrodlo].top().wartosc!=1)) &&
             (p_p_i_d[ind_cel].top().wartosc     ==  p_p_i_d_L_p_p[ind_zrodlo].top().wartosc-1)   &&
             (p_p_i_d[ind_cel].top().ikona       ==  p_p_i_d_L_p_p[ind_zrodlo].top().ikona)));
}


bool warunki_z_p_pocz_n_pocz(vector <stack <talia> > &p_p, int zrodlo, int cel)
{
    return (!(p_p[zrodlo-9].empty())      &&  (p_p[cel-9].empty())          ||
           (!(p_p[zrodlo-9].empty())      && !(p_p[cel-9].empty())          &&
             (p_p[zrodlo-9].top().wartosc ==  (p_p[cel-9].top().wartosc-1)) &&
             (p_p[zrodlo-9].top().kolor   !=  (p_p[cel-9].top().kolor))));
}


bool warunki_z_p_pom_n_pocz(vector <stack <talia> > &p_p_i_d, vector <stack <talia> > &p_p, int zrodlo, int cel)
{
    return (!(p_p_i_d[zrodlo-1].empty()) &&
           (((p_p[cel-9].empty())        && !(p_p_i_d[zrodlo-1].empty()))      ||
             (p_p[cel-9].top().wartosc-1 ==   p_p_i_d[zrodlo-1].top().wartosc) &&
             (p_p[cel-9].top().kolor     !=   p_p_i_d[zrodlo-1].top().kolor)));
}


bool warunki_zrodlo(vector <stack <talia > > p_p_i_d, vector <stack <talia > > p_p, int &zrodlo)
{
    return (!(cin>>zrodlo) || ((zrodlo!=50) && (zrodlo!=60))                &&
            ((zrodlo<1)    || (zrodlo>16)   || ((zrodlo>4)   && (zrodlo<9)) ||
            ((zrodlo>8)    && (zrodlo<17)   && (p_p[zrodlo-9].empty()))     ||
            ((zrodlo>0)    && (zrodlo<9)    && (p_p_i_d[zrodlo-1].empty()))));
}
