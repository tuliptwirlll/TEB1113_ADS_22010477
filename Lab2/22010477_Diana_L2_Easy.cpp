#include <stdio.h>
#include <stdlib.h>

#define R1 2 // number of rows in Matrix-1
#define C1 2 // number of columns in Matrix-1
#define R2 2 // number of rows in Matrix-2
#define C2 2 // number of columns in Matrix-2

void mulMat(int (*m1)[C1], int (*m2)[C2], int (*rslt)[C2]) {
    if (C1 != R2) {
        printf("Invalid Input: Number of columns in Matrix-1 must equal number of rows in Matrix-2.\n");
        return;
    }  
      
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0; // Initialize result matrix element

            for (int k = 0; k < C1; k++) { // Use C1 for multiplication
                rslt[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int m1[R1][C1];
    int m2[R2][C2];
    int rslt[R1][C2]; // Result matrix

    // Input for Matrix-1
    printf("Enter elements of Matrix-1 (%d x %d):\n", R1, C1);
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    // Input for Matrix-2
    printf("Enter elements of Matrix-2 (%d x %d):\n", R2, C2);
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    // Function call to multiply matrices
    mulMat(m1, m2, rslt);

    // Print the result matrix
    printf("Result matrix is:\n");
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d\t", rslt[i][j]);
        }
        printf("\n");
    }

    return 0;
}
