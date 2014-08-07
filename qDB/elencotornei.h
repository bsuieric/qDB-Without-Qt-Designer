#ifndef ELENCOTORNEI_H
#define ELENCOTORNEI_H

#include "Container.h"
#include "tornei.h"
#include "sitandgo.h"
#include "cash.h"


class ElencoTornei
{

    //Ridefinizione dell'operatore di output
    friend ostream& operator<<(ostream&, const ElencoTornei&);
public:
    class SmartPtr{
    private:
        Tornei * punt;
    public:
        SmartPtr(Tornei* p=0);
        SmartPtr(const SmartPtr&);
        ~SmartPtr();
        SmartPtr& operator=(const SmartPtr&);
        Tornei& operator*()const;
        Tornei* operator->()const;
        bool operator==(const SmartPtr&)const;
        bool operator!=(const SmartPtr&)const;
        Tornei* getTorneo()const;

    };

    ElencoTornei();
    ~ElencoTornei();
    bool addTorneo(const SmartPtr&);
    void addSitAndGo(string, int, double, double);
    bool addSitAndGoIfNotPresent(string, int, double, double);
    void addCash(string, int, double, int);
    bool addCashIfNotPresent(string, int, double, int);
    bool deleteTorneo(const string &);
    SmartPtr searchTorneo(const string&);
    Cash& modificaCash(const SmartPtr&);
    SitAndGo& modificaSitAndGo(const SmartPtr &);

    Container<ElencoTornei::SmartPtr>::Iterator editTornei(const string& nome);

    string nomiSalvati(const ElencoTornei&);

    double getAddCash();

    Container<SmartPtr>::Iterator& getIterator(const string &);
    SmartPtr& getAccount(Container<ElencoTornei::SmartPtr>::Iterator);


private:
    Container<SmartPtr>* elenco;

};

#endif // ELENCOTORNEI_H
