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
                break;
            case 2:
            	controller_agregarJugador(listaJugadores);
            	break;
            case 3:
            	controller_editarJugador(listaJugadores, listaSelecciones);
            	break;
            case 4:
            	controller_removerJugador(listaJugadores, listaSelecciones);
            	break;
            case 5:
        		if(!(ll_isEmpty(listaJugadores)))
            	{
					utn_getChar(&listado,"\nA) LISTAR TODOS LOS JUGADORES\nB) TODAS LAS SELECCIONES\nC) JUGADORES CONVOCADOS\n-> Ingrese opcion: ", "\nIngrese una opcion valida...",'A','C',20);
					switch(listado)
					{
						case 'A':
							controller_listarJugadores(listaJugadores, listaSelecciones);
							break;
						case 'B':
							controller_listarSelecciones(listaSelecciones);
							break;
						case 'C':
							controller_listarConvocados(listaJugadores, listaSelecciones);
							break;
					}
            	}else{
            		puts("\nPrimero tenes que hacer la carga del archivo .csv!");
            	}
            	break;
            case 6:
            	controller_convocarJugadores(listaSelecciones, listaJugadores);
            	break;
            case 7:
            	controller_ordenarJugadores(listaJugadores, listaSelecciones);
            	break;
            case 8:
            	controller_guardarJugadoresModoBinario("data.bin", listaJugadores, listaSelecciones); //wb
            	break;
            case 9:
           		controller_cargarJugadoresDesdeBinario("data.bin", listaJugadores, listaSelecciones); // rb
            	break;
            case 10:
           		controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores); // w
           		controller_guardarSeleccionesModoTexto("selecciones.csv", listaSelecciones); // w
            	break;
        }
    }while(option != 11);
    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaSelecciones);
    return 0;
}
