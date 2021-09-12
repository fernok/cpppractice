#include <bits/stdc++.h>

using namespace std;

int n, m;
int x, y;
int k;

int grid[22][22];
int command[1000];

void swap() {
    if (grid[x][y] == 0) {
        
    } else {
        
    }
    return;
}

void print() {
    
    return;
}

int main(int argc, char** argv) {
    int i, j;

    cin >> n >> m >> x >> y >> k;

    for (i = 0; i <= n + 1; i++) {
        for (j = 0; j <= m + 1; j++) {
            if (!i || !j || i == n + 1 || j == m + 1) {
                grid[i][j] = -1;
                continue;
            }
            cin >> grid[i][j];
        }
    }

    for (i = 0; i < k; i++) {
        cin >> command[i];
    }

    x++;
    y++;



    for (i = 0; i < k; i++) {
        switch (command[i])
        {
        case 1: // right
        if (grid[x][y + 1] == -1) break;
        y++;
        
            break;
        case 2: // left
        if (grid[x][y - 1] == -1) break;
        y--;
        
            break;
        case 3: // up
        if (grid[x - 1][y] == -1) break;
        x--;
        
            break;
        case 4: // down
        if (grid[x + 1][y] == -1) break;
        x++;
        
            break;
        default:
            break;
        }
    }

    return 0;
}