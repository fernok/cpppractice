#include <iostream>
#include <string>
using namespace std;

const string alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

int main() {
    string S;
    cin >> S;
    for(int i = 0; i < sizeof(alphabet) / sizeof(alphabet[0]); i++) {
        if(S.find(alphabet[i], 0) >= S.length()) cout << "-1 ";
        else cout << S.find(alphabet[i], 0) << " ";
    }
    cout << endl;
    return 0;
}