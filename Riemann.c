#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "function.h"

void Pn(double a,double b,double dx,double ptr[])
{
    int n= fabs(a-b)/dx; //Find the distance 
    

    for(int i=0; i<=n; i++) // calculating partition vector
    {
        //printf("%lf \n",i * dx); Debug
        ptr[i] = i * dx;
    }      
}

double U(double ptr[],int n) //Upper sum
{
   double output = 0;
   for(int i=0; i<=n; i++)
   {
      output += f(ptr[i+1]) * (ptr[i+1] - ptr[i]);
      //printf("i:%d %lf \n",i,output); Debug
   }
   return output;
}

double L(double ptr[],int n) //Lower sum
{
   double output = 0;
   for(int i=0; i<=n; i++)
   {
      output += f(ptr[i]) * (ptr[i+1] - ptr[i]);
      //printf("i:%d %lf \n",i,output); Debug
   }
   return output;
}


int main()
{
    FILE *fp; //File pointer
    double a,b,dx; //Variable declaration 

    printf("Insert a:\n");
    scanf("%lf",&a);
    printf("Insert b:\n");
    scanf("%lf",&b);
    printf("Insert dx:\n");
    scanf("%lf",&dx);

    int n= fabs(a-b)/dx; //Find the distance 
    double *ptr;
    ptr = (double*) malloc(n * sizeof(double)); //Dynamic  memory allocation
    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } 

    Pn(a,b,dx,ptr);
    
    //File writing
    fp =fopen("output.txt","a"); //Open in append mode 
    fprintf(fp,"\n a:%d b:%d dx:%lf U:%lf L:%lf U-L:%lf",(int)a,(int)b,dx,U(ptr,n),L(ptr,n),U(ptr,n)-L(ptr,n));

    fclose(fp);

    

    free(ptr);
}
