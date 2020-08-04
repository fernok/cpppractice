#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int did_take;
int N;
bool possible = true;

vector<int> should_take;

void pick(vector<int> v) {
    
}

int main() {
    cin >> did_take;
    vector<int> classes_taken(did_take);
    if(did_take == 0) {
        // ignore line
        fgetc(stdin);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else {
        for(int i = 0; i < did_take; i++) {
            cin >> classes_taken[i];
        }
    }
    cin >> N;
    vector<vector<int> > class_list(N);
    for(int i = 0; i < N; i++) {
        class_list[i] = vector<int>(100);
        cin >> class_list[i][0] >> class_list[i][1];
        for(int j = 0; j < class_list[i][1]; j++) cin >> class_list[i][j + 2];
        sort(class_list[i].begin() + 2, class_list[i].begin() + class_list[i][1] + 2);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < class_list[i][1]; j++) {
            cout << class_list[i][j + 2] << " ";
        }
        cout << endl;
    }
    if(possible) {

    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}