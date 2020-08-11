#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int result = 0;
    int count = 0;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '(') count++;
        else if(input[i] == ')' && input[i - 1] == '(') {
            count--;
            result += count;
        }
        else {
            count--;
            result++;
        }
    }

    cout << result << endl;

    return 0;
}