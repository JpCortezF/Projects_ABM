#include <stdio.h>
#include <stdlib.h>
#include "utn_get.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Seleccion.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int flag=0;
    char listado;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    do
    {
		printf("\n-------------------------\n");
		printf("\n     Menu principal    \n\n");
		printf("1. Carga de archivos\n");
		printf("2. Alta de jugador\n");
		printf("3. Modificacion de jugador\n");
		printf("4. Baja de jugador\n");
		printf("5. Listados\n");
		printf("6. Convocar jugadores\n");
		printf("7. Ordenar y listar\n");
		printf("8. Generar archivo binario\n");
		printf("9. Cargar archivo binario\n");
		printf("10. Guardar archivos .csv\n");
		printf("11. SALIR\n");
		utn_getNumberInt(&option, "Ingresar una opcion: ", "\nError, ingrese una opcion valida...\n",1,11,20);

        switch(option)
        {
            case 1:
            	controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores); // r
            	controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones); // r
            	flag=1;
                break;
            case 2:
            	if(flag!=0)
            	{
            		controller_agregarJugador(listaJugadores);
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 3:
            	if(flag!=0)
            	{
            		controller_editarJugador(listaJugadores);
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 4:
            	if(flag!=0)
            	{
            		controller_removerJugador(listaJugadores);
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 5:
            	if(flag!=0)
            	{
					utn_getChar(&listado,"\nA) LISTAR TODOS LOS JUGADORES\nB) TODAS LAS SELECCIONES\nC) JUGADORES CONVOCADOS\n-> Ingrese opcion: ", "\nIngrese una opcion valida...",'A','C',20);
					switch(listado)
					{
						case 'A':
							controller_listarJugadores(listaJugadores);
							break;
						case 'B':
							controller_listarSelecciones(listaSelecciones);
							break;
						case 'C':
							controller_listarConvocados(listaJugadores, listaSelecciones);
							break;
					}
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 6:
            	if(flag!=0)
            	{
            		controller_convocarJugadores(listaSelecciones, listaJugadores);
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 7:
            	if(flag!=0)
            	{
            		controller_ordenarJugadores(listaJugadores, listaSelecciones);
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 8:
            	if(flag!=0)
            	{
            		controller_guardarJugadoresModoBinario("data.bin", listaJugadores); //wb
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 9:
            	if(flag!=0)
            	{
            		controller_cargarJugadoresDesdeBinario("data.bin", listaJugadores); // rb
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 10:
            	if(flag!=0)
            	{
            		controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores); // w
            		controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones); // w
            		puts("\nArchivos .csv guardados correctamente!");
            	}else{
            		puts("Primero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
        }
    }while(option != 11);

    return 0;
}
