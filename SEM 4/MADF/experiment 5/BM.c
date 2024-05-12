#include<stdio.h>
#include<string.h>
#define MAX 100
char p[MAX];
char t[MAX];
int cmp[MAX]={0},cnt=0;
int store;

int lastoccurence(char a) {
    int m = strlen(p);
    for(int i = m - 1; i >= 0; i--){
        if(p[i] == a) {
            return i;
        }
    }
    return -1;
}

int min(int a, int b) {
    if(a <= b) {
        return a;
    }
    return b;
}

void space(int sp){
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

int BM(){
    int i,j,m,n,l,s,tmp;
    m = strlen(p);
    n = strlen(t);
    i = j = m-1;
    showstr(t);
    printf("\n\n");
    showstr(p);
    //  printf("%d\n", m);
    //   printf("%d\n", n);
    //    printf("%d\n", j);
    do{
        s=i;
        cnt++;
        if(t[i]==p[j]){
            if(j==0){
                printf("\ti=%d j=%d\n",i,j);
                space(s+j);
                tmp=cnt;
                for(int a=j; a<m; a++)
                    printf(" %2d ", tmp--);
                 printf("\n");
                return i;
            }
            else{
            j--;
            i--;
            }
        }

        else{
            l=lastoccurence(t[i]);
            printf("\ti=%d j=%d l=%d \n",i,j, l);
            space(s);
            tmp=cnt;
            for(int a=j; a<m; a++)
                printf(" %2d ", tmp--);
            printf("\n\n");
            i=i+m-min(j,l+1);
            j=m-1;
            space(i-m+1);
            showstr(p);
        }
    }while(i<n);

    return -1;
}
int main() {
    printf("Enter the text: ");
    scanf("%s", t);
    printf("Enter the pattern: ");
    scanf("%s", p);
     int i = BM();
      printf("\nThe index where the pattern is found is: %d",i);
    printf("\nTotal no. of Comparisons: %d\n",cnt);
    return 0;
}


/*
    abbcdbbabacabdabad
    abdab
*/