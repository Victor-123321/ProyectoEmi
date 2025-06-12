#include "Pelicula.h"

Pelicula::Pelicula(std::string ID, int Duracion, std::string Nombre, std::string Genero) : Video(ID, Duracion, Nombre, Genero) {
}

const std::string Pelicula::Mostrar() const {
    if (SacarPromedio() > 0) {
        return getID() + "," + getNombre() + "," + std::to_string(getDuracion()) + "," +
            getGenero() + "," + std::to_string(SacarPromedio());
    }
    return getID() + "," + getNombre() + "," + std::to_string(getDuracion()) + "," +
        getGenero() + "," + "NC";
}

