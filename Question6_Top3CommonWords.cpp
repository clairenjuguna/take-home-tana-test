#include <bits/stdc++.h>
using namespace std;

vector<string> top3CommonWords(const string& sentence) {
    unordered_map<string,int> freq;
    string token;
    stringstream ss(sentence);
    while (ss >> token) ++freq[token];

    /* pull all words into a vector, then partial‑sort by frequency */
    vector<pair<string,int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second != b.second ? a.second > b.second    // higher freq first
                                   : a.first   < b.first;    // tie → alpha
    });

    /* pick the first (up to) 3, then alpha‑sort as final step */
    vector<string> top;
    for (int i = 0; i < 3 && i < (int)v.size(); ++i)
        top.push_back(v[i].first);
    sort(top.begin(), top.end());            // ascending alphabetical order
    return top;
}

int main() {
    auto res = top3CommonWords(
        "hi there care to discuss algorithm basis or how to solve algorithm or");
    for (auto& w : res) cout << w << ' ';    // algorithm or to
    cout << '\n';
}