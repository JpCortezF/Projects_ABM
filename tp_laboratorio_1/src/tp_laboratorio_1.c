#include <stdio.h>
#include <stdlib.h>
#include "administrarEquipo.h"
#include "utn_get.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
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
	float porcentajeAfc=0;
	float porcentajeCaf=0;
	float porcentajeConcacaf=0;
	float porcentajeConmebol=0;
	float porcentajeUefa=0;
	float porcentajeOfc=0;
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
		printf(" Costo de Hospedaje -> $%.2f\n", costoHospedaje);
		printf(" Costo de Comida -> $%.2f\n", costoComida);
		printf(" Costo de Transporte -> $%.2f\n", costoTransporte);
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
				seCargo++;
				break;
			case 3:
				if(seCargo != 0)
				{
					porcentajeTotal(&porcentajeAfc, confederacionAfc, LEN);
					//
					porcentajeTotal(&porcentajeCaf, confederacionCaf, LEN);
					//
					porcentajeTotal(&porcentajeConcacaf, confederacionConcacaf, LEN);
					//
					porcentajeTotal(&porcentajeConmebol, confederacionConmebol, LEN);
					//
					porcentajeTotal(&porcentajeUefa, confederacionUefa, LEN);
					//
					porcentajeTotal(&porcentajeOfc, confederacionOfc, LEN);
					//
					printf("\nSe realizaron los calculos correctamente!\n");
					printf("\n------------------------------------------\n");
					seCalculo++;
				}
				break;
			case 4:
				if(seCalculo!=0)
				{
					printf("\n\n     Informar todos los resultados      \n\n");
					printf("Poncentaje Uefa: %.2f\n", porcentajeUefa);
					printf("Porcentaje Conmebol: %.2f\n", porcentajeConmebol);
					printf("Porcentaje Concacaf: %.2f\n", porcentajeConcacaf);
					printf("Porcentaje Afc: %.2f\n", porcentajeAfc);
					printf("Porcentaje Ofc: %.2f\n", porcentajeOfc);
					printf("Porcentaje Caf: %.2f\n", porcentajeCaf);
					if(porcentajeUefa >= 50 && costoMantenimiento!=0){
						aumentoUefa = (float) (costoMantenimiento / 100 ) * 35;
						aumentoUefaTotal = costoMantenimiento * 1.35;
						printf("\nel costo de mantenimiento era de $usd%.2f y recibio un aumento de $usd%.2f, su nuevo valor es de: $usd%.2f\n\n",costoMantenimiento, aumentoUefa, aumentoUefaTotal);
					}
					else{
						printf("\nel costo de mantenimiento es de %.2f\n\n", costoMantenimiento);
					}
					porcentajeUefa=0;
					porcentajeConmebol=0;
					porcentajeConcacaf=0;
					porcentajeAfc=0;
					porcentajeOfc=0;
					porcentajeCaf=0;
					break;
				}
		}
	}while(opcion!=5);
	return 0;
}
