#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Global variables
int n;                                 // Number of vertices
int m;                                 // Number of colors
int graph[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
int x[MAX_VERTICES];                   // Color assignment
int solCount = 0;
int nodeCount = 0;

void initializeGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0; // Set all values to -1 initially
        }
    }
}

void updateUserInput()
{
    int vertice1, vertice2;
    printf("Enter the vertices : \n");
    do
    {
        scanf("%d %d", &vertice1, &vertice2);
        if (vertice1 == -1 && vertice2 == -1)
            return;
        graph[--vertice1][--vertice2] = 1; // Change the value to 1
        graph[vertice2][vertice1] = 1;
    } while (true);
}

bool checkIfCorrect()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 1 && x[i] == x[j])
            {
                return false;
            }
        }
    }
    return true;
}

void mColouring(int k)
{
    for (int i = 0; i < m; i++)
    {
        x[k] = i;
        if (k == n - 1)
        {
            if (checkIfCorrect())
            {
                printf("Solution %d : {", ++solCount);
                for (int i = 0; i < n; i++)
                {
                    i == n - 1 ? printf("%d }", x[i] + 1) : printf("%d ,", x[i] + 1);
                }
                printf("\n");
            }
        }
        else
            mColouring(k + 1);
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    initializeGraph();
    updateUserInput();
    for (int i = 0; i < n; i++)
        x[i] = -1;

    // Print the updated graph (optional)
    printf("Adjacency matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }

    mColouring(0);
    return 0;
}

/*
8 3
1 2 1 4 2 4 2 5 2 6 3 6 3 7 4 5 4 8 5 6 6 7 6 8 -1 -1

*/