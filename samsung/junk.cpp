#include <iostream>


#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> primes, answer;

void solve(vector<int> v) {
    for (int i = 0; i < primes.size(); i++) {
        if (v.size() % primes[i] == 0) {
            if (v.size() == primes[i]) {
                // answer.insert(answer.end(), v.begin(), v.end());
                return;
            }
            vector<vector<int> > t(primes[i]);
            for (int j = 0; j < v.size(); j++) {
                t[j % primes[i]].push_back(v[j]);
            }
            for (int j = 0; j < primes[i]; j++) {
                solve(t[j]);
            }
            return;
        }
    }
    return;
}

void get_prime(vector<int> allnum) {
    for (int i = 2; i < allnum.size(); i++) {
        if (allnum[i] == 0) continue;
        for (int j = 2 * i; j < allnum.size(); j += i) {
            allnum[j] = 0;
        }
    }
    for (int i = 2; i <= allnum.size(); i++) {
        if (allnum[i]) primes.push_back(i);
    }
    return;
}

vector<int> solution(int n) {
    vector<int> mainvec;
    for (int i = 1; i <= n ; i++) {
        mainvec.push_back(i);
    }
    
    get_prime(mainvec);
    
    solve(mainvec);
    
    // vector<int> answer;
    // cout << answer << endl;
    return answer;
}

int main() {
    solution(12);
    return 0;
}