#include <iostream>
#include <vector>
using namespace std;

void get_self_number(int i, vector<int> &v) {
    if(i > 10000) return;
    int sum = i;
    while(i != 0) {
        sum += i % 10;
        i /= 10;
    }
    v[sum - 1] = 0;
    get_self_number(sum, v);
    return;
}

int main() {
    vector<int> v;
    for(int i = 1; i <= 10000; i++) v.push_back(i);
    for(int i = 0; i < 10000; i++) {
        if(v[i] == 0) continue;
        cout << i + 1 << endl;
        get_self_number(i + 1, v);
    }
    return 0;
}