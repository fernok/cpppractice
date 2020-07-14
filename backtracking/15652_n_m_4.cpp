#include <stdio.h>
#include <vector>

using namespace std;

void rec(vector<int> v, int num, int size, int target) {
    if(num > target) {
        for(int i = 0; i < target; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < size; i++) {
        if(num >= 2) {
            if(v[num - 2] > i + 1) continue;
        }
        v[num - 1] = i + 1;
        rec(v, num + 1, size, target);
        v[num - 1] = 0;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m, 0);

    rec(v, 1, n, m);
 
    return 0;
}