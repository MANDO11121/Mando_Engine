#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
namespace graficos{
class Index_Buffer{
public:
	Index_Buffer();
	~Index_Buffer();
	void crearBuffer(GLushort* datos,GLsizei total);
	void habilitar()const;
	void desabilitar()const;
	inline GLuint getNumComp()const{return _Num_Componentes;}
private:
	GLuint _Buffer_ID;
	GLuint _Num_Componentes;
};
}
