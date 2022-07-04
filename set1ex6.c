#include<stdio.h>
#include<stdlib.h>
#define a 500 //megethos plegmatos
#define run 100000 //arithos prosomoiwsewn
#define c 0.0001 //gia c=0.01,c=0.001,c=0.0001

int main()
{
  int i,j,numtrap,xtrap,ytrap,xpart,ypart,min,max,t;
  double num;

  int (*plegma)[a]=malloc(sizeof(int[a][a]));
  int *tau=malloc(run*sizeof(int)); //krataeti ton xrono twn vimatwn
  srand(4366);

  FILE *data;
  data=fopen("data6tau.txt","w");
  FILE *data1;
  data1=fopen("data6distribution.txt","w");
  
  numtrap=a*a*c; //to plithos twn pagidwn
  min=0; //gia tyxaies syntetagmenes pagidwn ENTOS plegamtos
  max=a;

  for(i=0;i<a;i++)
    {
      for(j=0;j<a;j++)
	{
	  plegma[i][j]=0; //mhdenizw oloklhro to plegma
	}
    }
  for(i=0;i<numtrap;i++)
    {
      // xtrap=(min+(float)rand()/(float)(RAND_MAX)*(max-min));
      //ytrap=(min+(float)rand()/(float)(RAND_MAX)*(max-min));
      xtrap=min+rand()%(max-min);
      ytrap=min+rand()%(max-min);
      while(plegma[xpart][ypart]==-1)
	{
	  xtrap=min+rand()%(max-min);
	  ytrap=min+rand()%(max-min);
	}
      plegma[xtrap][ytrap]=-1; //thetw tis pagides ises me -1
      //printf("%d %d \n",xtrap,ytrap);
    }

  for(i=0;i<run;i++) //gia tis 100000 prosomoiwseis......
    {
      tau[i]=0.0; //arxikopoiw ton pinaka twn xronwn
    }
  for(i=0;i<run;i++) //gia kathe swmatidio
    {
      //xpart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // xekina apo tyxaia
      //ypart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // thesh
      xpart=min+rand()%(max-min);
      ypart=min+rand()%(max-min);
      while(plegma[xpart][ypart]==-1)
	{ //synthhkh gia na mhn xekinaei apo pagida
	  //xpart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // xekina apo tyxaia
	  //ypart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // thesh
	  xpart=min+rand()%(max-min);
	  ypart=min+rand()%(max-min);
	}
      
      tau[i]=tau[i]+1; //1h thesh->1os xronos
      while(plegma[xpart][ypart]!=-1) //oso h thesh tou swmatidiou den einai pagida
	{
	  num=1.0*rand()/RAND_MAX;
	  if(num<=0.25)              xpart=xpart-1; //...metakineitai
	  if((num<=0.5)&&(num>0.25)) xpart=xpart+1;
	  if((num<=0.75)&&(num>0.5)) ypart=ypart-1;
	  if((num<=1.0)&&(num>0.75)) ypart=ypart+1;
	  if(xpart>=a) xpart=xpart-a; // an bgei ektos plegmatos to fernw mesa
	  if(xpart<0) xpart=xpart+a;
	  if(ypart>=a) ypart=ypart-a;
	  if(ypart<0) ypart=ypart+a;
	  tau[i]=tau[i]+1; //proxwrhse mia thesh,ayxhsa to xrono kata 1
	}
    }
  t=0;
  for (i=0;i<run;i++)
    {
      if(tau[i]>t)
	t=tau[i];  //briskw to megisto xrono pagideyshs
    }
  printf("t=%d",t);
  t=t+1;//o pinakas tha einai +1 megalyteros apo to megisto xrono gia na mh xanetai to teleytaio
  int *distribution=malloc(t*sizeof(int)); 

  for (i=0;i<t;i++) //gia na mh xanetai to teleytaio swmatidio
    distribution[i]=0; //Arxikopoihsh
  
  for (i=0;i<run;i++)
    distribution[tau[i]]++ ; //briskw to plhthos kathe xronikis timhs
  
  for(i=0;i<run;i++)
      fprintf(data,"%d\t%d\n",i,tau[i]);

  for (i=0;i<t;i++)
    {fprintf(data1,"%d\t%d\n",i+1,distribution[i]);}
  
  free(plegma);
  free(tau);
  free(distribution);
  fclose(data);
  fclose(data1);
}
