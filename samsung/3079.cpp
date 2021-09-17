#include <bits/stdc++.h>

using namespace std;

int n, m;

long long judge_time[100000];

int main() {
    cin >> n >> m;

    long long val = 0;
    int i;

    for (i = 0; i < n; i++) {
        cin >> judge_time[i];
        val = max(val, judge_time[i]);
    }
    
    long long left = 1;
    long long right = val * m;
    long long answer = 0;
    long long people;
    long long middle;

    while (left <= right) {
        middle = left + (right - left) / 2;
        people = 0;

        for (i = 0; i < n; i++) {
            people += middle / judge_time[i];
        }

        if (people < m) {
            left = middle + 1;
        } else {
            answer = middle;
            right = middle - 1;
        }
    }

    cout << answer << endl;

    return 0;
}