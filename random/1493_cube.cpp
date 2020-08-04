#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int length, width, height;
int n;
int num = 0;

void fill_box(vector<int> &v, int index, int l, int w, int h) {
    if(l == 0 || w == 0 || h == 0 || num == -1) return;
    if(index < 0) {
        num = -1;
        return;
    }
    if(v[2 * index + 1] == 0) {
        fill_box(v, index - 1, l, w, h);
    }
    else {
        int size = (int) pow(2, index);
        if(size <= l && size <= w && size <= h) {
            num++;
            v[2 * index + 1]--;
            fill_box(v, index, l, w, h - size);
            fill_box(v, index, l - size, w, size);
            fill_box(v, index, size, w - size, size);
        }
        else {
            fill_box(v, index - 1, l, w, h);
        }
    }
}

int main() {
    cin >> length >> width >> height;
    cin >> n;
    vector<int> v(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> v[2 * i] >> v[2 * i + 1];
    }
    fill_box(v, n - 1, length, width, height);
    if(num == 0) num = -1;
    cout << num << endl;
    return 0;
}