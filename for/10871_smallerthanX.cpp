#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, in;
    int count = 0;
    cin >> N >> X;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> in;
        if(in < X) { 
            v.push_back(in);
            count++;
        }
    }
    cout << "We are : " << v.front() << endl;
    for(int j = 0; j < count; j++) {
        cout << v.at(j) << " ";
    }
    cout << endl;
    return 0;
}