
#include <string>
#include <vector>
#include <iostream>
#include "Utilizator.h"
using namespace std;

class Eveniment {
private:
    string nume;
    string locatie;
    string data_incepere;
    string data_sfarsit;

public:
    Eveniment();
    Eveniment(const Eveniment& other);
    Eveniment(const string& nume,
        const string& locatie,
        const string& data_incepere,
        const string& data_sfarsit);

    string getNume() const;
    string getLocatie() const;
    string getData_incepere() const;
    string getData_sfarsit() const;

    void setNume(const string& name);
    void setLocatie(const string& locatie);
    void setData_incepere(const string& data_incepere);
    void setData_sfarsit(const string& data_sfarsit);

    bool operator==(const Eveniment& other) const;
    bool operator!=(const Eveniment& other) const;

    Eveniment& operator=(const Eveniment& other);

    friend ostream& operator<<(ostream& os, const Eveniment& event);
    friend istream& operator>>(istream& is, Eveniment& event);
};
