#include "TADReg.h"
typedef Reg Tvecreg[1001];
typedef struct{
	Tvecreg lista;
	int tam;
}T_lista;
T_lista inicializar();
T_lista cargar_vector();
void ordenar_rec(T_lista *A);
void agregar_repuesto(T_lista *);
void mostrar_respuestos(T_lista);
void mostrar_repuestoporcodigo(T_lista);
void modificar_precioporcodigo(T_lista *);
void mostrar_sinstock(T_lista);
void eliminardelalista(T_lista *);
void cantidadconelmismoprecio(T_lista);
