#include <stdio.h>

void readMatrix(int a[10][10], int r, int c) {
    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void displayMatrix(int a[10][10], int r, int c) {
    printf("\nMatrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int sum[10][10];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("\nMatrix Addition:\n");
    displayMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2) {
    int mul[10][10] = {0};

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c2; j++)
            for(int k = 0; k < c1; k++)
                mul[i][j] += a[i][k] * b[k][j];

    printf("\nMatrix Multiplication:\n");
    displayMatrix(mul, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int t[10][10];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            t[j][i] = a[i][j];

    printf("\nTranspose:\n");
    displayMatrix(t, c, r);
}

int main() {
    int a[10][10], b[10][10], r1, c1, r2, c2;

    printf("Enter rows & columns of matrix A: ");
    scanf("%d %d", &r1, &c1);
    readMatrix(a, r1, c1);

    printf("Enter rows & columns of matrix B: ");
    scanf("%d %d", &r2, &c2);
    readMatrix(b, r2, c2);

    addMatrix(a, b, r1, c1);
    multiplyMatrix(a, b, r1, c1, r2, c2);
    transposeMatrix(a, r1, c1);

    return 0;
}
