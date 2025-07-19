#include <bits/stdc++.h>
using namespace std;

string firstUniqueProduct(const vector<string>& products) {
    unordered_map<string,int> freq;
    for (auto& p : products) ++freq[p];  // count how many times each product appears

    for (auto& p : products)
        if (freq[p] == 1) return p;      // return the first one that appears only once
    return "null";  // if no unique product found
}

int main() {
    cout << firstUniqueProduct({"Apple","Computer","Apple","Bag"}) << '\n';  // should print: Computer
}
