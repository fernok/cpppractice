#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 1000;

typedef struct _dir{
    int x, y;
} dir;

dir movedir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int board[MAX][MAX];
int cache[MAX][MAX][2];

int main() {
    int n, m;
    int is_breakable;
    string input;
    cin >> n >> m;
    queue<pair<pair<int, int>, int> > q;
    pair<int, int> c, new_pos;  // current

    cache[0][0][1] = 1;

    for(int i = 0; i < n; i++) {
        cin >> input;
        for(int j = 0; j < m; j++) {
            board[i][j] = input[j] - 48;
        }
    }
    
    q.push(make_pair(make_pair(0, 0), 1));

    while(!q.empty()) {
        c = q.front().first;
        is_breakable = q.front().second;
        q.pop();
        if(c.first == n - 1 && c.second == m - 1) {
            cout << cache[n - 1][m - 1][is_breakable] << endl;
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            new_pos.first = c.first + movedir[i].x;
            new_pos.second = c.second + movedir[i].y;
            if(new_pos.first >= 0 && new_pos.first < n && new_pos.second >= 0 && new_pos.second < m) {
                if(board[new_pos.first][new_pos.second] == 0 && cache[new_pos.first][new_pos.second][is_breakable] == 0) {
                    cache[new_pos.first][new_pos.second][is_breakable] = cache[c.first][c.second][is_breakable] + 1;
                    q.push(make_pair(new_pos, is_breakable));
                }
                else if(board[new_pos.first][new_pos.second] == 1 && is_breakable) {
                    cache[new_pos.first][new_pos.second][is_breakable - 1] = cache[c.first][c.second][is_breakable] + 1;
                    q.push(make_pair(new_pos, is_breakable - 1));
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}