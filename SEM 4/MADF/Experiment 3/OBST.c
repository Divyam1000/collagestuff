#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct identifiers
{
    char* id;
    int num;
} idef;
int count =1;

void PrintHeader(float* p, float* q, idef* ident, int n){
	printf("            ");
	for(int i = 1; i <= n; i++)
		printf("%10s |", &ident[i].id);
	printf("\n");
	printf("            ");
	for(int i = 1; i <= n; i++)
		printf("%10.0f |", p[i]);
	printf("\n");
	for(int i = 0; i <= n; i++)
		printf("%10.0f |", q[i]);
	printf("\n");
	for(int i = 0; i <= 12*(n+1); i++)
		printf("-"); 
	printf("\n");
}

void PrintTable(float **w, float **c, int **r, int k, int m){
	for(int i = 0; i <= k; i++)
		printf("w[%d][%d]=%2.0f |", i, i+m, w[i][i+m]);
	printf("\n");
	for(int i = 0; i <= k; i++)
		printf("c[%d][%d]=%2.0f |", i, i+m, c[i][i+m]);
	printf("\n");
	for(int i = 0; i <= k; i++)
		printf("r[%d][%d]=%2d |", i, i+m, r[i][i+m]);
	printf("\n");
	for(int i = 0; i <= 12*(k+1); i++)
		printf("-"); 
	printf("\n");
}

void print_tree(int i, int j, idef *ident, int **r)
{
    if(i<j)
    {
        if (j - i == 5)
        {
            printf("\n\n     ");
            printf("%s\n    /     \\ \n", &ident[r[i][j]].id);
        }
        print_tree(i, r[i][j] - 1, ident, r);
        if (j - i == 1 && i == 0 && count == 1)
        {
            printf("%s", &ident[r[i][j]].id);
            count++;
        }
        print_tree(r[i][j], j, ident, r);
        if (j - i == 3)
        {
            printf("\t  %s\n", &ident[r[i][j]].id);
        }
    }
}
void part2(int i,int j, idef *ident,int **r)
{
    if(i<j)
    {
        part2(i, r[i][j] - 1,ident,r);
        if(j-i==1&&i==2)
        {
        printf("         /\t\\");
        printf("\n      %s", &ident[r[i][j]]);
        }
        part2(r[i][j], j, ident, r);
        if(j-i==1&&i==4)
        printf("\t%s\n", &ident[r[i][j]]);
    }
}

int Find(float**C, int**R,int i, int j)
{
    float min = INT_MAX;
    int l;
    for(int m=R[i][j-1]; m<=R[i+1][j]; m++)
    {
        if((C[i][m-1] + C[m][j]) < min)
        {
            min = C[i][m-1] + C[m][j];
            l = m;
        }
    }
    return l;
}


void OBST(float**C,float**W, int**R,float *p, float*q, int n)
{
    for(int i=0; i<=n; i++)
    {
        W[i][i] = q[i];
        R[i][i] = 0;
        C[i][i] = 0;
    
        W[i][i+1] = q[i] + q[i+1] + p[i+1];
        R[i][i+1] = i+1;
        C[i][i+1] = q[i] + q[i+1] + p[i+1];
    }
    PrintTable(W,C,R,n,0);

    for(int m=2; m<=n; m++)
    {
        
        for(int i=0; i<n; i++)
        {
            int j = i+m;
            W[i][j] = W[i][j-1] + p[j] + q[j];
            int k = Find(C,R,i,j);
            C[i][j] = W[i][j] + C[i][k-1] + C[k][j];
            R[i][j] = k;
        }
        PrintTable(W,C,R,n-m+1,m-1);
    }
    PrintTable(W,C,R,0,n);
    printf("\n");
}

int main() 
{
    int n;
    float **cost;
    float **W;
    int **R;
    float *p,*q;
    idef *ident;
    
    printf("Enter the number of indentifiers : ");
    scanf("%d",&n);
    
    cost = malloc(sizeof(*cost)*(n+1));
    W = malloc(sizeof(*W)*(n+1));
    R = malloc(sizeof(*R)*(n+1));
    p = malloc(sizeof(float)*(n+1));
    q = malloc(sizeof(float)*(n+1));
    ident = malloc(sizeof(*ident)*(n+1));
    for(int i=0; i<=n+1; i++)
    {
        ident[i].id = malloc(sizeof(*ident[i].id)*10);
        cost[i]=malloc(sizeof(*cost[i])*(n+1));
        W[i]=malloc(sizeof(*W[i])*(n+1));
        R[i]=malloc(sizeof(*R[i])*(n+1));
    }
    
     printf("Enter the list of identifiers: \n");
    for(int i = 1; i <= n; i++)
        scanf("%s",&ident[i].id);

    for(int i=1; i<=n; i++)
    {
        printf("Enter P[%d]: ",i);
        scanf("%f",&p[i]);
    }
    for(int i=0; i<=n; i++)
    {
        printf("Enter Q[%d]: ",i);
        scanf("%f",&q[i]);
    }

    PrintHeader(p,q,ident,n);
    OBST(cost,W,R,p,q,n);
    print_tree(0,n,ident,R);
    part2(0,n,ident,R);

    printf("\n");
    return 0;
}

//5 char float for struct union 5 6 3 5 4 6 4 5 6 5 4
