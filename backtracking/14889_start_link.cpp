#include <stdio.h>
#include <vector>

int n;
int min = 1000000000;

int abs(int x) {
    return x > 0? x : (-x);
}

void get_minimum(std::vector<std::vector<int> >v, std::vector<int> s, int stage) {
    if(stage == n / 2) {
        std::vector<int> diff;
        int sum1 = 0, sum2 = 0;
        int index = 0;
        for(int i = 0; i < n; i++) {
            if(s[index] != i) diff.push_back(i);
            else index++;
        }
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n / 2; j++) {
                sum1 += v[s[i]][s[j]];
                sum2 += v[diff[i]][diff[j]];
            }
        }
        if(abs(sum1 - sum2) < min) min = abs(sum1 - sum2);
        return;
    }
    for(int i = s[stage - 1] + 1; i < n; i++) {
        s.push_back(i);
        get_minimum(v, s, stage + 1);
        s.pop_back();
    }
}

int main() {
    scanf("%d", &n);
    std::vector<std::vector <int> > v(n);
    for(int i = 0; i < n; i++) {
        v[i] = std::vector<int>(n);
        for(int j = 0; j < n; j++) scanf("%d", &v[i][j]);
    }
    std::vector<int> start;
    start.push_back(0);
    get_minimum(v, start, 1);
    printf("%d\n", min);
    return 0;
}