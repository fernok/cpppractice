// Ski Course Design
#include <bits/stdc++.h>

using namespace std;

int n;
int min_height = 101;
int max_height = -1;

int hills[1001];
int answer = 1000000000;

int calculate(int index, int min_limit, int max_limit) {
    int tmp;
    if (hills[index] > max_limit) {
        tmp = hills[index] - max_limit;
    } else if (hills[index] < min_limit) {
        tmp = min_limit - hills[index];
    } else {
        tmp = 0;
    }
    return tmp * tmp;
}

int main() {
    int i, j;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> hills[i];
        if (hills[i] > max_height) max_height = hills[i];
        if (hills[i] < min_height) min_height = hills[i];
    }

    if (max_height - min_height <= 17) {
        cout << 0 << endl;
        return 0;
    }

    int temp_sum = 0;
    for (i = min_height; i <= max_height - 17; i++) {
        temp_sum = 0;
        for (j = 0; j < n; j++) {
            temp_sum += calculate(j, i, i + 17);
        }
        if (temp_sum < answer) answer = temp_sum;
    }

    cout << answer << endl;

    return 0;
}