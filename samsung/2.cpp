#include <string>
#include <vector>

using namespace std;


int searched[26][30];
int days;
int issue_count[26];

string solution(vector<string> research, int n, int k) {
    int i, j, l;
    days = n;
    
    for (i = 0; i < 26; i++) {
        issue_count[i] = 0;
        for (j = 0; j < research.size(); j++) searched[i][j] = 0;
    }
    
    for (i = 0; i < research.size(); i++) {
        for (j = 0; j < research[i].size(); j++) {
            searched[int(research[i][j]) - 97][i]++;
        }
    }
    
    bool broken;
    int sum;
    for (i = 0; i < research.size() - (n - 1); i++) {
        for (j = 0; j < 26; j++) {
            broken = false;
            sum = 0;
            for (l = 0; l < n; l++) {
                if (searched[j][i + l] < k) {
                    broken = true;
                    break;
                }
                sum += searched[j][i + l];
            }
            if (!broken && sum >= 2 * n * k) {
                issue_count[j]++;
            }
        }
    }
    
    int best_index = -1;
    int best_current = -1;
    
    bool no_best = false;
    
    for (i = 0; i < 26; i++) {
        if (best_current < issue_count[i]) {
            best_index = i;
            best_current = issue_count[i];
            no_best = false;
        }
    }
    
    string answer;
    
    if (no_best || best_current == 0) answer = "None";
    else {
        char temp = 'a' + best_index;
        answer += temp;
    }
    
    return answer;
}