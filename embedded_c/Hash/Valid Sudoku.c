#include <stdio.h>
#include <stdbool.h>

#define SIZE                9


bool isValidGroup(int group[SIZE])
{
    bool seen[SIZE] = {false};
    for(int i = 0; i < SIZE; i++)
    {
        int num = group[i];
        if(num == 0) continue; // skip empty cells
        if(num < 1 || num > 9 || seen[num - 1])
        {
            return false;
        }
        seen[num - 1] = true;
    }
    return true;
}

bool isValidSudoku(int board[SIZE][SIZE])
{
    int group[SIZE];

    // check rows
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            group[j] = board[i][j];
        }
        if(!isValidGroup(group)) return false;
    }

    // check columns
    for(int j = 0; j < SIZE; j++)
    {
        for(int i = 0; i < SIZE; i++)
        {
            group[i] = board[i][j];
        }
        if(!isValidGroup(group)) return false;
    }

    // check 3x3 subgrids
    for(int row = 0; row < SIZE; row += 3)
    {
        for(int col = 0; col < SIZE; col += 3)
        {
            int idx = 0;
            for(int i = row; i < row + 3; i++)
            {
                for(int j = col; j < col + 3; j++)
                {
                    group[idx++] = board[i][j];
                }
            }
            if(!isValidGroup(group)) return false;
        }
    }
    return true;
}

int main() {
    // 0 represents an empty cell
    int sudoku[SIZE][SIZE] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (isValidSudoku(sudoku)) {
        printf("Sudoku board is valid.\n");
    } else {
        printf("Sudoku board is invalid.\n");
    }

    return 0;
}