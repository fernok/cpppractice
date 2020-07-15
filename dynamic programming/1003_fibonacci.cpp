#include <stdio.h>
#include <vector>

typedef struct _zo {
    int zero;
    int one;
} zo;

zo arr[41];

void fibonacci(int n) {
    if (n == 0) {
        arr[0].zero = 1;
        return;
    } else if (n == 1) {
        arr[1].one = 1;
        return;
    } else {
        if(arr[n - 1].zero == 0 && arr[n - 1].one == 0) fibonacci(n - 1);
        if(arr[n - 2].zero == 0 && arr[n - 2].one == 0) fibonacci(n - 2);
        arr[n].zero = arr[n - 1].zero + arr[n - 2].zero;
        arr[n].one = arr[n - 1].one + arr[n - 2].one;
        return;
    }
}

int main() {
    int t, n;
    int max = -1;
    std::vector<int> result;
    scanf("%d", &t);
    for(int i = 0; i < 41; i++) {
        arr[i].zero = 0;
        arr[i].one = 0;
    }
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        result.push_back(n);
        if(max < n) max = n;
    }
    fibonacci(max);
    for(int i = 0; i < t; i++) {
        n = result[i];
        printf("%d %d\n", arr[n].zero, arr[n].one);
    }
    return 0;
}