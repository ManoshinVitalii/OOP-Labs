#include "solve.h"

int solve(int devider, int bound) {
    int ans = (bound / devider) * devider;
    return ans? ans : -1;
}
