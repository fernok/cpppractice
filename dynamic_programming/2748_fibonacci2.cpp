#include <stdio.h>
#include <vector>

std::vector<long int> fibonacci(90, -1);

long int fib(int n) {
    switch(n) {
        case 0:
            fibonacci[n] = 0;
            return 0;
        case 1:
            fibonacci[n] = 1;
            return 1;
        default:
            if(fibonacci[n - 2] == -1) fibonacci[n - 2] = fib(n - 2);
            if(fibonacci[n - 1] == -1) fibonacci[n - 1] = fib(n - 1);
            fibonacci[n] = fibonacci[n - 2] + fibonacci[n - 1];
            return fibonacci[n];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%ld\n", fib(n));
    return 0;
}