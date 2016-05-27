#pragma once
#include "textura.h"
#include "modelo.h"
namespace graficos{

class Textura_Arreglada
{
public:
    Textura_Arreglada();
    Textura_Arreglada(Textura2D *textura,GLuint numeroframes);
    Textura_Arreglada(Textura2D *textura,GLuint numeroframes,TransData *frames);
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

