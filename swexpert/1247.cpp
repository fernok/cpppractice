#include <iostream>

#define ABS(x) ((x) < 0 ? ((-1) * (x)) : (x))

using namespace std;

int distances[12][12];
int x_coords[12];
int y_coords[12];
bool visited[12];
int shortest_distance;
int n;

int get_distance(int i, int j) {
    return ABS(x_coords[i] - x_coords[j]) + ABS(y_coords[i] - y_coords[j]);
}

void reset_visited() {
    for (int i = 0; i < 12; i++) visited[i] = false;
    visited[0] = true;
    visited[1] = true;
    return;
}

int DFS(int previous, int current, int visited_cnt, int dist) {
    visited[current] = true;
    if (visited_cnt == n) {
        visited[current] = false;
        return dist + distances[current][1];
    }
    int shortest = 20000;
    for (int i = 2; i < n + 2; i++) {
        if (visited[i]) continue;
        if (i == current) continue;
        int d = DFS(current, i, visited_cnt + 1, dist + distances[current][i]);
        if (shortest > d) shortest = d;
    }
    visited[current] = false;
    return shortest;
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    int i, j;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> n;

        for (i = 0; i < n + 2; i++) {
            cin >> x_coords[i];
            cin >> y_coords[i];
        }

        for (i = 0; i < n + 2; i++) {
            for (j = i + 1; j < n + 2; j++) {
                distances[i][j] = get_distance(i, j);
                distances[j][i] = distances[i][j];
            }
        }

        shortest_distance = 2147483647;
        int d;

        for (i = 2; i < n + 2; i++) {
            reset_visited();
            d = DFS(0, i, 1, distances[0][i]);
            if (d < shortest_distance) shortest_distance = d;
        }

        cout << "#" << test_case << " " << shortest_distance << endl;
    }
    
    return 0;
}