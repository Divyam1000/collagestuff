#include <stdio.h>
#define MAX 100
int cnt = 0;
typedef struct
{
    int path[MAX];
    int length;
} Solution;
int graph[MAX][MAX];
int nol = 0, result_count = 0;
Solution solutions[MAX];
void print_path(int path[MAX], int n, int F)
{
    if (F == 1)
    {
        printf("\e[1m%d\e[m", path[1]);
    }
    else
    {
        printf("%d", path[1]);
    }
    for (int i = 2; i < n; i++)
    {
        if (F == 1)
        {
            printf("\e[1m -> %d\e[m", path[i]);
        }
        else
        {
            printf(" -> %d", path[i]);
        }
    }
    if (F == 1)
    {
        printf("\e[1m -> %d -> %d\e[m", path[n], path[1]);
    }
    else
    {
        printf("-> %d", path[1]);
    }
}
void next_val(int path[MAX], int nodes, int k)
{
    do
    {
        path[k] = (path[k] + 1) % (nodes + 1);
        if (path[k] == 0)
        {
            return;
        }
        if (graph[path[k - 1]][path[k]] != 0)
        {
            int j;
            for (j = 1; j < k; j++)
            {
                if (path[j] == path[k])
                {
                    break;
                }
            }
            if (j == k)
            {
                if ((k < nodes) || (k == nodes && graph[path[nodes]][path[1]] != 0))
                {
                    return;
                }
            }
        }
    } while (1);
}
void Hamiltonian(int path[MAX], int nodes, int k)
{
    int c = 0;
    do
    {
        next_val(path, nodes, k);
        if (path[k] != 0)
        {
            c = 1;
        }
        if (path[k] == 0)
        {
            if (c == 0)
            {
                printf(" %3d : ", ++nol);
                print_path(path, k, 0);
                printf("\r\t\t\t\t\t\t\tBound\n");
            }
            return;
        }
        if (k == nodes)
        {
            printf("\e[1m %3d : \e[m", ++nol);
            print_path(path, nodes, 1);
            printf("\r\t\t\t\t\t\t\t\e[1mSOLUTION\e[m\n");
            solutions[result_count].length = nodes;
            for (int i = 1; i <= nodes; i++)
                solutions[result_count].path[i] = path[i];
            result_count++;
        }
        else
            Hamiltonian(path, nodes, k + 1);
    } while (1);
}
int main()
{
    int num_nodes, path[MAX], k;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    for (int i = 1; i <= num_nodes; i++)
    {
        for (int j = 1; j <= num_nodes; j++)
        {
            graph[i][j] = 0;
        }
    }
    int edges[][2] = {
        {1, 2}, {1, 3}, {1, 7}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 7}, {4, 6}, {5, 6}, {6, 7}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);
    for (int i = 0; i < num_edges; i++)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
    }
    for (k = 1; k <= num_nodes; k++)
    {
        path[1] = k;
        for (int i = 2; i <= num_nodes; i++)
            path[i] = 0;
        printf("\nStarting vertex %d\nLeaf |\nNode | \n", k);
        Hamiltonian(path, num_nodes, 2);
        nol = 0;
    }
    printf("\nAll possible solutions :\n");
    for (int i = 0; i < result_count; i++)
    {
        cnt++;
        for (int j = 1; j <= solutions[i].length; j++)
        {
            if (j == solutions[i].length)
                printf("%d -> %d", solutions[i].path[j], solutions[i].path[1]);
            else
                printf("%d -> ", solutions[i].path[j]);
        }
            printf("\n");
    }
    printf("\nTotal number of solutions: %d\n", result_count);
    return 0;
}
