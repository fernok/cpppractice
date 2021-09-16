#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[502][502];

int max_sum = 0;

int main() {
    cin >> n;

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < m + 2; j++) {
            if (!i || !j || i == n + 1 || j == m + 1) {
                grid[i][j] = -1;
                continue;
            }
            cin >> grid[i][j];
        }
    }

    int temp_sum;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            temp_sum = 0;
        }
    }

    return 0;
}