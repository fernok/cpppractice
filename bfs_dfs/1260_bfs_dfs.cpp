#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void dfs(int s, vector<int> *v) {
    if(v[s][0]) return;
    v[s][0] = 1;
    cout << s << " ";
    for(int i = 1; i < v[s].size(); i++) {
        if(v[v[s][i]][0]) continue;
        dfs(v[s][i], v);
    }
}

void bfs(int s, vector<int> *v) {
    queue<int> q;
    int pop;
    q.push(s);
    while(!q.empty()) {
        pop = q.front();
        q.pop();
        if(v[pop][0]) continue;
        v[pop][0] = 1;
        cout << pop << " ";
        for(int i = 1; i < v[pop].size(); i++) {
            if(v[v[pop][i]][0]) continue;
            q.push(v[pop][i]);
        }
    }
}

int main() {
    vector<int> dfs_list[1001];
    vector<int> bfs_list[1001];
    int n, m, start, left, right;
    cin >> n >> m >> start;
    for(int i = 1; i <= n; i++) {
        dfs_list[i].push_back(0);
        bfs_list[i].push_back(0);
    }
    for(int i = 0; i < m; i++) {
        cin >> left >> right;
        dfs_list[left].push_back(right);
        dfs_list[right].push_back(left);
        bfs_list[left].push_back(right);
        bfs_list[right].push_back(left);
    }
    for(int i = 1; i <= n; i++) {
        sort(dfs_list[i].begin() + 1, dfs_list[i].end());
        sort(bfs_list[i].begin() + 1, bfs_list[i].end());
    }
    dfs(start, dfs_list);
    cout << endl;
    bfs(start, bfs_list);
    cout << endl;
    return 0;
}