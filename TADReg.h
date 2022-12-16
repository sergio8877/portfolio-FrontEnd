#define tamvec 1001
#define tamcade 80
typedef char Tcadena[tamcade];
typedef struct{
	long codigo;
	Tcadena nombre;
	float preciounidad;
	int unidades;
}Reg;
Reg cargar();
void mostrar_repuesto(Reg);
int retornar_unidades(Reg);
void modificarprecio(Reg *,float);
long retornar_codigo(Reg);
float retornar_preciorepuesto(Reg);
