#include <iostream>

using namespace std;

int n;
long long cnt = 0;
int board[100][100];

void jump(int x, int y) {
    if(x == n - 1 && y == n - 1) {
        cnt++;
        return;
    }
    if(board[x][y] == 0) return;
    if(x + board[x][y] < n) jump(x + board[x][y], y);
    if(y + board[x][y] < n) jump(x, y + board[x][y]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> board[i][j];
    }

    jump(0, 0);

    cout << cnt << endl;

    return 0;
}