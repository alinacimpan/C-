
#include "eveniment.h"
using namespace std;

Eveniment::Eveniment()
    : nume(""),
    locatie(""),
    data_incepere(""),
    data_sfarsit("")
{}

Eveniment::Eveniment(const Eveniment& other)
    : nume(other.nume),
    locatie(other.locatie),
    data_incepere(other.data_incepere),
    data_sfarsit(other.data_sfarsit)
{}

Eveniment::Eveniment(const string& nume, const string& locatie, const string& data_incepere, const string& data_sfarsit)
    : nume(nume),
    locatie(locatie),
    data_incepere(data_incepere),
    data_sfarsit(data_sfarsit)
{}

string Eveniment::getNume() const
{
    return nume;
}

string Eveniment::getLocatie() const
{
    return locatie;
}

string Eveniment::getData_incepere() const
{
    return data_incepere;
}

string Eveniment::getData_sfarsit() const
{
    return data_sfarsit;
}

void Eveniment::setNume(const string& nume)
{
    this->nume = nume;
}

void Eveniment::setLocatie(const string& locatie)
{
    this->locatie = locatie;
}

void Eveniment::setData_incepere(const string& data_incepere)
{
    this->data_incepere = data_incepere;
}

void Eveniment::setData_sfarsit(const string& data_sfarsit)
{
    this->data_sfarsit = data_sfarsit;
}

bool Eveniment::operator==(const Eveniment& other) const
{
    return nume == other.nume &&
        locatie == other.locatie &&
        data_incepere == other.data_incepere &&
        data_sfarsit == other.data_sfarsit;
}

bool Eveniment::operator!=(const Eveniment& other) const
{
    return !(*this == other);
}

Eveniment& Eveniment::operator=(const Eveniment& other)
{
    nume = other.nume;
    locatie = other.locatie;
    data_incepere = other.data_incepere;
    data_sfarsit = other.data_sfarsit;

    return *this;
}

ostream& operator<<(ostream& os, const Eveniment& event) {
    os << "Eveniment: " << event.nume << endl;
    os << "Locatie: " << event.locatie << endl;
    os << "Data inceperii: " << event.data_incepere << endl;
    os << "Data sfarsit: " << event.data_sfarsit << endl;

    return os;
}

istream& operator>>(istream& is, Eveniment& event) {
    string nume;
    string locatie;
    string data_incepere;
    string data_sfarsit;

    cout << "Nume: ";
    cin.ignore();
    getline(is, nume);

    cout << "Locatie: ";
    cin.ignore();
    getline(is, locatie);

    cout << "Data inceput: ";
    cin.ignore();
    getline(is, data_incepere);

    cout << "Data sfarsit: ";
    cin.ignore();
    getline(is, data_sfarsit);

    event.nume = nume;
    event.locatie = locatie;
    event.data_incepere = data_incepere;
    event.data_sfarsit = data_sfarsit;

    return is;
}
