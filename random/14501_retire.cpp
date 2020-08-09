#include <iostream>
#include <vector>

typedef struct _work {
    int day;
    int cost;
    int profit;
} work;

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    int max_profit = 0;
    cin >> n;
    vector<work> v(17);
    for(int i = 1; i <= n; i++) {
        cin >> v[i].day >> v[i].cost;
        v[i].profit = 0;
    }

    for(int i = 1; i <= n; i++) {
        if(i + v[i].day <= n + 1) {
            v[i + v[i].day].profit = max(v[i + v[i].day].profit, v[i].profit + v[i].cost);
            max_profit = max(max_profit, v[i + v[i].day].profit);
        }
        v[i + 1].profit = max(v[i + 1].profit, v[i].profit);
        max_profit = max(max_profit, v[i + 1].profit);
    }

    cout << max_profit << endl;

    return 0;
}