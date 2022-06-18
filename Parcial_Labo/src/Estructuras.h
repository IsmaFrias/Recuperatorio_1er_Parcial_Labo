#ifndef ESTRUCTURAS_H_
#define ESTRUCTURAS_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int identServicio;//PK
	char nombreCliente[50];
	eFecha fecha;
	int diagnostico;//FK
	float cotizacion;
	int idMecanico;//FK
	int estadoDiagnostico;
	int estado;
	int idMoneda;//FK
}eServicio;

typedef struct
{
	int idMecanico;//PK
	char nombreMecanico[50];
	char especialidad[20];
	int idEspecialidad;//FK
	int idServicio;
	int estadoMecanico;
}eMecanico;

typedef struct
{
	int idDiagnostico;//PK
	char descripcion[25];
}eDiagnostico;

typedef struct
{
	int idEspecialidad;//PK
	char descripcion[25];
}eEspecialidad;

typedef struct
{
	int idMoneda;//PK
	char tipoMoneda[25];
	int metodoDePago;
}eMoneda;

#endif /* ESTRUCTURAS_H_ */
