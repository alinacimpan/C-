#include "retea.h"

class UserInterface {
public:
    UserInterface();
    ~UserInterface();

    void start();

private:
    Retea& retea;

    void detaliiUtilizator();
    void listareUtilizatori();
    void adaugareUtilizator();
    void actualizareUtilizator();
    void stergereUtilizator();

    void detaliiEveniment();
    void listareEvenimente();
    void adaugareEveniment();
    void actualizareEveniment();
    void stergereEveniment();
    void listareEvenimenteUtilizator();
    void listareUtilizatoriEveniment();

    void adaugarePrietenie();
    void stergerePrietenie();
    void listarePrieteni();
    void listarePrieteniComuni();

    void adaugareParticipare();
    void stergereParticipare();

    void adaugareMesaj();
    void afisareMesajeUtilizator();
    void afisareMesajeUtilizatori();
};


