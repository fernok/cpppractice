#include <iostream>
using namespace std;

int main() {
    int a, b;
    int one, two, three, result;
    cin >> a >> b;
    one = a * (b % 10);
    b = b / 10;
    two = a * (b % 10);
    b = b / 10;
    three = a * (b % 10);
    cout << one << endl << two << endl << three << endl << 100 * three + 10 * two + one << endl;
    return 0;
}