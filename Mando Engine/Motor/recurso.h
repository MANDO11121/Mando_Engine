#pragma once

namespace mandoengine{namespace graficos{
	
class Recurso{
public:
	Recurso();
	inline const char* getNombre(){return _nombre;}
	inline const char* setNombre(const char* nombre){_nombre=nombre;}
	virtual char* aCharArray()=0;
private:
	const char* nombre;
};
	
}}

