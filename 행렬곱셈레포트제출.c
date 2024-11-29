#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

void input2DArray(int array[100][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 2 + 1;
        }
    }
}

void print2DArray(int array[100][100], int row, int col) {
    printf("====================\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int s1[100][100], int s2[100][100], int target[100][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            target[i][j] = s1[i][j] + s2[i][j];
        }
    }
}

void subMatrix(int s1[100][100], int s2[100][100], int target[100][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            target[i][j] = s1[i][j] - s2[i][j];
        }
    }
}

int main() {
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];

    int row1, col1, row2, col2;

    srand(time(NULL));
    printf("Input matrix 1 row & col: ");
    scanf("%d %d", &row1, &col1);
    printf("Input matrix 2 row & col: ");
    scanf("%d %d", &row2, &col2);

    if (col1 == row2) {
        printf("Matrix dimensions are compatible.\n");
        
        // Input matrices
        input2DArray(matrix1, row1, col1);
        input2DArray(matrix2, row2, col2);
        
        // Print matrices
        printf("Matrix 1:\n");
        print2DArray(matrix1, row1, col1);
        printf("Matrix 2:\n");
        print2DArray(matrix2, row2, col2);
        
        // Add matrices
        addMatrix(matrix1, matrix2, result, row1, col1);
        printf("Addition Result:\n");
        print2DArray(result, row1, col1);

        // Subtract matrices
        subMatrix(matrix1, matrix2, result, row1, col1);
        printf("Subtraction Result:\n");
        print2DArray(result, row1, col1);
    } else {
        printf("Matrix dimensions are not compatible for operations.\n");
    }

    return 0;
}
