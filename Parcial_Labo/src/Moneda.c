#include <stdio.h>
#include "Estructuras.h"
#include "Moneda.h"

/*****************************************************************************/

void listaDeMonedas(eMoneda moneda[])
{
	for(int i=0; i<3; i++)
	{
		printf("\nID: %d   Moneda: %s\n", moneda[i].idMoneda, moneda[i].tipoMoneda);
	}
}

/*****************************************************************************/

void cargarMonedas(eMoneda moneda[])
{
	eMoneda auxiliar[3] = {{1,"USD", 4},
						   {2,"Euro", 5},
						   {3,"Pesos Arg", 6}};

			for(int i = 0; i<3; i++)
			{
				moneda[i] = auxiliar[i];
			}
}

/*****************************************************************************/

void servciosMonedaYEspecialidad(eMoneda moneda[], eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], eDiagnostico miDiagnosticos[])
{
	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(miServicios[i].idMoneda == moneda[j].idMoneda)
			{
				for(int p=0; p<6; p++)
				{
					if(miServicios[i].idMecanico == miMecanicos[p].idMecanico)
					{
						for(int t=0; t<3; t++)
						{
							if(miServicios[i].diagnostico == miDiagnosticos[t].idDiagnostico)
							{
								if(moneda[j].metodoDePago == Bitcoin)
								{
									printf("\nCliente: %s   Mecanico: %s   Diagnostico: %s   Moneda: %s   Metodo de pago: Bitcoin", miServicios[i].nombreCliente,
									miMecanicos[p].nombreMecanico, miDiagnosticos[t].descripcion, moneda[j].tipoMoneda);
								}
								else if(moneda[j].metodoDePago == Tarjeta)
								{
									printf("\nCliente: %s   Mecanico: %s   Diagnostico: %s   Moneda: %s   Metodo de pago: Tarjeta", miServicios[i].nombreCliente,
									miMecanicos[p].nombreMecanico, miDiagnosticos[t].descripcion, moneda[j].tipoMoneda);
								}
								else if(moneda[j].metodoDePago == Efectivo)
								{
									printf("\nCliente: %s   Mecanico: %s   Diagnostico: %s   Moneda: %s   Metodo de pago: Efectivo", miServicios[i].nombreCliente,
									miMecanicos[p].nombreMecanico, miDiagnosticos[t].descripcion, moneda[j].tipoMoneda);
								}
							}
						}
					}
				}
			}
		}
	}
}
