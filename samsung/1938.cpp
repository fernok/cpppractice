#include <bits/stdc++.h>

using namespace std;

int n;

int moves = INT_MAX;

char grid[52][52];

int current[3];
int target[3];

void print() {
    cout << current[0] << " " << current[1] << " " << current[2] << endl;
}


// direction = 1 => | /// direction = 0 => --
// u d l r t
// 0 1 2 3 4
bool moveable(int move) {
    if (current[2]) {
        if (move == 0) {
            if (grid[current[0] - 2][current[1]] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 1) {
            if (grid[current[0] + 2][current[1]] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 2) {
            if (grid[current[0]][current[1] - 1] != '1' && 
            grid[current[0] - 1][current[1] - 1] != '1' &&
            grid[current[0] + 1][current[1] - 1] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 3) {
            if (grid[current[0]][current[1] + 1] != '1' && 
            grid[current[0] - 1][current[1] + 1] != '1' &&
            grid[current[0] + 1][current[1] + 1] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 4) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (grid[current[0] + i][current[1] + j] == '1') return false;
                }
            }
            return true;
        }
    } else {
        if (move == 2) {
            if (grid[current[0]][current[1] - 2] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 3) {
            if (grid[current[0]][current[1] + 2] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 0) {
            if (grid[current[0] - 1][current[1]] != '1' && 
            grid[current[0] - 1][current[1] - 1] != '1' &&
            grid[current[0] - 1][current[1] + 1] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 1) {
            if (grid[current[0] + 1][current[1]] != '1' && 
            grid[current[0] + 1][current[1] - 1] != '1' &&
            grid[current[0] + 1][current[1] + 1] != '1') {
                return true;
            } else {
                return false;
            }
        }
        if (move == 4) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (grid[current[0] + i][current[1] + j] == '1') return false;
                }
            }
            return true;
        }
    }
    return false;
}

void action(int move) {
    print();
    switch (move)
    {
    case 0:
        current[0]--;
        break;
    case 1:
        current[0]++;
        break;
    case 2:
        current[1]--;
        break;
    case 3:
        current[1]++;
        break;
    case 4:
        current[2] = !current[2];
        break;
    default:
        break;
    }
}

void save(int a[3]) {
    a[0] = current[0];
    a[1] = current[1];
    a[2] = current[2];
    return;
}

void reset(int a[3]) {
    current[0] = a[0];
    current[1] = a[1];
    current[2] = a[2];
    return;
}

bool is_answer() {
    for (int i = 0; i < 3; i++) {
        if (current[i] != target[i]) return false;
    }
    return true;
}

bool is_redundant(int prev, int move) {
    if (prev == 0 && move == 1) return true;
    if (prev == 1 && move == 0) return true;
    if (prev == 2 && move == 3) return true;
    if (prev == 3 && move == 2) return true;
    if (prev == 4 && move == 4) return true;
    return false;
}

void solve(int level, int previous) {
    if (level > moves) return;
    int a[3];
    save(a);
    for (int i = 0; i < 5; i++) {
        if (is_redundant(previous, i)) continue;
        reset(a);
        if (moveable(i)) {
            action(i);
            if (is_answer()) {
                if (level < moves) moves = level;
                return;
            }
            solve(level + 1, i);
        }
    }
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (!i || !j || i == n + 1 || j == n + 1) {
                grid[i][j] = '1';
                continue;
            }
            cin >> grid[i][j];
        }
    }

    for (i = 0; i < (n + 2) * (n + 2); i++) {
        if (grid[i / (n + 2)][i % (n + 2)] == 'B') {
            if (grid[(i / (n + 2)) + 1][i % (n + 2)] == 'B') {
                current[0] = i / (n + 2) + 1;
                current[1] = i % (n + 2);
                current[2] = 1;
                break;
            } else {
                current[0] = i / (n + 2);
                current[1] = i % (n + 2);
                current[2] = 1;
                break;
            }
        }
    }

    for (i = 0; i < (n + 2) * (n + 2); i++) {
        if (grid[i / (n + 2)][i % (n + 2)] == 'E') {
            if (grid[(i / (n + 2)) + 1][i % (n + 2)] == 'E') {
                target[0] = i / (n + 2) + 1;
                target[1] = i % (n + 2);
                target[2] = 1;
                break;
            } else {
                target[0] = i / (n + 2);
                target[1] = i % (n + 2);
                target[2] = 1;
                break;
            }
        }
    }


    int a[3];
    save(a);
    for (i = 0; i < 5; i++) {
        reset(a);
        if (moveable(i)) {
            action(i);
            if (is_answer()) {
                moves = 1;
                cout << 1 << endl;
                return 0;
            }
            solve(2, i);
        }
    }

    return 0;
}