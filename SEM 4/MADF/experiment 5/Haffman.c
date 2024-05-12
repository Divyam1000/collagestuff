#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct node {
    int freq;
    char c;
    struct node *next, *left, *right;
};

char text[MAX];             // Text
struct node *start = NULL;  // Queue
int greatest = 0;           // this holds the greatest freq
int treeCount = 1;          // To keep track of the number of trees formed

void addatend(char c[], int f[], int n) {
    for (int i = 0; i <= n; i++) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->c = c[i];
        temp->freq = f[i];
        temp->next = NULL;
        temp->left = NULL;
        temp->right = NULL;
        
        struct node *ptr = start;
        struct node *prev = NULL;
        while (ptr != NULL && (ptr->freq < temp->freq || (ptr->freq == temp->freq && ptr->c < temp->c))) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev == NULL) {
            temp->next = start;
            start = temp;
        } else {
            temp->next = ptr;
            prev->next = temp;
        }
    }
}

void showlist() {
    printf("\n");
    printf("Queue    :");
    struct node *ptr = start;
    while (ptr != NULL) {
        printf(" %c ", ptr->c);
        ptr = ptr->next;
    }
    printf("\n");
    printf("Frequency:");
    ptr = start;
    while (ptr != NULL) {
        printf(" %d ", ptr->freq);
        ptr = ptr->next;
    }
    printf("\n");
}

void findgreatest() {
    if (start == NULL)
        return;

    struct node *ptr = start;
    greatest = ptr->freq;
    while (ptr != NULL) {
        if (ptr->freq > greatest)
            greatest = ptr->freq;
        ptr = ptr->next;
    }
}

struct node *delfront() {
    if (start == NULL)
        return NULL;

    struct node *temp = start;
    start = start->next;
    return temp;
}

void addafterliketerms(struct node *temp) {
    struct node *ptr = start;
    struct node *prev = NULL;
    while (ptr != NULL && (ptr->freq < temp->freq || (ptr->freq == temp->freq && ptr->c < temp->c))) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev == NULL) {
        temp->next = start;
        start = temp;
    } else {
        temp->next = ptr;
        prev->next = temp;
    }
}

void HuffmanEncoding() {
    if (start == NULL) return;
    int iteration = 1;
    while (start->next != NULL) {
        printf("Iteration %d: ", iteration++);
        showlist();
        struct node *a = delfront();
        struct node *b = delfront();
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->c = '#';
        temp->freq = a->freq + b->freq;
        temp->left = a;
        temp->right = b;
        temp->next = NULL;
        if (temp->freq >= greatest)
            greatest = temp->freq;
        printf("t%d (%c%d) + t%d (%c%d) -> t%d (%c%d)\n", treeCount, a->c, a->freq, treeCount + 1, b->c, b->freq, treeCount + 2, temp->c, temp->freq);
        treeCount += 2;
        addafterliketerms(temp);
    }
}

void printcodes(struct node *root, int path[], int stringlen) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < stringlen; i++)
            printf("%d", path[i]);
        printf("\t%c\n", root->c);
    }
    path[stringlen] = 0;
    printcodes(root->left, path, stringlen + 1);
    path[stringlen] = 1;
    printcodes(root->right, path, stringlen + 1);
}

void printTree(struct node *root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    printf("\n");
    for (int i = 0; i < level; i++)
        printf("    ");
    if (root->c == '#') 
        printf("|----");
    else printf("|---%c", root->c);
    printf("(%d)", root->freq);
    printTree(root->left, level + 1);
}

int main() {
    printf("Enter the text: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0';

    int freq[256] = {0};
    int n = strlen(text);
    for (int i = 0; i < n; i++)
        freq[(int)text[i]]++;

    char arr[MAX];
    int unique_freq[MAX];
    int unique_count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            arr[unique_count] = (char)i;
            unique_freq[unique_count] = freq[i];
            unique_count++;
        }
    }

    addatend(arr, unique_freq, unique_count - 1);
    printf("Initial list: ");
    showlist();

    findgreatest();
    HuffmanEncoding();

    printf("\nHuffman Tree:\n");
    printTree(start, 0);
    printf("\n");

    printf("\nHuffman Codes:\n");
    int path[MAX];
    printcodes(start, path, 0);

    return 0;
}

// three missionaries and three cannibals