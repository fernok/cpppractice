#include <bits/stdc++.h>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace std;

bool grid[102][102];
int n, k, l;
int survival_time = 0;

int dir_y[] = {1, -1, 0, 0};
int dir_x[] = {0, 0, -1, 1};
int direction = RIGHT;

queue<vector<int> > snake;
queue<pair<int, char> > commands;

int main() {
    int i, j, x, y;
    
    cin >> n >> k;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            grid[i][j] = false;
        }
    }

    for (i = 0; i < k; i++) {
        cin >> x >> y;
        grid[x][y] = true;
    }

    cin >> l;

    int amount;
    char direction;
    for (i = 0; i < l; i++) {
        cin >> amount >> direction;
        commands.push(make_pair(amount, direction));
    }
    

    return 0;
}