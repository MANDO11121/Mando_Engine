#pragma once

namespace graficos{

class Recurso{
public:
	inline Recurso(){};
	inline const char* getNombre(){return _nombre;}
	inline void setNombre(const char* nombre){_nombre=nombre;}
	virtual char* aCharArray()=0;
private:
	const char* _nombre;
};
}

