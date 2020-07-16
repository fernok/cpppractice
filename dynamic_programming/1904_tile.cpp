#include <stdio.h>
#include <vector>

void count(std::vector<int>&v, int n) {
    if(n == 1) v[n - 1] = 1;
    else if(n == 2) v[n - 1] = 2;
    else {
        if(v[n - 2] == 0) count(v, n - 1);
        if(v[n - 3] == 0) count(v, n - 2);
        v[n - 1] = v[n - 2] + v[n - 3];
        v[n - 1] %= 15746;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> v(n, 0);
    count(v, n);
    printf("%d\n", v[n - 1] % 15746);
    return 0;
}