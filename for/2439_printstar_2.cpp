#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = N; j > i + 1; j--) cout << " ";
        for(int j = 0; j <= i; j++) cout << "*";
        cout << endl;
    }
    return 0;
}