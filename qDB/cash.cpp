#include "cash.h"

double Cash::addizionale=5;

Cash::Cash():Tornei(),durata(0){}

Cash::Cash(string s, int i, double d, int f):Tornei(s,i,d),durata(f){}

Cash::Cash(const Cash & c):Tornei(c),durata(c.durata){}

int Cash::getDurata()const{return durata;}

void Cash::resetDurata(int newDurata){durata=newDurata;}

double Cash::getAddizionale(){return addizionale;}

void Cash::resetAddizionale(double newAddizionale){addizionale=newAddizionale;}

double Cash::tax()const{
    double totale=0;
    if(getDurata()>2)
    {
        totale=getNumeroGiocatori()*getTaxPerGiocatore()+getAddizionale();
    }
    else
        totale=getNumeroGiocatori()*getTaxPerGiocatore();
    return totale;
}

bool Cash::operator ==(const Cash & c)const{
    return durata==c.durata;
}

Tornei* Cash::clona()const{
    return new Cash(*this);
}
