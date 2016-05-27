#pragma once
#include "gl_contexto.h"
#include "simple_shader.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "array_buffer.h"

class Ventana : public graficos::GL_Contexto
{
public:
    Ventana();
    Ventana(int ancho,int alto,std::string titulo);
    virtual ~Ventana();

protected:
    virtual void enCargar();
    virtual void enActualizar();
    virtual void enRenderizar();
    virtual void enTerminar();

private:
    graficos::Vertex_Array _Vao;
    graficos::Index_Buffer _Ibo;
    graficos::Simple_Shader _shader;
};
