#include <stdio.h>
#include "Diagnostico.h"

void cargarDiagnosticos(eDiagnostico miDiagnosticos[])
{
	eDiagnostico auxiliar[6] = {{1,"Cambio de aceite"},
							 	{2,"Reparar motor"},
								{3,"Suspencion"}};

			for(int i = 0; i<6; i++)
			{
				miDiagnosticos[i] = auxiliar[i];
			}
}

/*****************************************************************************/

void listaDeDiagnosticos(eDiagnostico miDiagnosticos[])
{

	for(int i=0; i<3; i++)
	{
		printf("\nID: %d   Descripcion: %s\n", miDiagnosticos[i].idDiagnostico, miDiagnosticos[i].descripcion);
	}
}

/*****************************************************************************/

void desperfectosMasDiagnosticados(eDiagnostico miDiagnosticos[], eServicio miServicios[], int sizeServicios)
{

	int contadorCambioDeAceite;
	int contadorRepararMotor;
	int contadorSuspencion;
	contadorCambioDeAceite = 0;
	contadorRepararMotor = 0;
	contadorSuspencion = 0;

	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(miServicios[i].diagnostico == miDiagnosticos[j].idDiagnostico)
			{
				if(miDiagnosticos[j].idDiagnostico == 1)
				{
					contadorCambioDeAceite++;
				}
				if(miDiagnosticos[j].idDiagnostico == 2)
				{
					contadorRepararMotor++;
				}
				if(miDiagnosticos[j].idDiagnostico == 3)
				{
					contadorSuspencion++;
				}
			}
		}
	}

	if(contadorCambioDeAceite > contadorRepararMotor && contadorCambioDeAceite > contadorSuspencion)
	{	printf("\n1-Cambio de aceite");
		if(contadorRepararMotor > contadorSuspencion)
		{
			printf("\n2-Reparar motor\n3-Suspencion");
		}
		else if(contadorSuspencion > contadorRepararMotor)
		{
			printf("\n2-Suspencion\n3-Reparar motor");
		}
	}
	else if(contadorRepararMotor > contadorCambioDeAceite && contadorRepararMotor > contadorSuspencion)
	{	printf("\n1-Reparar motor");
		if(contadorCambioDeAceite > contadorSuspencion)
		{
			printf("\n2-Cambio de aceite\n3-Suspencion");
		}
		else if(contadorSuspencion > contadorCambioDeAceite)
		{
			printf("\n2-Suspencion\n3-Cambio de aceite");
		}
	}
	else if(contadorSuspencion > contadorCambioDeAceite && contadorSuspencion > contadorRepararMotor)
	{
		printf("\n1-Suspencion");
		if(contadorCambioDeAceite > contadorRepararMotor)
		{
			printf("\n2-Cambio de aceite\n3-Reparar motor");
		}
		else if(contadorRepararMotor > contadorCambioDeAceite)
		{
			printf("\n2-Reparar motor\n3-Cambio de aceite");
		}
	}
}
