#include <iostream>
#include <string>

using namespace std;

int main() {
    int numbers[10] = {0,};
    int max = 0;
    string input;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        numbers[input[i] - 48]++;
    }
    for(int i = 0; i < 9; i++) {
        if(i == 6) continue;
        if(max < numbers[i]) max = numbers[i];
    }
    max = max < ((numbers[6] + numbers[9]) / 2 + (numbers[6] + numbers[9]) % 2) ? ((numbers[6] + numbers[9]) / 2 + (numbers[6] + numbers[9]) % 2) : max;
    cout << max << endl;
    return 0;
}