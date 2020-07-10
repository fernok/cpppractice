#include <iostream>
using namespace std;

const int kIsOddYear = 1;
const int kNotOddYear = 0;

int main() {
    int year;
    cin >> year;
    if(year % 4 == 0) {
        if(year % 400 == 0) cout << kIsOddYear << endl;
        else if(year % 100 == 0) cout << kNotOddYear << endl;
        else cout << kIsOddYear << endl;
    }
    else cout << kNotOddYear << endl;
    return 0; 
}