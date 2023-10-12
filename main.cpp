#include <iostream>
#include "solve.h"
using namespace std;

int main() {
    int devider, bound, ans;

    cout << "Enter the devider \n";
    cin >> devider;
    cout << "Enter the  bound \n";
    cin >> bound;

    ans = solve(devider, bound);
    cout << "Answer is: " << ans << '\n';

    return 0;
}