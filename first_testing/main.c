//main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//librerias propias:
#include "eventos.h"
//Macros
#define SRAND srand(time(NULL));//generar numeros aleatorios totalmente diferentes con el tiempo

//funciones:
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

//Funcion que imprime el menu incial con 2 simples opciones
void menu_inicial ()
{
    int menu;
    printf("1. Jugar\n2. Creditos\n");
    printf("Elige una opcion para comenzar: ");
    scanf("%d",&menu);
    switch (menu)
    {
    case 1:
        introduccion();
        struct Recursos recursos;
        inicializar_recursos(&recursos);
        probabilidad_eventos(&recursos);
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
    printf("-Recuerda que tus acciones pueden traerte beneficios como tambien consecuencias\n");
    
}

void creditos ()
{
    printf("Gracias por jugar att:\n-Alan\n-Victoria\n-Francisco\n");
}
void inventario ()
{
    
}