#include "textura.h"
#include <string>
#include "stb_image.h"

namespace graficos{

Textura2D::Textura2D()
{

}

Textura2D::~Textura2D()
{

}

bool Textura2D::cargar(const char* archivo)
{
    glGenTextures(1, &_textID);
    glBindTexture(GL_TEXTURE_2D, _textID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int numComponents;
    unsigned char* data = stbi_load(archivo, &_ancho, &_largo, &numComponents, 4);
    if(data == NULL)
    {
        MLOG("No se pudo cargar el archivo: "<<archivo);
        glDeleteTextures(1,&_textID);
        return false;

    }
    else
        MERROR("Textura Cargada: " << archivo);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _ancho, _largo, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);
    MLOG("Creada textura con id: "<<_textID);
    stbi_image_free(data);
    return true;
}

void Textura2D::eliminar()
{
    glDeleteTextures(1,&_textID);
    delete(this);
}

GLuint Textura2D::getID()
{
    return _textID;
}

void Textura2D::habilitar()
{
    glBindTexture(GL_TEXTURE_2D, _textID);
}

void Textura2D::desabilitar()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

int Textura2D::getAncho()
{
    return _ancho;
}

int Textura2D::getLargo()
{
    return _largo;
}

}
