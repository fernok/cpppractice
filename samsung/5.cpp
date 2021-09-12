#include <string>
#include <vector>

using namespace std;

int nicksame[100][100] = {0,};
int emailsame[100][100] = {0,};

// zero, one, two
// zero - one, zero - two, one - one
vector<string> remove_one(string nick) {
    vector<string> result;
    string temp;
    for (int i = 0; i < nick.size(); i++) {
        temp = nick;
        result.push_back(temp.erase(i, 1));
    }
    return result;
}

vector<string> remove_two(string nick) {
    vector<string> result;
    string temp, temp2;
    for (int i = 0; i < nick.size(); i++) {
        temp = nick;
        temp.erase(i, 1);
        for (int j= 0; j < temp.size(); j++) {
            temp2 = temp;
            temp2.erase(j, 1);
            result.push_back(temp2);
        }
    }
    return result;
}

bool contains(string s, vector<string> v) {
    if (find(v.begin(), v.end(), s) != v.end()) return true;
    else return false;
}

bool ones_same(vector<string> a, vector<string> b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) return true;
        }
    }
    return false;
}

void check_id(vector<string> nicks) {
    vector<vector<string>> ones(nicks.size());
    vector<vector<string>> twos(nicks.size());
    
    for (int i = 0; i < nicks.size(); i++) {
        ones[i] = remove_one(nicks[i]);
        twos[i] = remove_two(nicks[i]);
    }
    
    bool zo, oz, zt, tz, oo;
    for (int i = 0; i < nicks.size(); i++) {
        for (int j = i + 1; j < nicks.size(); j++) {
            zo = contains(nicks[i], ones[j]);
            oz = contains(nicks[j], ones[i]);
            zt = contains(nicks[i], twos[j]);
            tz = contains(nicks[j], twos[i]);
            oo = ones_same(ones[i], ones[j]);
            if (zo || oz || zt || tz || oo)  {
                nicksame[i][j] = 1;
            }
        }
    }
}

int solution(vector<string> nicks, vector<string> emails) {
    int answer = -1;
    return answer;
}