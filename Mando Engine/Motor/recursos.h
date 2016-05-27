#pragma once
#include <vector>
#include <dibujable.h>
#include <sprite.h>
#include <textura.h>
#include <textura_arreglada.h>

namespace graficos{

enum TipoRecurso{
ME_TEXTURA2D,
ME_TEXTURA_ARREGLADA,
ME_SPRITE
};

class Recursos
{
    public:
        static Recursos *INST();
        virtual ~Recursos();
        Recurso* getRecurso(const TipoRecurso tipo,const char* nombre);
        Recurso* getRecurso(const char* nombre);

        Textura_Arreglada* crearTextura_Arreglada(const char* nom_Tex,GLuint numeroframes,const char* nombre);
        Textura_Arreglada* crearTextura_Arreglada(const char* nom_Tex,GLuint numeroframes,TransData *frames,const char* nombre);

        Textura_Arreglada* crearTextura_Arreglada(Textura2D *tx,GLuint numeroframes,const char* nombre);
        Textura_Arreglada* crearTextura_Arreglada(Textura2D *tx,GLuint numeroframes,TransData *frames,const char* nombre);

        Textura2D* crearTextura2D(const char* archivo,const char* nombre);

    private:

        Textura2D* buscarTextura2D(const char* nom_Tex);
        Textura_Arreglada* buscarTextura_Arrglada(const char* nom_Tex);
        Sprite* buscarSprite(const char* nom_Tex);

        std::vector<Textura2D> _texturas;
        std::vector<Textura_Arreglada> _texturas_arregladas;
        std::vector<Sprite> _sprites;

        static Recursos *_inst;
        Recursos();
};

}

