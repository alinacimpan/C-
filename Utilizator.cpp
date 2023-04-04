
#include "Utilizator.h"
using namespace std;

Utilizator::Utilizator()
    : username(""),
    parola(""),
    email(""),
    prenume(""),
    nume("")
{
}


Utilizator::Utilizator(const string& username, const string& parola, const string& email, const string& prenume,
                        const string& nume)
    : username(username),
    parola(parola),
    email(email),
    prenume(prenume),
    nume(nume)
{
}


Utilizator::Utilizator(const Utilizator& other)
    : username(other.username),
    parola(other.parola),
    email(other.email),
    prenume(other.prenume),
    nume(other.nume)
{
}


Utilizator::~Utilizator()
{
}


string Utilizator::getUsername()
{
    return username;
}


string Utilizator::getParola()
{
    return parola;
}


string Utilizator::getEmail()
{
    return email;
}


string Utilizator::getPrenume()
{
    return prenume;
}


string Utilizator::getNume()
{
    return nume;
}


void Utilizator::setUsername(const string& username)
{
    this->username = username;
}


void Utilizator::setParola(const string& parola)
{
    this->parola = parola;
}


void Utilizator::setEmail(const string& email)
{
    this->email = email;
}


void Utilizator::setPrenume(const string& prenume)
{
    this->prenume = prenume;
}


void Utilizator::setNume(const string& nume) {
    this->nume = nume;
}

bool Utilizator::operator==(const Utilizator& other) const {
    return username == other.username;
}

ostream& operator<<(ostream& os, const Utilizator& user) {
    cout << "Nume de utilizator: " << user.username << endl;
    os << "Parola: " << user.parola << endl;
    os << "Email: " << user.email << endl;
    os << "Prenume: " << user.prenume << endl;
    os << "Nume: " << user.nume<< endl;

    return os;
}


istream& operator>>(istream& is, Utilizator& user) {
    string username;
    string parola;
    string email;
    string prenume;
    string nume;

    cout << "Nume de utilizator: ";
    is >> username;
    cout << "Parola: ";
    is >> parola;
    cout << "Email: ";
    is >> email;
    cout << "Prenume: ";
    is >> prenume;
    cout << "Nume: ";
    is >> nume;

    user.username = username;
    user.parola = parola;
    user.email = email;
    user.prenume = prenume;
    user.nume = nume;
    return is;
}


ostream& writeCSV(ostream& os, const Utilizator& user) {
    os << user.username << ",";
    os << user.parola << ",";
    os << user.email << ",";
    os << user.prenume << ",";
    os << user.nume << "," ;
    return os;
}

istream& readCSV(istream& is, Utilizator& user) {
    string username;
    string parola;
    string email;
    string prenume;
    string nume;

    getline(is, username, ',');
    getline(is, parola, ',');
    getline(is, email, ',');
    getline(is, prenume, ',');
    getline(is, nume, ',');

    user.username = username;
    user.parola = parola;
    user.email = email;
    user.prenume = prenume;
    user.nume = nume;
    return is;
}
