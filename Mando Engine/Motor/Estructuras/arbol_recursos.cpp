#include "arbol_recursos.h"


namespace graficos{

Arbol_Recursos::Arbol_Recursos()
{
    _raiz=nullptr;
}

Arbol_Recursos::~Arbol_Recursos()
{

}

void Arbol_Recursos::add(Recurso *nuevo)
{

    if(_raiz==nullptr)
    {
        _raiz= new Nodo(nuevo);
    }
    else
    {



    }
}

void Arbol_Recursos::eliminar(const char* nombre)
{

}

void Arbol_Recursos::add(Nodo *hoja,Nodo *nuevo)
{

}

void Arbol_Recursos::eliminar(Nodo *hoja,const char* nombre)
{

}

}

