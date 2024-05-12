#include<stdio.h>
#include<string.h>
#define MAX 100
char p[MAX];
char t[MAX];
int f[MAX];
int cmp[MAX]={0},cnt=0;
int store,m,n;

void space(int sp){
    if(sp==0)
        return;
    for(int i=0;i<sp;i++){
        printf("    ");
    }
}
void showstr(char *s){
    printf("|");
    for(int i=0;i<strlen(s);i++){
        printf(" %c |", s[i]);
    }
}
void FailureFunction(int m) {
    f[0] = 0;
    int i = 1, j = 0;
    printf("Failure Function (f[]): ");
    while (i < m) {
        if (p[i] == p[j]) {
            f[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = f[j - 1];
        } else {
            f[i] = 0;
            i++;
        }
    }
    for (int k = 0; k < m; k++)
        printf("%d ", f[k]);
    printf("\n");
}

int KMP(int m, int n) {
    FailureFunction(m);
    printf("\n");
    showstr(t);
    printf("\n\n");
    int i = 0, j = 0, tmp,s=0;
    while (i < n) {
        if(s==i){
        space(s);
        showstr(p);
        tmp = cnt;
        }
        
        cnt++;
        if (t[i] == p[j]) {
            if (j == m - 1){
                printf("\n");
                space(s);
                for(int b=s; b<=i; b++)
                    printf(" %2d ", ++tmp);
                s=i;
                return i-m+1;
                }
            i++;
            j++;
        } 
        else if (j > 0) {
            j = f[j - 1];
                printf("\n");
                space(s);
                for(int b=s; b<=i; b++)
                    printf(" %2d ", ++tmp);
                printf("\n\n");
                s=i;
        } 
        
        else {
                printf("\n");
                space(s);
                // printf("%d %d %d", j,s,i);
                for(int b=s; b<=i; b++)
                    printf(" %2d ", ++tmp);
                printf("\n\n");        
            i++;
            s=i;
        }
    }
    return -1;
}
int main() {
    printf("Enter the text: ");
    scanf("%s", t);
    printf("Enter the pattern: ");
    scanf("%s", p);
     m = strlen(p);
     n = strlen(t);
    int i = KMP(m,n);
    printf("\nThe index where the pattern is found is: %d",i);
    printf("\nTotal no. of Comparisons: %d\n",cnt);
    return 0;
}

/*
110123110022311312012
13120
*/