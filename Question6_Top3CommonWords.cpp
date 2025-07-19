#include <bits/stdc++.h>
using namespace std;

vector<string> top3CommonWords(const string& sentence) {
    unordered_map<string,int> freq;
    string token;
    stringstream ss(sentence);

    // split sentence into words and count how many times each appears
    while (ss >> token) ++freq[token];

    // move all words with their count into a vector for sorting
    vector<pair<string,int>> v(freq.begin(), freq.end());

    // sort by how frequent a word is. if tie, use alphabetical order
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second != b.second ? a.second > b.second    // higher first
                                   : a.first   < b.first;    // tie? then by name
    });

    vector<string> top;
    // take the top 3 most common words
    for (int i = 0; i < 3 && i < (int)v.size(); ++i)
        top.push_back(v[i].first);

    // finally sort the 3 in alphabetical order
    sort(top.begin(), top.end());

    return top;
}

int main() {
    auto res = top3CommonWords(
        "hi there care to discuss algorithm basis or how to solve algorithm or");

    for (auto& w : res) cout << w << ' ';  // algorithm or to
    cout << '\n';
}
