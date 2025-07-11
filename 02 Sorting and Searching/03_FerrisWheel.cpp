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