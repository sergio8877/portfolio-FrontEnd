#include <stdio.h>
#include "TADVecReg.h"
#include <stdlib.h>
#include "TADCadena.h"
int main(){
	int opcion;
	T_lista A;
	Tcadena  P;
	leecad(P,tamcade);
	printf("%s",P);
	A=cargar_vector();
	ordenar_rec(&A);
	do{
		system("CLS");
		printf("\nIngresar opcion: ");
		printf("\n1. Agregar repuesto. ");
		printf("\n2. Mostrar todos los respuestos. ");
		printf("\n3. Mostrar repuesto segun codigo. ");
		printf("\n4. Modificar precio de un repuesto segun codigo.");
		printf("\n5. Mostrar repuestos sin stock");
		printf("\n6. Eliminar repuesto de la lista.");
		printf("\n7. Mostrar cantidad con el mismo precio.");
		printf("\n0. SALIR.");
		scanf("%d",&opcion);
		switch (opcion){
		case 1:agregar_repuesto(&A);
		break;
		case 2:mostrar_respuestos(A);
		break;
		case 3:mostrar_repuestoporcodigo(A);
		break;
		case 4:modificar_precioporcodigo(&A);
		break;
		case 5:mostrar_sinstock(A);
		break;
		case 6:eliminardelalista(&A);
		break;
		case 7:cantidadconelmismoprecio(A);
		break;
		}
		system("PAUSE");
	} while(opcion!=0);
	
	
	return 0;
}
