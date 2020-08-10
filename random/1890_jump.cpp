#include <iostream>

using namespace std;

int n, val;
int board[100][100];
long long route[100][100];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            route[i][j] = 0;
            cin >> board[i][j];
        }
    }

    route[0][0] = 1;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) continue;
            val = board[i][j];
            if(i + val < n) route[i + val][j] += route[i][j];
            if(j + val < n) route[i][j + val] += route[i][j];
        }
    }

    cout << route[n - 1][n - 1] << endl;

    return 0;
}