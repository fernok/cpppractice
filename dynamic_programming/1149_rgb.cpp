#include <stdio.h>
#include <vector>

using namespace std;

class Cost {
    public:
        int rgb[3];
        int cost[3];
        
        void initialize(int x, int y, int z);
};

void Cost::initialize(int x, int y, int z) {
    rgb[0] = x;
    rgb[1] = y;
    rgb[2] = z;
}

vector<Cost> houses;

int small(int x, int y) { return x < y? x : y; }

int main() {
    int n, r, g, b;
    scanf("%d", &n);
    Cost new_house;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &r, &g, &b);
        new_house.initialize(r, g, b);
        houses.push_back(new_house);
    }
    for(int i = 0; i < 3; i++) houses[0].cost[i] = houses[0].rgb[i];
    for(int i = 1; i < n; i++) {
        houses[i].cost[0] = small(houses[i - 1].cost[1], houses[i - 1].cost[2]) + houses[i].rgb[0];
        houses[i].cost[1] = small(houses[i - 1].cost[0], houses[i - 1].cost[2]) + houses[i].rgb[1];
        houses[i].cost[2] = small(houses[i - 1].cost[1], houses[i - 1].cost[0]) + houses[i].rgb[2];
    }
    printf("%d\n", small(small(houses[n - 1].cost[0], houses[n - 1].cost[1]), houses[n - 1].cost[2]));
    return 0;
}