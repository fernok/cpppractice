#include <bits/stdc++.h>

using namespace std;

int n, m;

int grid[10][10];

int cleanzone = 0;

int main() {
    int i, j;
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


    return 0;
}