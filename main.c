#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int rows=3,cols=3;
    int a[rows][cols],b[cols][1],c[rows][1];
    int i,j,size;

    clock_t t;
    t = clock();

    for(i=0;i<rows;i++)
	{
        for(j=0;j<cols;j++)
        {
            a[i][j] = i;
        }
	}

	for(int i=0;i<cols;i++)
        b[i][0]=1;


    printf("Enter chunk size:\n");
    scanf("%d",&size);
    #pragma omp parallel shared(a,b,c) private(i,j)
   {
        #pragma omp for  schedule(static,size)
        for (i=0; i<rows; i=i+1)
        {
            c[i][0]=0.;
            for (j=0; j<cols; j=j+1)
            {
                c[i][0]=(c[i][0])+((a[i][j])*(b[j][0]));
            }
        }
   }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

	printf("Resultant column vector c is \n");
	#pragma omp parallel for default(none) shared(c,rows,cols) private(i,j) num_threads(1)
    for(i=0; i<rows; i++)
    {
        printf("%d\t",c[i][0]);
    }

    printf("\nExecution time: %f",time_taken);

	return 0;
}

