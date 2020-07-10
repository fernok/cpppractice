#include <iostream>
using namespace std;

const int kQuadrant1 = 1;
const int kQuadrant2 = 2;
const int kQuadrant3 = 3;
const int kQuadrant4 = 4;

int main() {
    int x, y;
    cin >> x >> y;
    if(x > 0) {
        if(y > 0) cout << kQuadrant1 << endl;
        else cout << kQuadrant4 << endl;
    }
    else {
        if(y > 0) cout << kQuadrant2 << endl;
        else cout << kQuadrant3 << endl;
    }
    return 0; 
}