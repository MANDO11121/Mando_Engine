#pragma once

namespace graficos{

class Recurso{
public:
	inline Recurso(){};
	inline Recurso(const char* nombre){_nombre=nombre;};
	inline const char* getNombre(){return _nombre;}
	inline void setNombre(const char* nombre){_nombre=nombre;}
private:
	const char* _nombre;
};
}

