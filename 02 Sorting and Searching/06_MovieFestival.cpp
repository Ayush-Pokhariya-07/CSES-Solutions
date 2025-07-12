// ✅ Problem: Movie Festival
// 🔗 Link: https://cses.fi/problemset/task/1629
// 🧠 Idea: Classic activity selection problem — sort by end time, pick non-overlapping
// 🚀 Time: O(n log n), Space: O(1) extra

// 🔥 Approach:
// 1. Store each movie as {end, start} for easy sorting by end time
// 2. Sort all intervals by end time (greedy strategy)
// 3. For each movie:
//    - If start ≥ last selected movie's end ➝ select it
//    - Update previousEnd and count selected


#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,int>> arr;
    
    while(n--){
        ll a,b;
        cin>>a>>b;
        arr.push_back({b,a});    
    }
    
    sort(arr.begin(),arr.end());
    
    ll pvsEnd = 0, cnt = 0;
    for(auto& it:arr){
        ll end = it.first;   
        ll start = it.second;
        
        if(start >= pvsEnd){
            cnt++;
            pvsEnd = end;
        }
    }

    cout<<cnt;
    return 0;
}