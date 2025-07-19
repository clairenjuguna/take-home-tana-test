#include <bits/stdc++.h>
using namespace std;

vector<string> rotateRight(vector<string> ids, int n) {
    // if the input list is empty, just return it as is
    if (ids.empty()) return ids;

    // if n is bigger than the size, we wrap it around
    n %= ids.size();

    // rotate the vector to the right by n positions
    rotate(ids.rbegin(), ids.rbegin() + n, ids.rend());

    return ids;
}

int main() {
    vector<string> ids = {
        "ID_A01","ID_A02","ID_A03","ID_A04","ID_A05","ID_A06"};

    // call the rotateRight function with n = 2
    auto out = rotateRight(ids, 2);

    // print the rotated result
    for (auto& x : out) cout << x << ' ';
    cout << '\n';  // Expected: ID_A05 ID_A06 ID_A01 ID_A02 ID_A03 ID_A04
}
