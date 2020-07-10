#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a) {
    int size = a.size();
    long long result = 0;
    for(int i = 0; i < size; i++) {
        result += a[i];
    }
    return result;
}

int main() {
    int in;
    vector<int> v;
    for(int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    long long result = 0;
    result = sum(v);
    cout << result << endl;
    return 0;
}