#include <stdio.h>
#include <vector>

using namespace std;

void rec(vector<int> v, vector<bool> used, int num, int target) {
    if(num > target) {
        for(int i = 0; i < target; i++) printf("%d ", v[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < used.size(); i++) {
        if(used[i] == true) continue;
        used[i] = true;
        v[num - 1] = i + 1;
        rec(v, used, num + 1, target);
        used[i] = false;
        v[num - 1] = 0;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(m, 0);
    vector<bool> used(n, false);

    rec(v, used, 1, m);
 
    return 0;
}