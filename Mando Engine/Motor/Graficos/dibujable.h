#pragma once
#include "glm/glm.hpp"
#include "color.h"
#include "recurso.h"
#include "modelo.h"
namespace graficos{
class Dibujable : public Recurso
{
public:
    Dibujable();
    Dibujable(TransData trans,Color color,const char* nombre);
    virtual ~Dibujable();

protected:
    Color _color;
    TransData _trans;
private:
};

}
