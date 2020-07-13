#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    int R;
    string S;
    vector<string> v;
    cin >> T;
    for(int i = 0; i < T; i++) {
        string new_string;
        cin >> R;
        cin >> S;
        for(int j = 0; j < S.size(); j++) {
            for(int k = 0; k < R; k++) new_string.push_back(S[j]);
        }
        v.push_back(new_string);
    }
    for(int i = 0; i < v.size(); i++) cout << v[i] << endl;
    return 0;
}