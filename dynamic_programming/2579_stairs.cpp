#include <stdio.h>
#include <vector>

int n;
std::vector<int> input;

int get_max(int x, int y) { return x > y ? x : y; }

void get_points(std::vector<int> &v, int n) {
    if(n == 0) v[n] == input[0];
    else if(n == 1) {

    }
    else if(n == 2) {
        if(v[0] == 0) get_points(v, 0);
        v[n] == v[0]
    }
}

int main() {
    scanf("%d", &n);
    int x;
    std::vector<int> stairs(n, 0);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        input.push_back(x);
    }
    return 0;
}