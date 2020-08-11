#include <iostream>
#include <vector>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    char input;
    int count_row = 0, count_col = 0;
    vector<bool> row(n, false), col(m, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input;
            if(input == 'X') {
                row[i] = true;
                col[j] = true;
            }
        }
        if(row[i] == false) count_row++;
    }
    for(int i = 0; i < m; i++) if(col[i] == false) count_col++;
    int result = count_row > count_col ? count_row : count_col;
    cout << result << endl;
    return 0;
}