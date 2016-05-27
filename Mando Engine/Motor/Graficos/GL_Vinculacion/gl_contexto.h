#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "logger.h"
#include "color.h"
namespace graficos{
class GL_Contexto
{
public:
    GL_Contexto();
    GL_Contexto(int ancho,int alto,std::string titulo);
    virtual ~GL_Contexto();
    void correr();
    inline void setColorFondo(Color color){_colorFondo=color;}
protected:
    virtual void enCargar()=0;
    virtual void enActualizar()=0;
    virtual void enRenderizar()=0;
    virtual void enTerminar()=0;

    GLFWwindow* _ventana;
    std::string _titulo;
    int _ancho;
    int _alto;
    Color _colorFondo;
    double DeltaTiempo;

private:
    double _frame_actual;
    double _frame_pasado;
    bool iniciar();
    void cargar();
    void actualizar();
    void renderizar();
    void terminar();

};

}
