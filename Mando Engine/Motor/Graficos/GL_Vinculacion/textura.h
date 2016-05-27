#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include "logger.h"
namespace graficos{
class Textura2D
{
public:
    Textura2D();
    virtual ~Textura2D();
    bool cargar(const char* archivo);
    void habilitar();
    void desabilitar();
    GLuint getID();
    int getAncho();
    int getLargo();
private:
    void eliminar();
    GLuint _textID;
    int _ancho;int _largo;

};

}
