#include <stdio.h>
#include <vector>

using namespace std;

bool check(vector<vector<bool> >board, int x, int y, int n) {
    int count = 0;
    int x_pos = x, y_pos = y;
    x_pos = x - 1;
    while(x_pos >= 0) if(board[x_pos--][y_pos] == true) return false;
    x_pos = x - 1;
    y_pos = y + 1;
    while(x_pos >= 0 && y_pos < n) if(board[x_pos--][y_pos++] == true) return false;
    x_pos = x - 1;
    y_pos = y - 1;
    while(x_pos >= 0 && y_pos >= 0) if(board[x_pos--][y_pos--] == true) return false;
    return true;
}

void run_queen(vector<vector<bool> >board, int now, int n, int *c) {
    if(now == n) {
        (*c)++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(check(board, now, i, n)) {
            board[now][i] = true;
            run_queen(board, now + 1, n, c);
            board[now][i] = false;
        }
    }
}

int main() {
    int N;
    int count = 0;
    scanf("%d", &N);

    // 2D vector
    vector<vector<bool> > board(N);
    for(int i = 0; i < N; i++) board[i] = vector<bool>(N, false);

    for(int i = 0; i < N; i++) {
        board[0][i] = true;
        run_queen(board, 1, N, &count);
        board[0][i] = false;
    }
    
    printf("%d\n", count);
    return 0;
}