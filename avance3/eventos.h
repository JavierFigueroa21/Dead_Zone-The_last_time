//eventos.h
//header file, archivo de cabecera de las funciones e implementaciones
//de la librería stats.
#ifndef EVENTOS_H
#define EVENTOS_H

//Estructura para guardar las variables de comida y agua
struct Dia
{
    int contador_dias;
};
struct Recursos
{
    int c;
    int a;
    int vida;
    int arma;
    int tickets;

    //float dia;
};

// Contenido de tu archivo de cabecera
void inicializar_recursos(struct Recursos *recursos, struct Dia *dia);
void seleccionar_recursos_iniciales(struct Recursos *recursos);
void gestionar_refugio(struct Recursos *recursos);
void evento_caja_advertencia (struct Recursos *recursos, struct Dia *dia);
void evento_caja (struct Recursos *recursos, struct Dia *dia);
void evento_buscando_recursos(struct Recursos *recursos,struct Dia *dia);
void evento_tickets(struct Recursos *recursos, struct Dia *dia);
bool probabilidad_eventos (struct Recursos *recursos, struct Dia *dia);
//void eventos(struct Dia*dia);
#endif // EVENTOS_H