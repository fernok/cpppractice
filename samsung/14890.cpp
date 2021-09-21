#include <bits/stdc++.h>

#define ABS(x) ((x) > 0 ? (x) : ((-1) * (x)))
#define OVER2(x) (ABS(x) > 1 ? (1) : (0))

using namespace std;

int n, l;
int grid[100][100];

int answer = 0;

int main() {
    int i, j, k;
    
    cin >> n >> l;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        
    }

    cout << answer << endl;

    return 0;
}