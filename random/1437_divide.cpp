#include <iostream>

using namespace std;

int main() {
    int n, k = 1;
    cin >> n;
    while (n >= 5) {
        k *= 3;
        k %= 10007;
        n -= 3;
    }
    
    cout << (k * n) % 10007 << endl;
    return 0;
}