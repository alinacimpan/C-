
#include "retea.h"
#include  <fstream>
using namespace std;

Retea::Retea()
    : users(),
    prieteni(),
    evenimente(),
    participare_evenimente()
{
    citireCSV("utilizatori.csv");
}

void Retea::citireCSV(string filename) {
    ifstream f(filename);
    if (f.is_open()) {
        Utilizator user;
        while (readCSV(f, user)) {
            this->users.add(user);
        }
    }
}

void Retea::scriereCSV(string filename) {
    ofstream f(filename);
    auto users_vec = this->users.getAll();

    if (f.is_open()) {
        for (int i = 0; i < users_vec.size(); i++) {
            writeCSV(f, *users_vec[i]);
        }
    }
}

Retea& Retea::getInstance() {
    static Retea instance;
    return instance;
}

Retea::~Retea()
{
    scriereCSV("utilizatori.csv");
}


List<Utilizator>& Retea::getUsers() {
    return users;
}

List<Eveniment>& Retea::getEvents() {
    return evenimente;
}

MultiDictionary<Utilizator*, Utilizator*>& Retea::getPrieteni() {
    return prieteni;
}

MultiDictionary<Utilizator*, Eveniment*>& Retea::getParticipareEvenimente() {
    return participare_evenimente;
}

void Retea::adaugareUtilizator(Utilizator* user) {
    users.add(*user);
}
void Retea::stergereUtilizator(Utilizator* user) {
    auto prtni = prieteni.get(user);

    for (auto& prtn : prtni) {
        prieteni.remove(prtn, user);
    }

    for (auto& participanti_eveniment : participare_evenimente.get(user)) {
        participare_evenimente.remove(user, participanti_eveniment);
    }

    participare_evenimente.remove(user);

    users.remove(*user);
}

Utilizator* Retea::gasireUtilizator(string username) {
    for (auto& user : users.getAll()) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    return nullptr;
}
void Retea::adaugareEveniment(Eveniment* event) {
    evenimente.add(*event);
}
void Retea::actualizareUtilizator(Utilizator* utilizator, Utilizator utilizator_nou) {
    utilizator->setUsername(utilizator_nou.getUsername());
    utilizator->setParola(utilizator_nou.getParola());
    utilizator->setEmail(utilizator_nou.getEmail());
    utilizator->setPrenume(utilizator_nou.getPrenume());
    utilizator->setNume(utilizator_nou.getNume());
}
Eveniment* Retea::gasireEveniment(string event_name) {
    for (auto& event : evenimente.getAll()) {
        if (event->getNume() == event_name) {
            return event;
        }
    }
    return nullptr;
}

void Retea::adaugarePrieten(Utilizator* utilizator1, Utilizator* utilizator2) {
    if (!prieteni.contains(utilizator1, utilizator2))
        prieteni.put(utilizator1, utilizator2);

    if (!prieteni.contains(utilizator2, utilizator1))
        prieteni.put(utilizator2, utilizator1);
}

void Retea::adaugareParticipare(Utilizator* utilizator, Eveniment* eveniment) {
    if (!participare_evenimente.contains(utilizator, eveniment))
        participare_evenimente.put(utilizator, eveniment);
}

void Retea::adaugareMesaj(Mesaj mesaj) {
    messages.push_back(mesaj);
}

void Retea::actualizareEveniment(Eveniment* eveniment, Eveniment eveniment_nou) {
    eveniment->setNume(eveniment_nou.getNume());
    eveniment->setData_incepere(eveniment_nou.getData_incepere());
    eveniment->setData_sfarsit(eveniment_nou.getData_sfarsit());
    eveniment->setLocatie(eveniment_nou.getLocatie());
}

void Retea::stergereEveniment(Eveniment* eveniment) {

    for (auto& utilizator : users.getAll()) {
        participare_evenimente.remove(utilizator, eveniment);
    }

    evenimente.remove(*eveniment);
}

void Retea::stergerePrietenie(Utilizator* utilizator1, Utilizator* utilizator2) {
    prieteni.remove(utilizator1, utilizator2);
    prieteni.remove(utilizator2, utilizator1);
}

void Retea::stergereParticipare(Utilizator* utilizator, Eveniment* eveniment) {
    participare_evenimente.remove(utilizator, eveniment);
}

vector<Utilizator*> Retea::getPrieteniUser(Utilizator* utilizator) {
    return prieteni.get(utilizator);
}

vector<Utilizator*> Retea::getPrieteniComuni(Utilizator* utilizator1, Utilizator* utilizator2) {
    vector<Utilizator*> comuni;

    for (auto& prieteni_1 : getPrieteniUser(utilizator1)) {
        for (auto& prieteni_2 : getPrieteniUser(utilizator2)) {
            if (prieteni_1 == prieteni_2) {
                comuni.push_back(prieteni_1);
            }
        }
    }
    return comuni;
}

vector<Eveniment*> Retea::getEvenimenteUtilizator(Utilizator* user) {
    return participare_evenimente.get(user);
}

vector<Utilizator*> Retea::getUtilizatoriEveniment(Eveniment* eveniment) {
    vector<Utilizator*> participanti;

    for (auto& user_p : users.getAll()) {
        for (auto& event_p : getEvenimenteUtilizator(user_p)) {
            if (event_p == eveniment) {
                participanti.push_back(user_p);
            }
        }
    }
    return participanti;
}

vector<Mesaj> Retea::getMesaj(Utilizator* utilizator) {
    vector<Mesaj> msj;

    for (auto& text : messages) {
        if (text.getReceptor() == utilizator || text.getExpeditor() == utilizator) {
            msj.push_back(text);
        }
    }

    return msj;
}

vector<Mesaj> Retea::getMesaj(Utilizator* utilizator1, Utilizator* utilizator2) {
    vector<Mesaj> msj;

    for (auto& text : messages) {
        if ((text.getReceptor() == utilizator1 && text.getExpeditor() == utilizator2) || (text.getReceptor() == utilizator2 && text.getExpeditor() == utilizator1)) {
            msj.push_back(text);
        }
    }

    return msj;
}
