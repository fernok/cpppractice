// Start Taxi
#include <bits/stdc++.h>
#define TO_CUSTOMER 0
#define TO_DESTINATION 1

using namespace std;

int n, m, fuel;
int grid[22][22];
int cx[400], cy[400];
int dx[400], dy[400];
int tx, ty;

bool visited[22][22];

void reset() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) visited[i][j] = false;
    }
}

int distance(int target, int index) {
    int x, y;
    if (target == TO_CUSTOMER) {
        x = cx[index];
        y = cy[index];
    } else {
        x = dx[index];
        y = dy[index];
    }

    queue<int> qx;
    queue<int> qy;

    visited[tx][ty] = true;

    qx.push(x);
    qy.push(y);

    while (!qx.empty() && !qy.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();

        if (grid[x][y] == 1 || visited[x][y]) continue;

        
    }
}

int main() {
    int i, j;

    cin >> n >> m >> fuel;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (!i || !j || i == n + 1 || j == n + 1) {
                grid[i][j] = 1;
                continue;
            }
            cin >> grid[i][j];
        }
    }

    cin >> tx >> ty;

    for (i = 0; i < m; i++) {
        cin >> cx[i] >> cy[i] >> dx[i] >> dy[i];
    }

    cout << fuel << endl;
    return 0;
}