#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/*
 * Created by:
 * - Aldo Manco Jr
 * - Alessandro Cancelliere
 */

#define SIZE 9
#define MINUS_INFINITE -2147483648

bool sudokuSolver(int sudokuGrid[][SIZE]);

int main() {

    // SUDOKU WHICH NEEDS TO BE SOLVED

    /*int sudokuGrid[SIZE][SIZE] =
            {{0, 0, 0, 0, 6, 0, 2, 0, 7},
             {6, 7, 8, 0, 0, 0, 0, 0, 5},
             {2, 0, 5, 0, 0, 0, 0, 0, 0},
             {0, 9, 0, 0, 0, 0, 0, 0, 0},
             {0, 2, 0, 7, 3, 0, 0, 5, 0},
             {0, 0, 0, 2, 0, 9, 0, 7, 0},
             {0, 0, 0, 9, 0, 6, 0, 0, 0},
             {0, 0, 0, 0, 5, 0, 4, 3, 0},
             {8, 0, 0, 4, 0, 0, 5, 2, 0}};*/

    // SUDOKU SOLVED

    int sudokuGrid[SIZE][SIZE] =
            {{5, 3, 4, 6, 7, 8, 9, 1, 2},
             {6, 7, 2, 1, 9, 5, 3, 4, 8},
             {1, 9, 8, 3, 4, 2, 5, 6, 7},
             {8, 5, 9, 7, 6, 1, 4, 2, 3},
             {4, 2, 6, 8, 5, 3, 7, 9, 1},
             {7, 1, 3, 9, 2, 4, 8, 5, 6},
             {9, 6, 1, 5, 3, 7, 2, 8, 4},
             {2, 8, 7, 4, 1, 9, 6, 3, 5},
             {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    assert(!sudokuSolver(sudokuGrid));

    return 0;
}

bool sudokuSolver(int sudokuGrid[][SIZE]) {

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE - 1; ++j) {
            for (int k = j + 1; k < SIZE; ++k) {

                if (sudokuGrid[i][j] == sudokuGrid[i][k]) {

                    printf("Two elements on the same row:\n"
                           "#1 Element: (%i, %i)\n"
                           "#2 Element: (%i, %i)",
                           i, j, i, k);

                    return false;
                }

                if (sudokuGrid[j][i] == sudokuGrid[k][i]) {

                    printf("Two elements on the same column:\n"
                           "#1 Element: (%i, %i)\n"
                           "#2 Element: (%i, %i)",
                           j, i, k, i);

                    return false;
                }
            }
        }
    }

    int tmp, counter = 0;

    for (int w = 0, x = 2; w <= 6 && x <= 8; w += 3, x += 3) {
        for (int y = 0, z = 2; y <= 6 && z <= 8; y += 3, z += 3) {
            for (int k = 0; k < 9; ++k) {
                for (int i = w; i <= x; ++i) {
                    for (int j = y; j <= z; ++j) {

                        if (counter==k){
                            tmp=sudokuGrid[i][j];
                            counter++;
                            continue;
                        }

                        if (sudokuGrid[i][j]==tmp){

                            printf("Two elements on the same submatrix\n\n"
                                   "Corners of Submatrix:\n"
                                   "- First Element: (%i, %i);\n"
                                   "- Last Element: (%i, %i)\n\n"
                                   "Elements in conflict: %i, %i",
                                   w, x, y, z, tmp, sudokuGrid[i][j]);

                            return false;
                        }
                        counter++;
                    }
                }
                counter=0;
                tmp=MINUS_INFINITE;
            }
        }
    }
    return true;
}