#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef enum boolean {true = 1, false = 0}bool;

int *x;
int n;
int solCount = 0;

void Write()
{
    int Q_cnt = 1;
    printf("\033[1m\nSolution %d\n",++solCount);
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(x[i] != j)
                printf(" * ");
            else
                printf(" %d ",Q_cnt++);
        }
        printf("\n");
    }
    printf("\033[0m");
}

void Write2(int k, int l)
{
    int Q_cnt = 1;
    printf("\n");
    for(int i=0; i<n ;i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i <= k)
            {
                if(x[i] > j)
                {
                    printf(" - ");
                }
                else if(x[i] == j)
                {
                    printf(" %d ",Q_cnt++);
                }
                else 
                {
                    printf(" * ");
                }
            }
            else
            {
                printf(" * ");
            }
        }
        printf("\n");
    }
}


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
                Write2(k,i);
                N_Quueens(k+1);
            }
            else {
                Write();
            }
        }
    }
    
}

int main()
{
    printf("Enter the size of n queens : ");
    scanf("%d",&n);

    x = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        x[i] = -1;

    printf("\n%d - Queens problem soution\n",n);
    N_Quueens(0);

}
