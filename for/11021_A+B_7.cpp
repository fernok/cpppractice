#include <iostream>
using namespace std;

int main() {
    int N, a, b;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << endl;
    }
    return 0;
}