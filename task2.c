#include <stdio.h>

/* Function declarations */
void readMatrix(int a[10][10], int r, int c);
void printMatrix(int a[10][10], int r, int c);
void addMatrix(int a[10][10], int b[10][10], int r, int c);
void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2);
void transposeMatrix(int a[10][10], int r, int c);

int main() {
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;
    int choice;

    printf("Matrix Operations Menu:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:   // Addition
            printf("Enter rows and columns of matrices: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of Matrix A:\n");
            readMatrix(A, r1, c1);

            printf("Enter elements of Matrix B:\n");
            readMatrix(B, r1, c1);

            addMatrix(A, B, r1, c1);
            break;

        case 2:   // Multiplication
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Multiplication not possible!\n");
                return 0;
            }

            printf("Enter elements of Matrix A:\n");
            readMatrix(A, r1, c1);

            printf("Enter elements of Matrix B:\n");
            readMatrix(B, r2, c2);

            multiplyMatrix(A, B, r1, c1, r2, c2);
            break;

        case 3:   // Transpose
            printf("Enter rows and columns of Matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of Matrix:\n");
            readMatrix(A, r1, c1);

            transposeMatrix(A, r1, c1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

/* Function definitions */

void readMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void printMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int i, j, sum[10][10];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResult of Matrix Addition:\n");
    printMatrix(sum, r, c);
}

void multiplyMatrix(int a[10][10], int b[10][10],
                    int r1, int c1, int r2, int c2) {
    int i, j, k;
    int mul[10][10] = {0};

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    printMatrix(mul, r1, c2);
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j, t[10][10];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("\nTranspose of Matrix:\n");
    printMatrix(t, c, r);
}
