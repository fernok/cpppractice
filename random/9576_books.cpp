#include <iostream>
#include <vector>

using namespace std;

int person[1001];
bool book_is_chosen[1001];
vector<pair<int, int> > request;

bool dfs(int x) {
    int t;
    for(int i = 0; i < request[x].second - request[x].first + 1; ++i) {
        t = request[x].first + i;
        if(book_is_chosen[t]) continue;
        book_is_chosen[t] = true; 
        if(person[t] == 0 || dfs(person[t])) {
            person[t] = x;
            return true;
        }
    }
    return false;
}

int main() {
    int num_case, n, m, cnt, start, end;
    vector<int> result;
    cin >> num_case;
    while(num_case--) {
        // n: number of books, m: number of people
        cin >> n >> m;

        request.clear();
        request.push_back(pair<int, int>(0, 0));

        for(int i = 0; i < m; i++) {
            cin >> start >> end;
            request.push_back(pair<int, int>(start, end));
        }

        cnt = 0;

        fill(person, person + 1001, 0);
        
        for(int i = 1; i <= m; i++) {
            fill(book_is_chosen, book_is_chosen + 1001, false);
            if (dfs(i)) cnt++;
        }

        result.push_back(cnt);
    }

    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;

    return 0;
}

// bool dfs(int *person, bool *is_chosen, ab *v, int x) {
//     for(int i = v[x].a; i <= v[x].b; i++) {
//         if(is_chosen[i]) continue;
//         is_chosen[i] = true;
//         if(person[i] == -1 || dfs(person, is_chosen, v, person[i])) {
//             person[i] = x;
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int num_case, n, m, cnt;
//     vector<int> result;
//     cin >> num_case;
//     while(num_case-- > 0) {
//         cin >> n >> m;
//         ab request[m];
//         int person_for_book[n];
//         bool book_is_chosen[n];
//         for(int i = 0; i < m; i++) {
//             cin >> request[i].a >> request[i].b;
//         }
//         cnt = 0;
//         fill(person_for_book, person_for_book + n, -1);
//         for(int i = 0; i < m; i++) {
//             fill(book_is_chosen, book_is_chosen + n, false);
//             if(dfs(person_for_book, book_is_chosen, request, i)) cnt++;
//         }
//         result.push_back(cnt);
//         // result.push_back(distribute(n, request));
//     }

//     for(int i = 0; i < result.size(); i++) cout << result[i] << endl;

//     return 0;
// }