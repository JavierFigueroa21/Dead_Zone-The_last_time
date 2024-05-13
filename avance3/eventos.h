// eventos.h
// Archivo de cabecera que define las estructuras y funciones utilizadas
// para manejar los eventos del juego Dead Zone: The Last Time.
#ifndef EVENTOS_H
#define EVENTOS_H


// Estructura para contar los días transcurridos en el juego.
struct Dia
{
    int contador_dias;
};
// Estructura para guardar las variables de comida y agua
// Estructura para almacenar los recursos del jugador.
struct Recursos {
    int c;       // Unidades de comida
    int a;       // Unidades de agua
    int vida;    // Puntos de vida del jugador
    int arma;    // Indicador de posesión de arma (0 = no, 1 = sí)
    int tickets; // Tickets para eventos especiales
};

// Funciones para la gestión de recursos y eventos en el juego.
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