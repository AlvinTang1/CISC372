#include <stdio.h>   
#include <stdlib.h> 
int main(){

 int signed_NumOne,signed_NumTwo,signed_NumThree,i,j,counter;
      unsigned int dim1,dim2,dim3;
      printf("Dimensionality	of	3-D	matrix	===>");
      scanf("%d,%d,%d", &signed_NumOne,&signed_NumTwo,&signed_NumThree);
       dim1 = signed_NumOne;
       dim2 = signed_NumTwo;
       dim3 = signed_NumThree;
       float *OneDim = malloc(dim1*dim2*dim3*sizeof(float));
       float **TwoDim = malloc2D(dim1,dim2*dim3,sizeof(float));
       float ***ThreeDim = malloc3D(dim1,dim2,dim3,sizeof(float));
       float input[dim1*dim2*dim3];
       printf("\n");
      printf("Enter %d Values ",dim1*dim2*dim3);
     for(int i =0;i<dim1*dim2*dim3;i++){
     scanf("%f",&input[i]);
     OneDim[i]=input[i];
      printf("\n");
      }
      counter = 0;
      for( i=0;i<dim1;i++){
      for( j=0; j<dim2*dim3;j++){
    
      TwoDim[i][j] = OneDim[counter];
      counter++;
      }
      }
       for( i=0;i<dim1;i++){
      for( j=0; j<dim2*dim3;j++){
      if(j%(dim2*dim3)==(dim2*dim3-1)){
      if(j%(dim2*dim3)==(dim2*dim3-1) && i%dim1==(dim1-1)){
      
      printf("%0.2f\n",TwoDim[i][j]);
      }
      else{
      printf("%0.2f;",TwoDim[i][j]);
      }}
      else{
      printf("%0.2f,",TwoDim[i][j]);
      }
      
      }}
      memcpy(**ThreeDim,*TwoDim,dim1*dim2*dim3*sizeof(float));
      for(int i=0;i<dim1;i++){
      for(int j=0; j<dim2;j++){
      for(int k=0; k<dim3;k++){
      if(j%(dim2)==(dim2-1)){ 
      if(j%dim2==(dim2-1)&&k%dim3==(dim3-1)){
      printf("%0.2f\n",ThreeDim[i][j][k]);
      }
      else{
      printf("%0.2f;",ThreeDim[i][j][k]);
      }
      }
      else{
      printf("%0.2f,",ThreeDim[i][j][k]);
      } 
      }}}
      free2D(&TwoDim);
      free3D(&ThreeDim);
      free(OneDim);
      }