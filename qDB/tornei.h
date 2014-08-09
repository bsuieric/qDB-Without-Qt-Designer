#ifndef TORNEI_H
#define TORNEI_H

#include <string>
using namespace std;


//Classe Tornei di poker

class Tornei
{
private:
    string nome;
    int numeroGiocatori;
    double taxPerGiocatore;
public:
    //costruttore di default
    Tornei();

    //costruttore che chiede il numero dei giocatori
    Tornei(string, int,double);

    //costruttore di copia
    Tornei(const Tornei&);

    //restituisce il nome del tornei
    string getNome()const;

    //permette di cambiare il nome del torneo
    void resetNome(string);

    //restituisce il numero dei giocatori
    int getNumeroGiocatori()const;

    //permette di cambiare il numero dei giocatori
    void resetNumeroGiocatori(int);

    //restituisce la taxPerGiocatore
    double getTaxPerGiocatore()const;

    //permette di cambiare la tax
    void resetTax(double);

    //clona l'oggetto d'stanza sullo heap, ritorna un puntatore Tornei* all'oggetto creato
    virtual Tornei* clona() const=0;

    //Distruttore virtuale
    virtual ~Tornei();

    //metodo tax virtuale
    virtual double tax()const=0;

    //Operatore di uguaglianza virtuale
    virtual bool operator==(const Tornei&) const;

};
#endif // TORNEI_H
