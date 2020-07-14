#include <stdio.h>
#include <vector>

using namespace std;

bool flag = false;

bool check_legit(vector<vector<int> >v, int row, int col, int num) {
    int now_row = (row / 3) * 3;
    int now_col = (col / 3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[now_row + i][now_col + j] == num || v[row][3 * i + j] == num || v[3 * i + j][col] == num) return false;
        }
    }
    return true;
}

void run_sudoku(vector<vector<int> >v, int row, int col) {
    if(flag) return;
    while(v[row][col] != 0) {
        col++;
        if(col >= 9) {
            if(row == 8) {
                for(int i = 0; i < 9; i++) {
                    for(int j = 0; j < 9; j++) printf("%d ", v[i][j]);
                    printf("\n");
                }
                flag = true;
                return;
            }
            col = 0;
            row++;
        }
    }
    for(int i = 1; i <= 9; i++) {
        if(flag) return;
        if(check_legit(v, row, col, i)) {
            v[row][col] = i;
            run_sudoku(v, row, col);
        }
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