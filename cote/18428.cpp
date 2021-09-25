// 감시 피하기
#include <bits/stdc++.h>

using namespace std;

int n;

int grid[8][8];

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

int teacher = 0;

int tx[5];
int ty[5];

bool success = false;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool validate_single(int index) {
    for (int i = 0; i < 4; i++) {
        int x = tx[index];
        int y = ty[index];
        while (grid[x][y] != 1) {
            if (grid[x][y] == 3) return true;
            x += dirx[i];
            y += diry[i];
        }
    }

    return false;
}

// if TRUE : the position failed
// if FALSE : the position succeeded - algorithm is true
bool validate() {
    bool fails = false;
    for (int i = 0; i < teacher; i++) {
        fails = fails || validate_single(i);
    }
    return fails;
}

void traverse(int index, int level) {
    int x = index / (n + 1);
    int y = index % (n + 1);

    if (grid[x][y]) return;

    grid[x][y] = 1;

    if (level == 3) {
        if (validate()) {
            grid[x][y] = 0;
            return;
        }
        else {
            grid[x][y] = 0;
            success = true;
            return;
        }
    }

    for (int i = index + 1; i < (n + 1) * (n + 1); i++) {
        traverse(i, level + 1);
    }

    grid[x][y] = 0;
    return;
}

int main() {
    int i, j;
    char in;

    cin >> n;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (!i || !j || i == n + 1 || j == n + 1) {
                grid[i][j] = 1;
                continue;
            }
            cin >> in;
            if (in == 'X') grid[i][j] = 0;
            else if (in == 'T') {
                grid[i][j] = 2;
                tx[teacher] = i;
                ty[teacher] = j;
                teacher++;
            }
            else if (in == 'S') grid[i][j] = 3;
        }
    }

    int x, y;

    for (i = n + 3; i < (n + 1) * (n + 1); i++) {
        x = i / (n + 1);
        y = i % (n + 1);
        if (grid[x][y]) continue;
        traverse(i, 1);
    }

    // if (validate()) cout << "YAY!" << endl;
    // else cout << "NAY..." << endl;

    if (success) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}