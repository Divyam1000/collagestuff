#include <stdio.h>

typedef struct {
    float p;
    float w;
} PW;

void TraceBack(float p[], float w[], PW pair[], int x[], int m, int n) {
    int i = n - 1, j = m;
    while (i > 0 && j > 0) {
        if (pair[i].p == pair[i - 1].p) {
            x[i] = 0;
        } else {
            x[i] = 1;
            j -= w[i];
        }
        i--;
    }
    x[i] = (j > 0) ? 1 : 0;

    printf("Selected items: ");
    for (i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int Largest(PW pair[], float w[], int t, int h, int i, int m) {
    int u = t;
    float max = 0.0;

    for (int j = t; j <= h; j++) {
        if (w[i] + pair[j].w <= m && pair[j].p > max) {
            max = pair[j].p;
            u = j;
        }
    }
    return u;
}

void DKnap(float p[], float w[], int x[], int n, int m) {
    PW pair[100]; 
    int b[100];
    int t = 1, h = 1, next = 2;

    b[0] = 1;
    pair[1].p = pair[1].w = 0.0;

    for (int i = 0; i < n - 1; i++) {
        int k = t;
        int u = Largest(pair, w, t, h, i, m);

        for (int j = t; j <= u; j++) {
            float pp = pair[j].p + p[i];
            float ww = pair[j].w + w[i];

            while ((k <= h) && (pair[k].w < ww)) {
                pair[next].p = pair[k].p;
                pair[next].w = pair[k].w;
                next++;
                k++;
            }

            if ((k <= h) && (pair[k].w == ww)) {
                if (pp < pair[k].p) pp = pair[k].p;
                k++;
            }

            if (pp > pair[next - 1].p) {
                pair[next].p = pp;
                pair[next].w = ww;
                next++;
            }

            while ((k <= h) && (pair[k].p <= pair[next - 1].p)) {
                k++;
            }
        }

        while (k <= h) {
            pair[next].p = pair[k].p;
            pair[next].w = pair[k].w;
            next++;
            k++;
        }

        t = h + 1;
        h = next - 1;
        b[i + 1] = next;
    }

    TraceBack(p, w, pair, x, m, n);
}

int main() {
    float p[] = {28,34,12,17,23,45,35};
    float w[] = {6,2,8,5,6,4,7};
    int x[7];
    int n = 7, m = 20;

    DKnap(p, w, x, n, m);

    printf("Selected items: ");
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}
