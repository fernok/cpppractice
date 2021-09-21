#include <bits/stdc++.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define UNCLEAN 0
#define WALL 1
#define CLEAN 2

using namespace std;

int turn_direction[] = {LEFT, UP, RIGHT, DOWN};
int back_direction[] = {DOWN, LEFT, UP, RIGHT};

int move_x[] = {-1, 0, 1, 0};
int move_y[] = {0, 1, 0, -1};

int n, m, r, c, global_direction;
int grid[50][50];

int answer = 0;

bool check_fourways(int x, int y) {
    bool fails = true;
    for (int i = 0; i < 4; i++) {
        fails = fails && (grid[x + move_x[i]][y + move_y[i]] == WALL || grid[x + move_x[i]][y + move_y[i]] == CLEAN);
    }
    return fails;
}

void check_condition(int x, int y) {
    if (grid[x][y] == UNCLEAN) {
        grid[x][y] = CLEAN;
        answer++;
    }

    if (check_fourways(x, y)) {
        if (grid[x + move_x[back_direction[global_direction]]][y + move_y[back_direction[global_direction]]] == WALL) {
            return;
        } else {
            check_condition(x + move_x[back_direction[global_direction]], y + move_y[back_direction[global_direction]]);
            return;
        }
    }

    global_direction = turn_direction[global_direction];

    if (grid[x + move_x[global_direction]][y + move_y[global_direction]] == UNCLEAN) {
        x += move_x[global_direction];
        y += move_y[global_direction];
        check_condition(x, y);
        return;
    } else {
        check_condition(x, y);
        return;
    }

    return;
}

int main() {
    int i, j;
    cin >> n >> m;
    cin >> r >> c >> global_direction;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    check_condition(r, c);

    cout << answer << endl;
    

    return 0;
}