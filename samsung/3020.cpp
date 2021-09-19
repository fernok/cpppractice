#include <bits/stdc++.h>

using namespace std;

int n, h;

int orders[200000];
int cave[500000] = { 0, };

void print(int index) {
    cout << index << " ) ";

    for (int i = 0; i < h; i++) cout << cave[i] << " ";

    cout << endl;

    return;
}

int main() {
    cin >> n >> h;

    int i, j;
    int x;

    for (i = 0; i < n; i++) cin >> orders[i];

    for (i = 0; i < n; i++) {
        x = orders[i];
        
        if (i % 2) {
            for (j = h - 1; j >= (h - x); j--) {
                cave[j]++;
            }
        } else {
            for (j = 0; j < x; j++) {
                cave[j]++;
            }
        }

        print(x);
    }

    int answer = 500000;
    int nums = 0;

    for (i = 0; i < h; i++) {
        if (cave[i] < answer) {
            answer = cave[i];
            nums = 1;
        } else if (cave[i] == answer) {
            nums++;
        } else {
            continue;
        }
    }

    cout << answer << " " << nums << endl;

    // for (i = 0; i < n; i++) cout << cave[i] << endl;

    return 0;
}