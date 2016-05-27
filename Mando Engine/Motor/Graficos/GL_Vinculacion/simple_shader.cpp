#include "simple_shader.h"
#include <fstream>
#include <iostream>
namespace graficos{
    Simple_Shader::Simple_Shader()
    {
        _vsID=0;
        _fsID=0;
    }

    Simple_Shader::~Simple_Shader()
    {
        glDeleteShader(_fsID);
        glDeleteShader(_vsID);
        glDeleteProgram(_shaderID);
    }

    bool Simple_Shader::cargar(const char* archivo,int tiposhader)
    {
        std::ifstream shader;
        shader.open(archivo,std::ios::in);

        if(shader.is_open())
        {
            std::string linea;
            std::string contenido;
            while(!shader.eof())
            {
                getline(shader,linea);
                contenido=contenido+"\n"+linea;
            }

            if(tiposhader==GL_VERTEX_SHADER)
                crearVS(contenido);
            if(tiposhader==GL_FRAGMENT_SHADER)
                crearFS(contenido);
       }
       else
       {
           MERROR("ERROR: No se pudo abrir el archivo "<< archivo);
           return false;
       }

       return true;
    }

    bool Simple_Shader::cargar(const char* VS,const char* FS)
    {
        std::string linea;
        std::string contenido;
        std::ifstream shader;
        shader.open(VS,std::ios::in);

        if(shader.is_open())
        {
            while(!shader.eof())
            {
                getline(shader,linea);
                contenido=contenido+"\n"+linea;
            }
            crearVS(contenido);
            shader.close();
        }
       else
       {
           MERROR("ERROR: No se pudo abrir el archivo "<< VS);
           return false;
       }

       shader.open(FS,std::ios::in);

       if(shader.is_open())
       {
            contenido="";
            while(!shader.eof())
            {
                getline(shader,linea);
                contenido=contenido+"\n"+linea;
            }
                crearFS(contenido);
                shader.close();
       }
       else
       {
           MERROR("ERROR: No se pudo abrir el archivo "<<FS);
           return false;
       }
        link();
        return true;
    }

    void Simple_Shader::link()
    {
        _shaderID = glCreateProgram();
        glAttachShader(_shaderID, _vsID);
        glAttachShader(_shaderID, _fsID);
        glLinkProgram(_shaderID);

        GLint exito;
        GLchar log[512];
        glGetProgramiv(_shaderID, GL_LINK_STATUS, &exito);
        if(!exito)
        {
            glGetProgramInfoLog(_shaderID, 512, NULL, log);
            MLOG("ERROR al linkear shader\n" << log );
        }
    }

    bool Simple_Shader::crearVS(std::string codigo)
    {
        _vsID = glCreateShader(GL_VERTEX_SHADER);
        const char* cod =codigo.c_str();
        glShaderSource(_vsID,1,&cod,NULL);
        glCompileShader(_vsID);

        GLint exito;
        GLchar log[512];
        glGetShaderiv(_vsID,GL_COMPILE_STATUS,&exito);
        if(!exito)
        {
            MERROR("ERROR COMPILANDO VERTEX SHADER");
            MERROR("No se pudo compilar:");
            MERROR(cod);
            MERROR("\nError:");
            MERROR(log);
            return false;
        }
        else
        {
            MLOG("Vertex shader cargado correctamente");
            return true;
        }
    }

    bool Simple_Shader::crearFS(std::string codigo)
    {
        _fsID = glCreateShader(GL_FRAGMENT_SHADER);
        const char* cod =codigo.c_str();
        glShaderSource(_fsID,1,&cod,NULL);
        glCompileShader(_fsID);

        GLint exito;
        GLchar log[512];
        glGetShaderiv(_fsID,GL_COMPILE_STATUS,&exito);
        if(!exito)
        {
            MERROR("ERROR COMPILANDO FRAGMENT SHADER");
            MERROR("No se pudo compilar:");
            MERROR(cod);
            MERROR("\nError:");
            MERROR(log);
            return false;
        }
        else
        {
            MLOG("Fragment shader cargado correctamente");
            return true;
        }
    }


    void Simple_Shader::habilitar()
    {
        glUseProgram(_shaderID);
    }

    void Simple_Shader::desabilitar()
    {
        glUseProgram(0);
    }

}
