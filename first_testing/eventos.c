//eventos.c
//librerías necesarias para las funciones
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//archivo de implementación de la librería eventos.h.
#include "eventos.h"
//Macros
#define SRAND srand(time(NULL));//generar números aleatorios totalmente diferentes con el tiempo



void inicializar_recursos(struct Recursos *recursos)
{
    recursos->a = 0;
    recursos->c = 0;
}


//funciones de eventos:
void evento_caja_advertencia (struct Recursos *recursos)//evento de caja con avisos
{
    SRAND //macro
    // Generar un número aleatorio entre 0 y 10
    int probabilidad = rand() % 10;

    printf("%d\n", probabilidad);//linea no necesaria
    // Asignar los eventos con las probabilidades respectivas
    if(probabilidad == 0 || probabilidad == 1 )//probabilidad 20%
    {
        printf("Encontraste 3 unidades de comida\n");
        recursos->c = recursos->c + 3;
    } 
    else if (probabilidad == 2)//probabilidad 10%
    {
        printf("Encontraste 2 botellas de agua\n");
        recursos->a = recursos->a + 2;
        //+2u de agua
    } 
    else//restante 70%
    {
        printf("Esta caja tenia dentro gases que te enfermaron\n");
        recursos->c = recursos->c - 2;
        recursos->a = recursos->a - 3;
    }
}



void evento_caja (struct Recursos *recursos) //evento de caja sola
{
    SRAND //macro
    int probabilidad = rand() % 2;
    printf("%d\n", probabilidad);//linea no necesaria
    if (probabilidad == 0 )//probabilidad 50%
    {
        printf("Encontraste 2 unidades de comida\n");
        recursos->c = recursos->c + 2;
        //+2u comida
    } 
    else //probabilidad 50%
    {
        printf("Un ratón te robo, perdiste 2 unidades de comida\n");
        recursos->c = recursos->c - 2;
    } 
    //recursos-> dia = recursos-> dia + 0.5;
}


//Asignar dicha probabilidad dentro de eventos
void probabilidad_eventos (struct Recursos *recursos)
{
    SRAND//macro
    int probabilidad = rand()%10;
    if (probabilidad == 0 || probabilidad == 1)  
    {
        //función de la caja normal
        printf("Acabas de encontrar una caja normal\n");
        printf("Quieres abrir la caja? 1 para si, 0 para no: ");
        int abrirCaja;
        scanf("%d", &abrirCaja);
        if (abrirCaja == 1)
        {
            evento_caja(recursos);
        }
        
    }
    else if (probabilidad == 2)//evento caja con avisos
    {
        printf("Acabas de encontrar una caja con varias etiquetas de advertencia\n");
        printf("Quieres abrir la caja? 1 para si, 0 para no: ");
        int abrirCaja;
        scanf("%d", &abrirCaja);
        if (abrirCaja == 1)
        {
            evento_caja_advertencia(recursos);
        }
    }
    //las demás futuras funciones
    else
    {
        printf("Coming soon(Próximamente más funciones)");
    }

}