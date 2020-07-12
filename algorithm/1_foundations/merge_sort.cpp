#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

// set inf to largest possible integer
const int inf = numeric_limits<int>::max();

void merge(vector<int> &v, int p, int q, int r) {
    vector<int> left_v(v.begin() + p, v.begin() + q + 1);
    vector<int> right_v(v.begin() + q + 1, v.begin() + r + 1);
    left_v.push_back(inf);
    right_v.push_back(inf);
    int left = 0, right = 0;
    for(int i = p; i <= r; i++) {
        if(left_v[left] <= right_v[right]) v[i] = left_v[left++];
        else v[i] = right_v[right++];
    }
}

void merge_sort(vector<int> &v, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    vector<int> v;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 999);

    for(int i = 0; i < 10000; i++) {
        v.push_back(dis(gen));
    }

    merge_sort(v, 0, v.size() - 1);

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time Taken : " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " µs" << std::endl;

    //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

    return 0;
}