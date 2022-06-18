#ifndef MONEDA_H_
#define MONEDA_H_

#define Bitcoin 4
#define Tarjeta 5
#define Efectivo 5

/// @brief carga los tipos de monedas hardcodeadas
/// @param moneda
void cargarMonedas(eMoneda moneda[]);

/// @brief muestra los servicios con su moneda, especialidad, moneda y metodo de pago
/// @param moneda
/// @param miServicios
/// @param sizeServicios
/// @param miMecanicos
/// @param miDiagnosticos
void servciosMonedaYEspecialidad(eMoneda moneda[], eServicio miServicios[], int sizeServicios, eMecanico miMecanicos[], eDiagnostico miDiagnosticos[]);
#endif /* MONEDA_H_ */
