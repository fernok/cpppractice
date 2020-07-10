#include <iostream>
using namespace std;

int main() {
    int N, a, b;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}