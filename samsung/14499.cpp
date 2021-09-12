#include <bits/stdc++.h>

using namespace std;

int n, m;
int x, y;
int k;

int grid[22][22];
int command[1000];

int dice[4][3];

void print() {
    cout << dice[1][1] << endl;
    return;
}

void up() {
    int temp = dice[0][1];
    for (int i = 0; i < 3; i++) {
        dice[i][1] = dice[i + 1][1];
    }
    dice[3][1] = temp;
    return;
}

void down() {
    up();
    up();
    up();
}

void right() {
    int temp = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = dice[1][2];
    dice[1][2] = temp;
    return;
}

void left() {
    right();
    right();
    right();
    return;
}

void swap() {
    if (grid[x][y] == 0) {
        grid[x][y] = dice[3][1];
    } else {
        dice[3][1] = grid[x][y];
        grid[x][y] = 0;
    }
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

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) dice[i][j] = 0;
    }

    for (i = 0; i < k; i++) {
        switch (command[i])
        {
        case 1: // right
        if (grid[x][y + 1] == -1) break;
        y++;
        right();
        swap();
        print();
            break;
        case 2: // left
        if (grid[x][y - 1] == -1) break;
        y--;
        left();
        swap();
        print();
            break;
        case 3: // up
        if (grid[x - 1][y] == -1) break;
        x--;
        up();
        swap();
        print();
            break;
        case 4: // down
        if (grid[x + 1][y] == -1) break;
        x++;
        down();
        swap();
        print();
            break;
        default:
            break;
        }
    }

    return 0;
}