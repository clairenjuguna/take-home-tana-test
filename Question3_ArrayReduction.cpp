#include <bits/stdc++.h>
using namespace std;

// checks if it's possible to reduce array to all zeros
int canReduceToZero(const vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i)
        if (a[i] < a[i - 1]) return 0;  // if any element is smaller than the one before, not possible
    return 1;  // if the array is non-decreasing, it's always doable
}

int main() {
    cout << canReduceToZero({1,2,3}) << '\n';  // expected: 1  yses, possible
    cout << canReduceToZero({2,1})   << '\n';  // expected: 0  no, not possible

