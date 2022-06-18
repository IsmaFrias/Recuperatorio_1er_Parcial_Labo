#ifndef SERVICIOS_H_
#define SERVICIOS_H_
#include "Estructuras.h"

#define LIBRE 0
#define OCUPADO 1
#define Cambio_de_aceite 1
#define Reparacion_de_motor 2
#define Suspencion 3
#define Diagnosticado 1
#define NoDiagnosticado 0


/// @brief iniciliaza los servicios en libre
/// @param miServicios
/// @param sizeServicios
/// @return retorna si se pudo hacer
int inicializarServicios(eServicio miServicios[], int sizeServicios);

/// @brief busca espacio libre en el array
/// @param miServicios
/// @param sizeServicios
/// @return retorn el indice donde hay un espacio libre
int buscarLugarLibre(eServicio miServicios[], int sizeServicios);

/// @brief carga un cliente
/// @param miServicios
/// @param sizeServicios
/// @param contadorIDs
/// @return retorna un entero si la carga fue o no exitosa
int agregarServicio(eServicio miServicios[], int sizeServicios, int contadorIDs);

/// @brief busca un id ingresado por el usuario en el array
/// @param miServicios
/// @param sizeServicios
/// @return retorna el ID si es que lo encontro
int buscarServicioPorID(eServicio miServicios[], int sizeServicios);

/// @brief modifica el nombre del cliente ingresado por ID
/// @param miServicios
/// @param sizeServicios
/// @param idServicio
/// @return retonar un entero si la modificacion fue exitosa
int ModificarNombreDelCliente(eServicio miServicios[], int sizeServicios, int idServicio);

/// @brief modifica la fecha del servicio ingresado por ID
/// @param miServicios
/// @param sizeServicios
/// @param idServicio
/// @return retonar un entero si la modificacion fue exitosa
int ModificarFechaDelServicio(eServicio miServicios[], int sizeServicios, int idServicio);

/// @brief da de baja el servicio ingresado por ID
/// @param miServicios
/// @param sizeServicios
/// @param idServicio
/// @return retonar un entero si la baja fue exitosa
int cancelarServicio(eServicio miServicios[], int sizeServicios, int idServicio);

/// @brief diagnostica un servicio que se haya diagnosticado antes
/// @param miServicios
/// @param sizeServicios
/// @param idServicio
/// @param miDiagnosticos
/// @param idMecanico
/// @param miMecanicos
/// @param moneda
/// @return retorna si la diagnosticacion fue exitosa o no
int diagnosticarServicio(eServicio miServicios[], int sizeServicios, int idServicio, eDiagnostico miDiagnosticos[], int idMecanico, eMecanico miMecanicos[], eMoneda moneda[]);

/// @brief muestra la lista de todos los servicios
/// @param miServicios
/// @param sizeServicios
void mostrarListaServicios(eServicio miServicios[], int sizeServicios);

/// @brief busca un servicio no diagnosticado mediante el ID ingresado
/// @param miServicios
/// @param sizeServicios
/// @return retorna un entero si lo encontro
int buscarServicioNoDiagnosticado(eServicio miServicios[], int sizeServicios);

/// @brief muestra una lista de los servicios que no se han diagnosticado aún
/// @param miServicios
/// @param sizeServicios
void mostrarListaServiciosNoDiagnosticados(eServicio miServicios[], int sizeServicios);

/// @brief inicializa todos los diagnosticos en "no diagnosticaos" por defecto
/// @param miServicios
/// @param sizeServicios
void inicializarDiagnostico(eServicio miServicios[], int sizeServicios);

/// @brief muestra una lista de los servicios diagnosticados
/// @param miServicios
/// @param sizeServicios
void mostrarListaServiciosDiagnosticados(eServicio miServicios[], int sizeServicios);

/// @brief busca un servicio diagnosticaso mediante el ID ingresado
/// @param miServicios
/// @param sizeServicios
/// @param miMecanicos
/// @param sizeMecanicos
/// @return retorna el ID si lo encontro
int buscarServicioDiagnosticado(eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], int sizeMecanicos);

/// @brief muesta una lista de los servicios ordenados por fecha de menor a mayor
/// @param miServicios
/// @param sizeServicios
void listadoDeServiciosOrdenadosPorFecha(eServicio miServicios[], int sizeServicios);

/// @brief muestra una lista de las cotizacion total por cambio de aceite dada una fecha ingresada
/// @param miServicios
/// @param sizeServicios
void fechaCotizacionesCambioDeAceite(eServicio miServicios[], int sizeServicios);

/// @brief muestra una lista de la cotizacion promedio por mecanico
/// @param miServicios
/// @param sizeServicios
void cotizacionPromedioPorMecanico(eServicio miServicios[], int sizeServicios);

/// @brief muestra cual/cuales son los mecanicos con mas servicios
/// @param miMecanicos
/// @param sizeMecanicos
/// @param miServicios
/// @param sizeServicios
void mecanicosConMasServicios(eMecanico miMecanicos[], int sizeMecanicos, eServicio miServicios[], int sizeServicios);

/// @brief muestra una lista de servicios ordenados por especialidad
/// @param miServicios
/// @param sizeServicios
/// @param miMecanicos
/// @param sizeMecanicos
void serviciosOrdenadosPorEspecialidadAlfabeticamente(eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], int sizeMecanicos);

/// @brief muestra una lista de los servicios diagnosticados entre marzo y mayo de 2022 si es que los hay
/// @param miServicios
/// @param sizeServicios
/// @param miEspecialidad
void serviciosEntreMarzoYMayo(eServicio miServicios[], int sizeServicios, eEspecialidad miEspecialidad[]);

/// @brief muestra una lista del porcentaje de diagnosticos por mecanico
/// @param miServicios
/// @param sizeServicios
void porcentajeDeDiagnosticosPorMecanicos(eServicio miServicios[], int sizeServicios);

#endif
