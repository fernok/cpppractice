#include <iostream>
using namespace std;

int main() {
    int N;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = N; i >= 1; i--) {
        cout << i << "\n";
    }
    return 0;
}