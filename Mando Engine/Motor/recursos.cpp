#include "recursos.h"
#include <stdio.h>
#include <string.h>

namespace graficos{

Recursos* Recursos::_inst=nullptr;

Recursos* Recursos::INST()
{
    if(_inst==nullptr)
        _inst=new Recursos;
    return _inst;
}

Recursos::Recursos()
{
    //ctor
}

Recursos::~Recursos()
{
    //dtor
}

Recurso* Recursos::getRecurso(const TipoRecurso tipo,const char* nombre)
{
    switch(tipo)
    {
    case ME_SPRITE:
        return (Recurso*)buscarSprite(nombre);
        break;
    case ME_TEXTURA2D:
        return (Recurso*)buscarTextura2D(nombre);
        break;
    case ME_TEXTURA_ARREGLADA:
        return (Recurso*)buscarTextura_Arrglada(nombre);
    break;
    default:
        return nullptr;
        break;
    }

}

Recurso* Recursos::getRecurso(const char* nombre)
{
    bool encontrado=false;
    Recurso *busqueda=nullptr;
    if(!encontrado)
    {
        busqueda=(Recurso*)buscarSprite(nombre);
        if(busqueda!=nullptr)
            encontrado=true;
    }

    if(!encontrado)
    {
        busqueda=(Recurso*)buscarTextura2D(nombre);
        if(busqueda!=nullptr)
            encontrado=true;
    }

    if(!encontrado)
    {
        busqueda=(Recurso*)buscarTextura_Arrglada(nombre);
        if(busqueda!=nullptr)
            encontrado=true;
    }

    return busqueda;
}

Textura2D* Recursos::buscarTextura2D(const char* nom_Tex)
{

        return nullptr;
}

Textura_Arreglada* Recursos::buscarTextura_Arrglada(const char* nom_Tex)
{

        return nullptr;
}

Sprite* Recursos::buscarSprite(const char* nom_Tex)
{

        return nullptr;
}

Textura_Arreglada* Recursos::crearTextura_Arreglada(const char* nom_Tex,GLuint numeroframes,const char* nombre)
{
    Textura2D *text=buscarTextura2D(nom_Tex);
    if(text!=nullptr)
    {
        unsigned int pos =_texturas_arregladas.size();
        _texturas_arregladas.push_back(Textura_Arreglada(text,numeroframes,nombre));
        return &_texturas_arregladas[pos];
    }
    else
        return nullptr;
}

Textura_Arreglada* Recursos::crearTextura_Arreglada(const char* nom_Tex,GLuint numeroframes,TransData *frames,const char* nombre)
{
    Textura2D *text=buscarTextura2D(nom_Tex);
    if(text!=nullptr)
    {
        unsigned int pos =_texturas_arregladas.size();
        _texturas_arregladas.push_back(Textura_Arreglada(text,numeroframes,frames,nombre));
        return &_texturas_arregladas[pos];
    }
    else
        return nullptr;
}

Textura_Arreglada* Recursos::crearTextura_Arreglada(Textura2D *tx,GLuint numeroframes,const char* nombre)
{
    unsigned int pos =_texturas_arregladas.size();
    _texturas_arregladas.push_back(Textura_Arreglada(tx,numeroframes,nombre));
    return &_texturas_arregladas[pos];
}

Textura_Arreglada* Recursos::crearTextura_Arreglada(Textura2D *tx,GLuint numeroframes,TransData *frames,const char* nombre)
{
    unsigned int pos =_texturas_arregladas.size();
    _texturas_arregladas.push_back(Textura_Arreglada(tx,numeroframes,frames,nombre));
    return &_texturas_arregladas[pos];
}

Textura2D* Recursos::crearTextura2D(const char* archivo,const char* nombre)
{
    Textura2D tx(nombre);
    if(tx.cargar(archivo))
    {
        unsigned int pos = _texturas.size();
        _texturas.push_back(tx);
        return &_texturas[pos];
    }
    else
    {
        tx.eliminar();
        return nullptr;
    }

}

}
