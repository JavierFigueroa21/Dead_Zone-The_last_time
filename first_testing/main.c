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
void menu_inicial();
void comenzar_juego();
//void introduccion();
void introduccion(const char* nombre);
void creditos ();


int main() {
    printf("\nBienvenido a Dead Zone: The last time\n");
    printf("========================================\n\n");
    menu_inicial();
    return 0;
}

void menu_inicial() {
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
            comenzar_juego(); // Inicializa el juego
            return;
        case 2:
            creditos();
            break;
        case 3:
            return;
        default:
            printf("\nOpción no válida. Inténtalo de nuevo.\n\n");
            menu_inicial(); // Llama de nuevo al menú si la opción no es válida
            break;
        }
    }
    while (true);
    
}


// Creación de función para inicializar el juego con el nombre del jugador
void comenzar_juego() {
    char nombre_jugador[50];  // Asumiendo un nombre no muy largo.
    printf("\nPor favor, introduce tu nombre: ");
    scanf("%49s", nombre_jugador); 

    introduccion(nombre_jugador);  // Pasamos el nombre a la función de introducción.

    struct Recursos recursos;
    inicializar_recursos(&recursos);
    probabilidad_eventos(&recursos);
}

void introduccion(const char* nombre) {
    printf("\n- Hola %s, actualmente estás en un apocalipsis zombie, donde debes aplicar lo que sabes sobre supervivencia para avanzar.\n", nombre);
    printf("- Recuerda que tus acciones pueden traerte beneficios, así como también consecuencias.\n\n");
}


void creditos ()
{
    printf("\nGracias por jugar att:\n- Alan\n- Victoria\n- Javier\n\n");
}
void inventario ()
{
    
}