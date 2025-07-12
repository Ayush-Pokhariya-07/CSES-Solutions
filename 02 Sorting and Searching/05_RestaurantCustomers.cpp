// ✅ Problem: Restaurant Customers
// 🔗 Link: https://cses.fi/problemset/task/1619
// 🧠 Idea: Track all entry (+1) and exit (-1) times, sort, and simulate timeline
// 🚀 Time: O(n log n), Space: O(n)

// 🔥 Approach:
// 1. For each customer, store two events: {arrival, +1}, {departure, -1}
// 2. Sort all events by time (entry before exit if same time)
// 3. Traverse the timeline:
//    - Add +1 on arrival, -1 on exit
//    - Track current number of customers and keep max


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
        arr.push_back({a,1});    // 🟢 Arrival = +1
        arr.push_back({b,-1});   // 🔴 Departure = -1
    }
    
    sort(arr.begin(),arr.end());
    
    ll ans = 0, cnt = 0;
    for(auto& a:arr){
        int x = a.second;       // ➕ Update current customer count
        cnt += x;
        ans = max(ans,cnt);     // 🎯 Track max at any time
    }

    cout<<ans;
    return 0;
}