#include <bits/stdc++.h>

using namespace std;

int n, m;

int grid[10][10];

int cleanzone = 0;

int answer = -1;

void print(int arg[10][10]) {
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) cout << arg[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int bfs(int wall1, int wall2, int wall3) {
    int temp_grid[10][10];
    int i, j;
    int temp_cleanzone = cleanzone;

    queue<pair<int, int> > virus;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < m + 2; j++) {
            temp_grid[i][j] = grid[i][j];
            if (grid[i][j] == 2) virus.push(make_pair(i, j));
        }
    }

    temp_grid[wall1 / (m + 2)][wall1 % (m + 2)] = 1;
    temp_grid[wall2 / (m + 2)][wall2 % (m + 2)] = 1;
    temp_grid[wall3 / (m + 2)][wall3 % (m + 2)] = 1;

    while (!virus.empty()) {
        int x = virus.front().first;
        int y = virus.front().second;
        virus.pop();

        if (temp_grid[x + 1][y] == 0) {
            temp_grid[x + 1][y] = 2;
            temp_cleanzone--;
            virus.push(make_pair(x + 1, y));
        }
        if (temp_grid[x - 1][y] == 0) {
            temp_grid[x - 1][y] = 2;
            temp_cleanzone--;
            virus.push(make_pair(x - 1, y));
        }
        if (temp_grid[x][y + 1] == 0) {
            temp_grid[x][y + 1] = 2;
            temp_cleanzone--;
            virus.push(make_pair(x, y + 1));
        }
        if (temp_grid[x][y - 1] == 0) {
            temp_grid[x][y - 1] = 2;
            temp_cleanzone--;
            virus.push(make_pair(x, y - 1));
        }
    }

    return temp_cleanzone - 3;
}

int main() {
    int i, j, k;
    cin >> n >> m;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < m + 2; j++) {
            if (!i || !j || i == n + 1 || j == m + 1) {
                grid[i][j] = 1;
                continue;
            }
            cin >> grid[i][j];
            if (grid[i][j] == 0) cleanzone++;
        }
    }

    for (i = m + 3; i < (m + 2) * (n + 2); i++) {
        if (grid[i / (m + 2)][i % (m + 2)]) continue;
        for (j = i + 1; j < (m + 2) * (n + 2); j++) {
            if (grid[j / (m + 2)][j % (m + 2)]) continue;
            for (k = j + 1; k < (m + 2) * (n + 2); k++) {
                if (grid[k / (m + 2)][k % (m + 2)]) continue;

                int traverse_result = bfs(i, j, k);

                if (traverse_result > answer) answer = traverse_result;

            }
        }
    }

    cout << answer << endl;


    return 0;
}