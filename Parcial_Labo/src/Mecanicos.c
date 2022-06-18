#include <stdio.h>
#include <string.h>
#include "inputsParcial.h"
#include "Mecanicos.h"
#include "Servicios.h"
#include "Estructuras.h"


/*****************************************************************************/

int ModificarMecanico(eMecanico miMecanicos[], int sizeMecanicos, eServicio miServicios[], int sizeServicios, eEspecialidad miEspecialidad[])
{
	char respuesta[5];
	int retorno;
	int bandera;
	retorno = -1;
	bandera = 0;

				for(int i=0; i<sizeMecanicos; i++)
				{
					for(int j=0; j<sizeServicios; j++)
					{
						if(miMecanicos[i].idMecanico == miServicios[j].idMecanico && miServicios[j].estadoDiagnostico == Diagnosticado && bandera == 0)
						{
							fflush(stdin);
							PedirCadena(respuesta, "\nSeguro que desea modificar el mecanico?(si-no): ");
							retorno = 1;
								if(strcmp(respuesta, "si")== 0)
								{
									SeparadorConGuionesCorto();
									listaDeMecanicos(miMecanicos, miEspecialidad);
									SeparadorConGuionesCorto();
									if(utn_getNumero(&miMecanicos[i].idMecanico, "\nIngrese el ID del nuevo mecanico: ", "\nIngrese un ID valido", 1, 6, 100)==0)
									retorno = 2;
									bandera = 1;

								}
						}
					}
				}

	return retorno;
}

/*****************************************************************************/

void cargarMecanicos(eMecanico miMecanicos[])
{
	eMecanico auxiliar[6] = {{1,"Jose", "Reparardor de motor", 2, 0, 0},
							 {2,"Manuel", "Cambio de aceite", 1, 0, 0},
							 {3,"Pablo", "Suspencion", 3, 0, 0},
							 {4,"Pedro", "Cambio de aceite", 1, 0, 0},
							 {5,"Juan", "Suspencion", 3, 0, 0},
							 {6,"Raul", "Reparador de motor", 2, 0, 0}};

			for(int i = 0; i<6; i++)
			{
				miMecanicos[i] = auxiliar[i];
			}
}

/*****************************************************************************/

void listaDeMecanicos(eMecanico miMecanicos[], eEspecialidad miEspecialidad[])
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(miMecanicos[i].idEspecialidad == miEspecialidad[j].idEspecialidad)
			{
					printf("\nID: %-4d    Mecanico: %-4s    Especialidad: %-4s\n", miMecanicos[i].idMecanico, miMecanicos[i].nombreMecanico, miEspecialidad[j].descripcion);
			}
		}
	}
}

/*****************************************************************************/

int buscarMecanicoPorID(eMecanico miMecanicos[], int sizeMecanicos)
{
	int idMecanico;
	int retorno;
	retorno = -1;

			if(utn_getNumero(&idMecanico, "\nIngrese ID del mecanico: ",
					"\nError ingrese un ID, valido", 1, 6, 50)==0)
			for(int i = 0; i<sizeMecanicos; i++)
			{
				if(miMecanicos[i].idMecanico == idMecanico)
				{
					printf("\nSe selecciono al mecanico:  %s", miMecanicos[i].nombreMecanico);
					retorno = idMecanico;
				}
			}
	return retorno;
}

/*****************************************************************************/

void listaDeMecanicosSinServicio(eMecanico miMecanicos[], int sizeMecanicos, eEspecialidad miEspecialidad[])
{
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(miMecanicos[i].estadoMecanico == 0)
			{
				if(miMecanicos[i].idEspecialidad == miEspecialidad[j].idEspecialidad)
				{
					printf("\nID: %-4d    Mecanico: %-4s    Especialidad: %-4s\n", miMecanicos[i].idMecanico, miMecanicos[i].nombreMecanico, miEspecialidad[j].descripcion);
				}
			}
		}
	}
}

/*****************************************************************************/

void mecanicosConMasServicios(eMecanico miMecanicos[], int sizeMecanicos, eServicio miServicios[], int sizeServicios)
{
	int contadorJose = 0;
	int contadorManuel = 0;
	int contadorPablo = 0;
	int contadorPedro = 0;
	int contadorJuan = 0;
	int contadorRaul = 0;
	int mecanicoConMasServicios;

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estadoDiagnostico == 1)
		{
			if(miServicios[i].idMecanico == 1)
			{
				contadorJose++;
			}
			else if(miServicios[i].idMecanico == 2)
			{
				contadorManuel++;
			}
			else if(miServicios[i].idMecanico == 3)
			{
				contadorPablo++;
			}
			else if(miServicios[i].idMecanico == 4)
			{
				contadorPedro++;
			}
			else if(miServicios[i].idMecanico == 5)
			{
				contadorJuan++;
			}
			else if(miServicios[i].idMecanico == 6)
			{
				contadorRaul++;
			}
		}
	}

	if((contadorJose > contadorManuel && contadorJose > contadorPablo && contadorJose > contadorPedro && contadorJose > contadorJuan && contadorJose > contadorRaul) ||
		contadorJose == contadorManuel || contadorJose == contadorPablo || contadorJose == contadorPedro || contadorJose == contadorJuan || contadorJose == contadorRaul)
	{
		mecanicoConMasServicios = contadorJose;
	}
	else if((contadorManuel > contadorJose && contadorManuel > contadorPablo && contadorManuel > contadorPedro && contadorManuel > contadorJuan && contadorManuel > contadorRaul) ||
			contadorManuel == contadorJose || contadorManuel == contadorPablo || contadorManuel == contadorPedro || contadorManuel == contadorJuan || contadorManuel == contadorRaul)
	{
		mecanicoConMasServicios = contadorManuel;
	}
	else if((contadorPablo > contadorJose && contadorPablo > contadorManuel && contadorPablo > contadorPedro && contadorPablo > contadorJuan && contadorPablo > contadorRaul) ||
			contadorPablo == contadorJose || contadorPablo == contadorManuel || contadorPablo == contadorPedro || contadorPablo == contadorJuan || contadorPablo == contadorRaul)
	{
		mecanicoConMasServicios = contadorPablo;
	}
	else if((contadorPedro > contadorJose && contadorPedro > contadorManuel && contadorPedro > contadorPablo && contadorPedro > contadorJuan && contadorPedro > contadorRaul) ||
			contadorPedro == contadorJose || contadorPedro == contadorManuel || contadorPedro == contadorPablo || contadorPedro == contadorJuan || contadorPedro == contadorRaul)
	{
		mecanicoConMasServicios = contadorPedro;
	}
	else if((contadorJuan > contadorJose && contadorJuan > contadorManuel && contadorJuan > contadorPablo && contadorJuan > contadorPedro && contadorJuan > contadorRaul) ||
			contadorJuan == contadorJose || contadorJuan == contadorManuel || contadorJuan == contadorPablo || contadorJuan == contadorPedro || contadorJuan == contadorRaul)
	{
		mecanicoConMasServicios = contadorJuan;
	}
	else if((contadorRaul > contadorJose && contadorRaul > contadorManuel && contadorRaul > contadorPablo && contadorRaul > contadorPedro && contadorRaul > contadorJuan) ||
			contadorRaul == contadorJose || contadorRaul == contadorManuel || contadorRaul == contadorPablo || contadorRaul == contadorPedro || contadorRaul == contadorJuan)
	{
		mecanicoConMasServicios = contadorRaul;
	}

		if(contadorJose == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Jose con: %d diagnosticos\n", contadorJose);
		}
		if(contadorManuel == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Manuel con: %d diagnosticos\n", contadorManuel);
		}
		if(contadorPablo == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Pablo con: %d diagnosticos\n", contadorPablo);
		}
		if(contadorPedro == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Pedro con: %d diagnosticos\n", contadorPedro);
		}
		if(contadorJuan == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Juan con: %d diagnosticos\n", contadorJuan);
		}
		if(contadorRaul == mecanicoConMasServicios)
		{
			printf("\nEl/los mecanicos que diagnosticaron mas servicios es Raul con: %d diagnosticos\n", contadorRaul);
		}
}
