#include <bits/stdc++.h>

using namespace std;

int max_safe = 1;

int n;
int max_level = -1;

int grid[102][102];
bool visited[102][102];

void fill(int level) {
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (grid[i][j] <= level) visited[i][j] = true;
        }
    }
    return;    
}

void bfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    bfs(x + 1, y);
    bfs(x - 1, y);
    bfs(x, y + 1);
    bfs(x, y - 1);
    return;
}

void search() {
    int islands = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                islands++;
                bfs(i, j);
            }
        }
    }
    if (islands > max_safe) max_safe = islands;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1) {
                grid[i][j] = 101;
                visited[i][j] = true;
                continue;
            }
            visited[i][j] = false;
            cin >> grid[i][j];
            if (grid[i][j] > max_level) max_level = grid[i][j];
        }
    }

    for (int i = 1; i < max_level; i++) {
        fill(i);
        search();
    }

    cout << max_safe << endl;
    return 0;
}