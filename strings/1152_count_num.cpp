#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int count = 0;
    getline(cin, s);
    if(s[0] != 32) count++;
    for(int i = 1; i < s.size(); i++) {
        if(s[i - 1] != 32) continue;
        count++;
    }
    cout << count << endl;
    return 0;
}