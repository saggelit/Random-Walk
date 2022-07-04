#include<stdio.h>
#include<stdlib.h>

#define runs 10000
#define a 1000 // plegma
#define steps 1000 
#define b 10 //mikos pinaka

int main()
{
  int x,run,i,k,t;
  double num;

  int *plegma=malloc(a*sizeof(int));
  double *s=malloc(b*sizeof(double));
  srand(4366);

  FILE *data;
  data=fopen("data5_1D.txt","w");
  
  for(i=0;i<b;i++) s[i]=0.0;
  
  for(run=0;run<runs;run++)
    {
      for(k=0;k<a;k++) plegma[k]=0;
      x=a/2;
      plegma[x]=1;
      s[0]=s[0]+1;
      for(i=0;i<b;i++)
	{
	  for(t=0;t<steps/b;t++) // xwrizw ta 1000steps se b=10 100staria
	    {
	      num=1.0*rand()/RAND_MAX;
	      if(num>=0.5) x=x+1;
	      if(num<0.5) x=x-1;
	      if(x>=a) x=x-a;
	      if(x<0) x=x+a;
	      if(plegma[x]!=1)
		{
		  plegma[x]=1;
		  s[i]=s[i]+1;
		}
	    }
	}
    }
  for(i=1;i<10;i++)
    {
      s[i]=s[i]+s[i-1]; //ekfrazei th desmeumenh pithanothta
    }
  for(i=0;i<b;i++)
    {
      printf("%d\t%f\n",(i+1)*100,s[i]/runs);
      fprintf(data,"%d\t%f\n",(i+1)*100,s[i]/runs);
    }
  free(plegma);
  free(s);
  fclose(data);
}
