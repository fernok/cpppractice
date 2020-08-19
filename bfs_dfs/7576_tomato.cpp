#include <iostream>
#include <queue>

using namespace std;

int main() {
    int board[1002][1002] = { -1, };
    int m, n;
    queue<pair<int, int> > q;
    pair<int, int> current;
    cin >> m >> n;
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            board[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) q.push(pair<int, int>(i, j));
        }
    }
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(board[current.first + 1][current.second] == 0) {
            board[current.first + 1][current.second] = board[current.first][current.second] + 1;
            q.push(pair<int, int>(current.first + 1, current.second));
        }
        if(board[current.first - 1][current.second] == 0) {
            board[current.first - 1][current.second] = board[current.first][current.second] + 1;
            q.push(pair<int, int>(current.first - 1, current.second));
        }
        if(board[current.first][current.second + 1] == 0) {
            board[current.first][current.second + 1] = board[current.first][current.second] + 1;
            q.push(pair<int, int>(current.first, current.second + 1));
        }
        if(board[current.first][current.second - 1] == 0) {
            board[current.first][current.second - 1] = board[current.first][current.second] + 1;
            q.push(pair<int, int>(current.first, current.second - 1));
        }
    }
    int max = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == 0) {
                cout << "-1" << endl;
                return 0;
            }
            if(board[i][j] > max) max = board[i][j];
        }
    }
    cout << max - 1 << endl;
    return 0;
}