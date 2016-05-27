#include <iostream>
#include "ventana.h"
#include "color.h"
#include <iostream>
int main()
{
    graficos::Color azul(COLOR_BlueViolet);
    Ventana ventana(1280,720,"MANDO");
    ventana.setColorFondo(azul);
    ventana.correr();
    return 0;
}
