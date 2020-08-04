#include <stdio.h>
#include <vector>

using namespace std;

typedef struct _rel {
    int node;
    int input;          // change
    int total_relation;
    int diff_number;    // change
} rel;

int how_different(vector<int> input, vector<int> relationship) {
    int count = 0;
    for(int i = 0; i < relationship.size(); i++) {
        if(input[i * 2] != input[i * 2 + 1]) count++;
    }
    return count;
}

int run(vector<rel> relationship, int diff, int opp, int index) {
    if(index == relationship.size()) return diff + opp;
    int x = run(relationship, diff, opp, index + 1);
    relationship[index].input = (relationship[index].input + 1) % 2;
    diff = diff - 2 * relationship[index].diff_number + relationship[index].total_relation;
    relationship[index].diff_number = relationship[index].total_relation - relationship[index].diff_number;
    int y = run(relationship, diff, opp + 1, index + 1);
    return x < y ? x : y;
}

int main() {
    int people, relation, i, j, k;
    vector<int> result;
    vector<rel> master;
    int num_different_vote = 0; // different vote between friends
    scanf("%d %d", &people, &relation);
    while(people != 0) {
        master.reserve(people);
        num_different_vote = 0;
        for(i = 0; i < people; i++) {
            scanf("%d", &j);
            master[i].node = i + 1;
            master[i].input = j;
        }
        for(i = 0; i < relation; i++) {
            scanf("%d %d", &j, &k);
            master[j - 1].total_relation++;
            master[k - 1].total_relation++;
            if(master[j - 1].input != master[k - 1].input) {
                master[j - 1].diff_number++;
                master[k - 1].diff_number++;
                num_different_vote++;
            }
        }

        result.push_back(run(master, num_different_vote, 0, 0));

        // result.push_back(num_different_vote + num_opposite_vote);
        scanf("%d %d", &people, &relation);
    }
    
    for(i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}