#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct solution
{
    int *x;
};
struct solution allSolution[100];
int solutionCount = 0;
int n;
int x[100];
int G[100][100];
int startVertex = 0;
int leafNodeCount = 0;

void InitializeGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = 0; // Set all values to 0 initially
        }
    }
}

void UpdateUserInput()
{
    int vertice1, vertice2;
    printf("Enter the vertices : (-1 -1) to exit\n");
    do
    {
        scanf("%d %d", &vertice1, &vertice2);
        if (vertice1 == -1 && vertice2 == -1)
            return;
        G[--vertice1][--vertice2] = 1; // Change the value to 1
        G[vertice2][vertice1] = 1;
    } while (true);
}

void PrintPath(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", x[i] + 1);
        }
        else
        {
            printf("%d->", x[i] + 1);
        }
    }
}

void StoreSolution(int n)
{
    allSolution[solutionCount].x = malloc(sizeof(int) * (n+1));
    for (int i = 0; i < n; i++)
    {
        allSolution[solutionCount].x[i] = x[i];
    }
    allSolution[solutionCount].x[n] = x[0];
    solutionCount++;
}

void SolutionFound(int n)
{
    x[n]=x[0];
    printf("Leaf Node %3d : ", ++leafNodeCount);
    printf("Path : ");
    PrintPath(n+1); // n+1 because of the extra node at the end to complete the cycle
    printf("(Solution)\n");
    StoreSolution(n);
}

void SolutionNotFound(int k)
{
    printf("Leaf Node %3d : ", ++leafNodeCount);
    printf("Path : ");
    PrintPath(k);
    printf("(Bound)\n");
}

void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == n)
        {
            x[k] = -1;
        }
        if (x[k] == -1)
            return;
        if (G[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 0; j < k; ++j)
            {
                if (x[j] == x[k])
                {
                    SolutionNotFound(k);
                    break;
                }
            }
            if (j == k)
            {
                if (k < n-1 || (k == n-1 && G[x[k]][x[0]] != 0))
                {
                    return;
                }
            }
        }
    } while (true);
}

void Hamiltonian(int k)
{
    do
    {
        NextValue(k);
        if (x[k] == -1)
        {
            return;
        }
        if (k == n - 1)
            SolutionFound(n);
        else
        {
            Hamiltonian(k + 1);
        }
    } while (true);
}

int main()
{

    printf("Enter number of vertices in a the graph : ");
    scanf("%d", &n);

    InitializeGraph();
    printf("Input Graph values : \n");
    UpdateUserInput();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", G[i][j]);
        printf("\n");
    }

    for (startVertex = 0; startVertex < n; startVertex++)
    {
        for (int i = 0; i <= n; i++)
            x[i] = -1;
        x[0] = startVertex;
        printf("\nStart Vertex %d\n", startVertex + 1);
        Hamiltonian(1);
        leafNodeCount = 0;
    }

    printf("\n\nAll the solutions are :\n");
    for (int i = 0; i < solutionCount; i++)
    {
        printf("\nSolution %3d : ", i + 1);
        for (int j = 0; j <= n; j++)
        {
            if (j == n )
            {
                printf("%d", allSolution[i].x[j] + 1);
            }
            else
            {
                printf("%d->", allSolution[i].x[j] + 1);
            }
        }
    }

    return 0;
}

// 7 1 2 1 3 1 7 2 3 2 4 2 5 3 4 3 7 4 6 5 6 6 7 -1 -1

