#include <stdio.h>
#include <vector>

using namespace std;

int abs(int x) {
    return x > 0? x : -x;
}

void run_queen(vector<int>board, int now, int n, int *c) {
    bool is_placeable;
    if(now == n) {
        (*c)++;
        return;
    }
    for(int i = 0; i < n; i++) {
        is_placeable = true;
        for(int j = 0; j < now; j++) {
            if(board[j] == i || abs(now - j) == abs(i - board[j])) {
                is_placeable = false;
                break;
            }
        }
        if(is_placeable) {
            board[now] = i;
            run_queen(board, now + 1, n, c);
        }
    }
}

int main() {
    int N;
    int count = 0;
    scanf("%d", &N);

    vector<int> board(N, 0);

    run_queen(board, 0, N, &count);
    
    printf("%d\n", count);
    return 0;
}