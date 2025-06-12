#pragma once
#include<iostream>
#include<vector>
#include <string>
class Video {
private:
    std::string ID;
    int Duracion;
    std::string Nombre;
    std::string Genero;
    std::vector<float> Calificaciones;
public:

    Video(std::string ID, int Duracion, std::string Nombre, std::string Genero);
    virtual ~Video() {};
    bool AñadirCalificaciones(float calificacion);
    float SacarPromedio() const;
    virtual const std::string Mostrar() const = 0;
    const std::string getID() const;
    const int getDuracion() const;
    const std::string getNombre() const;
    const std::string getGenero() const;
    friend std::ostream& operator<<(std::ostream& os, const Video& video);

};

