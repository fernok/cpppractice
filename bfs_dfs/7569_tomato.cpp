#include <iostream>
#include <queue>

using namespace std;

typedef struct _pos {
    int h;
    int n;
    int m;
} pos;

int main() {
    int board[102][102][102] = { -1, };
    int m, n, h;
    queue<pos> q;
    pos current, new_pos;
    cin >> m >> n >> h;
    for(int a = 0; a <= h + 1; a++) {
        for(int b = 0; b <= n + 1; b++) {
            for(int c = 0; c <= m + 1; c++) {
                board[a][b][c] = -1;
            }
        }
    }
    // board[height][n][m]
    for(int a = 1; a <= h; a++) {
        for(int b = 1; b <= n; b++) {
            for(int c = 1; c <= m; c++) {
                cin >> board[a][b][c];
                if(board[a][b][c] == 1) {
                    current.h = a;
                    current.n = b;
                    current.m = c;
                    q.push(current);
                }
            }
        }
    }
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(board[current.h + 1][current.n][current.m] == 0) {
            board[current.h + 1][current.n][current.m] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.h = current.h + 1;
            q.push(new_pos);
        }
        if(board[current.h - 1][current.n][current.m] == 0) {
            board[current.h - 1][current.n][current.m] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.h = current.h - 1;
            q.push(new_pos);
        }
        if(board[current.h][current.n + 1][current.m] == 0) {
            board[current.h][current.n + 1][current.m] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.n = current.n + 1;
            q.push(new_pos);
        }
        if(board[current.h][current.n - 1][current.m] == 0) {
            board[current.h][current.n - 1][current.m] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.n = current.n - 1;
            q.push(new_pos);
        }
        if(board[current.h][current.n][current.m + 1] == 0) {
            board[current.h][current.n][current.m + 1] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.m = current.m + 1;
            q.push(new_pos);
        }
        if(board[current.h][current.n][current.m - 1] == 0) {
            board[current.h][current.n][current.m - 1] = board[current.h][current.n][current.m] + 1;
            new_pos = current;
            new_pos.m = current.m - 1;
            q.push(new_pos);
        }
    }
    int max = 0;
    for(int a = 1; a <= h; a++) {
        for(int b = 1; b <= n; b++) {
            for(int c = 1; c <= m; c++) {
                if(board[a][b][c] == 0) {
                    cout << "-1" << endl;
                    return 0;
                }
                if(max < board[a][b][c]) max = board[a][b][c];
            }
        }
    }
    cout << max - 1 << endl;
    return 0;
}