//*main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//librerías propias:
#include "eventos.h"
//Macros
#define SRAND srand(time(NULL));//generar números aleatorios totalmente diferentes con el tiempo

//* Funciones:
void eventos(); 
void menu_inicial();
void introduccion();
void creditos ();


int main ()
{
    printf("Hola\n");
    menu_inicial();
    return 0;
}

//*Función que imprime el menu inicial con 2 simples opciones
void menu_inicial ()
{
    int menu;
    printf("1. Jugar\n2. Créditos\n");
    printf("Elige una opción para comenzar: ");
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
        introduccion();

        //* Estas 3 lineas de código solo son de prueba para ver que funcionan correctamente las librerías
        printf("Quieres abrir la caja? -1 para si, -0 para no: ");
        int abrirCaja;
        scanf("%d", &abrirCaja);
        if (abrirCaja == 1)
        {
            struct Recursos recursos; // Crear una instancia de Recursos
            inicializar_recursos(&recursos); // Inicializar la estructura
            evento_caja(&recursos); // Pasar la estructura a la función
        }
        break;
    case 2:
        creditos();
        menu_inicial();
        break;
    default:
        break;
    }
}

void introduccion ()
{
    printf("-Hola usuario actualmente estas en un apocalipsis zombie, en donde debes aplicar lo que sabes sobre supervivencia para avanzar.\n");
    printf("-Recuerda que tus acciones pueden traerte tanto beneficios como también consecuencias\n\n\n");
    
}

void creditos ()
{
    printf("Gracias por jugar atte:\n-Alan\n-Victoria\n-Javier\n");
}
void inventario ()
{
    
}