#include "vertex_array.h"
namespace graficos{

	Vertex_Array::Vertex_Array()
	{
        _Array_ID=0;
	}

	Vertex_Array::~Vertex_Array()
	{
		for(GLuint i=0;i<=_buffers.size();i++)
			delete _buffers[i];
        glDeleteVertexArrays(1,&_Array_ID);
	}

    void Vertex_Array::crear()
    {
        glGenVertexArrays(1,&_Array_ID);
    }
	void Vertex_Array::add_Array_Buffer(Array_Buffer *buffer,GLuint indice)
	{
		habilitar();
		buffer->habilitar();
		glVertexAttribPointer(indice,buffer->getNumComp(),GL_FLOAT,GL_FALSE,0,0);
		buffer->desabilitar();
		desabilitar();
		_buffers.push_back(buffer);
	}

	void Vertex_Array::habilitar()const
	{
		glBindVertexArray(_Array_ID);
	}

	void Vertex_Array::desabilitar()const
	{
		glBindVertexArray(_Array_ID);
	}

}
