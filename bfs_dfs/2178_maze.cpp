#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, m;
    int maze[102][102] = { 0, };
    string input;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        for(int j = 1; j <= m; j++) {
            maze[i][j] = input[j - 1] - 48;
        }
    }
    queue<pair<int, int> > q;
    pair<int, int> current;
    q.push(pair<int, int>(1, 1));
    int cnt = 1;
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(current.first == n && current.second == m) break;
        if(maze[current.first + 1][current.second] != 0 && maze[current.first + 1][current.second] <= maze[current.first][current.second]) {
            q.push(pair<int, int>(current.first + 1, current.second));
            maze[current.first + 1][current.second] = maze[current.first][current.second] + 1;
        }
        if(maze[current.first - 1][current.second] != 0 && maze[current.first - 1][current.second] <= maze[current.first][current.second]) {
            q.push(pair<int, int>(current.first - 1, current.second));
            maze[current.first - 1][current.second] = maze[current.first][current.second] + 1;
        }
        if(maze[current.first][current.second + 1] != 0 && maze[current.first][current.second + 1] <= maze[current.first][current.second]) {
            q.push(pair<int, int>(current.first, current.second + 1));
            maze[current.first][current.second + 1] = maze[current.first][current.second] + 1;
        }
        if(maze[current.first][current.second - 1] != 0 && maze[current.first][current.second - 1] <= maze[current.first][current.second]) {
            q.push(pair<int, int>(current.first, current.second - 1));
            maze[current.first][current.second - 1] = maze[current.first][current.second] + 1;
        }
    }
    cout << maze[n][m] << endl;
    return 0;
}