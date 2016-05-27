#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
namespace graficos{
class Array_Buffer{
public:
	Array_Buffer();
	~Array_Buffer();
	void crearBuffer(GLfloat* datos,GLsizei total,GLuint numComponentes);
	void habilitar()const;
	void desabilitar()const;
	inline GLuint getNumComp()const{return _Num_Componentes;}
private:
	GLuint _Buffer_ID;
	GLuint _Num_Componentes;
};
}
