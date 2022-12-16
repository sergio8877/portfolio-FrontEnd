#include "TADVecReg.h"
#include <stdio.h>
T_lista inicializar(){
	T_lista aux;
	aux.tam=0;
	return aux;
}
	void ordenarseguncodigo(Tvecreg v,int tam){
		int j;
		v[0]=v[tam];
		j=tam-1;
		while(retornar_codigo(v[0])<retornar_codigo(v[j])){
			v[j+1]=v[j];
			j--;
		}
		v[j+1]=v[0];
	}
void carga_rec(Tvecreg v,int tam){
	if(tam>0){
		carga_rec(v,tam-1);
		v[tam]=cargar();	
	}
}		
T_lista cargar_vector(){
	
	T_lista v;
	v=inicializar();
	printf("\nIngresar cantidad a cargar: ");
	scanf("%d",&v.tam);
    carga_rec(v.lista,v.tam);
	
	
	return v;
}
void qsortrec(Tvecreg v,int ini,int fin){
		int izq,der,med;
		Reg piv;
		if(ini<fin){
			izq=ini;
			der=fin;
			piv=v[ini];
			while(izq<der){
				while(der>izq&&retornar_codigo(v[der])>retornar_codigo(piv))
					der--;
				if(der>izq){
					v[izq]=v[der];
					izq++;
				}
				while(izq<der&&retornar_codigo(v[izq])<retornar_codigo(piv))
				   izq++;
				if(izq<der){
					v[der]=v[izq];
						der--;
				}
			}
			v[der]=piv;
			med=der;
			qsortrec(v,ini,med-1);
			qsortrec(v,med+1,fin);
		}
	}
void	ordenar_rec(T_lista *A){
		int ini,fin;
		ini=1;
		fin=A->tam;
			qsortrec(A->lista,ini,fin);
	}	

	void mostrar_respuestos(T_lista a){
		int i;
		for(i=1;i<=a.tam;i++){
			mostrar_repuesto(a.lista[i]);
		}
	}	
		
int busqueda(T_lista a,long cod){
	int pos=0,i;
	for(i=1;i<=a.tam;i++){
		if(retornar_codigo(a.lista[i])==cod){
			pos=i;
		}
	}
	return pos;
}
	void agregar_repuesto(T_lista *a){
		a->tam=a->tam+1;
		a->lista[a->tam]=cargar();
		ordenarseguncodigo(a->lista,a->tam);
	}	
void mostrar_repuestoporcodigo(T_lista a){
	int pos;
	long cod;
	printf("\nIngrese codigo para mostrar el repuesto: ");
	scanf("%ld",&cod);	
	pos=busqueda(a,cod);
	if(pos!=0){
		mostrar_repuesto(a.lista[pos]);
	}
	else {
		printf("\nNo existe repuesto.");
	}
	
}
	void modificar_precioporcodigo(T_lista *a){
		int pos;
		long cod;
		float prec;
		printf("\nIngrese codigo para modificar el precio del repuesto: ");
			scanf("%ld",&cod);
			printf("\nIngrese nuevo precio : ");
			scanf("%f",&prec);
			pos=busqueda(*a,cod);
		if(pos!=0){
			
			modificarprecio(&a->lista[pos],prec);
			mostrar_repuesto(a->lista[pos]);
		}
		else {
			printf("\nNo existe repuesto.");
		}
		
	}
	void mostrar_sinstock(T_lista a){
		int i,b=0;
		for(i=1;i<=a.tam;i++){
		if(retornar_unidades(a.lista[i])==0){
			mostrar_repuesto(a.lista[i]);
			b=1;
		}
			
		}
		if(b==0){
			printf("\nNo existe repuestos sin stock.");
		}
	}
		int BBR(Tvecreg vec, int ini, int fin,long Bus)
		{
			int med;
			med=(ini+fin)/2;
			if (ini<=fin)
				if ( Bus==retornar_codigo(vec[med])) return med;
				else
					if(Bus<retornar_codigo(vec[med]))
					return BBR(vec, ini, (med-1), Bus);
					else
						return BBR(vec, (med+1),fin , Bus);
					else return -1;
		}
		int posbus(T_lista A){
			int ini=1,fin,pos;
			fin=A.tam;
			long P;
			printf("\nIngrese codigo.");
				scanf("%ld",&P);
			pos=BBR(A.lista,ini,fin,P);
				return pos;	
		}
			void corrimientorec(Tvecreg v,int tam,int pos){
				if(tam>=pos){
					corrimientorec(v,tam-1,pos);
						v[tam]=v[tam+1];	
				}
				
			}
				void corrimiento(T_lista *A,int pos){
					int N=A->tam;
					corrimientorec(A->lista,N,pos);
					A->tam=A->tam-1;
				}
					void eliminardelalista(T_lista *A){
						int pos;
						pos=posbus(*A);
						corrimiento(A,pos);
					}	
						void contarcorr(Tvecreg v,int tam,int *c,float corr){
							if(tam>0){
								if( corr==retornar_preciorepuesto(v[tam])){
									*c=*c+1;
								}
								contarcorr(v,tam-1,c,corr);
								
							}
							
						}	
						void cantidadconelmismoprecio(T_lista A){
							float corr;
							int c=0;
							printf("\nIngrese preciod de unidad:");
							scanf("%f",&corr);
							contarcorr(A.lista,A.tam,&c,corr);
							printf("\nCantidad de repuestos con el mismo precio: %d",c);
						}			
