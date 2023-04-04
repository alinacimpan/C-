#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <iostream>
using namespace std;
class Utilizator
{
private:
	string username;
	string parola;
	string email;
	string prenume;
	string nume;

public:
	Utilizator();
	Utilizator(const string& username, const string& parola, const string& email, const string& prenume, const string& nume);
	Utilizator(const Utilizator& other);
	~Utilizator();

	string getUsername();
	string getParola();
	string getEmail();
	string getPrenume();
	string getNume();

	void setUsername(const string& username);
	void setParola(const string& parola);
	void setEmail(const string& email);
	void setPrenume(const string& prenume);
	void setNume(const string& nume);

	string toString();

	friend ostream& operator<<(ostream& os, const Utilizator& user);
	friend istream& operator>>(istream& is, Utilizator& user);

	friend ostream& writeCSV(ostream& os, const Utilizator& user);
	friend istream& readCSV(istream& is, Utilizator& user);

	bool operator==(const Utilizator& other) const;
};

ostream& writeCSV(ostream& os, const Utilizator& user);
istream& readCSV(istream& is, Utilizator& user);

#endif // UTILIZATOR_H
