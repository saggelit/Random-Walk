#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,run,n;
  double r,num,dx2;

  srand(4366);

  double sum=0.0;
  for(run=1;run<=10000;run++)
    {
      r=0.0;
      for(n=1;n<=1000;n++)
	{
	  num=1.0*rand()/(RAND_MAX+1.0);
	  if(num>=0.5) r=r+1.0;
	  if(num<0.5) r=r-1.0;
	}
      sum=sum+r;
    }
  dx2=sum*sum/10000;
  printf("dx2=%f\n",dx2);
  return(0);
}
