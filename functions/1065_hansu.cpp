#include <iostream>
#include <vector>
using namespace std;

bool is_hansu(int n) {
    if(n < 10) return true;
    int diff = (n / 10) % 10 - n % 10;
    while(n >= 10) {
        if(diff != (n / 10) % 10 - n % 10) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int N;
    int count = 0;
    vector<int> v;
    cin >> N;
    for(int i = 1; i <= N; i++) if(is_hansu(i)) count++;
    cout << count << endl;
    return 0;
}