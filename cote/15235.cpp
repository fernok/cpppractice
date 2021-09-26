#include <bits/stdc++.h>

using namespace std;

int n;

int input[1000];
int output[1000];

int main() {
    cin >> n;

    int answer = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int breaker = 0;

    while (++answer) {
        if (input[index] == 0) {
            answer--;
            breaker++;
            index = (index + 1) % n;
            if (breaker == n) break;
            continue;
        }

        breaker = 0;

        input[index]--;
        if (input[index] == 0) output[index] = answer;
        
        index = (index + 1) % n;
    }

    for (int i = 0; i < n; i++) cout << output[i] << " ";
    cout << endl;
    return 0;
}