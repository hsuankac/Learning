#include <stdio.h>

void spiralPrint(int rows, int cols, int matrix[rows][cols]) {
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Print top row
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Print bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Print left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    printf("\n");
}

int main() {
    printf("Spiral traversal of 3x4 matrix:\n");
    int matrix1[3][4] = {
        { 1,  2,  3,  4 },
        { 5,  6,  7,  8 },
        { 9, 10, 11, 12 }
    };
    spiralPrint(3, 4, matrix1);

    printf("\nSpiral traversal of 4x2 matrix:\n");
    int matrix2[4][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    spiralPrint(4, 2, matrix2);

    return 0;
}
