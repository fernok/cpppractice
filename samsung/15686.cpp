#include <bits/stdc++.h>

#define ABS(x) ((x) > 0 ? (x) : ((-1) * (x)))

using namespace std;

int n, m;

int grid[52][52];

int house = 0;
int house_x[100];
int house_y[100];

int chicken = 0;
int chicken_x[13];
int chicken_y[13];
bool delete_chicken[13];

int chicken_distance = 10000;

int get_distance(int x1, int y1, int x2, int y2) {
    return ABS(x1 - x2) + ABS(y1 - y2);
}

int get_chicken_distance() {
    int dist = 0;
    int min_dist;
    for (int i = 0; i < house; i++) {
        min_dist = 100000;
        for (int j = 0; j < chicken; j++) {
            if (!delete_chicken[j]) continue;
            int temp_dist = get_distance(house_x[i], house_y[i], chicken_x[j], chicken_y[j]);
            if (temp_dist < min_dist) min_dist = temp_dist;
        }
        dist += min_dist;
    }
    return dist;
}

void traverse(int index, int num_deletes) {
    if (chicken - num_deletes == m) {
        // get chicken distance
        int dist = get_chicken_distance();
        if (dist < chicken_distance) chicken_distance = dist;
        return;
    }
    if (index == chicken && (chicken - num_deletes < m)) {
        // failed
        return;
    }
    if (index == chicken) {
        return;
    }
    delete_chicken[index] = false;
    traverse(index + 1, num_deletes + 1);
    delete_chicken[index] = true;
    traverse(index + 1, num_deletes);
    return;
}

int main() {
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            if (!i || !j || i == n + 1 || j == n + 1) {
                grid[i][j] = 100;
                continue;
            }
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                house_x[house] = i;
                house_y[house] = j;
                house++;
                continue;
            }
            if (grid[i][j] == 2) {
                chicken_x[chicken] = i;
                chicken_y[chicken] = j;
                delete_chicken[chicken] = true;
                chicken++;
                continue;
            }
        }
    }

    traverse(0, 0);

    cout << chicken_distance << endl;

    return 0;
}