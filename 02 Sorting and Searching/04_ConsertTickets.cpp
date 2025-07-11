// ✅ Problem: Concert Tickets
// 🔗 Link: https://cses.fi/problemset/task/1091
// 🧠 Idea: Use multiset to keep ticket prices, find the highest ticket ≤ customer's max price
// 🚀 Time: O(m log n), Space: O(n) (due to multiset)

// 🔥 Approach:
// 1. Store all ticket prices in a multiset (sorted automatically, allows duplicates)
// 2. For each customer:
//    - Use `upper_bound(max_price)` to get first ticket > max_price
//    - Move one step left (if possible) to get ticket ≤ max_price
//    - If no ticket found, print -1
//    - Else, print ticket price and erase it (mark as sold)


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int max_price;
        cin >> max_price;

        auto it = tickets.upper_bound(max_price);

        if (it == tickets.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            tickets.erase(it); // sell ticket
        }
    }

    return 0;
}
