#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    int max_score;
    int score = 0;
    cin >> n;
    vector<string> answer(n);
    unordered_map<string, int> war;
    vector<string> hyunwu(n);
    string left;
    for(int i = 0; i < n; i++) {
        cin >> answer[i];
        war.insert(make_pair(answer[i], i));
    }
    for(int i = 0; i < n; i++) cin >> hyunwu[i];
    max_score = n * (n - 1) / 2;
    for(int i = 0; i < n - 1; i++) {
        left = hyunwu[i];
        for(int j = i + 1; j < n; j++) {
            if(war[left] < war[hyunwu[j]]) score++;
        }
    }

    cout << score << "/" << max_score << endl;

    return 0;
}