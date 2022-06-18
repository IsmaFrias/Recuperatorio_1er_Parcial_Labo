#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_
#include "Estructuras.h"

/// @brief carga los diagnosticos hardcodeados
/// @param miDiagnosticos
void cargarDiagnosticos(eDiagnostico miDiagnosticos[]);

/// @brief muestra una lista de diagnosticos
/// @param miDiagnosticos
void listaDeDiagnosticos(eDiagnostico miDiagnosticos[]);

/// @brief muestra un top 3 de desperfectos mas diagnosticados
/// @param miDiagnosticos
/// @param miServicios
/// @param sizeServicios
void desperfectosMasDiagnosticados(eDiagnostico miDiagnosticos[], eServicio miServicios[], int sizeServicios);

#endif /* DIAGNOSTICO_H_ */
