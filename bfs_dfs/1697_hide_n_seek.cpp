#include <iostream>
#include <queue>

using namespace std;

int main() {
    int board[100001] = { 0, };
    int n, m, current;
    cin >> n >> m;
    board[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(current == m) {
            cout << board[current] - 1 << endl;
            return 0;
        }
        if(current + 1 <= 100000 && board[current + 1] == 0) {
            board[current + 1] = board[current] + 1;
            q.push(current + 1);
        }
        if(current - 1 >= 0 && board[current - 1] == 0) {
            board[current - 1] = board[current] + 1;
            q.push(current - 1);
        }
        if(2 * current <= 100000 && board[2 * current] == 0) {
            board[2 * current] = board[current] + 1;
            q.push(2 * current);
        }
    }
    return 0;
}