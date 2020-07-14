#include <stdio.h>
#include <vector>

using namespace std;

bool flag = false;

bool rectangle_is_legit(vector<vector<int> >v, int row, int col, int num) {
    int now_row = (row / 3) * 3;
    int now_col = (col / 3) * 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(v[now_row + i][now_col + j] == num) return false;
        }
    }
    return true;
}

bool row_col_is_legit(vector<vector<int> >v, int row, int col, int num) {
    for(int i = 0; i < 9; i++) {
        if(v[row][i] == num || v[i][col] == num) return false;
    }
    return true;
}

void print_matrix(vector<vector <int> >v) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) printf("%d", v[i][j]);
        printf("\n");
    }
    return;
}

void run_sudoku(vector<vector<int> >v, int row, int col) {
    //printf("(%d, %d)\n", row, col);
    while(v[row][col] != 0) {
        col++;
        if(col >= 9) {
            if(row == 8) {
                print_matrix(v);
                flag = true;
                return;
            }
            col = 0;
            row++;
        }
    }
    for(int i = 1; i <= 9; i++) {
        if(flag) return;
        if(rectangle_is_legit(v, row, col, i) && row_col_is_legit(v, row, col, i)) {
            v[row][col] = i;
            run_sudoku(v, row, col);
        }
    }
}

int main() {
    vector<vector<int> > sudoku(9);
    char s[9];
    for(int i = 0; i < 9; i++) {
        sudoku[i] = vector<int>(9);
        scanf("%s", s);
        for(int j = 0; j < 9; j++) sudoku[i][j] = s[j] - 48;
    }
    run_sudoku(sudoku, 0, 0);
    return 0;
}