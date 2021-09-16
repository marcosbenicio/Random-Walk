#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#define Nsteps   100000   //100000//número total de passos
#define p        0.475
#define Ncam     10000   //10000//número total de caminhantes
#define Nsimu    1       //número de simulações independentes

int main(){

  int n,s,l;
  
  int N[Ncam+1];
  
  double X[Nsteps],XX[Nsteps];
  
  double ran;
  
  unsigned long int m,r,a;
  
  r=27; 
  a=16807;
  //m=2147483647;
  m=4294967296;
  FILE *pta,*ptg;
  
  //sprintf(arquivo,"caminhada.txt");    
  pta=fopen("caminhada_10000caminhantes_p0,475_x_xx.txt","w");
  if(!pta) exit(0); 
  
  ptg=fopen("posicao_final_10000caminhantes_p0,475.txt","w");
  if(!pta) exit(0);
  
  fprintf(pta,"#t\t\t\t\t\t\t#<x>\t\t\t\t\t\t#<x²>\n");
  fprintf(pta,"0\t\t\t\t\t\t0\t\t\t\t\t\t0\n");
  
  for(s=1;s<=Nsteps;s++){ 
    X[s]=0;
    XX[s]=0;
  }          
  
  //for(l=1;l<=Nsimu;l++){  //simulações idependentes       
  	
  	for(n=1;n<=Ncam;n++) N[n]=0;// condição inicial,todos caminhantes começando em zero  		
 		
 		for(s=1;s<=Nsteps;s++){ //loop para passos
   		  
 		  for(n=1;n<=Ncam;n++){ //loop para cada caminhante dar 1 passo
  	 	  r=(r*a)%m; 
  	 	  ran=((double)r)/m;    	     
  	 		if(ran<=p){
  	    
  	   	  N[n]++;
  	   	   
  	    } 
  	 	  else{
  	 	    
  	   	  N[n]--;
  	    }
  	    X[s]=X[s]+(double)N[n]/Ncam;
  	    XX[s]=XX[s]+(double)N[n]*N[n]/Ncam;
  	  }           		   
  	}
  //}  
  for(n=1;n<=Ncam;n++){
     fprintf(ptg,"%d\n",N[n]);
  }
  for(s=1;s<=Nsteps;s++){ //loop para imprimir os valores
	  fprintf(pta,"%d\t\t\t\t\t\t%lf\t\t\t\t\t\t%lf\n",s,(double)X[s],(double)XX[s]);
  }
 	 fclose(pta);
 	 fclose(ptg);   

}   





