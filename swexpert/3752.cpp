#include <iostream>

using namespace std;

bool used[10000];
int points[100];
int n;
int max_points;

void reset_used() {
    for (int i = 0; i < n; i++) used[i] = false;
    return;
}

void subtract(int x) {
    
}

int main(int argc, char** argv) {
    int test_case;
	int T;
    int i, j;

    cin >> T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        for (i = 0; i < 100; i++) {
            cin >> points[i];
            max_points += points[i];
        }

	}
    return 0;
}