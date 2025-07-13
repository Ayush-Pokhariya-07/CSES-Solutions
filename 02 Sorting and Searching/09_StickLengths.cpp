// ✅ Problem: Stick Lengths
// 🔗 Link: https://cses.fi/problemset/task/1074
// 🧠 Idea: To minimize total cost, make all sticks equal to the median length
// 🚀 Time: O(n log n), Space: O(1)

// 🔥 Why Median?
// - For minimizing sum of absolute differences, median gives optimal result
// - Unlike mean (used for squared diff), median minimizes total linear movement


#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll findMinCost(vector<ll>& arr, int n){
    sort(arr.begin(),arr.end());
    ll cost = 0;

    int mid = arr[n/2];

    for(int i=0;i<n;i++){
        if(arr[i] != mid){
            cost += abs(mid - arr[i]);
        }    
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];

    cout<<findMinCost(arr,n);

    return 0;
}


