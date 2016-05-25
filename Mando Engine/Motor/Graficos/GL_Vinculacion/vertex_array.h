#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <vector>
#include "array_buffer.h"
namespace mandoengine{namespace graficos{
class Vertex_Array{
public:
	Vertex_Array();
	~Vertex_Array();
	void add_Array_Buffer(Array_Buffer *buffer,GLuint indice);
	void habilitar()const;
	void desabilitar()const;
private:
	std::vector<Array_Buffer*>  _buffers;
	GLuint _Array_ID;
	GLuint _Num_Componentes;
};
}}