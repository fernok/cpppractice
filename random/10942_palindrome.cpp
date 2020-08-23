#include <iostream>
#include <vector>

using namespace std;

int input[2001];

int palindrome(int left, int right) {
    int sum = 0;
    if((right - left) % 2) {
        while(left != right) {
            if(input[left++] == input[right--]) continue;
            else return 0;
        }
        return 1;
    }
    else {
        while(left < right) {
            if(input[left++] == input[right--]) continue;
            else return 0;
        }
        return 1;
    }
    
}

int main() {
    int n, m;
    int left, right;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> input[i];
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> left >> right;
        cout << palindrome(left, right) << endl;
    }
    return 0;
}