#include "sitandgo.h"

SitAndGo::SitAndGo():Tornei(),buyIn(0){}

SitAndGo::SitAndGo(string s, int i, double a, double b):
    Tornei(s,i,a), buyIn(b){}

SitAndGo::SitAndGo(const SitAndGo &s):Tornei(s),buyIn(s.buyIn){}

double SitAndGo::getBuyIn()const{return buyIn;}

void SitAndGo::resetBuyIn(double newBuyIn){buyIn=newBuyIn;}

double SitAndGo::tax()const{
    double totale=0;
    double rake=0.05*buyIn;
    totale=getNumeroGiocatori()*getTaxPerGiocatore()+rake;
    return totale;
}

bool SitAndGo::operator ==(const SitAndGo& s)const{
    return buyIn==s.buyIn;
}

Tornei* SitAndGo::clona()const{
    return new SitAndGo(*this);
}
