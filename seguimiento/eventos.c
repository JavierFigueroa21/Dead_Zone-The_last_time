//eventos.c
//librerías necesarias para las funciones
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//archivo de implementación de la librería eventos.h.
#include "eventos.h"
//Macros
#define SRAND srand(time(NULL));//generar números aleatorios totalmente diferentes con el tiempo



void inicializar_recursos(struct Recursos *recursos)
{
    recursos->a = 0;
    recursos->c = 0;
    recursos->vida = 100;
    recursos->arma=0;
}
// * aqui agregaron eventos dia, que imprime el dia



//* Funciones de eventos:
void evento_caja_advertencia (struct Recursos *recursos)//evento de caja con avisos
{
    SRAND //macro
    // Generar un número aleatorio entre 0 y 9
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
    } 
    else//restante 70%
    {
        printf("Esta caja tenia dentro gases que te enfermaron\n");
        recursos->c = recursos->c > 1 ? recursos->c - 1 : 0;
        recursos->a = recursos->a > 1 ? recursos->a - 1 : 0;
        //recursos->vida = recursos->vida > 20 ? recursos->vida - 20 : 0;
        recursos->vida = recursos->vida -20;
    }
}


// * Evento de una caja sola
void evento_caja (struct Recursos *recursos)
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
        //recursos->c = recursos->c - 1;
        recursos->c = recursos->c > 1 ? recursos->c - 1 : 0;
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
        printf("\nAcabas de encontrar una caja normal\n");
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
        printf("\nAcabas de encontrar una caja con varias etiquetas de advertencia\n");
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

// * Buscando recursos
void evento_buscando_recursos(struct Recursos *recursos, int dia) {
    printf("\nSales a buscar recursos en una tienda/mercado cercano.\n");
    printf("Mientras guardas los recursos, escuchas un ruido muy cercano...\n");

    printf("Elige una acción:\n1. Esconderse y esperar un rato.\n2. Correr de regreso a 'casa'.\n3. Investigar el ruido.\n");
    int eleccion;
    scanf("%d", &eleccion);

    switch (eleccion) {
        case 1:  // Esconderse
            printf("Te escondes un rato y luego regresas seguro a casa.\n");
            printf("Lograste mantenerte más a salvo y conseguiste recursos.\n");
            recursos->c += 2;
            recursos->a += 2;
            break;
        case 2:  // Correr
            printf("Corres de vuelta a casa sin más incidentes, pero te sientes más cansado.\n");
            printf("Esto te resta puntos de vida por no conseguir nada y solo gastar energía");
            recursos->vida -= 5; 
            break;
        case 3:  // Investigar el ruido
            printf("Decides investigar el ruido...\n");
            int resultado = rand() % 10;  // Genera un número aleatorio del 0 al 9
            if (resultado < 3) {
                printf("\nEra solo un ratón.\n");
            } else if (resultado < 6) {
                printf("\n¡Es un zombie! Te ataca.\n");
                if (recursos->arma ==1) {
                    printf("\nTe defiendes con tu arma.\n");
                    // Podrías considerar efectos adicionales aquí
                } else {
                    printf("\nEl zombie hace que te hieras gravemente.\n");
                    printf("Esto hace que pierdas vida y por lo tanto recursos");
                    recursos->vida = recursos->vida > 20 ? recursos->vida - 20 : 0;
                    recursos->a = recursos->a > 2 ? recursos->a - 2 : 0;
                    recursos->c = recursos->c > 1 ? recursos->c - 1 : 0;
                }
            } else if (dia >= 40 && resultado == 9) {
                printf("\nEs un rescatista que te lleva a una comunidad segura.\n");
                printf("Se termina el juego, vaya suerte!");
                break;
                //* se termino el juego
            } else {
                printf("\nNo hay nada, el ruido era del viento.\n");
            }
            break;
        default:
            printf("\nNo seleccionaste una opción válida.\n");
            break;
    }
}


void seleccionar_recursos_iniciales(struct Recursos *recursos) {
    int eleccion;
    printf("\nAntes de comenzar el juego, puedes elegir un paquete inicial de recursos:\n");
    printf("\n1. Paquete alto en comida (5 unidades de comida, 2 de agua)\n");
    printf("2. Paquete alto en agua (2 unidades de comida, 5 de agua)\n");
    printf("3. Paquete equilibrado\n");
    printf("\nToma en cuenta que esto puede afectar en tu supervivencia");
    printf("\nElige una opción (1 o 3): ");
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
        printf("Estás en el refugio. ¿Deseas hacer algo?\n");
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



