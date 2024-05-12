#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum boolean {true = 1, false = 0}bool;

int *x;
int n;
int solCount = 0, firstSol = 0;;
int *y;

bool Place(int k,int i )
{
    for(int j = 0; j < k ; j++)
    {
        if((x[j] == i) || (abs(x[j]-i) == abs(j -k)))
            return false;
    }
    return true;
}

void N_Quueens(int k)
{
    int i;
    if(k == n)
        return;
    for( i = 0; i < n; i++)
    {
        if(Place(k,i))
        {
            x[k] = i;
            if(k != n-1)
            {
                N_Quueens(k+1);
            }
            else {
                if(firstSol == 0)
                {
                    for(int j = 0; j<n; j++)
                    {
                        y[j] = x[j];
                    }
                    firstSol = 1;
                }
                solCount++;
            }
        }
    }
    
}

int main()
{
    int totalNCount;
    printf("Enter the number of n queens : ");
    scanf("%d",&totalNCount); printf("\n");
    x = malloc(sizeof(int)*totalNCount);
    y = malloc(sizeof(int)*totalNCount);
    for(int i=0; i<totalNCount; i++)
    {
        x[i] = -1;
        y[i] = -1;
    }
    n = 1;
    for(int i=0; i<totalNCount; i++)
    {
        N_Quueens(0);
        if(solCount !=0)
        {
            printf("%d - Queens problem soution\n",n);
            printf("Total Number of solutions : %d\n",solCount);
            printf("solution : { ");
            for(int j=0; j<n; j++)
            {
                if(j != n-1)
                    printf("%d,",y[j]+1);
                else
                    printf("%d",y[j]+1);
            }
            printf(" }\n");
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n ; k++)
                {
                    if(k == y[j])
                        printf(" Q ");
                    else
                        printf(" * ");
                }
                printf("\n");
            }
            firstSol = solCount = 0;
        }
        else
        {
            printf("%d - Queens \n",n);
            printf("No solution for %d - Queens\n",n);
        }
        printf("\n");
        n++;
    }
}
