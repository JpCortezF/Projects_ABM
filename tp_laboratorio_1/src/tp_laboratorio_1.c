#include <stdio.h>
#include <stdlib.h>
#include "administrarEquipo.h"
#include "utn_get.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int menuPrincipal;
	int seCargo=0;
	int seCalculo=0;
	int confederacionAfc=0;
	int confederacionCaf=0;
	int confederacionConcacaf=0;
	int confederacionConmebol=0;
	int confederacionUefa=0;
	int confederacionOfc=0;
	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	float costoMantenimiento=0;
	float promedioAfc=0;
	float promedioCaf=0;
	float promedioConcacaf=0;
	float promedioConmebol=0;
	float promedioUefa=0;
	float promedioOfc=0;
	float aumentoUefa;
	float aumentoUefaTotal;
	int arqueros=0;
	int defensores=0;
	int mediocampistas=0;
	int delanteros=0;

	do
	{
		printf("\n------------------------------------------\n");
		printf("\n           Menu principal           \n\n");
		printf("1. Ingreso de los costos de Mantenimiento\n");
		printf(" Costo de Hospedaje -> $usd%.2f\n", costoHospedaje);
		printf(" Costo de Comida -> $usd%.2f\n", costoComida);
		printf(" Costo de Transporte -> $usd%.2f\n", costoTransporte);
		printf("2.Carga de jugadores\n");
		printf(" Arqueros -> %d\n", arqueros);
		printf(" Defensores -> %d\n", defensores);
		printf(" Mediocampistas -> %d\n", mediocampistas);
		printf(" Delanteros -> %d\n", delanteros);
		printf("3.Realizar todos los calculos\n");
		printf("4.Informar todos los resultados\n");
		printf("5.Salir\n");
		utn_getNumberInt(&opcion, "\nIngrese una opcion: ", "\nError, ingrese una opcion valida...\n",1, 5, 3);
		switch(opcion)
		{
			case 1:
				calcularCosto(&costoHospedaje, &costoComida, &costoTransporte, &costoMantenimiento);
				break;
			case 2:
				cargarEquipo(&arqueros, &defensores, &mediocampistas, &delanteros, &confederacionAfc, &confederacionCaf, &confederacionConcacaf, &confederacionConmebol, &confederacionUefa, &confederacionOfc);
				if(arqueros!=0 || defensores!=0 || mediocampistas!=0 || delanteros!=0)
				{
					seCargo++;
				}
				break;
			case 3:
				if(seCargo != 0)
				{
					promedioTotal(&promedioAfc, confederacionAfc, LEN);
					promedioTotal(&promedioCaf, confederacionCaf, LEN);
					promedioTotal(&promedioConcacaf, confederacionConcacaf, LEN);
					promedioTotal(&promedioConmebol, confederacionConmebol, LEN);
					promedioTotal(&promedioUefa, confederacionUefa, LEN);
					promedioTotal(&promedioOfc, confederacionOfc, LEN);
					printf("\n--------------------------------------------");
					printf("\n| Se realizaron los calculos correctamente!|");
					printf("\n|------------------------------------------|\n");
					utn_getNumberInt(&menuPrincipal, "\nIngrese '1' para volver al menu principal: ", "\nIngrese una opcion valida...\n",1,1,5);
					seCalculo++;
				}
				else{
					printf("\nNo hay nada cargado...\n");
					utn_getNumberInt(&menuPrincipal, "\nIngrese '1' para volver al menu principal: ", "\nIngrese una opcion valida...\n",1,1,5);
				}
				break;
			case 4:
				if(seCalculo!=0)
				{
					printf("\n\n     Informar todos los resultados      \n\n");
					printf("Promedio Uefa: %.2f\n",promedioUefa);
					printf("Promedio Conmebol: %.2f\n", promedioConmebol);
					printf("Promedio Concacaf: %.2f\n", promedioConcacaf);
					printf("Promedio Afc: %.2f\n", promedioAfc);
					printf("Promedio Ofc: %.2f\n", promedioOfc);
					printf("Promedio Caf: %.2f\n", promedioCaf);
					seCalculo=0;
					if(promedioUefa >= 50 && costoMantenimiento!=0){
						aumentoUefa = (float) (costoMantenimiento / 100 ) * 35;
						aumentoUefaTotal = costoMantenimiento * 1.35;
						printf("\nel costo de mantenimiento era de $usd %.2f y recibio un aumento de $usd %.2f, su nuevo valor es de: $usd %.2f\n\n",costoMantenimiento, aumentoUefa, aumentoUefaTotal);
						utn_getNumberInt(&menuPrincipal, "\nIngrese '1' para volver al menu principal: ", "\nIngrese una opcion valida...\n",1,1,5);
					}
					else{
						printf("\nel costo de mantenimiento es de $usd %.2f\n\n", costoMantenimiento);
						utn_getNumberInt(&menuPrincipal, "\nIngrese '1' para volver al menu principal: ", "\nIngrese una opcion valida...\n",1,1,5);
					}
					promedioUefa=0;
					promedioConmebol=0;
					promedioConcacaf=0;
					promedioAfc=0;
					promedioOfc=0;
					promedioCaf=0;
					break;
				}
				else{
					printf("\nPrimero tenes que hacer los calculos...\n");
					utn_getNumberInt(&menuPrincipal, "\nIngrese '1' para volver al menu principal: ", "\nIngrese una opcion valida...\n",1,1,5);
				}
		}
	}while(opcion!=5);
	printf("\nGracias por usar el programa...");
	return 0;
}
