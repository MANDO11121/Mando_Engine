#pragma once
#include <string>
#define GLEW_STATIC
#include <GL/glew.h>
#include "logger.h"
namespace graficos{

class Simple_Shader
{
public:
    Simple_Shader();
    virtual ~Simple_Shader();
    bool cargar(const char* archivo,int tiposhader);
    bool cargar(const char* VS,const char* FS);
    void link();
    void habilitar();
    void desabilitar();
    inline GLuint getID()const{return _shaderID;}
    inline GLuint getVShaderID()const{return _vsID;}
    inline GLuint getFShaderID()const{return _fsID;}

private:
    bool crearVS(std::string codigo);
    bool crearFS(std::string codigo);
    GLuint _shaderID;
    GLuint _vsID;
    GLuint _fsID;

};

}
