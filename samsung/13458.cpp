#include <bits/stdc++.h>

using namespace std;

long long sum = 0;

int n;
int students[1000000];
int memory[1000001];
int b, c;

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> students[i];
        memory[i] = -1;
    }
    cin >> b;
    cin >> c;

    for (i = 0; i < 1000001; i++) memory[i] = -1;

    int temp;

    for (i = 0; i < n; i++) {
        if (memory[students[i]] != -1) {
            sum += memory[students[i]];
            continue;
        }
        temp = 1;
        students[i] -= b;
        if (students[i] > 0) {
            temp += students[i] / c;
            if (students[i] % c > 0) {
                temp++;
            }
        }
        
        memory[students[i] + b] = temp;
        sum += temp;
    }

    cout << sum << endl;

    return 0;
}