#include <bits/stdc++.h>

using namespace std;

int n, m;
int red_col, red_row;
int blue_col, blue_row;

char grid[10][10];

int best_score = 11;

void left_right(int, int);
void up_down(int, int);

void cleanup(int rc, int rr, int bc, int br) {
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (grid[i][j] == 'R' || grid[i][j] == 'B') grid[i][j] = '.';
        }
    }

    red_col = rc;
    red_row = rr;
    blue_col = bc;
    blue_row = br;

    grid[red_row][red_col] = 'R';
    grid[blue_row][blue_col] = 'B';

    return;
}

void left_right(int level, int direction) {
    if (level >= best_score) return;
    if (grid[red_row][red_col + direction] == '#' && grid[blue_row][blue_col + direction] == '#') return;

    int rc = red_col, rr = red_row, bc = blue_col, br = blue_row;
    
    while (grid[red_row][red_col + direction] == '.' || grid[blue_row][blue_col + direction] == '.')
    {
        if (grid[red_row][red_col + direction] == '.') {
            grid[red_row][red_col] = '.';
            grid[red_row][red_col + direction] = 'R';
            red_col += direction;
        }
        if (grid[blue_row][blue_col + direction] == '.') {
            grid[blue_row][blue_col] = '.';
            if (blue_col + direction == 9) cout << (direction > 0 ? "RIGHT " : "LEFT ") << blue_row << "," << blue_col + direction << endl;
            grid[blue_row][blue_col + direction] = 'B';
            blue_col += direction;
        }
    }

    if (grid[red_row][red_col] != 'R') red_col -= direction;
    if (grid[blue_row][blue_col] != 'B') blue_col -= direction;

    if (grid[blue_row][blue_col + direction] == 'O') {
        cleanup(rc, rr, bc, br);
        return;
    }
    
    if (grid[red_row][red_col + direction] == 'O') {
        grid[red_row][red_col] = '.';
        while (grid[blue_row][blue_col] != '#') {
            if (grid[blue_row][blue_col] == 'O') {
                cleanup(rc, rr, bc, br);
                return;
            }
            blue_col += direction;
        }
        if (best_score > level) {
            best_score = level;
            cleanup(rc, rr, bc, br);
            return;
        }
        return;
    }

    left_right(level + 1, -1 * direction);
    up_down(level + 1, 1);
    up_down(level + 1, -1);

    cleanup(rc, rr, bc, br);
    return;
}

void up_down(int level, int direction) {
    if (level >= best_score) return;
    if (grid[red_row + direction][red_col] == '#' && grid[blue_row + direction][blue_col] == '#') return;

    int rc = red_col, rr = red_row, bc = blue_col, br = blue_row;
    while (grid[red_row + direction][red_col] == '.' || grid[blue_row + direction][blue_col] == '.')
    {
        if (grid[red_row + direction][red_col] == '.') {
            grid[red_row][red_col] = '.';
            grid[red_row + direction][red_col] = 'R';
            red_row += direction;
        }
        if (grid[blue_row + direction][blue_col] == '.') {
            grid[blue_row][blue_col] = '.';
            if (blue_row + direction == 9) cout << (direction > 0 ? "DOWN " : "UP ") << blue_row + direction << "," << blue_col << endl;
            grid[blue_row + direction][blue_col] = 'B';
            blue_row += direction;
        }
    }

    if (grid[red_row][red_col] != 'R') red_row -= direction;
    if (grid[blue_row][blue_col] != 'B') blue_row -= direction;

    if (grid[blue_row + direction][blue_col] == 'O') {
        cleanup(rc, rr, bc, br);
        return;
    }
    
    if (grid[red_row + direction][red_col] == 'O') {
        grid[red_row][red_col] = '.';
        while (grid[blue_row][blue_col] != '#') {
            if (grid[blue_row][blue_col] == 'O') {
                cleanup(rc, rr, bc, br);
                return;
            }
            blue_row += direction;
        }
        if (best_score > level) {
            best_score = level;
            cleanup(rc, rr, bc, br);
            return;
        }
        return;
    }

    if (blue_row == 9) cout << "hhh";

    left_right(level + 1, 1);
    left_right(level + 1, -1);
    up_down(level + 1, -1 * direction);

    cleanup(rc, rr, bc, br);
    return;
}

int main() {
    int i, j;

    cin >> n >> m;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                red_row = i;
                red_col = j;
            } else if (grid[i][j] == 'B') {
                blue_row = i;
                blue_col = j;
            }
        }
    }

    left_right(1, 1);
    left_right(1, -1);
    up_down(1, 1);
    up_down(1, -1);

    cout << (best_score == 11 ? -1 : best_score) << endl;

    return 0;
}