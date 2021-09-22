#include <bits/stdc++.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

typedef struct _CCTV {
    int type;
    int x;
    int y;
} cctv;

int n, m;
int k = 0;

int grid[10][10];

cctv arr[8];

int dir_x[] = {-1, 0, 1, 0};
int dir_y[] = {0, 1, 0, -1};

int calculate_area(int g[10][10]) {
    int value = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 0) value++;
        }
    }
    return value;
}

bool is_cctv(int c) {
    if (1 <= c && c <= 5) return true;
    else return false;
}

void clear_grid(int g[10][10], int value) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == value) g[i][j] = 0;
        }
    }
}

int traverse(int g[10][10], int index) {
    if (index == k) {
        return calculate_area(g);
    }

    int type = arr[index].type;
    int x = arr[index].x;
    int y = arr[index].y;
    int i, j;

    int min_value = 65;
    int tmp;

    int CHECK = index + 10;

    if (type == 1) {
        for (i = 0; i < 4; i++) {
            int to_x = x;
            int to_y = y;
            while (1) {
                to_x += dir_x[i];
                to_y += dir_y[i];
                if (g[to_x][to_y] == 6) break;
                if (is_cctv(g[to_x][to_y])) continue;
                if (g[to_x][to_y] >= 7) continue;
                g[to_x][to_y] = CHECK;
            }
            tmp = traverse(g, index + 1);
            if (tmp < min_value) min_value = tmp;
            clear_grid(g, CHECK);
        }
    }
    if (type == 2) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 3; j += 2) {
                int to_x = x;
                int to_y = y;

                while (1) {
                    to_x += dir_x[j + i];
                    to_y += dir_y[j + i];
                    if (g[to_x][to_y] == 6) break;
                    if (is_cctv(g[to_x][to_y])) continue;
                    if (g[to_x][to_y] >= 7) continue;
                    g[to_x][to_y] = CHECK;
                }
            }
            tmp = traverse(g, index + 1);
            if (tmp < min_value) min_value = tmp;
            clear_grid(g, CHECK);
        }
    }
    if (type == 3) {
        for (i = 0; i < 4; i++) {
            j = (i + 1) % 4;
            int to_x = x;
            int to_y = y;

            while (1) {
                to_x += dir_x[i];
                to_y += dir_y[i];
                if (g[to_x][to_y] == 6) break;
                if (is_cctv(g[to_x][to_y])) continue;
                if (g[to_x][to_y] >= 7) continue;
                g[to_x][to_y] = CHECK;
            }

            to_x = x;
            to_y = y;

            while (1) {
                to_x += dir_x[j];
                to_y += dir_y[j];
                if (g[to_x][to_y] == 6) break;
                if (is_cctv(g[to_x][to_y])) continue;
                if (g[to_x][to_y] >= 7) continue;
                g[to_x][to_y] = CHECK;
            }
        
            tmp = traverse(g, index + 1);
            if (tmp < min_value) min_value = tmp;
            clear_grid(g, CHECK);
        }
    }
    if (type == 4) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (j == i) continue;
                int to_x = x;
                int to_y = y;

                while (1) {
                    to_x += dir_x[j];
                    to_y += dir_y[j];
                    if (g[to_x][to_y] == 6) break;
                    if (is_cctv(g[to_x][to_y])) continue;
                    if (g[to_x][to_y] >= 7) continue;
                    g[to_x][to_y] = CHECK;
                }
            }
            tmp = traverse(g, index + 1);
            if (tmp < min_value) min_value = tmp;
            clear_grid(g, CHECK);
        }
    }
    if (type == 5) {
        for (i = 0; i < 4; i++) {
            int to_x = x;
            int to_y = y;

            while (1) {
                to_x += dir_x[i];
                to_y += dir_y[i];
                if (g[to_x][to_y] == 6) break;
                if (is_cctv(g[to_x][to_y])) continue;
                if (g[to_x][to_y] >= 7) continue;
                g[to_x][to_y] = CHECK;
            }
        }
        tmp = traverse(g, index + 1);
        if (tmp < min_value) min_value = tmp;
        clear_grid(g, CHECK);
    }

    return min_value;
}

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < m + 2; j++) {
            if (!i || !j || i == n + 1 || j == m + 1) {
                grid[i][j] = 6;
                continue;
            } else {
                cin >> grid[i][j];
                if (grid[i][j] >= 1 && grid[i][j] <= 5) {
                    arr[k].type = grid[i][j];
                    arr[k].x = i;
                    arr[k].y = j;
                    k++;
                }
            }
        }
    }

    int answer = traverse(grid, 0);

    cout << answer << endl;

    return 0;
}