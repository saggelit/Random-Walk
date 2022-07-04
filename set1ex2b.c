#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  int run,n;
  double num,x,y,rr,sumrr,dx2;

  srand(4366);

  sumrr=0.0;
  for(run=1;run<=10000;run++)
    {
      x=0.0;
      y=0.0;
      for(n=1;n<=1000;n++)
	{
	  num=1.0*rand()/(RAND_MAX+1.0);
	  if(num<=0.25)
	    {
	      x=x+1;
	    }
	  else if ((num<=0.5)&&(num>0.25))
	    {
	      x=x-1.0;
	    }
	  else if((num>0.5)&&(num<=0.75))
	    {
	      y=y+1.0;
	    }
	  else
	    {
	      y=y-1.0;
	    }
	  rr=x*x+y*y;
	}
      sumrr=sumrr+rr;
    }
  dx2=sumrr/10000;
  printf("dx^2=%f\n",dx2);
  return(0);
}
