// ✅ Problem: Collecting Numbers II
// 🔗 Link: https://cses.fi/problemset/task/2217
// 🧠 Idea: Track the order of numbers from 1 to n, and count how many times that order breaks.
//    When two numbers are swapped, only their immediate surroundings are affected.
// 🚀 Time: O(n + t * log k), where k is a small constant set size (since we only check nearby elements)
// 🧠 Space: O(n)

// 🔥 Approach:
// 1. Build a `pos` array: pos[i] tells where number i is in the input.
// 2. Initially count the number of "rounds" needed where pos[i] < pos[i-1].
// 3. For each swap query, only positions of i, i+1, j, j+1 can affect the count.
// 4. Subtract their contributions before swap, update pos and v, then add back.



#include<bits/stdc++.h>
using namespace std;

int check(int i, vector<int>& pos){
    if(i > 1 && pos[i] < pos[i - 1])
        return 1;
    return 0;
}

int count(vector<int>& pos, int n){
    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]) cnt++;
    }
    return cnt;
}

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for(int i = 0; i < n; i++)      cin >> v[i];

    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        pos[v[i]] = i;
    }

    int rounds = count(pos, n);

    while(t--){
        int x, y;
        cin >> x >> y;

        int i = v[x - 1];
        int j = v[y - 1];

        set<int> affected = {i, i+1, j, j+1};
        for(int val : affected){
            if(val >= 1 && val <= n)
                rounds -= check(val, pos);
        }

        swap(v[x - 1], v[y - 1]);
        swap(pos[i], pos[j]);

        for(int val : affected){
            if(val >= 1 && val <= n)
                rounds += check(val, pos);
        }

        cout << rounds << endl;
    }

    return 0;
}
