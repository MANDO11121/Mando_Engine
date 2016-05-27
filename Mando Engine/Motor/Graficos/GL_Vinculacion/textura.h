#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include "logger.h"
#include "recurso.h"
namespace graficos{
class Textura2D : public Recurso
{
public:
    Textura2D();
    Textura2D(const char* nombre);
    virtual ~Textura2D();
    bool cargar(const char* archivo);
    void habilitar();
    void desabilitar();
    GLuint getID();
    int getAncho();
    int getLargo();
    void eliminar();
private:
    GLuint _textID;
    int _ancho;int _largo;

};

}
