#include <stdio.h>
#include <vector>

bool flag = false;

bool check_legit(int v[][9], int row, int col, int num) {
    int now_row = (row / 3) * 3;
    int now_col = (col / 3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[now_row + i][now_col + j] == num || v[row][3 * i + j] == num || v[3 * i + j][col] == num) return false;
        }
    }
    return true;
}

void run_sudoku(int v[][9], std::vector<int> zero, int index) {
    //printf("%d ", index);
    if(flag) return;
    if(index == zero.size()) {
        flag = true;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) printf("%d ", v[i][j]);
            printf("\n");
        }
        return;
    }
    int row = zero[index] / 9;
    int col = zero[index] % 9;
    for(int i = 1; i <= 9; i++) { 
        if(flag) return;
        if(check_legit(v, row, col, i)) {
            v[row][col] = i;
            run_sudoku(v, zero, index + 1);
        }
    }
}

int main() {
    int sudoku[9][9];
    std::vector<int> zero;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
            if(sudoku[i][j] == 0) zero.push_back(i * 9 + j);
        }
    }
    run_sudoku(sudoku, zero, 0);
    for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) printf("%d ", sudoku[i][j]);
            printf("\n");
        }
    return 0;
}