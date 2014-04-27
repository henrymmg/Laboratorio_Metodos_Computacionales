#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

/*Definicion de variables */
  int n=1000; //Numero de puntos
  int i;
  int j;
  int n_tiempo;
  float x[n]; 
  float u_inicial[n]; 
  float u_futuro[n];
  float u_pasado[n];
  float u_presente[n];
  float delta_x;
  float delta_t;
  float c;
  float r;
  FILE *finales;
  FILE *iniciales;
    
/*Archivo para la animacion*/
  char filename1[20]="datos_finales.txt";
  finales=fopen(filename1,"w");
/*Archivo para la grafica*/    
  char filename[20]="datos_iniciales.txt";
  iniciales=fopen(filename,"w");
    
/*Ecuacion u*/
for(i=0;i<n;i++){
   x[i]=((float)i)/((float)n);
   u_inicial[i]= exp( -(( (x[i]-0.3)*(x[i]-0.3) )/ (0.01)) );
   fprintf(iniciales, "%f %f\n", x[i], u_inicial[i]); //Guardo los datos iniciales en archivo .txt
   }
fclose(iniciales);

/*Primera iteracion para condiciones de frontera*/
 delta_x=x[1]-x[0];
 delta_t = 0.0005;
 c=1.0;
 r=c*delta_t/delta_x;

 u_inicial[0]=0.0; //Condiciones de frontera
 u_inicial[n-1]=0.0;
 u_futuro[0]=0.0;
 u_futuro[n-1]=0.0;
    
 for(i=1;i<n-1;i++){
   u_futuro[i] = u_inicial[i] + (pow(r,2)/2.0) * (u_inicial[i+1] - 2.0 * u_inicial[i] + u_inicial[i-1]);
   }

 //Se guardan los valores presentes y anteriores
 for(i=0;i<n;i++){ 
   u_pasado[i]=u_inicial[i];
   u_presente[i]=u_futuro[i];
 }

/*Siguientes iteraciones*/
   n_tiempo = 1000;
    
    for(j=0;j<n_tiempo;j++){
        for(i=1;i<n-1;i++){
	  u_futuro[i] = (2.0*(1.0-pow(r,2)))*u_presente[i] - u_pasado[i] + pow(r,2)*(u_presente[i+1] + u_presente[i-1]);
            fprintf(finales, "%f", u_futuro[i]);
        }
        fprintf(finales,"\n");
    }
 //Se guardan los valores presentes y anteriores
 for(i=0;i<n;i++){ 
   u_pasado[i]=u_presente[i];
   u_presente[i]=u_futuro[i];
 }
fclose(finales);

return 0;

}
