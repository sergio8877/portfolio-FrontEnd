#include "TADCadena.h"
#include <stdio.h>
void leecad(Tcadena c,int tam){
	int j=0,m;
	while(j<tam-1&&(m=getchar())!=EOF&&m!='\n'){
		c[j]=m;
		j++;
	}
	c[j]='\0';
	if(m!=EOF&&m!='\n'){
		while((m=getchar())!=EOF&&m!='\n'){
		}
	}
}
