/**********************************************************/
/* Programma sto opoio pragmatopoioume tyxaia diadromh    */
/* gia 1000 vhmata se 2D kai theloume na prosdiorisoume   */
/* to meso tetragwno ths metatopishs <R^2>, ana 100 vhmata*/
/* theloume to m.o. gia 10.000 runs se 2D                 */
/**********************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define a 10
int main()
{
  int i,n,run;
  double x,y,num;
  srand(4366);

  FILE *data;
  data=fopen("data3b.txt","w");
  double *rr=malloc(a*sizeof(double));
  //double *mrr=malloc(a*sizeof(double));
  for(i=0;i<10;i++){
    rr[i]=0.0;
    // mrr[i]=0.0;
  }
  
  for(run=1;run<=10000;run++)
    {
      x=0.0;
      y=0.0;
      for(i=0;i<10;i++)
	{
	  for(n=0;n<100;n++)
	    {
	      num=1.0*rand()/RAND_MAX;
	      if(num<=0.25)
		{
		  x=x+1.0;
		}
	      else if (num<=0.5)
		{
		  x=x-1.0;
		}
	      else if(num<=0.75)
		{
		  y=y+1.0;
		}
	      else
		{
		  y=y-1.0;
		}
	    }
	  rr[i]=rr[i]+x*x+y*y; //rr[100],rr[200],rr[300]......
	  //rr[i]=x*x+y*y;
	  //mrr[i]=mrr[i]+rr[i]/10000; //prosthetheis kathe fora tis meses times
	}
    }
  for(i=0;i<10;i++)
    {
      //printf("mrr[%d]=%.3f",i,mrr[i])
      rr[i]=rr[i]/10000; //mporw na pw mrr[i]=rr[i]/10000 kai na print to mrr[i]
      printf("%d\trr[%d]=%.3f\n",(i+1)*100,i,rr[i]);
      fprintf(data,"%d\t%f\n",(i+1)*100,rr[i]);
    }
  free(rr);
  //free(mrr);
  fclose(data);
  return(0);
}
