#include "sprite.h"
namespace graficos{
Sprite::Sprite()
{

}

Sprite::Sprite(TransData trans,Color color,Textura_Arreglada *txar,const char* nombre) : Dibujable(trans,color,nombre)
{
    textura_arr=txar;
}

Sprite::~Sprite()
{

}

}
