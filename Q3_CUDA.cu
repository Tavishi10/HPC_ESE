//Find Factorial of a number using CUDA.
%%cu
#include<stdio.h>
#include<cuda.h>

__global__ void calc_factorial(int *a, long int *fact)
{     
    int i;
    *fact=1;
    for(i=1;i<=*a;i++)
      *fact=*fact * i;
}

int main()
{
  int n=10;
  int *num;
  long int *res, result;  
  cudaMalloc((void**)&num,sizeof(int));
  cudaMalloc((void**)&res,sizeof(long int));
  cudaMemcpy(num,&n,sizeof(int),cudaMemcpyHostToDevice);
  calc_factorial<<<1,3>>>(num,res);
  cudaMemcpy(&result,res,sizeof(long int),cudaMemcpyDeviceToHost);
  printf("\nFactorial of number %d is %ld \n",n,result); 
  cudaFree(num);     
  cudaFree(res);
  return 0; 
}
