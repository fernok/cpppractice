#include <bits/stdc++.h>

using namespace std;

int n, h;

vector<int> top, bottom;

int main() {
    cin >> n >> h;

    int i, j;
    int x;

    for (i = 0; i < n; i++) {
        cin >> x;
        if (i % 2) top.push_back(x);
        else bottom.push_back(x);
    }

    sort(top.begin(), top.end());
    sort(bottom.begin(), bottom.end());

    int answer = 500000;
    int nums = 0;

    for (i = 0; i < h; i++) {
        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i + 1) - bottom.begin());
        temp += top.size() - (lower_bound(top.begin(), top.end(), h - i) - top.begin());
        
        if (temp < answer) {
            answer = temp;
            nums = 1;
        } else if (temp == answer) {
            nums++;
        }
    }
    cout << answer << " " << nums << endl;

    return 0;
}