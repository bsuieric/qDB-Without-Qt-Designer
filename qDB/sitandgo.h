#ifndef SITANDGO_H
#define SITANDGO_H

#include "tornei.h"
#include <string>
using std::string;

class SitAndGo: public Tornei
{
private:
    double buyIn;
public:
    //costruttore di default
    SitAndGo();

    //costruttore a 4 parametri
    SitAndGo(string,int,double,double);

    //costruttore di copia
    SitAndGo(const SitAndGo&);

    //restituisce il buyIn
    double getBuyIn()const;

    //permette di cambiare il buyIn
    void resetBuyIn(double);

    virtual Tornei* clona()const;


    //metodo tax
    virtual double tax()const;

    //operatore di uguaglianza
    bool operator==(const SitAndGo&)const;

};
#endif // SITANDGO_H
