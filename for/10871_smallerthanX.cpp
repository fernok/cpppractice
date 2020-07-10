#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, in;
    cin >> N >> X;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        cin >> in;
        if(in < X) v.push_back(in);
    }
    for(int j = 0; j < v.size(); j++) {
        cout << v.at(j) << " ";
    }
    cout << endl;
    return 0;
}