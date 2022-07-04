#include<stdio.h>
#include<stdlib.h>

#define runs 10000
#define a 500 // plegma
#define steps 1000 
#define b 10
#define n1 1.0/6.0
#define n2 2.0/6.0
#define n3 3.0/6.0
#define n4 4.0/6.0
#define n5 5.0/6.0

int main()
{
  int x,y,z,run,i,k,l,m,t;
  double num;

  int ***plegma;
  plegma=(int***)malloc(a*sizeof(int **));
  for(i=0;i<a;i++)
    {
      plegma[i]=(int**)malloc(a*sizeof(int*));
      for(k=0;k<a;k++)
	{
	  plegma[i][k]=(int*)malloc(a*sizeof(int));
	}
    }
  
  
  double *s=malloc(b*sizeof(double));
  srand(4366);

  FILE *data;
  data=fopen("data5_3D.txt","w");
  
  for(i=0;i<b;i++) s[i]=0.0;
  
  for(run=0;run<runs;run++)
    {
      for(k=0;k<a;k++)
	{
	  for(l=0;l<a;l++)
	    {
	      for(m=0;m<a;m++)
		{
		  plegma[k][l][m]=0;
		}
	    }
	}
      x=a/2;
      y=a/2;
      z=a/2;
      plegma[x][y][z]=1;
      s[0]=s[0]+1;
      for(i=0;i<b;i++)
	{
	  for(t=0;t<steps/b;t++) // xwrizw ta 1000steps se b=10 100staria
	    {
	      num=1.0*rand()/RAND_MAX;
	      if(num<=n1) x=x-1;
	      if((num<=n2)&&(num>n1)) x=x+1;
	      if(num<=n3&&num>n2) y=y-1;
	      if(num<=n4&&num>n3) y=y+1;
	      if(num<=n5) z=z-1;
	      if(num<=1.0) z=z+1;
	      if(x>=a) x=x-a;
	      if(x<0) x=x+a;
	      if(y>=a) y=y-a;
	      if(y<0) y=y+a;
	      if(z>=a) z=z-a;
	      if(z<0) z=z+a;
	      if(plegma[x][y][z]!=1)
		{
		  plegma[x][y][z]=1;
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
