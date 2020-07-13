#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v(26, 0);
    string s;
    int max = 0;
    int index;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] - 97 < 0) index = s[i] - 65;
        else index = s[i] - 97;
        v[index]++;
        if(v[index] > max) max = v[index];
    }
    index = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == max) {
            index++;
            s = i + 65;
        }
    }
    if(index == 1) cout << s << endl;
    else cout << "?" << endl;
    return 0;
}