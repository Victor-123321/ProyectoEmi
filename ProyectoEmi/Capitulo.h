#pragma once
#include "Video.h"

class Capitulo : public Video {
private:
    int NumTemporada;
    int NumCapitulo;
    std::string NombreSerie;

public:
    Capitulo(std::string ID, int Duracion, std::string Nombre, std::string Genero, std::string NombreSerie, int NumTemporada, int NumCapitulo);
    const std::string Mostrar() const override;
    const int getNumTemporada() const;
    const int getNumCapitulo() const;
    const std::string getNombreSerie() const;
};
