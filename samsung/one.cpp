#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> senior;


int solution(vector<int> student, int k) {
    int i, j;
    
    for (i = 0; i < student.size(); i++) {
        if (student[i]) senior.push_back(i);
    }
    
    int answer = 0;
    
    // left_start, left_end [i] [j] right_start, right_end
    int left_start, left_end, right_start, right_end;
    for (i = 0, j = k - 1; j < senior.size(); i++, j++) {
        left_start = i > 0 ? senior[i - 1] + 1 : 0;
        // left_end = senior[i] - 1 >= 0 ? senior[i] : 0;
        left_end = senior[i];
        // right_start = senior[j] + 1 < student.size() ? senior[j] : student.size() - 1;
        right_start = senior[j];
        right_end = j < senior.size() - 1 ? senior[j + 1] - 1 : student.size() - 1;



        cout << left_start << " " << left_end << " " << right_start << " " << right_end << endl;

        answer += (left_end - left_start + 1) * (right_end - right_start + 1);
    }
    
    return answer;
}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    cout << solution(v, 2) << endl;
    return 0;
}