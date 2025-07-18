// ✅ Problem: Towers (CSES)
// 🔗 Link: https://cses.fi/problemset/task/1073
// 🧠 Idea: Greedily place each cube on the *leftmost* tower where it can fit (i.e., cube < top).
//          If no such tower exists, start a new tower.
// 🚀 Time: O(n log n), Space: O(n)
// 📌 Uses custom binary search to simulate upper_bound (to avoid STL)

// 🔥 Approach:
// - Maintain a `tops[]` array that stores the top cube of each tower (in increasing order).
// - For each incoming cube:
//    🔍 Use binary search to find the first tower whose top > cube (because cube must go on top of a larger cube).
//    🧱 If such tower doesn't exist → start new tower.
//    🧩 Otherwise, place the cube on the found tower (replace the top).

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int upper_bound(vector<ll>& tops, int size, ll cube){
    int low = 0, high = size;
    int ans = size;

    while(low < high){
        int mid = (low + high) / 2;
        if(tops[mid] > cube){
            ans = mid;
            high = mid;
        } 
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<ll> tops; 
    int towers = 0;

    for(int i = 0; i < n; i++){
        ll cube;
        cin>>cube;

        int pos = upper_bound(tops, towers, cube);

        if(pos == towers){
            // 🔨 No tower found, make new tower
            tops.push_back(cube);
            towers++;
        } 
        else{
            // 🏗️ Place cube on found tower
            tops[pos] = cube;
        }
    }

    cout<<towers<<endl;
    return 0;
}
