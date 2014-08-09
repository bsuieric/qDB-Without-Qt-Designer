#include "elencotornei.h"

ElencoTornei::SmartPtr::SmartPtr(Tornei *p):punt(p){}

ElencoTornei::SmartPtr::SmartPtr(const SmartPtr& s):punt(s.punt->clona()){}

ElencoTornei::SmartPtr::~SmartPtr(){
    if(punt)
    delete punt;
}

ElencoTornei::SmartPtr& ElencoTornei::SmartPtr::operator =(const SmartPtr& s){
    if(this!=&s){
        delete punt;
        punt=s.punt->clona();
    }
    return *this;
}

Tornei& ElencoTornei::SmartPtr::operator *()const{
    return *punt;
}

Tornei* ElencoTornei::SmartPtr::operator ->()const{
    return punt;
}

bool ElencoTornei::SmartPtr::operator ==(const SmartPtr& s)const{
    return punt==s.punt;
}

bool ElencoTornei::SmartPtr::operator !=(const SmartPtr& s)const{
    return punt!=s.punt;
}

Tornei* ElencoTornei::SmartPtr::getTorneo()const
{
    return punt;
}

ElencoTornei::ElencoTornei():elenco(new Container<SmartPtr>()){}

ElencoTornei::~ElencoTornei(){
    delete elenco;
}

void ElencoTornei::addSitAndGo(string n,int num,double tax, double buy){
    elenco->add(new SitAndGo(n,num,tax,buy));
}

bool ElencoTornei::addSitAndGoIfNotPresent(string n, int num, double tax, double buy){
    SmartPtr s=new SitAndGo(n,num,tax,buy);
    bool inserito=addTorneo(s);
    return inserito;
}

void ElencoTornei::addCash(string n,int num,double tax, int tempo){
    elenco->add(new Cash(n,num,tax,tempo));
}

bool ElencoTornei::addCashIfNotPresent(string n, int num, double tax, int tempo){
        SmartPtr s=new Cash(n,num,tax, tempo);
        bool inserito=addTorneo(s);
        return inserito;
}

bool ElencoTornei::addTorneo(const SmartPtr& s){
    bool presente=false;
    Container<SmartPtr>::Iterator it = elenco->begin();
    for(; it!=elenco->end() && !presente ;++it){
        SmartPtr * t=static_cast<SmartPtr*>(&(it.getPunt()->info));
        if(t){
            if(t->getTorneo()->getNome()==s.getTorneo()->getNome())
                presente=true;
        }
    }
    if(!presente){
        elenco->add(s);
        return presente;
    }
    else
        return presente;
}

bool ElencoTornei::deleteTorneo(const string& nome){
    bool presente=false;
    Container<SmartPtr>::const_Iterator it = elenco->begin();
    for(; it!=elenco->end() && !presente ;++it){
        SmartPtr * t=static_cast<SmartPtr*>(&(it.getPunt()->info));
        if(t){
            if(t->getTorneo()->getNome()==nome){
                presente=true;
                elenco->remove(*it);
            }
        }
    }
    return presente;
}




ElencoTornei::SmartPtr ElencoTornei::searchTorneo(const string& nameT){
    Container<SmartPtr>::Iterator it = elenco->begin();
    for(; it != elenco->end(); ++it){
        SmartPtr* t = static_cast<SmartPtr*>(& (it.getPunt()->info) );
        if(t){
            Tornei* torneo = t->getTorneo();
            if(nameT == torneo->getNome())
                return *t;
        }
    }
    return 0;
}

Container<ElencoTornei::SmartPtr>::Iterator& ElencoTornei::getIterator(const string & name){
    bool presente=false;
    Container<SmartPtr>::Iterator it = elenco->begin();
    for(; it != elenco->end() && !presente; ++it){
        SmartPtr* t = static_cast<SmartPtr*>(& (it.getPunt()->info) );
        if(t){
            if(name == t->getTorneo()->getNome()){
                presente=true;
                return it;
            }
        }
    }
}


ElencoTornei::SmartPtr& ElencoTornei::getAccount(Container<ElencoTornei::SmartPtr>::Iterator i){
    return (*elenco)[i];
}

Cash& ElencoTornei::modificaCash(const SmartPtr & i){
    Cash* c=dynamic_cast<Cash*>(i.getTorneo());
    if(c)
        return *c;
}



SitAndGo& ElencoTornei::modificaSitAndGo(const SmartPtr & i){
    SitAndGo* s=dynamic_cast<SitAndGo*>(i.getTorneo());
    if(s)
        return *s;
}

Container<ElencoTornei::SmartPtr>::Iterator ElencoTornei::editTornei(const string& nome){
    bool presente=false;
    Container<SmartPtr>::Iterator it = elenco->begin();
    for(; it!=elenco->end() && !presente ;++it){
        SmartPtr * t=static_cast<SmartPtr*>(&(it.getPunt()->info));
        if(t){
            if(t->getTorneo()->getNome()==nome){
                    return it;
            }
        }
    }
}

double ElencoTornei::getAddCash(){
    return Cash::getAddizionale();
}

string ElencoTornei::nomiSalvati(const ElencoTornei& e){
    Container<ElencoTornei::SmartPtr>::Iterator it=e.elenco->begin();
    for(; it!=e.elenco->end(); ++it){
        ElencoTornei::SmartPtr* t=static_cast<ElencoTornei::SmartPtr*>(&(it.getPunt()->info));
        if(t)
            return t->getTorneo()->getNome();
     }
}



