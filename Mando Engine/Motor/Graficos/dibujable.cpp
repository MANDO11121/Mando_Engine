#include "dibujable.h"
namespace graficos{

Dibujable::Dibujable()
{

}

Dibujable::Dibujable(TransData trans,Color color,const char* nombre) : Recurso(nombre)
{
    _trans=trans;
    _color=color;
}

Dibujable::~Dibujable()
{
    //dtor
}

}
