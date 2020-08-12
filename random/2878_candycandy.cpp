#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long minimum(long long a, long long b) {
    return a > b ? b : a;
}

int main() {
    long m;
    long long sum = 0, given = 0, rage = 0;
    long long leftover, democracy;
    long long divider = pow(2, 64);
    int n, i;
    cin >> m >> n;
    vector<long> desire(n);
    for(i = 0; i < n; i++) {
        cin >> desire[i];
        sum += (long long) desire[i];
    }
    sort(desire.begin(), desire.end());
    leftover = sum - (long long) m;

    for(i = 0; i < n; i++) {
        if(leftover == 0) continue;
        given = desire[i] < leftover / (n - i) ? desire[i] : leftover / (n - i);
        leftover -= given;
        rage += given * given;
        rage %= divider;

    }
    
    cout << rage % divider << endl;
    return 0;
}