#include "TADReg.h"
#include "TADCadena.h"
#include <stdio.h>

Reg cargar(){
	Reg aux;
	printf("\nIngrese codigo de repuesto: ");
	scanf("%ld",&aux.codigo);
	fflush(stdin);
	printf("\n Ingrese nombre de repuesto: ");
	leecad(aux.nombre,tamcade);
	fflush(stdin);
	printf("\nIngrese precio unitario de repuesto: ");
	scanf("%f",&aux.preciounidad);
	printf("\nIngrese cantidad de repuesto: ");
	scanf("%d",&aux.unidades);
	return aux;
}
	
	void mostrar_repuesto(Reg rep){
		
			printf("\nCodigo : %ld",rep.codigo);
			printf("\nNombre : %s",rep.nombre);
			printf("\nPrecio : %2f",rep.preciounidad);
			printf("\nStock : %d",rep.unidades);

	}		
int retornar_unidades(Reg rep){
	return rep.unidades;
}			
float retornar_preciorepuesto(Reg rep){
	return rep.preciounidad;
}
void modificarprecio(Reg *rep,float nuevoprecio){
	rep->preciounidad=nuevoprecio;
}	
long retornar_codigo(Reg rep){
	return rep.codigo;
}
