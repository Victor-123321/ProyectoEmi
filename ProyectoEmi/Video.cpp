#include "Video.h"

Video::Video(std::string ID, int Duracion, std::string Nombre, std::string Genero)
    : ID(ID), Duracion(Duracion), Nombre(Nombre), Genero(Genero), Calificaciones() {
    Calificaciones = std::vector<float>();
}

bool Video::AñadirCalificaciones(float calificacion) {

    if (calificacion >= 0.0 && calificacion <= 5.0) {
        Calificaciones.push_back(calificacion);
        return true;
    }
    return false;
}

float Video::SacarPromedio() const {

    if (Calificaciones.empty()) {
        return 0;
    }

    float suma = 0;
    int contador = 0;

    for (float i : Calificaciones) {
        suma += i;
        ++contador;
    }
    return suma / (float)contador;
}

const std::string Video::getID() const {
    return ID;
}
const std::string Video::getNombre() const {
    return Nombre;
}
const std::string Video::getGenero() const {
    return Genero;
}
const int Video::getDuracion() const {
    return Duracion;
}
std::ostream& operator<<(std::ostream& os, const Video& video) {
    os << video.Mostrar();
    return os;
}
