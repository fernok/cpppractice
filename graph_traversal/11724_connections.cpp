#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int connected;

void traverse(int from, int to) {
    
}

int main() {
    cin >> N >> M;
    int from, to;
    connected = 0;
    vector< vector<int> > graph (N);
    vector<bool> checked(N, true);

    for (int i = 0; i < N; i++) graph[i] = vector<int>(N, 0);
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        graph[from-1][to-1] = 1;
        graph[to-1][from-1] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (checked[i]) {
            connected++;
            checked[i] = false;
            for (int j = 0; j < N; j++) {
                if (graph[i][j] == 0) continue;
                int pop;
                queue<int> q;
                q.push(j);
                while (!q.empty()) {
                    pop = q.front();
                    q.pop();
                    if (checked[pop] == false) continue;
                    checked[pop] = false;
                    for (int k = 0; k < N; k++) if (graph[pop][k]) q.push(k);
                }
            }
        }
    }

    cout << connected << endl;

    return 0;
}