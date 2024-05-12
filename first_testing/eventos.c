//*eventos.c
//*librerías necesarias para las funciones
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*archivo de implementación de la librería eventos.h.
#include "eventos.h"
//*Macros
#define SRAND srand(time(NULL)); //*generar números aleatorios totalmente diferentes con el tiempo

void inicializar_recursos(struct Recursos *recursos)
{
    recursos->a = 0;
    recursos->c = 0;
}
//*funciones de eventos:
void evento_caja_advertencia (struct Recursos *recursos) // *evento de caja con avisos
{
    SRAND //macro
    // * Generar un número aleatorio entre 0 y 10
    int probabilidad = rand() % 10;

    printf("%d\n", probabilidad); //*linea no necesaria

    //* Asignar los eventos con las probabilidades respectivas
    if (probabilidad == 0 || probabilidad == 1 )//*probabilidad 20%
    {
        printf("Encontraste 3 unidades de comida\n");
        recursos->c = recursos->c + 3;
        //*+3u comida
    } 
    else if (probabilidad == 2) //*probabilidad 10%
    {
        printf("Encontraste 2 botellas de agua\n");
        recursos->a = recursos->a + 3;
        //*+2u de agua
    } 
    else//*restante 70%
    {
        printf("Esta caja tenia dentro gases que te enfermaron\n");
        recursos->c = recursos->c - 2;
        recursos->a = recursos->a - 3;
        //*-2u de comida y -3u agua
    }
}

void evento_caja (struct Recursos *recursos) //*evento de caja sola
{
    SRAND //*macro
    int probabilidad = rand() % 2;
    printf("%d\n", probabilidad);//*linea no necesaria

    if (probabilidad == 0 )//*probabilidad 50%
    {
        printf("Encontraste 2 unidades de comida\n");
        recursos->c = recursos->c + 2;
        //+2u comida
    } 
    else //probabilidad 50%
    {
        printf("Una ratón te robo, perdiste 2 unidades de comida\n");
        recursos->c = recursos->c - 2;
        //-2u de comida
    } 
    
}