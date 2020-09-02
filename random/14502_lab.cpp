#include <iostream>

using namespace std;

int map[10][10] = { 1, };

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    return 0;
}