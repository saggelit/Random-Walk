#include<stdio.h>
#include<stdlib.h>

#define runs 10000
#define a 1000 // plegma
#define steps 1000 
#define b 10

int main()
{
  int x,y,run,i,k,l,t;
  double num;
  
  int (*plegma)[a]=malloc(sizeof(int[a][a]));
  double *s=malloc(b*sizeof(double));
  srand(4366);

  FILE *data;
  data=fopen("data5_2D.txt","w");
  
  for(i=0;i<b;i++) s[i]=0.0;
  
  for(run=0;run<runs;run++)
    {
      for(k=0;k<a;k++)
	{
	  for(l=0;l<a;l++)
	    {
	      plegma[k][l]=0;
	    }
	}
      x=a/2;
      y=a/2;
      plegma[x][y]=1;
      s[0]=s[0]+1;
      for(i=0;i<b;i++)
	{
	  for(t=0;t<100;t++) // xwrizw ta 1000steps se b=10 100staria
	    {
	      num=1.0*rand()/RAND_MAX;
	      if(num<=0.25) x=x-1;
	      if((num<=0.5)&&(num>0.25)) x=x+1;
	      if((num<=0.75)&&(num>0.5)) y=y-1;
	      if((num<=1.0)&&(num>0.75)) y=y+1;
	      if(x>=a) x=x-a;
	      if(x<0) x=x+a;
	      if(y>=a) y=y-a;
	      if(y<0) y=y+a;
	      if(plegma[x][y]!=1)
		{
		  plegma[x][y]=1;
		  s[i]=s[i]+1;
		}
	    }
	}
    }
  for(i=1;i<10;i++)
    {
      s[i]=s[i]+s[i-1]; //ekfrazei th desmeumenh pithanothta
    }
  for(i=0;i<10;i++)
    {
      printf("%d\t%f\n",(i+1)*100,s[i]/runs);
      fprintf(data,"%d\t%f\n",(i+1)*100,s[i]/runs);
    }
  free(plegma);
  free(s);
  fclose(data);
}
