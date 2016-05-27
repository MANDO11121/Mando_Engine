#include "color.h"
namespace graficos{
Color::Color()
{
    _color.x=1;
    _color.y=1;
    _color.z=1;
}

Color::Color(int r,int g,int b)
{
    _color.x=(r/255.0f);
    _color.y=(g/255.0f);
    _color.z=(b/255.0f);
}

Color::Color(float r,float g,float b)
{
    _color.x=r;
    _color.y=g;
    _color.z=b;
}
Color::Color(int hex)
{
  _color.x = ((hex >> 16) & 0xFF) / 255.0f;
  _color.y = ((hex >> 8) & 0xFF) / 255.0f;
  _color.z = ((hex) & 0xFF) / 255.0f;
}

Color::~Color()
{
    //dtor
}

char* Color::aCharArray() const
{
    return "Color";
}

float Color::getR()
{
    return _color.x;
}

float Color::getG()
{
    return _color.y;
}

float Color::getB()
{
    return _color.z;
}

void Color::setR(float r)
{
    _color.x=r;
}

void Color::setG(float g)
{
    _color.y=g;
}

void Color::setB(float b)
{
    _color.z=b;
}

void Color::setR(int r)
{
    _color.x=(r/255.0f);

}

void Color::setG(int g)
{
    _color.y=(g/255.0f);

}

void Color::setB(int b)
{
    _color.z=(b/255.0f);
}

glm::vec3& Color::getVector()
{
    return _color;
}

}
