
#include "ui.h"
#include <iostream>
using namespace std;

UserInterface::UserInterface()
    : retea(Retea::getInstance())
{}

UserInterface::~UserInterface()
{}

void UserInterface::start() {
    int command = -1;

    while (true) {
        cout << "UTILIZATORI                                  " << endl;
        cout << "------------------- 1.  Adauga utilizator ---------------------------" << endl;
        cout << "------------------- 2.  Lista de utilizatori ------------------------" << endl;
        cout << "------------------- 3.  Detalii utilizator --------------------------" << endl;
        cout << "------------------- 4.  Actualizeaza utilizator ---------------------" << endl;
        cout << "------------------- 5.  Sterge utilizator ---------------------------" << endl;

        cout << "PRIETENI                                 " << endl;
        cout << "------------------- 6. Adauga prieten -------------------------------" << endl;
        cout << "------------------- 7. Sterge prieten -------------------------------" << endl;
        cout << "------------------- 8. Lista prieteni -------------------------------" << endl;
        cout << "------------------- 9. Lista de prieteni comuni ---------------------" << endl;

        cout << "MESAJE                                   " << endl;
        cout << "------------------- 10. Adauga mesaj --------------------------------" << endl;
        cout << "------------------- 11. Listeaza mesajele utilizatorului ------------" << endl;
        cout << "------------------- 12. Lista de mesaje a doi utilizatori -----------" << endl;

        cout << "EVENIMENTE                                " << endl;
        cout << "------------------- 13. Adauga eveniment ----------------------------" << endl;
        cout << "------------------- 14. Lista evenimente ----------------------------" << endl;
        cout << "------------------- 15. Detalii eveniment ---------------------------" << endl;
        cout << "------------------- 16. Actualizeaza eveniment ----------------------" << endl;
        cout << "------------------- 17. Sterge eveniment ----------------------------" << endl;
        cout << "------------------- 18. Afiseaza evenimentele unui utilizator -------" << endl;
        cout << "------------------- 19. Lista utilizatorilor de la un eveniment -----" << endl;
        cout << "------------------- 20. Participare la eveniment --------------------" << endl;
        cout << "------------------- 21. Renuntare la eveniment ----------------------" << endl;
        cout << "------------------- 22. Exit ----------------------------------------" << endl;

        cout << "Alege optiunea: ";
        cin >> command;

        switch (command) {
        case 1:
            adaugareUtilizator();
            break;
        case 2:
            listareUtilizatori();
            break;
        case 3:
            detaliiUtilizator();
            break;
        case 4:
            actualizareUtilizator();
            break;
        case 5:
            stergereUtilizator();
            break;
        case 6:
            adaugarePrietenie();
            break;
        case 7:
            stergerePrietenie();
            break;
        case 8:
            listarePrieteni();
            break;
        case 9:
            listarePrieteniComuni();
            break;
        case 10:
            adaugareMesaj();
            break;
        case 11:
            afisareMesajeUtilizator();
            break;
        case 12:
            afisareMesajeUtilizatori();
            break;
        case 13:
            adaugareEveniment();
            break;
        case 14:
            listareEvenimente();
            break;
        case 15:
            detaliiEveniment();
            break;
        case 16:
            actualizareEveniment();
            break;
        case 17:
            stergereEveniment();
            break;
        case 18:
            listareEvenimenteUtilizator();
            break;
        case 19:
            listareUtilizatoriEveniment();
            break;
        case 20:
            adaugareParticipare();
            break;
        case 21:
            stergereParticipare();
            break;
        case 22:
            return;
        default:
            cout << "Optiune invalida. Incearca din nou." << endl;
        }
        cout << "Apasati enter pentru a face alta operatie...";
        cin.ignore();
        cin.get();

    }
}

void UserInterface::detaliiUtilizator() {
    string username;
    cout << "Introdu utilizator: ";
    cin >> username;

    Utilizator* user = retea.gasireUtilizator(username);
    if (retea.gasireUtilizator(username) == nullptr) {
        cout << "Utilizator negasit." << endl;
        return;
    }

    cout << *user << endl;
}

void UserInterface::listareUtilizatori() {
    auto users = retea.getUsers().getAll();

    cout << "Utilizatori:" << endl;
    for (auto& user : users) {
        cout << user->getUsername() << endl;
    }
}

void UserInterface::adaugareUtilizator() {
    cin.ignore();

    Utilizator* user = new Utilizator();
    cin >> *user;

    retea.adaugareUtilizator(user);

    cout << "Utilizator adaugat." << endl;
}

void UserInterface::actualizareUtilizator() {
    string username;
    cout << "Introduceti numele de utilizator: ";
    cin >> username;

    Utilizator* user = retea.gasireUtilizator(username);

    if (user == nullptr) {
        cout << "Utilizatorul nu a fost gasit" << endl;
        return;
    }

    Utilizator user_actualizat;
    cin >> user_actualizat;

    retea.actualizareUtilizator(user, user_actualizat);

    cout << "Utilizator actualizat." << endl;
}

void UserInterface::stergereUtilizator() {
    string username;
    cout << "Introdu username-ul: ";
    cin >> username;

    Utilizator* user = retea.gasireUtilizator(username);

    if (user == nullptr) {
        cout << "Utilizatorul nu a fost gasit" << endl;
        return;
    }

    retea.stergereUtilizator(user);

    cout << "Utilizator sters." << endl;
}

void UserInterface::detaliiEveniment() {
    string nume_eveniment;
    cout << "Introduceti numele evenimentului: ";
    cin >> nume_eveniment;

    Eveniment* eveniment = retea.gasireEveniment(nume_eveniment);
    if (eveniment == nullptr) {
        cout << "Evenimentul nu a fost gasit." << endl;
        return;
    }

    cout << *eveniment << endl;
}

void UserInterface::listareEvenimente() {

    cout << "Evenimente: " << endl;
    for (auto& e : retea.getEvents().getAll()) {
        cout << e->getNume() << endl;
    }
}

void UserInterface::adaugareEveniment() {
    Eveniment* eveniment = new Eveniment();
    cin >> *eveniment;

    retea.adaugareEveniment(eveniment);

    cout << "Eveniment adaugat." << endl;
}

void UserInterface::actualizareEveniment() {
    string nume_eveniment;
    cout << "Introdu numele evenimentului: ";
    cin >> nume_eveniment;

    Eveniment* eveniment = retea.gasireEveniment(nume_eveniment);

    if (eveniment == nullptr) {
        cout << "Evenimentul nu a fost gasit" << endl;
        return;
    }

    Eveniment eveniment_nou;
    cin >> eveniment_nou;

    retea.actualizareEveniment(eveniment, eveniment_nou);

    cout << "Evenimnet actualizat." << endl;
}

void UserInterface::stergereEveniment() {
    string nume_eveniment;
    cout << "Introdu numele evenimentului: ";
    cin >> nume_eveniment;

    Eveniment* eveniment = retea.gasireEveniment(nume_eveniment);

    if (eveniment == nullptr) {
        cout << "Evenimnetul nu a fost gasit" << endl;
        return;
    }

    retea.stergereEveniment(eveniment);

    cout << "Evenimnetul a fost sters." << endl;
}

void UserInterface::listareEvenimenteUtilizator() {
    string username;
    cout << "Introdu username-ul: ";
    cin >> username;

    if (retea.gasireUtilizator(username) == nullptr) {
        cout << "Utilizator nu exista" << endl;
        return;
    }

    cout << "La eveniment sunt prezenti " << retea.gasireUtilizator(username)->getUsername() << ":" << endl;
    for (auto& eveniment : retea.getParticipareEvenimente().get(retea.gasireUtilizator(username))) {
        cout << eveniment->getNume() << endl;
    }
}

void UserInterface::listareUtilizatoriEveniment() {
    string nume_eveniment;
    cout << "Introdu numele evenimentului: ";
    cin >> nume_eveniment;

    if (retea.gasireEveniment(nume_eveniment) == nullptr) {
        cout << "Evenimentul nu exista" << endl;
        return;
    }

    cout << "Utilizatorii prezenti la " << retea.gasireEveniment(nume_eveniment)->getNume() << " sunt: " << endl;
    for (auto& user : retea.getUsers().getAll()) {
        for (auto& event : retea.getEvenimenteUtilizator(user)) {
            if (event == retea.gasireEveniment(nume_eveniment))
            {
                cout << user->getUsername() << endl;
                break;
            }
        }
    }
}

void UserInterface::adaugarePrietenie() {
    string username1;
    string username2;
    cout << "Introdu primul utilizator: ";
    cin >> username1;
    cout << "Introdu al doilea utilizator: ";
    cin >> username2;


    if (retea.gasireUtilizator(username1) == nullptr){
        cout << "Utilizatorul1 nu exista" << endl;
        return;}

    if(retea.gasireUtilizator(username2) == nullptr) {
        cout << "Utilizatorul2 nu exista" << endl;
        return;
    }
    retea.adaugarePrieten(retea.gasireUtilizator(username1), retea.gasireUtilizator(username2));

    cout << "Prieten adaugat." << endl;
}

void UserInterface::stergerePrietenie() {
    string username1;
    string username2;
    cout << "Introdu primul utilizator: ";
    cin >> username1;
    cout << "Introdu al doilea utilizator: ";
    cin >> username2;

    if (retea.gasireUtilizator(username1) == nullptr){
        cout << "Utilizatorul1 nu exista" << endl;
        return;}

    if(retea.gasireUtilizator(username2) == nullptr) {
        cout << "Utilizatorul2 nu exista" << endl;
        return;
    }

    retea.stergerePrietenie(retea.gasireUtilizator(username1), retea.gasireUtilizator(username2));

    cout << "Prieten sters." << endl;
}

void UserInterface::listarePrieteni() {
    string username;
    cout << "Introdu utilizatorul: ";
    cin >> username;

    if (retea.gasireUtilizator(username) == nullptr) {
        cout << "Utilizatorul nu exista" << endl;
        return;
    }

    auto prieteni = retea.getPrieteni().get(retea.gasireUtilizator(username));

    cout << "Utilizatorul " << retea.gasireUtilizator(username)->getUsername() << " are ca prieteni: " << endl;
    for (auto& prieten : prieteni) {
        cout << prieten->getUsername() << endl;
    }
}

void UserInterface::listarePrieteniComuni() {
    string username1;
    string username2;
    cout << "Introdu primul urilizator: ";
    cin >> username1;
    cout << "Introdu al doilea utilizator: ";
    cin >> username2;


    if (retea.gasireUtilizator(username1) == nullptr ||  retea.gasireUtilizator(username2) == nullptr) {
        cout << "Utilizatorul nu exista" << endl;
        return;
    }

    cout << "Prieteni comuni ai " << retea.gasireUtilizator(username1)->getUsername() << " si " << retea.gasireUtilizator(username2)->getUsername() << ":" << endl;
    for (auto& prieten : retea.getPrieteniComuni(retea.gasireUtilizator(username1), retea.gasireUtilizator(username2))) {
        cout << prieten->getUsername() << endl;
    }
}

void UserInterface::adaugareParticipare() {
    string event_nume;
    string username;
    cout << "Introdu numele evenimentului: ";
    cin >> event_nume;
    cout << "Introdu utilizatorul: ";
    cin >> username;
    if (retea.gasireEveniment(event_nume) == nullptr ) {
        cout << "Evenimentul nu a fost gasit" << endl;
        return;}
    if ( retea.gasireUtilizator(username) == nullptr){
        cout << "Utilizatorul nu a fost gasit" << endl;
        return;}
    retea.adaugareParticipare(retea.gasireUtilizator(username), retea.gasireEveniment(event_nume));

    cout << "Participare inregistrata cu succes." << endl;
}

void UserInterface::stergereParticipare() {
    string event_nume;
    string username;
    cout << "Introdu numele evenimentului: ";
    cin >> event_nume;
    cout << "Introdu utilizatorul: ";
    cin >> username;
    if (retea.gasireEveniment(event_nume) == nullptr ) {
        cout << "Evenimentul nu a fost gasit" << endl;
        return;}
    if ( retea.gasireUtilizator(username) == nullptr){
        cout << "Utilizatorul nu a fost gasit" << endl;
        return;}
    retea.stergereParticipare(retea.gasireUtilizator(username), retea.gasireEveniment(event_nume));

    cout << "Utilizatorul " << retea.gasireUtilizator(username)->getUsername() <<" nu va mai participa la evenimentul " <<retea.gasireEveniment(event_nume)->getNume() << endl;
}

void UserInterface::adaugareMesaj() {
    string username_expeditor;
    string username_receptor;
    string mesaj;
    cout << "Introdu username-ul expeditorului: ";
    cin >> username_expeditor;
    cout << "Introdu username-ul receptorului: ";
    cin >> username_receptor;
    cout << "Introdu mesajul: ";
    cin >> mesaj;
    if (retea.gasireUtilizator(username_expeditor) == nullptr || retea.gasireUtilizator(username_receptor) == nullptr) {
        cout << "Utilizator negasit" << endl;
        return;
    }

    retea.adaugareMesaj(Mesaj(mesaj, retea.gasireUtilizator(username_expeditor), retea.gasireUtilizator(username_receptor)));

    cout << "Mesaj trimis." << endl;
}

void UserInterface::afisareMesajeUtilizator() {
    string username;
    cout << "Introdu utilizator: ";
    cin >> username;
    if (retea.gasireUtilizator(username) == nullptr) {
        cout << "Utilizator negasit" << endl;
        return;
    }
    auto messages = retea.getMesaj(retea.gasireUtilizator(username));

    cout << "Mesaje ale " << retea.gasireUtilizator(username)->getUsername() << ":" << endl;
    for (auto& message : messages) {
        cout << message.getExpeditor()->getUsername() << " -> " << message.getReceptor()->getUsername() << ": " << message.getText() << endl;
    }
}

void UserInterface::afisareMesajeUtilizatori() {
    string username1;
    string username2;
    cout << "Introdu primul utilizator: ";
    cin >> username1;
    cout << "Introdu al 2-lea utilizator: ";
    cin >> username2;
    if (retea.gasireUtilizator(username1) == nullptr || retea.gasireUtilizator(username2) == nullptr) {
        cout << "Utilizator negasit" << endl;
        return;
    }

    auto messages = retea.getMesaj(retea.gasireUtilizator(username1), retea.gasireUtilizator(username2));

    cout << "Mesaje intre " << retea.gasireUtilizator(username1)->getUsername() << " si " << retea.gasireUtilizator(username2)->getUsername() << ":" << endl;
    for (auto& message : messages) {
        cout << message.getExpeditor()->getUsername() << " -> " << message.getReceptor()->getUsername() << ": " << message.getText() << endl;
    }
}

