#include <iostream>
#include "ventana.h"
#include "color.h"
int main()
{
    graficos::Color azul(COLOR_BlueViolet);
    Ventana ventana(800,600,"MANDO");
    ventana.setColorFondo(azul);
    ventana.correr();
    return 0;
}

