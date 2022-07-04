#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int run,n;
  double r1,r2,num1,num2;
  srand(4366);

  FILE *data1;
  data1=fopen("data4_1000.txt","w");
  FILE *data2;
  data2=fopen("data4_500.txt","w");

  for(run=1;run<=100000;run++)
    {
      r1=0.0;
      for(n=0;n<1000;n++)
	{
	  num1=1.0*rand()/(RAND_MAX+1.0); 
	  if(num1>=0.5) r1=r1+1.0;
	  if(num1<0.5) r1=r1-1.0;
	}
      fprintf(data1,"%d\t%f\n",run,r1);

      r2=0.0;
      for(n=0;n<500;n++)
	{
	  num2=1.0*rand()/(RAND_MAX+1.0); 
	  if(num2>=0.5) r2=r2+1.0;
	  if(num2<0.5) r2=r2-1.0;
	}
      fprintf(data2,"%d\t%f\n",run,r2);
    }
  fclose(data1);
  fclose(data2);
}
