#include <iostream>

using namespace std;

int main() {
    long long n, result;
    cin >> n;

    result = 1.5 * n * n + 2.5 * n + 1;

    cout << result % 45678 << endl;

    return 0;
}