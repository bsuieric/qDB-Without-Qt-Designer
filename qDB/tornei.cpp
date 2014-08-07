#include "tornei.h"

#include "sstream"


Tornei::Tornei():nome("nonIdentficato"),numeroGiocatori(0),taxPerGiocatore(0){}

Tornei::Tornei(string n, int g, double t):nome(n),numeroGiocatori(g),taxPerGiocatore(t){}

Tornei::Tornei(const Tornei & t):nome(t.nome),numeroGiocatori(t.numeroGiocatori),taxPerGiocatore(t.taxPerGiocatore){}

string Tornei::getNome()const{return nome;}

void Tornei::resetNome(string newNome){nome=newNome;}

int Tornei::getNumeroGiocatori()const{return numeroGiocatori;}

void Tornei::resetNumeroGiocatori(int newNumeroGiocatori){numeroGiocatori=newNumeroGiocatori;}

double Tornei::getTaxPerGiocatore()const{return taxPerGiocatore;}

void Tornei::resetTax(double newTax){taxPerGiocatore=newTax;}


Tornei::~Tornei() {}


bool Tornei::operator ==(const Tornei &t) const{
    return nome==t.nome && numeroGiocatori==t.numeroGiocatori && taxPerGiocatore==t.taxPerGiocatore;


}


string Tornei::toString() const {
    std::stringstream ng;
    std::stringstream tpg;

    ng << numeroGiocatori;
    tpg<<taxPerGiocatore;
    string s = "Torneo: " + nome + " " +
            "\t Giocatori: " + ng.str() + "\t Tax:"+tpg.str() + "\n";
    return s;
}
