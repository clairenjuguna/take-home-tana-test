#include <bits/stdc++.h>
using namespace std;

// This function checks if a word follows the given rules
bool isValid(const string& s, const unordered_set<char>& valid) {
    for (size_t i = 0; i < s.size(); ++i) {
        // rule 1: no same letters next to each other
        if (i && s[i] == s[i - 1]) return false;
        // rule 2: must be in the list of allowed characters
        if (!valid.count(s[i])) return false;
    }
    return true;
}

// This function finds the longest word that passes the rules
string getLongestString(const vector<char>& chars,
                        const vector<string>& candidates) {
    unordered_set<char> valid(chars.begin(), chars.end());
    string longest;

    for (const string& w : candidates) {
        // if it's valid and longer than what we have, we save it
        if (isValid(w, valid) && w.size() > longest.size())
            longest = w;
    }
    return longest;
}

// test run 
int main() {
    vector<char> chars = {'A','B','C','D'};
    vector<string> list = {"AABCDA", "ABCDZADC", "ABCDBCA", "ABCDABDCA"};
    cout << getLongestString(chars, list) << '\n'; // should print ABCDABDCA
}
