#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dice[6];

int get_two() {
    int small = 51 * 2;
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 6; j++) {
            if(i + j == 5) continue;
            if(dice[i] + dice[j] < small) small = dice[i] + dice[j];
        }
    }
    return small;
}

int get_three() {
    int small = 51 * 2;

    for(int i = 1; i < 4; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(i + j == 5) continue;
            if(dice[i] + dice[j] < small) small = dice[i] + dice[j];
        }
    }

    return dice[0] > dice[5] ? dice[5] + small : dice[0] + small;

}

int main() {
    int i;
    long long n;
    long long sum = 0;
    int small = 51;
    cin >> n;
    for(i = 0; i < 6; i++) {
        cin >> dice[i];
        if(dice[i] < small) small = dice[i];
    }

    if(n == 1) {
        sort(dice, dice + 6);
        for(i = 0; i < 5; ++i) sum += dice[i];
        cout << sum << endl;;
        return 0;
    }

    int two = get_two();
    int three = get_three();

    long long th3 = 4 * three;
    long long tw2 = two * (8 * n - 12);
    long long one = small * ((n - 2) * (n - 2) * 5 + (n - 2) * 4);
    sum = th3 + tw2 + one;
    cout << sum << endl;

    return 0;
}

