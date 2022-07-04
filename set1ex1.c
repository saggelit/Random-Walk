/**************************************************/
/* Programma sto opoio upologizoume to m.o. apo N */
/* tyxaious arithmous oi opoioi lambanontai apo   */
/* omoiomorfh katanomh sto [0,1]                  */
/**************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,n=10;
  FILE *data;
  data=fopen("data1.txt","w");
  for(n=10;n<=1000000;)
    {
      double sum=0.0;
      double *a=malloc(n*sizeof(double));
      srand(4366);
      for(i=0;i<n;i++)
	{
	  a[i]=1.0*rand()/RAND_MAX;
	  sum=sum+a[i];
	  // printf("a[%d]=%f\n",i,a[i]);
	}
      printf("n=%d, mo=%.3f\n",n,sum/n);
      fprintf(data,"%d %f\n",n,sum/n);
      n=n*10; //to vhma sto exwteriko loop tethhke edw ws ginomeno
    }
  fclose(data);
}

//na ginei logarithmiki grafiki parastash 
