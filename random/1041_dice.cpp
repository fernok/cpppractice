#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dice[6];

int get_two(int large) {
    int small = 51 * 2;
    for(int i = 0; i < 5; i++) {
        if(i == large) continue;
        for(int j = i + 1; j < 6; j++) {
            if(j == large) continue;
            if(dice[i] + dice[j] < small) small = dice[i] + dice[j];
        }
    }
    return small;
}

int sum_three(int x, int y, int z) {
    return dice[x] + dice[y] + dice[z];
}

int get_three() {
    int small = 51 * 3;
    if(sum_three(0, 1, 2) < small) small = sum_three(0, 1, 2);
    if(sum_three(0, 1, 3) < small) small = sum_three(0, 1, 3);
    if(sum_three(0, 2, 4) < small) small = sum_three(0, 2, 4);
    if(sum_three(0, 3, 4) < small) small = sum_three(0, 3, 4);
    if(sum_three(5, 1, 2) < small) small = sum_three(5, 1, 2);
    if(sum_three(5, 2, 4) < small) small = sum_three(5, 2, 4);
    if(sum_three(5, 3, 4) < small) small = sum_three(5, 3, 4);
    if(sum_three(5, 1, 3) < small) small = sum_three(5, 1, 3);

    return small;

}

int main() {
    int i;
    long long n;
    long long sum = 0;
    int a, b, c, d, e, f;
    int small = 51, large = 0, large_index = -1;
    cin >> n;
    for(i = 0; i < 6; i++) {
        cin >> dice[i];
    }

    if(n == 1) {
        sort(dice, dice + 6);
        for(i = 0; i < 5; ++i) sum += dice[i];
        cout << sum << endl;;
        return 0;
    }
    int two = get_two(large_index);
    int three = get_three();

    long long th3 = 4 * three;
    long long tw2 = two * (8 * n - 12);
    long long one = small * ((n - 2) * (n - 2) * 5 + (n - 2) * 4);
    sum = th3 + tw2 + one;
    cout << sum << endl;

    // cout << 4 * three + 5 * small * (n - 2) * (n - 2) + 4 * small * (n - 2) + 8 * two * (n - 2) + two * 4 << endl;

    return 0;
}

