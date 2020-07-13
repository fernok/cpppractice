#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        count++;
        if(s[i] == 'c') {
            if(i != s.size() - 1) {
                if(s[i + 1] == '=' || s[i + 1] == '-') i++;
            }
            continue;
        }
        if(s[i] == 'd') {
            if(i != s.size() - 1) {
                if(s[i + 1] == '-') i++;
                else if(i != s.size() - 2) {
                    if(s[i + 1] == 'z' && s[i + 2] == '=') i += 2;
                }
            }
            continue;
        }
        if(s[i] == 'l') {
            if(i != s.size() - 1) {
                if(s[i + 1] == 'j') i++;
            }
            continue;
        }
        if(s[i] == 'n') {
            if(i != s.size() - 1) {
                if(s[i + 1] == 'j') i++;
            }
            continue;
        }
        if(s[i] == 's') {
            if(i != s.size() - 1) {
                if(s[i + 1] == '=') i++;
            }
            continue;
        }
        if(s[i] == 'z') {
            if(i != s.size() - 1) {
                if(s[i + 1] == '=') i++;
            }
            continue;
        }
        
    }
    cout << count << endl;
    return 0;
}