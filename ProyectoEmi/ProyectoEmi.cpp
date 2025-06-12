#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Capitulo.h"

std::vector<Video*> cargarVideos(const std::string& archivoNombre) {
    std::vector<Video*> listaVideos;
    std::ifstream archivo(archivoNombre);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream datos(linea);
        std::string tipoVideo, id, titulo, genero, nombreSerie;
        int duracion, temporada, capitulo;
        char coma;

        std::getline(datos, tipoVideo, ',');
        std::getline(datos, id, ',');
        std::getline(datos, titulo, ',');
        datos >> duracion >> coma;
        std::getline(datos, genero, ',');

        if (tipoVideo == "p") {
            listaVideos.push_back(new Pelicula(id, duracion, titulo, genero));
        }
        else if (tipoVideo == "c") {
            std::getline(datos, nombreSerie, ',');
            datos >> temporada >> coma >> capitulo;

            std::string idSerie = id.substr(0, id.find('-'));
            Serie* serieEncontrada = nullptr;

            for (Video* video : listaVideos) {
                if (video->getID() == idSerie) {
                    serieEncontrada = dynamic_cast<Serie*>(video);
                    break;
                }
            }

            if (!serieEncontrada) {
                serieEncontrada = new Serie(idSerie, 0, nombreSerie, genero);
                listaVideos.push_back(serieEncontrada);
            }

            Capitulo* nuevoCap = new Capitulo(id, duracion, titulo, genero, nombreSerie, temporada, capitulo);
            serieEncontrada->AñadirCapitulo(nuevoCap);
        }
    }
    archivo.close();
    return listaVideos;
}

void mostrarVideos(const std::vector<Video*>& listaVideos) {
    for (const Video* video : listaVideos) {
        std::cout << *video << std::endl;
    }
}

void calificarUnVideo(std::vector<Video*>& listaVideos) {
    std::string idBuscar;
    float calificacion;

    std::cout << "Escriba el ID del video a calificar: ";
    std::cin >> idBuscar;

    for (Video* video : listaVideos) {
        if (video->getID() == idBuscar) {
            do {
                std::cout << "Ingrese calificacion (1 a 5): ";
                std::cin >> calificacion;

                if (video->AñadirCalificaciones(calificacion)) {
                    std::cout << "Calificacion guardada!\n";
                    return;
                }
                else {
                    std::cout << "Valor no valido. Debe ser de 1 a 5.\n";
                }
            } while (true);
        }
    }
    std::cout << "No se encontro un video con ese ID.\n";
}

void mostrarPorCalificacion(const std::vector<Video*>& listaVideos) {
    int opcionTipo;
    float calificacionMinima;

    std::cout << "Tipo de video? (1: Pelicula, 2: Capitulo, 3: Ambos): ";
    std::cin >> opcionTipo;

    std::cout << "Ingrese calificacion minima: ";
    std::cin >> calificacionMinima;

    for (const Video* video : listaVideos) {
        bool tipoCorrecto =
            (opcionTipo == 1 && dynamic_cast<const Pelicula*>(video)) ||
            (opcionTipo == 2 && dynamic_cast<const Capitulo*>(video)) ||
            (opcionTipo == 3);

        if (tipoCorrecto && video->SacarPromedio() >= calificacionMinima && video->SacarPromedio() > 0) {
            std::cout << video->getID() << " - " << video->getNombre()
                << " - Promedio: " << video->SacarPromedio() << std::endl;
        }
    }
}

void mostrarPorGenero(const std::vector<Video*>& listaVideos) {
    int opcionTipo;
    std::string generoBuscar;

    std::cout << "Tipo de contenido??? (1: Pelicula, 2: Capitulo, 3: Ambos): ";
    std::cin >> opcionTipo;

    std::cout << "Ingrese el genero: ";
    std::cin.ignore();
    std::getline(std::cin, generoBuscar);

    for (Video* video : listaVideos) {
        bool tipoCorrecto =
            (opcionTipo == 1 && dynamic_cast<const Pelicula*>(video)) ||
            (opcionTipo == 2 && dynamic_cast<const Capitulo*>(video)) ||
            (opcionTipo == 3);

        if (tipoCorrecto && video->getGenero() == generoBuscar) {
            float promedio = video->SacarPromedio();
            std::cout << video->getID() << " - " << video->getNombre()
                << " - " << video->getGenero()
                << " - Promedio: " << (promedio > 0 ? std::to_string(promedio) : "SC") << std::endl;
        }
    }
}

int main() {
    std::vector<Video*> listaVideos = cargarVideos("videos.txt");

    int opcion;
    do {
        std::cout << "\nMENU:\n";
        std::cout << "1. Mostrar catalogo\n";
        std::cout << "2. Calificar un video\n";
        std::cout << "3. Filtrar por calificacion\n";
        std::cout << "4. Filtrar por genero\n";
        std::cout << "5. Fuimonos\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
			case 1:
                mostrarVideos(listaVideos); 
                break;
			case 2:
                calificarUnVideo(listaVideos);
                break;
			case 3:
                mostrarPorCalificacion(listaVideos); 
                break;
			case 4:
                mostrarPorGenero(listaVideos);
                break;
			case 5: 
                std::cout << "Saliendo del programa...\n"; 
                break;
        default: std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 9);

    // Liberar memoria
    for (Video* video : listaVideos) {
        delete video;
    }

    return 0;
}

