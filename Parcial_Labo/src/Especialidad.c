#include <stdio.h>
#include "Especialidad.h"

void cargarEspecialidad(eEspecialidad miEspecialidad[])
{
	eEspecialidad auxiliar[3] = {{1,"Realiza cambio de aceite"},
							 	 {2,"Reparador de motores"},
								 {3,"Regulador de Suspencion"}};

			for(int i = 0; i<3; i++)
			{
				miEspecialidad[i] = auxiliar[i];
			}
}

/*****************************************************************************/

void listaDeEspecialidades(eEspecialidad miEspecialidad[])
{
	for(int i=0; i<3; i++)
	{
		printf("\nID: %d   Descripcion: %s\n", miEspecialidad[i].idEspecialidad, miEspecialidad[i].descripcion);
	}
}

/*****************************************************************************/

void especialidadesMasEstudidasPorMecanico(eEspecialidad miEspecialidad[], eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[])
{
	int realizaCambioAceite;
	int repararMotores;
	int regulaSuspenciones;

	for(int i=0; i<sizeServicios; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(miServicios[i].diagnostico == miMecanicos[j].idEspecialidad)
			{
				if(miMecanicos[j].idEspecialidad == 1)
				{
					realizaCambioAceite++;
				}
				if(miMecanicos[j].idEspecialidad == 2)
				{
					repararMotores++;
				}
				if(miMecanicos[j].idEspecialidad == 3)
				{
					regulaSuspenciones++;
				}
			}
		}
	}

	if(realizaCambioAceite > repararMotores && realizaCambioAceite > regulaSuspenciones)
	{	printf("\n1-Realiza cambios de aceite");
		if(repararMotores > regulaSuspenciones)
		{
			printf("\n2-Reparador de motores\n3-Regulador de suspencion");
		}
		else if(regulaSuspenciones > repararMotores)
		{
			printf("\n2-Regulador de suspencion\n3-Reparador de motores");
		}
	}
	else if(repararMotores > realizaCambioAceite && repararMotores > regulaSuspenciones)
	{	printf("\n1-Reparador de motores");
		if(realizaCambioAceite > regulaSuspenciones)
		{
			printf("\n2-Realiza cambios de aceite\n3-Regulador de suspencion");
		}
		else if(regulaSuspenciones > realizaCambioAceite)
		{
			printf("\n2-Regulador de suspencion\n3-Realiza cambios de aceite");
		}
	}
	else if(regulaSuspenciones > realizaCambioAceite && regulaSuspenciones > repararMotores)
	{
		printf("\n1-Regulador de suspencion");
		if(realizaCambioAceite > repararMotores)
		{
			printf("\n2-Realiza cambios de aceite\n3-Reparador de motores");
		}
		else if(repararMotores > realizaCambioAceite)
		{
			printf("\n2-Reparador de motores\n3--Realiza cambios de aceite");
		}
	}
}
