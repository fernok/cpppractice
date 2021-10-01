// Startlink
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000000000;
int answer = MAX;

int f, g, s, u, d;

int visited[1000001];

void traverse(int x, int level) {
    if (visited[x] == 11) return;

    if (x == g) {
        if (level < answer) answer = level;
        return;
    }

    if (x > f || x < 1) {
        return;
    }

    if ((visited[x] / 10) % 10 == 0) visited[x] += 10;
    if (visited[x] % 10 == 0) visited[x] += 10;
    if (x + u <= f) {
        if (visited[x + u] == 11) return;
        traverse(x + u, level + 1);
    }
    if (x - d >= 1) {
        if (visited[x - d] == 11) return;
        traverse(x - d, level + 1);
    }

    return;
}

int main() {
    cin >> f >> s >> g >> u >> d;

    traverse(s, 0);

    if (answer == MAX) cout << "use the stairs" << endl;
    else cout << answer << endl;
    return 0;
}