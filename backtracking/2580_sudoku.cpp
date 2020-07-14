#include <stdio.h>
#include <vector>

using namespace std;

bool is_rectangle(vector<vector<int> >v);

void run_sudoku(vector<vector<int> >v, int row, int col) {
    for(int i = 1; i <= 9; i++) {

    }
}

int main() {
    vector<vector<int> > sudoku(9);
    for(int i = 0; i < 9; i++) {
        sudoku[i] = vector<int>(9);
        for(int j = 0; j < 9; j++) scanf("%d", &sudoku[i][j]);
    }
    run_sudoku(sudoku, 0, 0);
    return 0;
}