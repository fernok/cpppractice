#include <bits/stdc++.h>

using namespace std;

typedef struct _dragon {
    vector<pair <int, int> > v;
    pair<int, int> end_point;
    pair<int, int> start_point;
    int g;
} dragon;

int n;
dragon arr[20];
int turns[20];

bool grid[101][101];

int dir_x[] = {1, 0, -1, 0};
int dir_y[] = {0, -1, 0, 1};

void turn(int x, int y, int a[2]) {
    int x_dist = x - a[0];
    int y_dist = y - a[1];

    a[0] = x + y_dist;
    a[1] = y - x_dist;
}

int main() {
    int x, y, d, g;
    int i, j;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        arr[i].end_point = make_pair(x + dir_x[d], y + dir_y[d]);
        arr[i].g = g;
        arr[i].v.push_back(make_pair(x, y));
        arr[i].v.push_back(arr[i].end_point);
        arr[i].start_point = make_pair(x, y);
    }

    int tmp[2];
    for (i = 0; i < n; i++) {
        while (arr[i].g) {
            vector<pair <int, int> > tmp_vec;
            pair<int, int> endp = arr[i].end_point;

            for (auto a : arr[i].v) {
                tmp[0] = a.first;
                tmp[1] = a.second;
                turn(endp.first, endp.second, tmp);
                tmp_vec.push_back(make_pair(tmp[0], tmp[1]));
            }

            arr[i].v.insert(arr[i].v.end(), tmp_vec.begin(), tmp_vec.end());

            tmp[0] = arr[i].start_point.first;
            tmp[1] = arr[i].start_point.second;
            turn(endp.first, endp.second, tmp);
            arr[i].end_point = make_pair(tmp[0], tmp[1]);
            arr[i].g--;
        }

        for (auto a : arr[i].v) {
            grid[a.first][a.second] = true;
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // if (grid[i][j]) cout << "1";
            // else cout << "0";
            if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1]) {
                answer++;
            }
        }
    }
    cout << answer << endl;
    return 0;
}