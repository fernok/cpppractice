#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int t, count;
    int input;
    vector<int> result;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        count = 0;
        scanf("%d", &input);

        for(int j = 5; j <= input; j *= 5) count += input / j;

        printf("%d\n", count);
    }

    return 0;
}