#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    array<int, 26> arr = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
    for(int i = 0; i < s.size(); i++) {
        count += arr[s[i] - 65];
    }
    cout << count << endl;
    return 0;
}