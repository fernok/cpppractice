#include <iostream>
#include <string>
using namespace std;

int main() {
    int length;
    cin >> length;
    string N;
    int sum = 0;
    cin >> N;
    for(int i = 0; i < length; i++) sum += N.at(i) - '0';
    cout << sum << endl;
    return 0;
}