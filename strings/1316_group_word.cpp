#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
    int N;
    int count = 0;
    string input;
    cin >> N;
    bool is_group;
    array<int, 26> arr = { 0, };
    array<int, 26> store;
    for(int i = 0; i < N; i++) {
        is_group = true;
        store = arr;
        cin >> input;
        store[input[0] - 97]++;
        for(int j = 1; j < input.size(); j++) {
            if(input[j - 1] != input[j]) {
                store[input[j] - 97]++;
                if(store[input[j] - 97] > 1) {
                    is_group = false;
                    break;
                }
            }
        } 
        if(is_group) count++;
    }
    cout << count << endl;
    return 0;
}