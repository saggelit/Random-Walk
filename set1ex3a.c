#include<stdio.h>
#include<stdlib.h>
#define a 10

int main()
{
  int i,run,n;
  double r,num;
  srand(4366);

  FILE *data;
  data=fopen("data3a.txt","w");
  double *rr=malloc(a*sizeof(double));
  for(i=0;i<10;i++) rr[i]=0.0;
  
  for(run=1;run<=10000;run++)
    {
      r=0.0;
      for(i=0;i<10;i++)
	{
	  for(n=0;n<100;n++)
	    {
	      num=1.0*rand()/(RAND_MAX+1.0);
	      if(num>=0.5) r=r+1.0;
	      if(num<0.5) r=r-1.0;
	    }
	  rr[i]=rr[i]+r*r; //rr[100],rr[200],rr[300]......
	}
    }
  for(i=0;i<10;i++)
    {
      rr[i]=rr[i]/10000;
      printf("%d\trr[%d]=%.3f\n",(i+1)*100,i,rr[i]);
      fprintf(data,"%d\t%f\n",(i+1)*100,rr[i]);
    }
  free(rr);
  fclose(data);
  return (0);
}
