#include <stdio.h>
#include <stdlib.h>
struct Pair
{
    double p; // Profit
    double w; // Weight
} pair[10000];
int b[101];
int maxm(int a, int b)
{
    return (a > b) ? a : b;
}
int Largest(struct Pair pair[], double w[], int t, int h, int i, int m)
{
    int q, max, mid, u = 0;
    max = 0;
    while (t <= h)
    {
        mid = (t + h) / 2;
        int y = pair[mid].w + w[i];
        if (y > max && y <= m)
        {
            max = pair[mid].w + w[i];
            u = mid;
        }
        if ((pair[mid].w + w[i]) <= m)
            t = mid + 1;
        else
            return u;
    }
    return u;
}
int BinarySearch(struct Pair pair[], int low, int high, double key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (pair[mid].p == key)
            return mid;
        else if (pair[mid].p < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high; // Return the index of the largest value less than or equal to the key
}

void TraceBack(double p[], double w[], struct Pair pair[], int x[], int to, int n)
{
    double totalProfit = pair[b[n + 1] - 1].p;
    double weight = pair[b[n + 1] - 1].w;
    printf(" \nMAX profit=%1.0f\nTotal weight used=%1.0f\n", totalProfit, pair[b[n + 1] - 1].w);
    double remainingWeight = to;
    for (int i = n - 1; i >= 0; i--)
    {
        int index = BinarySearch(pair, b[i], b[i + 1] - 1, totalProfit);
        if (pair[index].p == totalProfit)
        {
            x[i] = 0;
        }
        else
        {
            totalProfit -= p[i + 1];
            weight -= w[i + 1];
            x[i] = 1;
        }
    }
}
void AlgorithmDKnap(double p[], double w[], int x[], int n, int to)
{
    pair[1].p = 0;
    pair[1].w = 0;
    int t = 1;
    int h = 1;
    int next = 2;
    b[0] = 1;
    b[1] = 2;
    for (int i = 1; i <= n; i++)
    {
        int k = t;
        int u = Largest(pair, w, t, h, i, to);
        for (int j = t; j <= u; j++)
        {
            double pp = pair[j].p + p[i];
            double ww = pair[j].w + w[i];
            while (k <= h && pair[k].w < ww)
            {
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
            }
            if (k <= h && pair[k].w == ww)
            {
                if (pp < pair[k].p)
                {
                    pp = pair[k].p;
                }
                k++;
            }

            if (pp > pair[next - 1].p && ww <= to)
            {
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }
            while (k <= h && pair[k].p <= pair[next - 1].p)
                k++;
        }
        while (k <= h)
        {
            pair[next].p = pair[k].p;
            pair[next].w = pair[k].w;
            next++;
            k++;
        }
        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }
    TraceBack(p, w, pair, x, to, n);
    printf("\n\n");
    int cnt = 1;
    for (int i = 0; i < n + 1; i++)
    {
        printf(" S%d: ", i);
        for (int j = b[i]; j < b[i + 1]; j++)
        {
            printf(" (%.0lf,%.0lf ) ", pair[cnt].p, pair[cnt].w);
            cnt++;
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    double p[100]; // Profits
    double w[100]; // Weights
    int x[100];    // Solution vector
    int n;         // Number of items
    int to;        // Maximum weight capacity
    // Input
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the profits of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%lf", &p[i]);
    printf("\n");
    printf("Enter the weights of items:\n");
    for (int i = 1; i <= n; i++)
        scanf("%lf", &w[i]);
    printf("\n");
    printf("Profit : ");
    for (int i = 1; i <= n; i++)
        printf("%1.0f ", p[i]);
    printf("\nWeight : ");
     for (int i = 1; i <= n; i++)
        printf("%1.0f ", w[i]);
    printf("\nEnter the maximum weight capacity: ");
    scanf("%d", &to);
    // Solve the knapsack problem
    AlgorithmDKnap(p, w, x, n, to);
    // Output the solution vector
    printf("Solution vector (1 for selected, 0 for not selected):\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d]=%d ", i + 1, x[i]);
    }
    printf("\n");
    return 0;
}


// 7 28 34 12 17 23 45 35 6 2 8 5 6 4 7 20