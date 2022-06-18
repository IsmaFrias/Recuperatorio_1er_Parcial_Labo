/*
 ============================================================================
 Name        : Ismael Alejandro Frias
 Parcial     : Recuperatorio 1er Parcial
 División    : B
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputsParcial.h"
#include "Servicios.h"
#include "Mecanicos.h"
#include "Estructuras.h"
#include "Diagnostico.h"
#include "Especialidad.h"
#include "Moneda.h"
#define T 20

int main(void) {
	setbuf(stdout, NULL);

	eServicio miServicios[T];
	eMecanico miMecanicos[T];
	eDiagnostico miDiagnostico[3];
	eEspecialidad miEspecialidad[3];
	eMoneda moneda[3];


	cargarEspecialidad(miEspecialidad);
	cargarDiagnosticos(miDiagnostico);
	inicializarDiagnostico(miServicios, T);
	cargarMecanicos(miMecanicos);
	cargarMonedas(moneda);

	int opcion;
	int retorno;
	int contadorIDs;
	int idMecanico;
	contadorIDs = 0;

	do{
		if(utn_getNumero(&opcion, "\n1-Alta servicio\n2-Modificar servicio\n3-Cancelar servicio\n4-Diagnosticar\n5-Listar\n6-Salir\n\nIngrese una opcion: ",
			"\nError ingrese una opcion valida\n", 0, 6, 50) == 0)

			switch(opcion)
			{
			case 1:
				contadorIDs++;
				retorno = agregarServicio(miServicios, T, contadorIDs);
					switch(retorno)
					{
					case -1:
						printf("\nNo hay mas espacio\n");
					break;
					default:
						printf("\nSe agrego el servicio exitosamente!!!\n");
					break;
					}
			break;

			case 2:
				if(utn_getNumero(&opcion, "\nQue desea modificar?\n1-Nombre del cliente\n2-Fecha del servicio\n3-Mecanico\n\nIngrese una opcion: ",
						"\nError ingrese una opcion valida\n", 1, 3, 50) == 0)
					switch(opcion)
					{
					case 1:
						retorno = buscarServicioPorID(miServicios, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el servicio\n");
						}
						else
						{
							opcion = ModificarNombreDelCliente(miServicios, T, retorno);
							if(opcion != -1)
							{
								printf("\nSe cambio el nombre del cliente exitosamente!!!\n");
							}
							else
							{
								printf("\nSe cancelo la operación\n");
							}
						}
					break;
					case 2:
						retorno = buscarServicioPorID(miServicios, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el servicio\n");
						}
						else
						{
							opcion = ModificarFechaDelServicio(miServicios, T, retorno);
							if(opcion != -1)
							{
								printf("\nSe cambio la fecha del servicio exitosamente!!!\n");
							}
							else
							{
								printf("\nSe cancelo la operación\n");
							}
						}
					break;
					case 3:
						retorno = buscarServicioDiagnosticado(miServicios, T, miMecanicos, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el servicio\n");
						}
						else
						{
							opcion = ModificarMecanico(miMecanicos, T, miServicios, T, miEspecialidad);
							if(opcion == -1)
							{
								printf("\n\nError, debe hacer un diagnostico antes de poder cambiar de mecanico\n");
							}
							else if(opcion == 1)
							{
								printf("\nSe cancelo la operación\n");
							}
							else
							{
								printf("\nSe cambio el mecanico exitosamente!!!\n");
							}
						}
					break;
					}
			break;
			case 3:
				retorno = buscarServicioPorID(miServicios, T);
				if(retorno == -1)
				{
					printf("\nNo se econtro el servicio\n");
				}
				else
				{
					opcion = cancelarServicio(miServicios, T, retorno);
					if(opcion != -1)
					{
						printf("\nSe cancelo el servicio exitosamente!!!\n");
					}
					else
					{
						printf("\nSe cancelo la operación\n");
					}
				}
			break;
			case 4:
				SeparadorConGuionesCorto();
				listaDeMecanicos(miMecanicos, miEspecialidad);
				SeparadorConGuionesCorto();
				retorno = buscarMecanicoPorID(miMecanicos, T);
				idMecanico = retorno;
				if(retorno == -1)
				{
					printf("\nNo se econtro al mecanico\n");
				}
				else
				{
					if(opcion != -1)
					{

						retorno =  buscarServicioNoDiagnosticado(miServicios, T);
						if(retorno == -1)
						{
							printf("\nNo se econtro el servicio\n");
						}
						else
						{
							opcion = diagnosticarServicio(miServicios, T, retorno, miDiagnostico,idMecanico, miMecanicos, moneda);
							if(opcion == -1)
							{
								printf("\n\nError, \n");
							}
							else if(opcion == 1)
							{
								printf("\nSe asigno el diagnostico exitosamente!!! \n");
							}

						}

					}

				}
			break;
			case 5:
				if(utn_getNumero(&opcion, "\n\nQue desea ver?\n\n1-Todos los mecanicos\n2-Todos los servicios\n3-Todos los mecánicos a los cuales no se les haya asignado ningún servicio\n"
						"4-Listado de servicios ordenados por fecha\n5-Fecha determinada, suma de cotizaciones en concepto de cambio de aceite\n"
						"6-Cotización promedio de cada uno de los mecánicos\n7-Cuál/cuáles son los mecánicos que diagnosticaron más servicios\n"
						"8-Servicios ordenados por especialidad del mecánico alfabéticamente\n9-de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada\n"
						"10-Porcentaje de servicio diagnosticados que atiende cada mecánico en función del total de diagnósticos\n"
						"11-Top 3 desperfectos más diagnosticados\n12-Top 3 de especialidades más estudiadas por los mecánicos\n"
						"13-Cliente con su mecanico, diagnostico y moneda\n\nIngrese una opcion: ",
							"\nError ingrese una opcion valida\n", 0, 14, 50) == 0)
					switch(opcion)
					{
						case 1:
							SeparadorConGuionesCorto();
							listaDeMecanicos(miMecanicos, miEspecialidad);
							SeparadorConGuionesCorto();
						break;

						case 2:
							SeparadorConGuionesCorto();
							mostrarListaServicios(miServicios, T);
							SeparadorConGuionesCorto();
						break;
						case 3:
							SeparadorConGuionesCorto();
							listaDeMecanicosSinServicio(miMecanicos, 6, miEspecialidad);
							SeparadorConGuionesCorto();
						break;
						case 4:
							SeparadorConGuionesCorto();
							listadoDeServiciosOrdenadosPorFecha(miServicios, T);
							SeparadorConGuionesCorto();
						break;
						case 5:
							SeparadorConGuionesCorto();
							fechaCotizacionesCambioDeAceite(miServicios, T);
							SeparadorConGuionesCorto();
						break;
						case 6:
							cotizacionPromedioPorMecanico(miServicios, T);
						break;
						case 7:
							SeparadorConGuionesCorto();
							mecanicosConMasServicios(miMecanicos, 6, miServicios, T);
							SeparadorConGuionesCorto();
						break;
						case 8:
							SeparadorConGuionesCorto();
							serviciosOrdenadosPorEspecialidadAlfabeticamente(miServicios, T, miMecanicos,6);
							SeparadorConGuionesCorto();
						break;
						case 9:
							serviciosEntreMarzoYMayo(miServicios, T, miEspecialidad);
						break;
						case 10:
							porcentajeDeDiagnosticosPorMecanicos(miServicios, T);
						break;
						case 11:
							SeparadorConGuionesCorto();
							desperfectosMasDiagnosticados(miDiagnostico, miServicios, T);
							SeparadorConGuionesCorto();
						break;
						case 12:
							SeparadorConGuionesCorto();
							especialidadesMasEstudidasPorMecanico(miEspecialidad, miServicios, T, miMecanicos);
							SeparadorConGuionesCorto();
						break;
						case 13:
							SeparadorConGuionesCorto();
							servciosMonedaYEspecialidad(moneda, miServicios, T, miMecanicos, miDiagnostico);
							SeparadorConGuionesCorto();
						break;
					}
			break;
			}

	}while(opcion != 14);





	return EXIT_SUCCESS;
}
