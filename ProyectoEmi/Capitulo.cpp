#include "Capitulo.h"

Capitulo::Capitulo(std::string ID, int Duracion, std::string Nombre, std::string Genero, std::string NombreSerie, int NumTemporada, int NumCapitulo)
    : Video(ID, Duracion, Nombre, Genero), NombreSerie(NombreSerie), NumTemporada(NumTemporada), NumCapitulo(NumCapitulo) {
}

const std::string Capitulo::Mostrar() const {
    if (SacarPromedio() > 0) {
        return getID() + "," + getNombre() + "," + std::to_string(getDuracion()) + "," + getGenero() + "," + NombreSerie + ",T" + std::to_string(NumTemporada) + "," + std::to_string(NumCapitulo) + "," + std::to_string(SacarPromedio());
    }
    return getID() + "," + getNombre() + "," + std::to_string(getDuracion()) + "," + getGenero() + "," + NombreSerie + ",T" + std::to_string(NumTemporada) + "," + std::to_string(NumCapitulo) + "," + "NC";
}
const int Capitulo::getNumTemporada() const {
    return NumTemporada;
}

const int Capitulo::getNumCapitulo() const {
    return NumCapitulo;
}
const std::string Capitulo::getNombreSerie() const {
    return NombreSerie;
}
