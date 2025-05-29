#include <stdio.h>

#define ROWS 3
#define COLS 3

void diagonalTraversal(int matrix[ROWS][COLS]) {
    int i, j;

    // 1. Traverse diagonals starting from first row
    for (int col = 0; col < COLS; col++) {
        i = 0;
        j = col;
        while (i < ROWS && j >= 0) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    // 2. Traverse diagonals starting from last column (excluding first row)
    for (int row = 1; row < ROWS; row++) {
        i = row;
        j = COLS - 1;
        while (i < ROWS && j >= 0) {
            printf("%d ", matrix[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Diagonal Traversal (↘):\n");
    diagonalTraversal(matrix);

    return 0;
}
