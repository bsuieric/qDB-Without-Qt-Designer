#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
using std::ostream;

template <class T> class Container; //dichiarazione incompleta di classe

template <class T> ostream& operator<<(ostream&, const Container<T>&);

//classe Container
template<class T>
class Container{
    // dichiarazione di amicizia
    friend class Iterator;
    friend class const_Iterator;
    friend ostream& operator<<(ostream&, const Container<T>&);
private:
    //classe ListItem
    class ListItem{
    public:
        T info;
        ListItem* next;
        //costruttori
        ListItem();
        ListItem(const T&, ListItem*);
        //distruttore
        ~ListItem();
    };
    T getInfo()const;
    //puntatore a ListItem;
    ListItem* first;
    //metodi statici
    static ListItem* copia(ListItem*); //crea una copia della lista

public:
    //classe iteratore
    class Iterator{
        //dichiarazione di amicizia
        friend class Container<T>;
    private:
        Container::ListItem* punt; //ListItem puntato dall'iteratore
    public:
        //costruttore di default
        Iterator();
        //operatore di uguaglianza
        bool operator==(const Iterator&)const;
        //operatore di disuguaglianza
        bool operator!=(const Iterator&)const;
        //operatore ++ prefisso
        Iterator& operator++();
        //operatore ++ postfisso
        Iterator& operator++(int);


        Container::ListItem* getPunt();
    };

    class const_Iterator{
        //dichiarazione di amicizia
        friend class Container<T>;
    private:
        Container::ListItem* punt;//ListItem puntato dall'const_Iterator
    public:
        //costruttore di default
        const_Iterator();
        //costruttore come convertitore di tipo da iterator a const_Iterator
        const_Iterator(const Iterator&);
        //operatore di uguaglianza
        bool operator==(const const_Iterator&)const;
        //operatore di disuguaglianza
        bool operator!=(const const_Iterator&)const;
        //operatore ++ prefisso
        const_Iterator& operator++();
        //operatore ++ postfisso
        const_Iterator operator++(int);

        T& operator*()const;

        Container::ListItem* getPunt()const;
    };

    //costruttore di default di Container
    Container();
    //costruttore di copia di Container
    Container(const Container&);
    //distruttore
    ~Container();
    //metodi di Container
    //metodo che controlla se il contenitore e' vuoto
    bool isEmpty()const;
    //Numero di oggetti contenuti
    int getSize()const;
    //metodo che ritorna l'elemento nel contenitore
    const_Iterator element(const T&) const;
    //metodo che controlla se un elemento e' presente nel contenitore
    bool isPresent(const T&)const;
    //metodo che aggiunge in testa alla lista un elemento
    void add(const T&);
    //metodo che rimouve un elemento della lista
    void remove(const T&);

    //metodi di Iterator
    //Inizio Lista
    Iterator begin();
    //Fine Lista
    Iterator end();
    //operatore di indicizzazione
    T& operator[](const Iterator&);


    //metodi di const_Iterator
    //Inizio Lsta
    const_Iterator begin()const;
    //Fine Lista
    const_Iterator end()const;
    //operatore di indicizzazione
    const T& operator[](const const_Iterator&)const;
    //const T& operator*(const const_Iterator&)const;



};

/*
 **************************
 Metodi di ListItem
 **************************
*/

//costruttore di default
template<class T>
Container<T>::ListItem::ListItem() :next(0){}
//costruttore a 2 parametri
template<class T>
Container<T>::ListItem::ListItem(const T& t,ListItem* p): info(t),next(p){}
//distruttore
template<class T>
Container<T>::ListItem::~ListItem(){
    if(next){
        delete next;
    }//chiamata ricorsiva
}

/*
 **************************
 Metodi di Iterator
 **************************
*/

//costruttore di default
template<class T>
Container<T>::Iterator::Iterator() :punt(0){}
//operatore di uguaglianza
template<class T>
bool Container<T>::Iterator::operator ==(const Iterator & it)const{
    return punt==it.punt;
}
//operatore di disuguaglianza
template<class T>
bool Container<T>::Iterator::operator !=(const Iterator & it)const{
    return punt!=it.punt;
}
//incremento prefisso
template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator ++(){
    if(punt)
        punt=punt->next;
    return *this;
}
//incremento postfisso
template<class T>
typename Container<T>::Iterator& Container<T>::Iterator::operator ++(int){
    Iterator aux=*this;
    if(punt)
        punt=punt->next;
    return aux;
}

template<class T>
typename Container<T>::ListItem* Container<T>::Iterator::getPunt(){return punt;};

/*
 **************************
 Metodi di const_Iterator
 **************************
*/

//costruttore di default
template < class T >
Container<T>::const_Iterator::const_Iterator() : punt(0) {}

//costruttore come convertitore di tipo da Iterator => const_Iterator
//perchè con il tipo di ritorno non posso overloadare begin()
//se non ho un contenitore costante
template < class T >
Container<T>::const_Iterator::const_Iterator(const Iterator & it){
    punt = it.punt;
}

// operatore di uguaglianza
template < class T >
bool Container<T>::const_Iterator::operator ==( const const_Iterator& it ) const {
    return punt == it.punt;
}

// operatore di disuguaglianza
template < class T >
bool Container<T>::const_Iterator::operator !=( const const_Iterator& it ) const {
    return punt != it.punt;
}

// incremento prefisso
template < class T >
typename Container<T>::const_Iterator& Container<T>::const_Iterator::operator ++() {
    if(punt)
        punt = punt->next; //
    return *this;
}

// incremento postfisso
template < class T >
typename Container<T>::const_Iterator Container<T>::const_Iterator::operator ++( int ) {
    const_Iterator aux = *this;
    if(punt)
        punt = punt->next; //
    return aux;
}

template<class T>
typename Container<T>::ListItem* Container<T>::const_Iterator::getPunt()const{return punt;};
/*
 **************************
 Metodi di Container
 **************************
*/

//funzione statica copia
template<class T>
typename Container<T>::ListItem* Container<T>::copia(ListItem *item){
    if(!item)
        return 0;
    else
        return new ListItem(item->info,copia(item->next));
}


//costruttore di default
template<class T>
Container<T>::Container():first(0){}

//costruttore di copia
template<class T>
Container<T>::Container(const Container & c):first(copia(c.first)){}

//distruzione profonda
template<class T>
Container<T>::~Container(){
    if(first)
        delete first;
}

//metodo che controllo se il contenitore e vuoto
template<class T>
bool Container<T>::isEmpty()const{
    return first==0;
}

//metodo che cerca e torna l'elemento nel contenitore
template<class T>
typename Container<T>::const_Iterator Container<T>::element(const T & t) const{
    bool trovato=false;
    const_Iterator aux;
    aux.punt=0;
    Container<T>::const_Iterator it=begin();
    for(; it!=end() && !trovato; ++it){
        if(it.punt->info == t){
            aux.punt=it.punt;
            trovato=true;
        }
    }
    return aux;
}

//metodo che controllo se un elemento e presente dentro il contenitore
template<class T>
bool Container<T>::isPresent(const T & t) const{
    const_Iterator it= element(t);
    if(it.punt)
        return true;
    else
        return false;
}

//aggiungo un elemento al contenitore
template<class T>
void Container<T>::add(const T &t){
    first=new ListItem(t,first);
}

//rimuovo un elemento dal contenitore
template<class T>
void Container<T>::remove(const T & t){
    ListItem* aux=first;
    ListItem* prec=0;
    while(aux && !(aux->info ==t)){
        prec=aux;
        aux=aux->next;
    }
    if(aux){{
        if(!prec){
            first=aux->next;
            aux->next=0;
        }
        else{
            prec->next=aux->next;
            aux->next=0;
        }}
        delete aux;
    }
}

/*
 ***********************************
 Metodi di utilizzo dell'iteratore
 ***********************************
*/

//inizio della lista
template<class T>
typename Container<T>::Iterator Container<T>::begin(){
    Iterator it;
    it.punt=first;
    return it;
}

//fine lista
template<class T>
typename Container<T>::Iterator Container<T>::end(){
    Iterator it;
    it.punt=0;
    return it;
}

//operatore di indicizzazione
template<class T>
T& Container<T>::operator[](const Iterator & it){
    return (it.punt)->info;
}



/*
 *****************************************
 Metodi di uitilizzo dell'const_Iteratore
 *****************************************
*/

//inizio lista
template<class T>
typename Container<T>::const_Iterator Container<T>::begin()const{
    const_Iterator it;
    it.punt=first;
    return it;
}

//fine lista
template<class T>
typename Container<T>::const_Iterator Container<T>::end() const{
    const_Iterator it;
    it.punt=0;
    return it;
}

//operatore di indicizzazione
template<class T>
const T &Container<T>::operator[](const const_Iterator& it)const{
    return (it.punt)->info;
}

template<class T>
T& Container<T>::const_Iterator::operator*()const{
    return punt->info;
}


/*
 *******************************
 Operatore di output
 *******************************
*/
 //overloading operatore <<
template<class T>
ostream operator <<(ostream &os,const Container<T>& c){
    typename Container<T>::const_Iterator it=c.begin();
    for(; it != c.end(); ++it){
        os<<c[it]<<"\n";
    }
    return os;
}

#endif // CONTAINER_H

