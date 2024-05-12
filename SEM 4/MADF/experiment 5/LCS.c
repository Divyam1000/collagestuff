#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX 20
#define UP_ARROW '^'
#define LEFT_ARROW '<'
#define DIAGONAL_ARROW '\\'

char X[MAX]; //Pattern to be searched to
char Y[MAX]; //Pattern to be searched against
int L[MAX][MAX];//Matrix to store the DP result
int sub1[MAX]; //Solution for left method
int sub2[MAX]; //Solution for right method
int leftSequence[MAX][MAX] = {0}; //Computes if left arrow needed
int upSequence[MAX][MAX] = {0}; //Computes if up arrow needed

int maxleft(int a, int b){
    return (a > b) ? a : b;
}
int maxup(int a, int b){
    return (a >= b) ? a : b;
}
void LCS(int flag) {
    int n = strlen(X);
    int m = strlen(Y);
    for (int i = 0; i <= n; i++)
        L[i][0] = 0;
    for (int j = 0; j <= m; j++)
        L[0][j] = 0;
    if(flag == 0){
        for(int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (X[i - 1] == Y[j - 1]) 
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = maxleft(L[i - 1][j], L[i][j - 1]);
            }
        }
    } 
    else{
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = maxup(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
}
void traverse(int flag){
    int n = strlen(X);
    int m = strlen(Y);
    if (flag == 0) {
        int i = n;
        int j = m;
        int c = L[n][m];
        while (c > 0) {
            if (X[i - 1] == Y[j - 1]) {
                leftSequence[i][j] = DIAGONAL_ARROW;
                sub1[c] = X[i - 1];
                c--; i--; j--;
            } else {
                if (L[i - 1][j] > L[i][j - 1]) {
                    leftSequence[i][j] = UP_ARROW;
                    i--;
                } else {
                    leftSequence[i][j] = LEFT_ARROW;
                    j--;
                }
            }
        }
    } else {
        int i = n;
        int j = m;
        int c = L[n][m];
        while (c > 0) {
            if (X[i - 1] == Y[j - 1]) {
                upSequence[i][j] = DIAGONAL_ARROW;
                sub2[c] = X[i - 1];
                c--; i--; j--;
            } else {
                if (L[i - 1][j] >= L[i][j - 1]) {
                    i--;
                    upSequence[i][j] = UP_ARROW;
                } else {
                    j--;
                    upSequence[i][j] = LEFT_ARROW;
                }
            }
        }
    }
}

int main() {
    
    printf("Enter 2 strings :\n");
    scanf(" %s",X);
    scanf(" %s",Y);
    int n = strlen(X);
    int m = strlen(Y);
    printf("X = %s\nY = %s\n", X, Y);
    LCS(0);
    traverse(0);
    printf("Left Method:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (leftSequence[i][j] == DIAGONAL_ARROW) {
                printf(" %c", DIAGONAL_ARROW); printf("\e[1m%d\e[m",L[i][j]);
            } else if (leftSequence[i][j] == UP_ARROW) {
                printf(" %c", UP_ARROW);printf("\e[1m%d\e[m",L[i][j]);
            } else if (leftSequence[i][j] == LEFT_ARROW) {
                printf("%c ", LEFT_ARROW);printf("\e[1m%d\e[m",L[i][j]);
            } else {
                printf("  %d", L[i][j]);
            }
        }
        printf("\n");
    }
    printf("Longest Subsequence: ");
    for (int i = 1; i <= L[n][m]; i++)
        printf("%c ", sub1[i]);
        
    printf("\n\nUp Methods:\n");
    traverse(1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (upSequence[i][j] == DIAGONAL_ARROW) {
                printf(" %c", DIAGONAL_ARROW);printf("\e[1m%d\e[m",L[i][j]);
            } else if (upSequence[i][j] == UP_ARROW) {
                printf(" %c", UP_ARROW);printf("\e[1m%d\e[m",L[i][j]);
            } else if (upSequence[i][j] == LEFT_ARROW) {
                printf("%c ", LEFT_ARROW);printf("\e[1m%d\e[m",L[i][j]);
            } else {
                printf("  %d", L[i][j]);
            }
        }
        printf("\n");
    }
    printf("Longest Subsequence: ");
    for (int i = 1; i <= L[n][m]; i++)
        printf("%c ", sub2[i]);

    return 0;
}
