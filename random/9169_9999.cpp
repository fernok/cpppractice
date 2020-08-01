#include <stdio.h>
#include <vector>

using namespace std;

int num_different_vote = 0; // different vote between friends
int num_opposite_vote = 0;  // vote opposite to belief

int main() {
    int people, relation, i, j, k;
    vector<int> result;
    vector<int> input;
    vector<int> relation_vector;
    scanf("%d %d", &people, &relation);
    while(people != 0) {
        num_different_vote = 0;
        num_opposite_vote = 0;
        for(i = 0; i < people; i++) {
            scanf("%d", &j);
            input.push_back(j);
        }
        for(i = 0; i < relation; i++) {
            scanf("%d %d", &j, &k);
            relation_vector.push_back(j);
            relation_vector.push_back(k);
        }
        result.push_back(num_different_vote + num_opposite_vote);
        input.clear();
        relation_vector.clear();
        scanf("%d %d", &people, &relation);
    }
    
    for(i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}