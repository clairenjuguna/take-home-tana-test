#include <bits/stdc++.h>
using namespace std;

// Depth-first search to find all combinations that sum to target
void dfs(const vector<int>& a, size_t idx,
         int running, int target,
         vector<int>& path,
         set<vector<int>>& unique) {

    // if current sum matches target, we store this combination
    if (running == target) {
        unique.insert(path);
        return;
    }

    // if the sum goes past target or we're out of bounds, stop
    if (running > target || idx == a.size()) return;

    // include the current number
    path.push_back(a[idx]);
    dfs(a, idx + 1, running + a[idx], target, path, unique);
    path.pop_back();  // backtrack so we can try other options

    // skip the current number and try the next one
    dfs(a, idx + 1, running, target, path, unique);
}

// this function starts the DFS and returns the count of unique combos
int countUniqueSums(const vector<int>& a, int target) {
    set<vector<int>> uniq;
    vector<int> tmp;
    dfs(a, 0, 0, target, tmp, uniq);
    return static_cast<int>(uniq.size());
}

// test case
int main() {
    cout << countUniqueSums({1,2,3,4,5}, 10) << '\n';  // expected 3
    cout << countUniqueSums({1,2,4,7,5}, 17) << '\n';  // expected 1
}
