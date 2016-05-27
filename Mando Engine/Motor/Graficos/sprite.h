#pragma once
#include "dibujable.h"
#include "textura_arreglada.h"
namespace graficos{
class Sprite : public Dibujable
{
public:
    Sprite();
    Sprite(TransData trans,Color color,Textura_Arreglada *txar,const char* nombre);
    virtual ~Sprite();
private:
    Textura_Arreglada *textura_arr;
};
}

