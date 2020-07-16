#include <stdio.h>
#include <vector>

std::vector<long int> p(100, 0);

void padovan(int x) {
    if(x == 1 || x == 2 || x == 3) p[x - 1] = 1;
    else if(x == 4 || x == 5) p[x - 1] = 2;
    else {
        if(p[x - 2] == 0) padovan(x - 1); 
        if(p[x - 6] == 0) padovan(x - 5);
        p[x - 1] = p[x - 2] + p[x - 6];
    }
}

int main() {
    int n, m;
    int max = -1;
    std::vector<int> input, result;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(m > max) max = m;
        input.push_back(m);
    }
    for(int i = 0; i < n; i++) {
        padovan(input[i]);
        printf("%ld\n", p[input[i] - 1]);
    }
    return 0;
}