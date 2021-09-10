#include <iostream>
#include <cstring>

using namespace std;

bool words[10000000];
int map[4][4];
int sum;

void DFS(int i, int j, int level, int aggr) {
    int new_aggr = aggr * 10 + map[i][j];
    if (level == 6) {
        words[new_aggr] = true;
        return;
    }

    if (i + 1 <= 3) DFS(i + 1, j, level + 1, new_aggr);
    if (i - 1 >= 0) DFS(i - 1, j, level + 1, new_aggr);
    if (j + 1 <= 3) DFS(i, j + 1, level + 1, new_aggr);
    if (j - 1 >= 0) DFS(i, j - 1, level + 1, new_aggr);

    return;
}

int main(int argc, char** argv) {
    int test_case;
    int T;
    
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        memset(words, false, sizeof(words));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                DFS(i, j, 0, 0);
            }
        }

        sum = 0;
        for (int i = 0; i < 10000000; i++) if (words[i]) sum++;

        cout << "#" << test_case << " " << sum << endl;
    }
    return 0;
}