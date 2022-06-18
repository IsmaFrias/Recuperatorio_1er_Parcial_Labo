#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_
#include "Estructuras.h"

/// @brief carga las especialidad harcodedas
/// @param miEspecialidad
void cargarEspecialidad(eEspecialidad miEspecialidad[]);

/// @brief muestra una lista de especialidades
/// @param miEspecialidad
void listaDeEspecialidades(eEspecialidad miEspecialidad[]);

/// @brief muestra un top de especialidades mas estudiadas por mecanico
/// @param miEspecialidad
/// @param miServicios
/// @param sizeServicios
/// @param miMecanicos
void especialidadesMasEstudidasPorMecanico(eEspecialidad miEspecialidad[], eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[]);

#endif /* ESPECIALIDAD_H_ */
