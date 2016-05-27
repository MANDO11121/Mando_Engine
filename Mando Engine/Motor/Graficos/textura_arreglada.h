#pragma once
#include "textura.h"
#include "modelo.h"
#include "recurso.h"
namespace graficos{

class Textura_Arreglada : public Recurso
{
public:
    Textura_Arreglada();
    Textura_Arreglada(Textura2D *textura,GLuint numeroframes,const char* nombre);
    Textura_Arreglada(Textura2D *textura,GLuint numeroframes,TransData *frames,const char* nombre);
    virtual ~Textura_Arreglada();

    void setFrame(GLuint indice,TransData &frame);
    inline TransData &getFrame(GLuint indice)
    {
        if(indice>=_Num_Frames)
            MERROR("Fuera de indice");
        else
            return _Frames[indice];
    }

private:
    Textura2D *_textura;
    GLuint _Num_Frames;
    TransData *_Frames;

};
}

