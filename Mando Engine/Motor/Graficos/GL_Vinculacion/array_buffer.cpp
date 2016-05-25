#include "array_buffer.h"

namespace mandoengine{namespace graficos{

	Array_Buffer::Array_Buffer()
	{

	}

	Array_Buffer::~Array_Buffer()
	{

	}

	void Array_Buffer::crearBuffer(GLfloat* datos,GLsizei total,GLuint numComponentes)
	{
	    _Num_Componentes=numComponentes;
		glGenBuffers(1,&_Buffer_ID);
		glBindBuffer(GL_ARRAY_BUFFER,_Buffer_ID);
		glBufferData(GL_ARRAY_BUFFER,total*sizeof(GLfloat),datos,GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}

	void Array_Buffer::habilitar()const
	{
		glBindBuffer(GL_ARRAY_BUFFER,_Buffer_ID);
	}

	void Array_Buffer::desabilitar()const
	{
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}

}}
