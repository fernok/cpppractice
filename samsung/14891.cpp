#include <bits/stdc++.h>

#define RIGHT 1
#define LEFT -1
#define ROT(dir) ((dir) == RIGHT ? (LEFT) : (RIGHT))

using namespace std;

int wheel[4][8];

int k;

queue<pair<int, int> > q;

void setting(int index, int num) {
    for (int i = 0; i < 8; i++) {
        wheel[index][7 - i] = num % 10;
        num /= 10;
    }
}

void rotate(int index, int direction) {
    if (direction == LEFT) {
        int temp = wheel[index][0];
        for (int i = 0; i < 7; i++) {
            wheel[index][i] = wheel[index][i + 1];
        }
        wheel[index][7] = temp;
    } else {
        int temp = wheel[index][7];
        for (int i = 7; i >= 1; i--) {
            wheel[index][i] = wheel[index][i - 1];
        }
        wheel[index][0] = temp;
    }
}

bool is_rotating(int left_index, int right_index, int changing_index, int direction) {
    if (wheel[left_index][2] == wheel[right_index][6]) {
        return true;
    } else {
        if (changing_index == RIGHT) rotate(right_index, direction);
        else rotate(left_index, direction);
        return false;
    }
}

int main() {
    int i, j;
    int temp;

    for (i = 0; i < 4; i++) {
        cin >> temp;
        setting(i, temp);
    }

    cin >> k;

    int x, y;
    for (i = 0; i < k; i++) {
        cin >> x >> y;
        q.push(make_pair(x, y));
    }

    int index;
    int direction;
    int temp_dir;
    bool stop;
    int limit;

    for (i = 0; i < k; i++) {
        index = q.front().first - 1;
        direction = q.front().second;
        q.pop();

        stop = false;
        temp_dir = direction;
        limit = index;
        for (j = index + 1; j < 4; j++) {
            if (wheel[j - 1][2] != wheel[j][6]) limit = j;
            else break;
        }

        for (j = index + 1; j <= limit; j++) {
            temp_dir = ROT(temp_dir);
            rotate(j, temp_dir);
        }

        stop = false;
        temp_dir = direction;
        limit = index;
        for (j = index - 1; j >= 0; j--) {
            if (wheel[j][2] != wheel[j + 1][6]) limit = j;
            else break;
        }
        for (j = index - 1; j >= limit; j--) {
            temp_dir = ROT(temp_dir);
            rotate(j, temp_dir);
        }

        rotate(index, direction);

    }

    int mult = 1;
    int answer = 0;
    for (i = 0; i < 4; i++) {
        answer += mult * wheel[i][0];
        mult  *= 2;
    }

    cout << answer << endl;

    return 0;
}