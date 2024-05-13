// eventos.c
//*librerías necesarias para las funciones
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//archivo de implementación de la librería eventos.h.
#include "eventos.h"
//Macros
#define SRAND srand(time(NULL));//generar números aleatorios totalmente diferentes con el tiempo

void inicializar_recursos(struct Recursos *recursos, struct Dia *dia)
{
    recursos->a = 0;
    recursos->c = 0;
    recursos->vida = 100;
    recursos->arma=0;
    recursos->tickets = 0;

}
void eventos(struct Dia *dia) {
    //dia->contador_dias++;
    //printf("Día %d\n", dia->contador_dias); // Imprime el contador de días
}

//* Funciones de eventos:

void seleccionar_recursos_iniciales(struct Recursos *recursos) 
{
    int eleccion;
    printf("\nAntes de comenzar el juego, puedes elegir un paquete inicial de recursos:\n");
    printf("1. Paquete alto en comida (5 unidades de comida, 2 de agua)\n");
    printf("2. Paquete alto en agua (2 unidades de comida, 5 de agua)\n");
    printf("3. Paquete equilibrado\n");
    printf("Elige una opción (1 o 3): ");
    scanf("%d", &eleccion);
    if (eleccion == 1) {
        recursos->c = 5;
        recursos->a = 2;
    } else if (eleccion == 2) {
        recursos->c = 2;
        recursos->a = 5;
    } else if (eleccion == 3){
        recursos->c = 3;
        recursos->a = 3;
    } else {
        printf("Opción no válida. Por lo que no obtendrás ningún recurso\n");
        recursos->c = 0;
        recursos->a = 0;
    }
}

void gestionar_refugio(struct Recursos *recursos) {
    int opcion;
    bool accionValida = false;

    while (!accionValida) {
        printf("\nEstás en el refugio. ¿Deseas hacer algo?\n");
        printf("1. Comer (mejora la vida, consume comida)\n");
        printf("2. Beber (mejora la vida, consume agua)\n");
        printf("3. Incrementa la vida consumiendo ambos, comida y agua\n");
        printf("4. Decides no hacer nada\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (recursos->c > 0) {
                    recursos->c--;
                    recursos->vida = (recursos->vida + 10 > 100) ? 100 : recursos->vida + 10;
                    printf("Has comido algo, te sientes mejor.\n");
                    accionValida = true;
                } else {
                    printf("No tienes suficiente comida.\n");
                }
                break;
            case 2:
                if (recursos->a > 0) {
                    recursos->a--;
                    recursos->vida = (recursos->vida + 5 > 100) ? 100 : recursos->vida + 5;
                    printf("Has bebido agua, te sientes más hidratado.\n");
                    accionValida = true;
                } else {
                    printf("No tienes suficiente agua.\n");
                }
                break;
            case 3:
                if (recursos->a > 0 && recursos->c > 0) {
                    recursos->a--;
                    recursos->c--;
                    recursos->vida = (recursos->vida + 15 > 100) ? 100 : recursos->vida + 15;  // Incremento de vida más significativo al consumir ambos
                    printf("Has consumido agua y comida, mejorando significativamente tu salud.\n");
                    accionValida = true;
                } else {
                    if (recursos->a == 0 && recursos->c == 0) {
                        printf("No tienes suficiente agua ni comida.\n");
                    } else if (recursos->a == 0) {
                        printf("No tienes suficiente agua.\n");
                    } else if (recursos->c == 0) {
                        printf("No tienes suficiente comida.\n");
                    }
                }
                break;
            case 4:
                printf("Decides no consumir tus recursos hoy.\n");
                accionValida = true; // Decidir no hacer nada es siempre una acción válida
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
                break;
        }
    }
}

void evento_caja_advertencia (struct Recursos *recursos, struct Dia *dia)//evento de caja con avisos
{
    SRAND //macro
    // Generar un número aleatorio entre 0 y 10
    int probabilidad = rand() % 10;
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
        recursos->c = recursos->c > 1 ? recursos->c - 1 : 0;
        recursos->a = recursos->a > 1 ? recursos->a - 1 : 0;
        //recursos->vida = recursos->vida > 20 ? recursos->vida - 20 : 0;
        recursos->vida = recursos->vida -20;
    }
    //contar 1 dia cada vez que termine un evento
    //dia->contador_dias = dia->contador_dias + 1;
    //printf("Día %d\n", dia->contador_dias); 
}

void evento_caja (struct Recursos *recursos, struct Dia *dia) //evento de caja sola
{
    SRAND //macro
    int probabilidad = rand() % 2;
    if (probabilidad == 0 )//probabilidad 50%
    {
        printf("Encontraste 2 unidades de comida\n");
        recursos->c = recursos->c + 2;
        //+2u comida
    } 
    else //probabilidad 50%
    {
        printf("Un ratón te robo, perdiste 2 unidades de comida\n");
        recursos->c = recursos->c > 1 ? recursos->c - 1 : 0;
    } 
    //dia->contador_dias = dia->contador_dias + 1;
    //printf("Día %d\n", dia->contador_dias); 
}

void evento_tickets(struct Recursos *recursos, struct Dia *dia)
{
    SRAND //macro
    int probabilidad = rand() % 2;
    
   if (probabilidad == 1) // Hay un 50% de probabilidad de encontrar una caja de tickets
    {
        printf("Encontraste una caja con 50 tickets!\n");
        recursos->tickets += 50; // Agregar 50 tickets a los recursos
    }
    else
    {
        printf("No encontraste ninguna caja de tickets.\n");
    }
    dia->contador_dias = dia->contador_dias + 1;
    //printf("Día %d\n", dia->contador_dias); 
}
void eveto_buscando_recursos(struct Recursos *recursos, struct Dia *dia)
{
    SRAND
    int probabilidad = rand() % 8;
    if (probabilidad == 0 || probabilidad == 1 || probabilidad == 3)
    {
        printf("Solo fue un pequeño roedor pasando\n");
    }
    else if(probabilidad==4 || probabilidad==5)
    {
        printf("Encontraste un zombie, te a herido gravemente\n");
        printf("Perdiste 20 de vida y agua\n");
        recursos->vida = recursos->vida - 20;
        recursos->a = recursos->a - 1;
    }
    else if(dia->contador_dias > 20)
    {
        printf("Ese sonido era un elemento de la marina y te salvo\n");
        printf("Felicidades te han rescatado\n");
        //creditos();
    }
    else
    {
        printf("El sonido no era nada, regresaste al bunker\n");
    }
    //dia->contador_dias = dia->contador_dias + 1;
    //printf("Día %d\n", dia->contador_dias); 
}


//Asignar dicha probabilidad dentro de eventos
bool probabilidad_eventos (struct Recursos *recursos, struct Dia *dia)
{
    SRAND//macro
    int probabilidad = rand()%10;
    bool encontrados = false;
    if(recursos->c < 0 || recursos->a < 0)
    {
        recursos->vida = recursos->vida -20;
    }
    
    if (probabilidad == 0 || probabilidad == 1) 
    {
        //función de la caja normal--------------------------------------------------------
        printf("Acabas de encontrar una caja normal\n");
        printf("Quieres abrir la caja? 1 para si, 0 para no: ");
        int abrirCaja;
        scanf("%d", &abrirCaja);
        if (abrirCaja == 1)
        {
            evento_caja(recursos, dia);
        }
        
    }
    else if (probabilidad == 2)
    {
        //evento caja con avisos-----------------------------------------------------------
        printf("Acabas de encontrar una caja con varias etiquetas de advertencia\n");
        printf("Quieres abrir la caja? 1 para si, 0 para no: ");
        int abrirCaja;
        scanf("%d", &abrirCaja);
        if (abrirCaja == 1)
        {
            evento_caja_advertencia(recursos, dia);
        }
    }
    else if (probabilidad == 3)//evento de tickets
    {
        printf("Encontraste tickets felicidades\nDa 1 para continuar\n");
        int enter;
        scanf("%d",&enter);
        if (enter == 1)
        {
            evento_tickets(recursos, dia);
        }
        encontrados = true;
    }
    else if(probabilidad == 4|| probabilidad == 5 || probabilidad == 6 || probabilidad == 7 || probabilidad == 8 || probabilidad == 9 )
    {
        //evento zombie-----------------------------------------------------------
        printf("\nSales a buscar recursos en una tienda/mercado cercano.\n");
        printf("Mientras guardas los recursos, escuchas un ruido muy cercano...\n");
        printf("Elige una acción:\n1. Investigar el ruido\n2. Correr de regreso a 'casa'.\n");
        int eleccion;
        scanf("%d", &eleccion);
        if (eleccion == 1)
        {
            eveto_buscando_recursos(recursos, dia);
        }
        else if(eleccion == 2)
        {
            printf("Corres de vuelta a casa sin más incidentes, pero te sientes más cansado.\n");
            printf("Esto te resta puntos de vida por no conseguir nada y solo gastar energía\n");
            recursos->vida -= 5;
        }
        
    }
    //las demás futuras funciones----------------------------------------------------------------------------------------------
    else 
    {
        printf("Coming soon(Próximamente más funciones)aaaaaaaaaaaa");
    }
    return encontrados;
}
