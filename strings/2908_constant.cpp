#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string left, right;
    cin >> left >> right;
    reverse(left.begin(), left.end());
    reverse(right.begin(), right.end());
    if(left < right) cout << right << endl;
    else cout << left << endl;
    return 0;
}