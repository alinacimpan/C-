
#include "Utilizator.h"
using namespace std;

class Mesaj {
private:
    string text;
    Utilizator* expeditor;
    Utilizator* receptor;

public:
    Mesaj() = default;
    Mesaj(const string& text, Utilizator* expeditor, Utilizator* receptor);
    Mesaj(const Mesaj& message) = default;

    ~Mesaj();

    string getText() const;
    Utilizator* getExpeditor() const;
    Utilizator* getReceptor() const;
};


