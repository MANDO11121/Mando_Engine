#include "index_buffer.h"

namespace graficos{
	Index_Buffer::Index_Buffer()
	{

	}

	Index_Buffer::~Index_Buffer()
	{

	}

	void Index_Buffer::crearBuffer(GLushort* datos,GLsizei total)
	{
	    _Num_Componentes=total;
		glGenBuffers(1,&_Buffer_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_Buffer_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,total*sizeof(GLushort),datos,GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	}

	void Index_Buffer::habilitar()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_Buffer_ID);
	}

	void Index_Buffer::desabilitar()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	}

}
