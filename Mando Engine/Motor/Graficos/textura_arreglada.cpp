#include "textura_arreglada.h"
namespace graficos{
Textura_Arreglada::Textura_Arreglada() : Recurso()
{
    //ctor
}

Textura_Arreglada::Textura_Arreglada(Textura2D *textura,GLuint numeroframes,const char* nombre) : Recurso(nombre)
{
    _textura=textura;
    _Num_Frames=numeroframes;
    _Frames=new TransData[_Num_Frames];
}

Textura_Arreglada::Textura_Arreglada(Textura2D *textura,GLuint numeroframes,TransData *frames,const char* nombre) : Recurso(nombre)
{
    _textura=textura;
    _Num_Frames=numeroframes;
    _Frames=frames;
}

Textura_Arreglada::~Textura_Arreglada()
{
    //dtor
}

void Textura_Arreglada::setFrame(GLuint indice,TransData &frame)
{
    if(indice>=_Num_Frames)
        MERROR("Fuera de indice");
    else
        _Frames[indice]=frame;
}

}
