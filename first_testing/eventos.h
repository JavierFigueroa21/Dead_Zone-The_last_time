//eventos.h
//header file, archivo de cabecera de las funciones e implementaciones
//de la librería stats.
#ifndef EVENTOS_H
#define EVENTOS_H

//Estructura para guardar las variables de comida y agua
struct Recursos
{
    int c;
    int a;
    //float dia;
};

// Contenido de tu archivo de cabecera
void inicializar_recursos(struct Recursos *recursos);
void evento_caja_advertencia (struct Recursos *recursos);//supongo que un int de agua y otro de comida
void evento_caja (struct Recursos *recursos);//supongo que un int de agua y otro de comida
void probabilidad_eventos (struct Recursos *recursos);

#endif // EVENTOS_H