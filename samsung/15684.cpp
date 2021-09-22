#include <bits/stdc++.h>

using namespace std;

int n, m, h;

bool ladder[30][10];

int moves = 4;

bool traverse() {
    int current = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        current = i;
        for (j = 0; j < h; j++) {
            if (current > 0) {
                if (ladder[j][current - 1]) {
                    current--;
                    continue;
                }
            } 
            if (current < n - 1) {
                if (ladder[j][current]) {
                    current++;
                    continue;
                }
            }
        }
        if (current != i) return false;
    }
    return true;
}

bool is_incident(int x, int y) {
    if (ladder[x][y]) return true;
    if (y > 0) {
        if (ladder[x][y - 1]) return true;
    }
    if (y < n - 1) {
        if (ladder[x][y + 1]) return true;
    }
    return false;
}

int main() {
    int i, j, k;
    int a, b;

    cin >> n >> m >> h;

    for (i = 0; i < m; i++) {
        cin >> a >> b;
        ladder[a - 1][b - 1] = true;
    }

    // for (i = 0; i < h; i++) {
    //     for (j = 0; j < n - 1; j++) {
    //         if (ladder[i][j]) cout << "1";
    //         else cout << "0";
    //     }
    //     cout << endl;
    // }

    if (traverse()) {
        cout << 0 << endl;
        return 0;
    }

    int x, y;
    int x1, y1;
    int x2, y2;
    int counts = 0;
    for (i = 0; i < h * (n - 1); i++) {
        x = i / (n - 1);
        y = i % (n - 1);

        if (is_incident(x, y)) continue;

        ladder[x][y] = true;

        if (traverse()) {
            cout << 1 << endl;
            return 0;
        }

        for (j = i + 1; j < h * (n - 1); j++) {
            x1 = j / (n - 1);
            y1 = j % (n - 1);

            if (is_incident(x1, y1)) continue;

            ladder[x1][y1] = true;

            if (traverse()) {
                moves = (moves > 2 ? 2 : moves);
                ladder[x1][y1] = false;
                break;
            }

            for (k = j + 1; k < h * (n - 1); k++) {
                x2 = k / (n - 1);
                y2 = k % (n - 1);

                if (is_incident(x2, y2)) continue;

                ladder[x2][y2] = true;

                if (traverse()) {
                    moves = (moves > 3 ? 3 : moves);
                    ladder[x2][y2] = false;
                    break;
                }

                ladder[x2][y2] = false;
            }

            ladder[x1][y1] = false;
        }

        ladder[x][y] = false;

    }

    cout << (moves == 4 ? -1 : moves) << endl;

    return 0;
}