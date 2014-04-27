#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int i;
float n_puntos;
float u_inicial;
float x_min;
float x_max;
int puntos;

n_puntos=1000.0;
puntos=(int)n_puntos;
float x[puntos];
x[0]=0;
u_inicial=exp(-((x-0.3)*(x-0.3))/0.01);
paso=(x_max-x_min)/n_puntos;
for(i=1;i<n_puntos+1;i++){
    x[i]=x[i-1]+paso;
}
printf("%f\n",x[3]);
