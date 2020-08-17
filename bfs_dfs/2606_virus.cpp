#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(int n, vector<int> *v) {
    if(v[n][0]) return;
    v[n][0] = 1;
    cnt++;
    for(int i = 1; i < v[n].size(); i++) {
        if(v[v[n][i]][0]) continue;
        dfs(v[n][i], v);
    }
}

int main() {
    vector<int> network[101];
    int n, m, left, right;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) network[i].push_back(0);
    for(int i = 0; i < m; i++) {
        cin >> left >> right;
        network[left].push_back(right);
        network[right].push_back(left);
    }

    dfs(1, network);

    cout << cnt - 1 << endl;

    return 0;
}