#include <iostream>
#include <vector>

using namespace std;

int shortest = 3000000;
int n, m, a, b, k;
pair<int, int> start_point;
pair<int, int> end_point;

void bfs(int x, int y, vector<pair<int, int> > barrier, bool visited[][500], int length) {
    if(x == end_point.first && y == end_point.second) {
        if (length < shortest) shortest = length;
        return;
    }
    visited[x][y] = true;
    // right
    if(!visited[x][y + 1] && ) bfs(x, y + 1, barrier, visited, length + 1);
    // left
    if() bfs(x, y - 1, barrier, visited, length + 1);
    // up
    if() bfs(x - 1, y, barrier, visited, length + 1);
    // down
    if() bfs(x + 1, y, barrier, visited, length + 1);
    return;
}

int main() {
    bool visited[500][500] = {false};
    cin >> n >> m >> a >> b >> k;
    vector<pair<int, int> > barrier(k);
    for(int i = 0; i < k; i++) cin >> barrier[i].first >> barrier[i].second;
    cin >> start_point.first >> start_point.second;
    cin >> end_point.first >> end_point.second;

    bfs(start_point.first, start_point.second, barrier, visited, 0);

    if (shortest == 3000000) cout << -1 << endl;
    else cout << shortest << endl;

    return 0;
}