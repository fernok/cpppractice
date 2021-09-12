#include <vector>
#include <string>
#include <iostream>


using namespace std;

long long largest = -1;

void print(vector<int> v) {
    for (auto c : v) cout << c << " ";
}

vector<long long> parse(int n, int k) {
    vector<int> parsed;
    vector<long long> result;

    cout << n << " " << k;
    
    while (n) {
        parsed.push_back(n % k);
        n = n / k;
    }
    
    reverse(parsed.begin(), parsed.end());

    print(parsed);
    
    long long connected = 0;
    for (auto p : parsed) {
        if (p == 0) {
            if (connected != 0 ) result.push_back(connected);
            if (connected > largest) largest = connected;
            connected = 0;
            continue;
        }
        connected = connected * 10 + p;
    }
    if (connected != 0 ) result.push_back(connected);
    if (connected > largest) largest = connected;
    
    parsed.clear();
    
    return result;
}

vector<bool> get_prime(long long n) {
    vector<bool> result(n + 1, 0);
    
    long long i, j;
    
    for (i = 2; i <= n; i++) {
        result[i] = true;
    }
    
    for (i = 2; i <= n; i++) {
        if (result[i] == false) continue;
        for (j = 2 * i; j <= n; j += i) {
            result[j] = false;
        }
    }
    
    return result;
}


int solution(int n, int k) {
    int answer = 0;

    cout << "a" ;
    vector<long long> parsed;
    parsed = parse(n, k);

    cout << "parsed, ";
    
    vector<bool> primes;
    primes = get_prime(largest);

    cout << "primed! " << endl;
    
    for (auto p : parsed) {
        if (primes[p]) answer++;
        // if (is_prime(p)) answer++;
    }
    
    return answer;
}

int main() {
    int n, k;

    // primes = get_prime(1000000);

    // print(primes);

    // if (primes[1111111])

    cout << "aaaa" << endl;

    cout << solution(797161, 3) << endl;
    // for (int i = 3267; i <= 1000000; i++) {
    //     for (int j = 3; j <= 10; j++) {
    //         cout << i << " " << j << endl;
    //         cout << "(" << i << "," << j << ")" << solution(i, j) << " ";
    //     }
    // }
    return 0;
}