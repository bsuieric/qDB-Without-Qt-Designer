#ifndef CASH_H
#define CASH_H

#include "tornei.h"
#include <string>
using std::string;

class Cash:public Tornei
{
private:
    int durata;
    static double addizionale;
public:
    //costruttore di default
    Cash();

    //costruttore a 3 parametri
    Cash(string, int, double, int);

    //costruttore di copia
    Cash(const Cash &);

    //restituisce la durata
    int getDurata()const;

    //permette di cambiare la durata
    void resetDurata(int);

    //restituisce l'addizionale
    static double getAddizionale();

    //permette di cambare l'addizionale
    void resetAddizionale(double);

    //il metodo tax che calcola la tassa da pagare
    virtual double tax() const;

    //operator ==
    bool operator ==(const Cash&)const;

    virtual Tornei* clona()const;
};

#endif // CASH_H
