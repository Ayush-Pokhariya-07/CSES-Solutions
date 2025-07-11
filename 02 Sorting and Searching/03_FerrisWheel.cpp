// ✅ Problem: Ferris Wheel
// 🔗 Link: https://cses.fi/problemset/task/1090
// 🧠 Idea: Pair the heaviest person with the lightest person if their total ≤ x
// 🚀 Time: O(n log n), Space: O(1) extra

// 🔥 Approach:
// 1. Sort the array of weights
// 2. Use two pointers: left (lightest), right (heaviest)
// 3. If they fit together in one gondola (sum ≤ x), move both pointers
// 4. Else, the heavier person goes alone (move only right pointer)
// Count every attempt (whether solo or pair)


#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll count(vector<ll>& arr, ll n, ll x){
    sort(arr.begin(),arr.end());
    ll cnt = 0;

    ll left = 0;
    ll right = n-1;
    while(left <= right){
        if(arr[left] + arr[right] <= x){
            left++;
            right--;
        }
        else{
            right--;
        }
        cnt++;
    }
    return cnt;
}

int main(){
    ll n,x;
    cin>>n>>x;

    vector<ll> arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];

    cout<<count(arr,n,x);

    return 0;
}