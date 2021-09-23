#include <bits/stdc++.h>

using namespace std;

const int MAX_PPL = 1000;

int n, l, r;

int grid[52][52];
bool type[52][52];

int dir_x[] = {-1, 0, 1, 0};
int dir_y[] = {0, 1, 0, -1};

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << grid[i][j];
        cout << endl;
    }
    cout << endl;
}

void print_type() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (type[i][j] ? "1" : "0");
        }
        cout << endl;
    }
    cout << endl;
}

void reset_type() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            type[i][j] = false;
        }
    }
    return;
}

bool is_u (int x, int y) {
    int abs = x - y;
    abs = (abs > 0 ? abs : (-1) * abs);
    // cout << x << " <-> " << y << " : " << abs << endl;

    if (abs >= l && abs <= r) return true;
    else return false;
}

bool bfs(int x, int y) {
    queue<pair<int, int> > q;
    queue<pair<int, int> > iter_q;
    q.push(make_pair(x, y));

    int a, b, i;

    int population = 0;
    int nation_count = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        iter_q.push(p);
        q.pop();

        population += grid[p.first][p.second];
        nation_count++;

        type[p.first][p.second] = true;

        for (i = 0; i < 4; i++) {
            a = p.first + dir_x[i];
            b = p.second + dir_y[i];
            if (type[a][b] == false) {
                if (is_u(grid[p.first][p.second], grid[a][b])) {
                    type[a][b] = true;
                    q.push(make_pair(a, b));
                }
            }
        }
    }

    int average = population / nation_count;

    while (!iter_q.empty()) {
        pair<int, int> p = iter_q.front();
        iter_q.pop();
        grid[p.first][p.second] = average;
    }

    if (nation_count > 1) return true;
    else return false;
}

int main() {
    int i, j;

    cin >> n >> l >> r;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (!i || !j || i == n + 1 || j == n + 1) {
                grid[i][j] = MAX_PPL;
                type[i][j] = true;
                continue;
            }
            cin >> grid[i][j];
        }
    }

    int rounds = 0;
    bool changed;
    bool tmp;

    while (1) {
        changed = false;
        reset_type();

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (type[i][j]) continue;
                tmp = bfs(i, j);
                changed = changed || tmp;
            }
        }

        if (!changed) break;
        rounds++;
    }

    cout << rounds << endl;

    return 0;
}