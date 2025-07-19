#include <bits/stdc++.h>
using namespace std;

int closestMinDistance(const vector<int>& a) {
    // Get the smallest value in the array
    int mn = *min_element(a.begin(), a.end());

    int last = -1;              // will store index of last occurrence of min
    int best = INT_MAX;         // to keep track of the smallest distance

    for (int i = 0; i < static_cast<int>(a.size()); ++i) {
        if (a[i] == mn) {
            if (last != -1) {
                // compute distance between two min values
                best = min(best, i - last);
            }
            last = i;   // update last position of min value
        }
    }

    return best;  // return shortest distance found
}

int main() {
    cout << closestMinDistance({1,2,3,1,4,5,2}) << '\n';   // output should be 3
}
