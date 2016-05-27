#include "ventana.h"
#include "textura_arreglada.h"
Ventana::Ventana(int ancho,int alto,std::string titulo): GL_Contexto(ancho,alto,titulo)
{

}

Ventana::Ventana()
{
    //ctor
}

Ventana::~Ventana()
{

}

void Ventana::enCargar()
{
    graficos::Textura_Arreglada tx(nullptr,5);

    tx.getFrame(2);

    GLfloat vertices[]={
        -0.5f,0.5f,0.0f,
        0.5f,0.5f,0.0f,
        0.0f,0.5f,0.0f
    };
    GLushort indices[]={
        0,1,2
    };

    graficos::Array_Buffer *b= new graficos::Array_Buffer();
    _Ibo.crearBuffer(indices,3);
    b->crearBuffer(vertices,3*3,3);
    _Vao.add_Array_Buffer(b,0);

    _shader.cargar("Recursos/Shaders/simple.vs","Recursos/Shaders/simple.fs");
}

void Ventana::enActualizar()
{

}

void Ventana::enRenderizar()
{
    _shader.habilitar();
    _Vao.habilitar();
    _Ibo.habilitar();
    glDrawElements(GL_TRIANGLES,3,GL_UNSIGNED_SHORT,0);
    _Ibo.desabilitar();
    _Vao.desabilitar();
    _shader.desabilitar();
}

void Ventana::enTerminar()
{

}


