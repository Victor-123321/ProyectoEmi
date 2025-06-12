#include "Serie.h"

Serie::Serie(std::string ID, int Duracion, std::string Nombre, std::string Genero)
    : Video(ID, Duracion, Nombre, Genero) {
}

void Serie::AñadirCapitulo(Capitulo* capitulo) {
    Capitulos.push_back(capitulo);
}

const std::string Serie::Mostrar() const {
    std::string result;
    for (const Capitulo* cap : Capitulos) {
        result += cap->Mostrar() + "\n";
    }
    return result;
}

Serie::~Serie() {
    for (Capitulo* cap : Capitulos) {
        delete cap;
    }
}
