#ifndef MECANICOS_H_
#define MECANICOS_H_
#include "Estructuras.h"

#define MECANICOLIBRE 0
#define MECANICOOCUPADO 1

/// @brief muestra una lista de mecanicos
/// @param miMecanicos
/// @param miEspecialidad
void listaDeMecanicos(eMecanico miMecanicos[], eEspecialidad miEspecialidad[]);

/// @brief carga los mecanicos hardcodeados
/// @param miMecanicos
void cargarMecanicos(eMecanico miMecanicos[]);

/// @brief busca un mecanico mediante el ID ingresado por el usuario
/// @param miMecanicos
/// @param sizeMecanicos
/// @return retorna el ID del mecanico si lo encontro
int buscarMecanicoPorID(eMecanico miMecanicos[], int sizeMecanicos);

/// @brief modifica el ID del mecanico
/// @param miMecanicos
/// @param sizeMecanicos
/// @param miServicios
/// @param sizeServicios
/// @param miEspecialidad
/// @return retorna un entero si la modificacion fue exitosa
int ModificarMecanico(eMecanico miMecanicos[], int sizeMecanicos, eServicio miServicios[], int sizeServicios, eEspecialidad miEspecialidad[]);

/// @brief muestra una lista de mecanicos que no se les haya asigando ningun diagnostico
/// @param miMecanicos
/// @param sizeMecanicos
/// @param miEspecialidad
void listaDeMecanicosSinServicio(eMecanico miMecanicos[], int sizeMecanicos, eEspecialidad miEspecialidad[]);

#endif /* MECANICOS_H_ */
