#include "gl_contexto.h"
namespace graficos{

GL_Contexto::GL_Contexto()
{

}

GL_Contexto::GL_Contexto(int ancho,int alto,std::string titulo)
{
    _titulo=titulo;
    _ancho=ancho;
    _alto=alto;
    _colorFondo=Color(COLOR_Purple);
    MLOG("Ventana creada :: "<<_titulo<<" "<<_ancho<<"x"<<_alto<<" Color: "<<_colorFondo.aCharArray());

}

GL_Contexto::~GL_Contexto()
{

}

void GL_Contexto::correr()
{

    if(iniciar())
    {
        cargar();
    DeltaTiempo=0;
    while(!glfwWindowShouldClose(_ventana))
    {
        _frame_pasado = glfwGetTime();
        glfwPollEvents();
        actualizar();
        renderizar();
        DeltaTiempo=glfwGetTime()-_frame_pasado;
    }
    terminar();
    glfwTerminate();
    }
}

bool GL_Contexto::iniciar()
{
    glfwInit();
    #if 0
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_REFRESH_RATE,GLFW_DONT_CARE);
    #endif
    _ventana = glfwCreateWindow(_ancho, _alto,_titulo.c_str() , NULL,
    NULL);
    if (_ventana == NULL)
    {
        MERROR("No se pudo crear la ventana GLFW");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(_ventana);
    glewExperimental=GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        MERROR("No se pudo iniciar GLEW");
        glfwTerminate();
        return false;
    }

    /*glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);*/

    MLOG(glGetString(GL_VENDOR));
    MLOG(glGetString(GL_VERSION));

    GLint numext;
    glGetIntegerv(GL_NUM_EXTENSIONS,&numext);
    #if LOG_EXT
     for(int i=0;i<numext;i++)
        MLOG(glGetStringi(GL_EXTENSIONS,i));
    #endif

    return true;;
}

void GL_Contexto::cargar()
{
    enCargar();
}

void GL_Contexto::actualizar()
{
    enActualizar();
}

void GL_Contexto::renderizar()
{
    glClearColor(_colorFondo.getR(),_colorFondo.getG(),_colorFondo.getB(),1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    enRenderizar();
    glfwSwapBuffers(_ventana);
}

void GL_Contexto::terminar()
{
    enTerminar();
}

}
