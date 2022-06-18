#include "Servicios.h"
#include <stdio.h>
#include <string.h>
#include "inputsParcial.h"
#include "Estructuras.h"
#include "Moneda.h"
#include "Especialidad.h"


/*****************************************************************************/

int inicializarServicios(eServicio miServicios[], int sizeServicios)
{
	int index;
	index = -1;

	for(int i=0; i<sizeServicios; i++)
			{
				miServicios[i].estado = LIBRE;
				index = i;
				break;
			}
	return index;
}

/*****************************************************************************/

void inicializarDiagnostico(eServicio miServicios[], int sizeServicios)
{
	for(int i=0; i<sizeServicios; i++)
	{
		miServicios[i].estadoDiagnostico = NoDiagnosticado;
	}
}


/*****************************************************************************/


int buscarLugarLibre(eServicio miServicios[], int sizeServicios)
{
	int index;
	index = -1;

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}

/*****************************************************************************/

int agregarServicio(eServicio miServicios[], int sizeServicios, int contadorIDs)
{
	int index;

		index = buscarLugarLibre(miServicios, sizeServicios);

			if(index != -1)
			{
				miServicios[index].identServicio = contadorIDs;
				PedirCadena(miServicios[index].nombreCliente, "Ingrese nombre del cliente: ");
				if(utn_getNumero(&miServicios[index].fecha.dia, "\nIngrese dia (numerico): ", "\nError ingrese un dia valido\n",
						1, 31, 100)==0)
				if(utn_getNumero(&miServicios[index].fecha.mes, "\nIngrese mes (numerico): ", "\nError ingrese un mes valido\n",
						1, 12, 100)==0)
				if(utn_getNumero(&miServicios[index].fecha.anio, "\nIngrese año (numerico): ", "\nError ingrese un año valido\n",
						1990, 2022, 100)==0)
				miServicios[index].estadoDiagnostico = NoDiagnosticado;
				miServicios[index].estado = OCUPADO;
			}
	return index;
}

/*****************************************************************************/

int buscarServicioPorID(eServicio miServicios[], int sizeServicios)
{
	int idServicio;
	int retorno;
	retorno = -1;

			SeparadorConGuionesCorto();
			mostrarListaServicios(miServicios, sizeServicios);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idServicio, "\nIngrese ID del servicio: ",
					"\nError ingrese un ID, valido", 0, 10000, 50)==0)

			for(int i = 0; i<sizeServicios; i++)
			{
				if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio)
				{
					printf("\nSe encontro el servicio a nombre de:  %s",miServicios[i].nombreCliente);
					retorno = idServicio;
				}
			}
	return retorno;
}

/*****************************************************************************/

int ModificarNombreDelCliente(eServicio miServicios[], int sizeServicios, int idServicio)
{
	char nuevoNombre[51];
	char respuesta[5];
	int retorno;
	retorno = -1;

			for(int i = 0; i<sizeServicios; i++)
			{
				if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio)
				{
					fflush(stdin);
					PedirCadena(respuesta, "\nSeguro que desea modificar el nombre de cliente?(si-no): ");
					if(strcmp(respuesta, "si")== 0){
						fflush(stdin);
						PedirCadena(nuevoNombre, "\nIngrese el nuevo nombre de cliente: ");
						strcpy(miServicios[i].nombreCliente, nuevoNombre);
						fflush(stdin);
						retorno = 1;
					}
				}
			}
		return retorno;
}

/*****************************************************************************/

int ModificarFechaDelServicio(eServicio miServicios[], int sizeServicios, int idServicio)
{
	char respuesta[5];
	int retorno;
	retorno = -1;

			for(int i = 0; i<sizeServicios; i++)
			{
				if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio)
				{
					fflush(stdin);
					PedirCadena(respuesta, "\nSeguro que desea modificar la fecha del servicio?(si-no): ");
					if(strcmp(respuesta, "si")== 0)
					{
						if(utn_getNumero(&miServicios[i].fecha.dia, "\nIngrese nuevo dia (numerico): ", "\nError ingrese un dia valido\n",
							1, 31, 100)==0)
						if(utn_getNumero(&miServicios[i].fecha.mes, "\nIngrese nuevo mes (numerico): ", "\nError ingrese un mes valido\n",
							1, 12, 100)==0)
						if(utn_getNumero(&miServicios[i].fecha.anio, "\nIngrese nuevo año (numerico): ", "\nError ingrese un año valido\n",
							1990, 2022, 100)==0)
						retorno = 1;
					}
				}
			}
	return retorno;
}

/*****************************************************************************/

int cancelarServicio(eServicio miServicios[], int sizeServicios, int idServicio)
{
	int eliminado;
	char respuesta[5];
	eliminado = -1;

		for(int i = 0; i<sizeServicios; i++)
		{
			if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio)
			{
				fflush(stdin);
				PedirCadena(respuesta, "Seguro que desea cancelar el servicio?(si-no): ");
				if(strcmp(respuesta, "si")== 0){
					miServicios[i].estado = LIBRE;
					eliminado = 1;
				}
			}
		}
	return eliminado;
}

/*****************************************************************************/

int diagnosticarServicio(eServicio miServicios[], int sizeServicios, int idServicio, eDiagnostico miDiagnosticos[], int idMecanico, eMecanico miMecanicos[], eMoneda moneda[])
{
	int retorno;
	retorno = -1;

		for(int i=0; i<sizeServicios; i++)
		{
			if(miServicios[i].identServicio == idServicio)
			{
				SeparadorConGuionesCorto();
				listaDeDiagnosticos(miDiagnosticos);
				SeparadorConGuionesCorto();
				if(utn_getNumero(&miServicios[i].diagnostico, "\n\nIngrese diagnostico: ",
				"\nError ingrese un diagnostico valido\n", 1, 3, 100)==0)
				SeparadorConGuionesCorto();
				listaDeMonedas(moneda);
				SeparadorConGuionesCorto();
				if(utn_getNumero(&miServicios[i].idMoneda, "\nIngrese tipo de moneda: ", "\nErorr ingrese un tipo de moneda valdia",
						1, 3, 100)==0)
				do{ printf("\nIngrese precio: ");
				}while(validarFloat("%f", &miServicios[i].cotizacion));
				miServicios[i].estadoDiagnostico = Diagnosticado;
				miServicios[i].idMecanico = idMecanico;
				retorno = 1;
					for(int j=0; j<6; j++)
					{
						if(miMecanicos[j].idMecanico == idMecanico)
						{
							miMecanicos[j].estadoMecanico = 1;
						}
					}
				break;
			}
		}
	return retorno;
}

/*****************************************************************************/

void mostrarListaServicios(eServicio miServicios[], int sizeServicios)
{
	int contadorServicios;
	contadorServicios = 0;

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estado == OCUPADO)
		{
			printf("\nID: %-4d  Cliente: %-4s   Fecha: %d/%d/%d\n", miServicios[i].identServicio,
				miServicios[i].nombreCliente, miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
			contadorServicios++;
		}
	}

	if(contadorServicios == 0)
	{
		printf("\nNo hay servicios disponibles");
	}
}

/*****************************************************************************/

int buscarServicioNoDiagnosticado(eServicio miServicios[], int sizeServicios)
{
	int idServicio;
	int retorno;
	retorno = -1;

			SeparadorConGuionesCorto();
			mostrarListaServiciosNoDiagnosticados(miServicios, sizeServicios);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idServicio, "\nIngrese ID del servicio a diagnosticar: ",
					"\nError ingrese un ID, valido", 0, 10000, 50)==0)

			for(int i = 0; i<sizeServicios; i++)
			{
				if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio && miServicios[i].estadoDiagnostico == NoDiagnosticado)
				{
					printf("\nSe encontro el servicio a nombre de:  %s",miServicios[i].nombreCliente);
					retorno = idServicio;
				}
			}
	return retorno;
}

/*****************************************************************************/

void mostrarListaServiciosNoDiagnosticados(eServicio miServicios[], int sizeServicios)
{
	int contadorServicios;
	contadorServicios = 0;

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estado == OCUPADO && miServicios[i].estadoDiagnostico == NoDiagnosticado)
		{
			printf("\nID: %-4d  Cliente: %-4s   Fecha: %d/%d/%d\n", miServicios[i].identServicio,
				miServicios[i].nombreCliente, miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
			contadorServicios++;
		}
	}
		if(contadorServicios == 0)
		{
			printf("\nNo hay servicios disponibles");
		}
}

/*****************************************************************************/

int buscarServicioDiagnosticado(eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], int sizeMecanicos)
{
	int idServicio;
	int retorno;
	retorno = -1;

			SeparadorConGuionesCorto();
			mostrarListaServiciosDiagnosticados(miServicios, sizeServicios);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idServicio, "\nIngrese ID del servicio diagnosticado: ",
					"\nError ingrese un ID, valido", 0, 10000, 50)==0)

			for(int i = 0; i<sizeServicios; i++)
			{
				if(miServicios[i].estado == OCUPADO && miServicios[i].identServicio == idServicio && miServicios[i].estadoDiagnostico == Diagnosticado)
				{
					printf("\nSe encontro el servicio a nombre de:  %s",miServicios[i].nombreCliente);
					retorno = idServicio;
				}
			}
	return retorno;
}

/*****************************************************************************/

void mostrarListaServiciosDiagnosticados(eServicio miServicios[], int sizeServicios)
{
	int contadorServicios;
	contadorServicios = 0;

		for(int i=0; i<sizeServicios; i++)
		{
			if(miServicios[i].estadoDiagnostico == Diagnosticado)
			{
				printf("\nID: %-4d  Cliente: %-4s   Fecha: %d/%d/%d\n", miServicios[i].identServicio,
				miServicios[i].nombreCliente, miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
				contadorServicios++;
			}
		}

		if(contadorServicios == 0)
		{
			printf("\nNo hay servicios disponibles");
		}
}

/*****************************************************************************/

void listadoDeServiciosOrdenadosPorFecha(eServicio miServicios[], int sizeServicios)
{
	eServicio auxiliar;

	for(int i=0; i<sizeServicios-1; i++)
	{
		for(int j=i+1; j<sizeServicios; j++)
		{
			if(miServicios[i].estado == OCUPADO && miServicios[j].estado == OCUPADO)
			{
				if(miServicios[j].fecha.anio > miServicios[i].fecha.anio)
				{	auxiliar = miServicios[j];
					miServicios[j] = miServicios[i];
					miServicios[i] = auxiliar;
				}

				if(miServicios[j].fecha.anio == miServicios[i].fecha.anio)
				{
					if(miServicios[j].fecha.mes > miServicios[i].fecha.mes)
					{
						auxiliar = miServicios[j];
						miServicios[j] = miServicios[i];
						miServicios[i] = auxiliar;
					}
				}
				if(miServicios[j].fecha.anio == miServicios[i].fecha.anio)
				{
					if(miServicios[j].fecha.mes == miServicios[i].fecha.mes)
					{
						if(miServicios[j].fecha.mes > miServicios[i].fecha.mes)
						{
							auxiliar = miServicios[j];
							miServicios[j] = miServicios[i];
							miServicios[i] = auxiliar;
						}
					}
				}

			}
		}
	}
	mostrarListaServicios(miServicios, sizeServicios);
}

/*****************************************************************************/

void fechaCotizacionesCambioDeAceite(eServicio miServicios[], int sizeServicios)
{
	int anio;
	int mes;
	float acumuladorCambioDeAceite;
	acumuladorCambioDeAceite = 0;

	SeparadorConGuionesCorto();
	listadoDeServiciosOrdenadosPorFecha(miServicios,sizeServicios);
	SeparadorConGuionesCorto();

	if(utn_getNumero(&anio, "\nIngrese un año: ", "\nIngrese un año valido", 1990, 2022, 100)==0)
	if(utn_getNumero(&mes, "\nIngrese un mes: ", "\nIngrese un mes valido", 1, 12, 100)==0)

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estadoDiagnostico == Diagnosticado)
		{
			if(miServicios[i].diagnostico == 1 && miServicios[i].fecha.anio == anio && miServicios[i].fecha.mes == mes)
			{
				acumuladorCambioDeAceite = acumuladorCambioDeAceite + miServicios[i].cotizacion;
			}
		}
	}

		if(acumuladorCambioDeAceite == 0)
		{
			printf("\nNo hay sevicios en concepto de cambio de aceite en esta fecha");
		}
		else
		{
			printf("\nLa suma de cotizaciones en concepto de cambio de aceite en el año :%-4d mes: %-4d es de: %.2f", anio, mes, acumuladorCambioDeAceite);
		}
}

/*****************************************************************************/

void cotizacionPromedioPorMecanico(eServicio miServicios[], int sizeServicios)
{
	int contadorJose = 0;
	int contadorManuel = 0;
	int contadorPablo = 0;
	int contadorPedro = 0;
	int contadorJuan = 0;
	int contadorRaul = 0;

	float acumuladorJose = 0;
	float acumuladorManuel = 0;
	float acumuladorPablo = 0;
	float acumuladorPedro = 0;
	float acumuladorJuan = 0;
	float acumuladorRaul = 0;

	float promedioJose;
	float promedioManuel;
	float promedioPablo;
	float promedioPedro;
	float promedioJuan;
	float promedioRaul;


		for(int i=0; i<sizeServicios; i++)
			{
				if(miServicios[i].idMecanico == 1)
				{
					acumuladorJose = acumuladorJose + miServicios[i].cotizacion;
					contadorJose++;
				}
				else if(miServicios[i].idMecanico == 2)
				{
					acumuladorManuel = acumuladorManuel + miServicios[i].cotizacion;
					contadorManuel++;
				}
				else if(miServicios[i].idMecanico == 3)
				{
					acumuladorPablo = acumuladorPablo + miServicios[i].cotizacion;
					contadorPablo++;
				}
				else if(miServicios[i].idMecanico == 4)
				{
					acumuladorPedro = acumuladorPedro + miServicios[i].cotizacion;
					contadorPedro++;
				}
				else if(miServicios[i].idMecanico == 5)
				{
					acumuladorJuan = acumuladorJuan + miServicios[i].cotizacion;
					contadorJuan++;
				}
				else if(miServicios[i].idMecanico == 6)
				{
					acumuladorRaul = acumuladorRaul + miServicios[i].cotizacion;
					contadorRaul++;
				}

			}

		promedioJose = acumuladorJose / contadorJose;
		promedioManuel = acumuladorManuel / contadorManuel;
		promedioPablo = acumuladorPablo / contadorPablo;
		promedioPedro = acumuladorPedro / contadorPedro;
		promedioJuan = acumuladorJuan / contadorJuan;
		promedioRaul = acumuladorRaul / contadorRaul;

		SeparadorConGuionesCorto();
		printf("\nLa cotizacion promedio de Jose es: %.2f", promedioJose);
		printf("\nLa cotizacion promedio de Manuel es: %.2f", promedioManuel);
		printf("\nLa cotizacion promedio de Pablo es: %.2f", promedioPablo);
		printf("\nLa cotizacion promedio de Pedro es: %.2f", promedioPedro);
		printf("\nLa cotizacion promedio de Juan es: %.2f", promedioJuan);
		printf("\nLa cotizacion promedio de Raul es: %.2f", promedioRaul);
		SeparadorConGuionesCorto();
}

/*****************************************************************************/

void serviciosOrdenadosPorEspecialidadAlfabeticamente(eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], int sizeMecanicos)
{

	for(int i=0; i<sizeServicios-1; i++)
	{
		if(miServicios[i].diagnostico == Diagnosticado)
		{
			for(int j=0; j<sizeMecanicos; j++)
			{
				if(miServicios[i].idMecanico == miMecanicos[j].idMecanico)
				{
					if(miMecanicos[j].idEspecialidad == 1)
					{
						printf("\nCliente: %s   Mecanico: %s   Especialidad: %s",miServicios[i].nombreCliente, miMecanicos[j].nombreMecanico, miMecanicos[j].especialidad);
					}
					if(miMecanicos[j].idEspecialidad == 2)
					{
						printf("\nCliente: %s   Mecanico: %s   Especialidad: %s",miServicios[i].nombreCliente, miMecanicos[j].nombreMecanico, miMecanicos[j].especialidad);
					}
					if(miMecanicos[j].idEspecialidad == 3)
					{
						printf("\nCliente: %s   Mecanico: %s   Especialidad: %s",miServicios[i].nombreCliente, miMecanicos[j].nombreMecanico, miMecanicos[j].especialidad);
					}
				}
			}
		}
	}
}

/*****************************************************************************/

void serviciosEntreMarzoYMayo(eServicio miServicios[], int sizeServicios, eEspecialidad miEspecialidad[])
{
	int especialidad;
	int verificacion;
	verificacion = 0;

	SeparadorConGuionesCorto();
	listaDeEspecialidades(miEspecialidad);
	SeparadorConGuionesCorto();
	if(utn_getNumero(&especialidad, "\nIngrese especialidad: ", "\nError ingrese una especialidad valida",
			1, 3, 100)==0)

	for(int i=0; i<sizeServicios; i++)
	{
		if(miServicios[i].estadoDiagnostico == Diagnosticado)
		{
			if(miServicios[i].fecha.anio == 2022 && miServicios[i].fecha.mes >= 3 && miServicios[i].fecha.mes <= 5)
			{
				verificacion = 1;
				if(especialidad == 1 && miServicios[i].diagnostico == 1)
				{
					SeparadorConGuionesCorto();
					printf("Cliente: %s  Fecha: %d/%d/%d  Diagnostico: Cambio de aceite", miServicios[i].nombreCliente,
							miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
					SeparadorConGuionesCorto();
					verificacion = 2;
				}
				else if(especialidad == 2 && miServicios[i].diagnostico == 2)
				{
					SeparadorConGuionesCorto();
					printf("Cliente: %s  Fecha: %d/%d/%d  Diagnostico: Cambio de aceite", miServicios[i].nombreCliente,
							miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
					SeparadorConGuionesCorto();
					verificacion = 2;
				}
				else if(especialidad == 3 && miServicios[i].diagnostico == 3)
				{
					SeparadorConGuionesCorto();
					printf("Cliente: %s  Fecha: %d/%d/%d  Diagnostico: Cambio de aceite", miServicios[i].nombreCliente,
							miServicios[i].fecha.dia, miServicios[i].fecha.mes, miServicios[i].fecha.anio);
					SeparadorConGuionesCorto();
					verificacion = 2;
				}
			}
		}
	}
	if(verificacion == 0)
	{
		SeparadorConGuionesCorto();
		printf("No hay ningun servicio diagnosticado");
		SeparadorConGuionesCorto();
	}
	else if(verificacion == 1)
	{
		SeparadorConGuionesCorto();
		printf("No se encontro ningun servicio de la especialidad seleccionada entre Marzo y Mayo de 2022");
		SeparadorConGuionesCorto();
	}
}

/*****************************************************************************/

void porcentajeDeDiagnosticosPorMecanicos(eServicio miServicios[], int sizeServicios)
{
	int contadorJose = 0;
	int contadorManuel = 0;
	int contadorPablo = 0;
	int contadorPedro = 0;
	int contadorJuan = 0;
	int contadorRaul = 0;
	int contadorServiciosDiag = 0;

	float porcentajeJose;
	float porcentajeManuel;
	float porcentajePablo;
	float porcentajePedro;
	float porcentajeJuan;
	float porcentajeRaul;


		for(int i=0; i<sizeServicios; i++)
		{
			if(miServicios[i].estadoDiagnostico == Diagnosticado)
			{
				contadorServiciosDiag++;
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

	porcentajeJose = (contadorJose * 100) / contadorServiciosDiag;
	porcentajeManuel = (contadorManuel * 100) / contadorServiciosDiag;
	porcentajePablo = (contadorPablo * 100) / contadorServiciosDiag;
	porcentajePedro = (contadorPedro * 100) / contadorServiciosDiag;
	porcentajeJuan = (contadorJuan * 100) / contadorServiciosDiag;
	porcentajeRaul = (contadorRaul * 100) / contadorServiciosDiag;

	printf("\nPorcentaje de Jose: %.2f\n", porcentajeJose);
	printf("Porcentaje de Manuel: %.2f\n", porcentajeManuel);
	printf("Porcentaje de Pablo: %.2f\n", porcentajePablo);
	printf("Porcentaje de Pedro: %.2f\n", porcentajePedro);
	printf("Porcentaje de Juan: %.2f\n", porcentajeJuan);
	printf("Porcentaje de Raul: %.2f\n", porcentajeRaul);
}
