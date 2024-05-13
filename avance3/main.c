//main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//librerías propias:
#include "eventos.h"

//Macros
#define SRAND srand(time(NULL));//generar números aleatorios totalmente diferentes con el tiempo

//funciones:
void eventos(); 
void menu_inicial(struct Dia *dia, struct Recursos *recursos);
void comenzar_juego(struct Dia *dia, struct Recursos *recursos);
//void introduccion();
void introduccion(const char* nombre);
void creditos();


int main() {
    struct Dia dia;
    dia.contador_dias = 0;
    struct Recursos recursos;
    //recursos.tickets = 0;
    printf("\nBienvenido a Dead Zone: The last time\n");
    printf("========================================\n\n");
    menu_inicial(&dia, &recursos);
    return 0;
}

void menu_inicial(struct Dia *dia, struct Recursos *recursos) {
    int menu;
    do
    {
        printf("*************************\n");
        printf("*       MENÚ PRINCIPAL  *\n");
        printf("*************************\n");
        printf("* 1. Jugar              *\n");
        printf("* 2. Créditos           *\n");
        printf("* 3. Salir              *\n");
        printf("*************************\n");
        printf("Elige una opción para comenzar (1-3): ");
        scanf("%d", &menu);

        switch (menu) 
        {
        case 1:
            comenzar_juego(dia, recursos); // Inicializa el juego
            return;
        case 2:
            creditos();
            break;
        case 3:
            return;
        default:
            printf("\nOpción no válida. Inténtalo de nuevo.\n\n");
            menu_inicial(dia, recursos); // Llama de nuevo al menú si la opción no es válida
            break;
        }
    }
    while (true);
    
}


// Creación de función para inicializar el juego con el nombre del jugador
void comenzar_juego(struct Dia*dia, struct Recursos *recursos) {
    char nombre_jugador[50];  // Asumiendo un nombre no muy largo.
    printf("\nPor favor, introduce tu nombre: ");
    scanf("%49s", nombre_jugador); 

    introduccion(nombre_jugador);  // Pasamos el nombre a la función de introducción.
    //eventos(dia);

    inicializar_recursos(recursos, dia);
    seleccionar_recursos_iniciales(recursos);

    //printf("Tickets: %d\n", recursos->tickets);
    while (recursos->vida >= 0)
    {
        printf("Recursos = Comida: %d, Agua: %d, Vida: %d, Arma: %d, Tickets: %d\n", recursos->c, recursos->a, recursos->vida, recursos->arma, recursos->tickets);
        dia->contador_dias = dia->contador_dias + 1;
        printf("Día %d\n", dia->contador_dias);
        //gestionar_refugio(recursos);
        //probabilidad_eventos(recursos, dia);
        //
        int decision;
        printf("\n¿Qué deseas hacer hoy?\n1. Quedarte en el refugio\n2. Salir a explorar\nElige una opción (1 o 2): ");
        scanf("%d", &decision);
        getchar();  // Limpia el buffer de entrada para evitar problemas con entradas residuales

        if (decision == 1) {
            gestionar_refugio(recursos);
        } else if (decision == 2) {
            probabilidad_eventos(recursos, dia);
            printf("El evento te quito energía por lo tanto pierdes 5 de vida\n");
            recursos->vida = recursos->vida - 5;
        } else {
            printf("Opción no válida. Por favor elige 1 o 2.\n");
            //continue;
        }
    }
    printf("Has muerto. Juego terminado.\n");
    
    //probabilidad_eventos(recursos, dia);
}

void introduccion(const char* nombre) {
    printf("\n- Hola %s, actualmente estás en un apocalipsis zombie, donde debes aplicar lo que sabes sobre supervivencia para avanzar.\n", nombre);
    printf("- Recuerda que tus acciones pueden traerte beneficios, así como también consecuencias.\n\n");
}

void creditos() {
    printf("\033[1;36m\nGracias por jugar\033[0m\n"); // Cyan
    printf("\033[1;35mAtte:\033[0m\n"); // Magenta
    printf("\033[1;32m- Alan\033[0m\n"); // Verde
    printf("\033[1;34m- Victoria\033[0m\n"); // Azul
    printf("\033[1;31m- Javier\033[0m\n\n"); // Rojo
}
