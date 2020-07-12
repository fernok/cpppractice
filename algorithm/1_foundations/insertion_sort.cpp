#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

void insertion_sort(vector<int> &v) {
    int i, j, key;
    for(j = 1; j < v.size(); j++) {
        key = v[j];
        i = j - 1;
        while(i >= 0 && v[i] > key) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = key;
    }
}

int main() {
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    vector<int> v;

    // random_device for acquiring seed value
    random_device rd;

    // initialize random number generator engine using random_device
    mt19937 gen(rd());
    /*
     * this creates a random number generating engine object
     * based on the seed rd
     * can use a seed manually - mt19937 gen(1234);
     * Mersenne Twister
     */

    // uniform integer distribution between 0 and 99
    uniform_int_distribution<int> dis(0, 999);

    for(int i = 0; i < 10000; i++) {
        v.push_back(dis(gen));
    }

    insertion_sort(v);

    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    cout << "Time Taken : " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " µs" << std::endl;

    //for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

    return 0;
}
