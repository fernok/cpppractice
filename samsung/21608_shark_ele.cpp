#include <iostream>

using namespace std;

int n;
int seat[22][22];
int like[22][22];
int favorite[401][5];
int map[401];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << seat[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printl() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << like[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool likes(int id, int target) {
    if (target == -1) return false;
    for (int i = 1; i < 5; i++) {
        if (favorite[map[id]][i] == target) return true;
    }
    return false;
}

int get_score(int x, int y, int id) {
    int l = 0;
    int e = 0;

    if (seat[x - 1][y] == 0) e++;
    else if (likes(id, seat[x - 1][y])) l++;
    if (seat[x + 1][y] == 0) e++;
    else if (likes(id, seat[x + 1][y])) l++;
    if (seat[x][y - 1] == 0) e++;
    else if (likes(id, seat[x][y - 1])) l++;
    if (seat[x][y + 1] == 0) e++;
    else if (likes(id, seat[x][y + 1])) l++;
    
    return l * 10 + e;
}

void get_like(int x, int y) {
    int id = seat[x][y];
    if (likes(id, seat[x + 1][y])) {
        like[x][y]++;
    }
    if (likes(id, seat[x][y + 1])) {
        like[x][y]++;
    }
    if (likes(id, seat[x - 1][y])) {
        like[x][y]++;
    }
    if (likes(id, seat[x][y - 1])) {
        like[x][y]++;
    }
    return;
}

void traverse(int x, int y, int id, int score, int best_x, int best_y) {
    if (x == n && y == n) {
        if (seat[x][y]) seat[best_x][best_y] = id;
        else {
            int current_score = get_score(x, y, id);
            if (current_score > score) seat[x][y] = id;
            else seat[best_x][best_y] = id;
        }
        return;
    }

    int next_x = y + 1 > n ? x + 1 : x;
    int next_y = y + 1 > n ? 1 : y + 1;

    if (seat[x][y]) {
        traverse(next_x, next_y, id, score, best_x, best_y);
        return;
    }
    
    int current_score = get_score(x, y, id);
    
    if (current_score > score) traverse(next_x, next_y, id, current_score, x, y);
    else traverse(next_x, next_y, id, score, best_x, best_y);

    return;
}

int main(int argc, char** argv) {
    int i, j;

    cin >> n;
    // get input
    for (i = 0; i < n * n; i++) {
        for (j = 0; j < 5; j++) cin >> favorite[i][j];
        map[favorite[i][0]] = i;
    }
    // initialize seat array
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < n + 2; j++) {
            like[i][j] = 0;
            if (i == 0 || i == n + 1 || j == 0 || j == n + 1) seat[i][j] = -1;
            else seat[i][j] = 0;
        }
    }

    for (i = 1; i <= n * n; i++) {
        traverse(1, 1, favorite[i - 1][0], -1, 0, 0);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            get_like(i, j);
        }
    }

    int sum = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (like[i][j] == 0) continue;
            if (like[i][j] == 1) sum++;
            if (like[i][j] == 2) sum += 10;
            if (like[i][j] == 3) sum += 100;
            if (like[i][j] == 4) sum += 1000;
        }
    }

    // print();

    cout << sum << endl;

    return 0;
}