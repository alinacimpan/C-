#ifndef RETEA_H
#define RETEA_H

#include "eveniment.h"
#include "Utilizator.h"
#include "multiDictionar.h"
#include "list.h"
#include "mesaj.h"
#include <vector>
using namespace std;

class Retea {
private:
    List<Utilizator> users;
    List<Eveniment> evenimente;
    MultiDictionary<Utilizator*, Utilizator*> prieteni;
    MultiDictionary<Utilizator*, Eveniment*> participare_evenimente;
    vector<Mesaj> messages;

    Retea();

    void citireCSV(string filename);
    void scriereCSV(string filename);

public:
    static Retea& getInstance();

    ~Retea();

    List<Utilizator>& getUsers();
    List<Eveniment>& getEvents();
    MultiDictionary<Utilizator*, Utilizator*>& getPrieteni();
    MultiDictionary<Utilizator*, Eveniment*>& getParticipareEvenimente();

    Utilizator* gasireUtilizator(string username);
    Eveniment* gasireEveniment(string event_nume);

    void adaugareUtilizator(Utilizator* user);
    void actualizareUtilizator(Utilizator* user, Utilizator new_user);
    void stergereUtilizator(Utilizator* user);

    void adaugareEveniment(Eveniment* event);
    void actualizareEveniment(Eveniment* event, Eveniment new_event);
    void stergereEveniment(Eveniment* event);

    void adaugarePrieten(Utilizator* user1, Utilizator* user2);
    void stergerePrietenie(Utilizator* user1, Utilizator* user2);
    void adaugareParticipare(Utilizator* user, Eveniment* event);
    void stergereParticipare(Utilizator* user, Eveniment* event);

    void adaugareMesaj(Mesaj message);

    vector<Utilizator*> getPrieteniUser(Utilizator* user);
    vector<Utilizator*> getPrieteniComuni(Utilizator* user1, Utilizator* user2);
    vector<Eveniment*> getEvenimenteUtilizator(Utilizator* user);
    vector<Utilizator*> getUtilizatoriEveniment(Eveniment* event);
    vector<Mesaj> getMesaj(Utilizator* user);
    vector<Mesaj> getMesaj(Utilizator* user1, Utilizator* user2);
};

#endif // RETEA_H

