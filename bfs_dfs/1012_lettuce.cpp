#include <iostream>
#include <vector>

using namespace std;

void dfs(bool f[52][52], int n, int m) {
    if(!f[n][m]) return;
    f[n][m] = false;
    dfs(f, n + 1, m);
    dfs(f, n - 1, m);
    dfs(f, n, m + 1);
    dfs(f, n, m - 1);
}

int main() {
    int t, m, n, k;
    int left, right;
    vector<int> result;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int cnt = 0;
        cin >> m >> n >> k;
        bool field[52][52] = { false, };
        for(int j = 0; j < k; j++) {
            cin >> left >> right;
            field[right + 1][left + 1] = true;
        }
        for(int a = 1; a <= n; a++) {
            for(int b = 1; b <= m; b++) {
                if(field[a][b]) {
                    //dfs
                    dfs(field, a, b);
                    cnt++;
                }
            }
        }
        result.push_back(cnt);
    }

    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;

    return 0;
}