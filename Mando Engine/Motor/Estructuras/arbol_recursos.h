#pragma once
#include "recurso.h"

namespace graficos{

struct Nodo{
    Nodo(Recurso *rec){_rec=rec;}
    Nodo *IZQ;
    Nodo *DER;
    Recurso *_rec;
};

class Arbol_Recursos
{
public:
    Arbol_Recursos();
    virtual ~Arbol_Recursos();
    void add(Recurso *nuevo);
    void eliminar(const char* nombre);
    void reacomodar();
    Recurso *buscar();

private:
    void add(Nodo *hoja,Nodo *nuevo);
    void eliminar(Nodo *hoja,const char* nombre);
    Nodo *_raiz;

};

}
