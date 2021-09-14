#include <bits/stdc++.h>

using namespace std;

int n;

int grid[22][22];

int saved[22][22];

int largest = 0;

void left_right(int, int);
void up_down(int, int);

void print() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void save() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            saved[i][j] = grid[i][j];
        }
    }
}

void scan() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] > largest) largest = grid[i][j];

            grid[i][j] = saved[i][j];
        }
    }
}

// direction = 1 => left, -1 => right
void left_right(int level, int direction) {
    save();
    int rightmost;
    int moving_pos;
    int temp_pos;
    for (int i = 1; i <= n; i++) {
        rightmost = (direction < 0 ? n : 1);
        moving_pos = rightmost;
        while (rightmost >= 1 && rightmost <= n) {
            if (grid[i][rightmost] == 0) {
                rightmost += direction;
            } else {
                temp_pos = rightmost + direction;
                while (grid[i][temp_pos] == 0) {
                    temp_pos += direction;
                }
                int changed = grid[i][rightmost] * 2;
                if (grid[i][rightmost] == grid[i][temp_pos]) {
                    grid[i][rightmost] = 0;
                    grid[i][temp_pos] = 0;
                    grid[i][moving_pos] = changed;
                    moving_pos += direction;
                    rightmost = temp_pos + direction;
                } else if (grid[i][temp_pos] == -1) {
                    int tmp = grid[i][rightmost];
                    grid[i][rightmost] = 0;
                    grid[i][moving_pos] = tmp;
                    break;
                } else {
                    grid[i][rightmost] = 0;
                    grid[i][moving_pos] = changed;
                    moving_pos += direction;
                    rightmost = temp_pos;
                }
            }
        }
        
    }

    if (level == 5) {
        scan();
        return;
    }

    left_right(level + 1, -1 * direction);
    up_down(level + 1, -1);
    up_down(level + 1, 1);
    return;
}

void up_down(int level, int direction) {
    save();
    int rightmost;
    int moving_pos;
    int temp_pos;
    for (int i = 1; i <= n; i++) {
        rightmost = (direction < 0 ? n : 1);
        moving_pos = rightmost;
        while (rightmost >= 1 && rightmost <= n) {
            if (grid[rightmost][i] == 0) {
                rightmost += direction;
            } else {
                temp_pos = rightmost + direction;
                while (grid[temp_pos][i] == 0) {
                    temp_pos += direction;
                }
                int changed = grid[rightmost][i] * 2;
                if (grid[rightmost][i] == grid[temp_pos][i]) {
                    grid[rightmost][i] = 0;
                    grid[temp_pos][i] = 0;
                    grid[moving_pos][i] = changed;
                    moving_pos += direction;
                    rightmost = temp_pos + direction;
                } else if (grid[temp_pos][i] == -1) {
                    int tmp = grid[rightmost][i];
                    grid[rightmost][i] = 0;
                    grid[moving_pos][i] = tmp;
                    break;
                } else {
                    grid[rightmost][i] = 0;
                    grid[moving_pos][i] = changed;
                    moving_pos += direction;
                    rightmost = temp_pos;
                }
            }
        }    
    }

    if (level == 5) {
        scan();
        return;
    }

    up_down(level + 1, -1 * direction);
    left_right(level + 1, -1);
    left_right(level + 1, 1);
    return;
}

int main() {
    int i, j;
    cin >> n;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) grid[i][j] = -1;
            else cin >> grid[i][j];
        }
    }

    left_right(1, -1);
    left_right(1, 1);
    up_down(1, -1);
    up_down(1, 1);

    cout << largest << endl;
    return 0;
}