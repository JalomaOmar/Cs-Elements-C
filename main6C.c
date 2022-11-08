#include <stdio.h>
#include <stdlib.h>

int main() {
	int h;
	printf ("Este programa le indicara lo necesario para que usted pueda renovar su pasaporte \n");
	getchar ();
	printf ("Si su respuesta es \"si\", responda con un \"1\", y si su respuesta es \"no\", responda con un 0 \n");
	getchar ();
	printf ("¿Desea renovar su pasaporte? \n");
	scanf ("%d", &h);
	if (h==0){
		printf ("No hay ninguna indicación adicional \n"); 
	} else {
	int a;
	printf ("Su pasaporte fue expedido antes de 1995? \n");
	scanf ("%d", &a);
	      if (a==1){
	      	printf ("Usted debera acreditar la nacionalidad mexicana e identidad en cualquier oficina de la SRE \n");
	      	return 0;
	      }
	      else {
	      	int b;
	      	printf ("Su pasaporte fue robado, destruido o perdido? \n");
	      	scanf("%d", &b);
	      	if (b==1){
	      		int c;
	      		printf ("Fue robado? \n");
	      		scanf ("%d", &c);
	      		if (c==0){
	      			printf ("Esta deteriorado o mutilado ? \n");
	      			int d;
	      			scanf("%d", &d);
	      			if (d==0){
	      				int e;
	      				printf ("El pasaporte fue destruido? \n");
	      				scanf ("%d", &e);
	      				if (e==0){
	      					printf ("No hay instrucciones especificas para su caso \n");
	      					return 0;
						  }
						else {
							printf ("Usted debera acudir a su SRE mas cercana y acreditar la nacionalidad mexicana e identidad, se le entregara un formato para su llenado de forma gratuita y tendra que entregar el respectivo pasaporte \n");
							return 0;
						}  
					  } else {
					  	printf ("Usted debera acudir a su SRE mas cercana y acreditar la nacionalidad mexicana e identidad, se le entregara un formato para su llenado de forma gratuita y tendra que entregar el respectivo pasaporte \n");
							return 0;
					  }
				} else {
					int f;
				  	printf ("Fue robado en territorio nacional? \n");
				  	scanf ("%d", &f);
				  	if (f==0){
				  		printf ("Usted debera entregar el acta levantada ante la Oficina Consular o autoridad competente del pais. La SRE podra requerirle que el acta este legalizada o apostillada y traducida al español. \n");
				  		return 0;
					  } else {
					  	printf ("Debera levantar un acta ante el Ministerio Publico o autoridad competente y entregarla en original a la SRE, comunicandole a la vez y bajo protesta de decir verdad, el hecho y las circunstancias en que hubiera ocurrido a traves del formato que le sera proporcionada de manera gratuita \n");
					  	return 0;
					  }
				  }
				  
	      	    return 0;
		    } else { 
		    printf ("no hay indicaciones adicionales");
			}
			  }
		  }
	      
		  
	  return 0;
}
