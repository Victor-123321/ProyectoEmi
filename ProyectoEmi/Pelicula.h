#include "Video.h"

class Pelicula : public Video
{
public:
    Pelicula(std::string ID, int Duracion, std::string Nombre, std::string Genero);

    const std::string Mostrar() const override;

};

