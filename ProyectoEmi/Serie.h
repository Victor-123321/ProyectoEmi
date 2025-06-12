#include <vector>
#include "Video.h"
#include "Capitulo.h"

class Serie : public Video {

private:
    std::vector<Capitulo*> Capitulos;
public:
    Serie(std::string ID, int Duracion, std::string Nombre, std::string Genero);
    ~Serie();
    void AñadirCapitulo(Capitulo* capitulo);
    const std::string Mostrar() const override;
};

