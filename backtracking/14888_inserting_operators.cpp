#include <stdio.h>
#include <vector>

int min = 1000000000;
int max = -1000000000;
int n;

int calculate(int x, int op, int y) {
    switch(op) {
        case 0:
            return x + y;
        case 1:
            return x - y;
        case 2:
            return x * y;
        case 3:
            if(x > 0) return x / y;
            else return -((-x) / y);
        default:
            return 0;
    }
}

void run_operator(std::vector<int> v, std::vector<int> op, int stage, int current) {
    if(stage == n) {
        if(current > max) max = current;
        if(current < min) min = current;
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(op[i] == 0) continue;
        op[i]--;
        run_operator(v, op, stage + 1, calculate(current, i, v[stage]));
        op[i]++;
    }
}

int main() {
    int i;
    scanf("%d", &n);
    std::vector<int> input(n, 0);
    std::vector<int> op(4, 0);
    for(i = 0; i < n; i++) scanf("%d", &input[i]);
    for(i = 0; i < 4; i++) scanf("%d", &op[i]);
    run_operator(input, op, 1, input[0]);
    printf("%d\n%d\n", max, min);
    return 0;
}