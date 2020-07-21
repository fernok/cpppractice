#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

void bubble_sort(vector<int> &v) {
    int i, j, key;
    bool modified;
    for(i = 0; i < v.size() - 1; i++) {
        modified = false;
        for(j = v.size() - 1; j > i; j--) {
            if(v[j] < v[j - 1]) {
                key = v[j];
                v[j] = v[j - 1];
                v[j - 1] = key;
                modified = true;
            }
        }
        if(!modified) return;
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

    bubble_sort(v);

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Time Taken : " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " µs" << std::endl;

    //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

    return 0;
}
