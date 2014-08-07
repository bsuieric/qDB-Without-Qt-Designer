#include "sitandgo.h"

#include "sstream"

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

string SitAndGo::toString() const {
    std::stringstream ng;
    std::stringstream tpg;
    std::stringstream buy;

    ng << getNumeroGiocatori();
    tpg<< getTaxPerGiocatore();
    buy<< buyIn;
    string s = "Torneo SitAndGo: " + getNome() + " " +
            "\t Giocatori: " + ng.str() + "\t Tax:"+tpg.str() + "\t BuyIn:"+buy.str()+ "\n";
    return s;
}

Tornei* SitAndGo::clona()const{
    return new SitAndGo(*this);
}
