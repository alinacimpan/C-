
#include "mesaj.h"

Mesaj::Mesaj(const std::string& text, Utilizator* expeditor, Utilizator* receptor)
    : text(text),
    expeditor(expeditor),
    receptor(receptor)
{}

Mesaj::~Mesaj()
{}

std::string Mesaj::getText() const {
    return this->text;
}

Utilizator* Mesaj::getExpeditor() const {
    return this->expeditor;
}

Utilizator* Mesaj::getReceptor() const {
    return this->receptor;
}
