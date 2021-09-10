#include <iostream>

using namespace std;

#define EMPTY -2

// every element in a block share id
typedef struct _data {
    int id;
    int size;
    int num_rainbow;
    int gijun;
    bool visited;
} data;

int n, m;

int grid[22][22];
int score = 0;
data data_matrix[22][22];

int number;
int rainbow;

bool empty() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] != -1 || grid[i][j] != EMPTY) return true;
        }
    }
    return false;
}

void reset_data_matrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            data_matrix[i][j].id = 0;
            data_matrix[i][j].size = 0;
            data_matrix[i][j].num_rainbow = 0;
            data_matrix[i][j].gijun = 0;
            data_matrix[i][j].visited = false;
        }
    }
    return;
}

void dfs(int x, int y, int id, ) {
    
}

void solve() {
    // perform bfs
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            number = 0;
            rainbow = 0;
            if (grid[i][j] == 0 || grid[i][j] == EMPTY || grid[i][j] == -1) continue;
            if (data_matrix[i][j].visited) continue;
        }
    }
    // perform rotation and action
}

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) {
                grid[i][j] = -1;
                continue;
            }
            cin >> grid[i][j];
        }
    }

    while(empty()) {

    }

    cout << score << endl;
    
    return 0;
}