#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int n, int m, int d[27][27]) {
    queue<pair<int, int> > q;
    pair<int, int> current;
    int cnt = 0;
    q.push(pair<int, int>(n, m));
    while(!q.empty()) {
        current = q.front();
        q.pop();
        if(d[current.first][current.second] == 0) continue;
        d[current.first][current.second] = 0;
        cnt++;
        if(d[current.first - 1][current.second] != 0) q.push(pair<int, int>(current.first - 1, current.second));
        if(d[current.first][current.second - 1] != 0) q.push(pair<int, int>(current.first, current.second - 1));
        if(d[current.first + 1][current.second] != 0) q.push(pair<int, int>(current.first + 1, current.second));
        if(d[current.first][current.second + 1] != 0) q.push(pair<int, int>(current.first, current.second + 1));
    }
    return cnt;
}

int main() {
    int n;
    int danji[27][27] = { 0, };
    vector<int> result;
    int cnt;
    string input;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> input;
        for(int j = 1; j <= n; j++) {
            danji[i][j] = input[j - 1] - 48;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(danji[i][j] == 1) {
                result.push_back(bfs(i, j, danji));
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
    return 0;
}