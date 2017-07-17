#include <iostream>
#include "talia.h"

using namespace std;

void talia::drukowanie_karty()
{
    if(wartosc==1)
        cout<<"A"<<ikona<<"\t";
    else if(wartosc==11)
        cout<<"J"<<ikona<<"\t";
    else if(wartosc==12)
        cout<<"Q"<<ikona<<"\t";
    else if(wartosc==13)
        cout<<"K"<<ikona<<"\t";
    else
        cout<<wartosc<<ikona<<"\t";
}
