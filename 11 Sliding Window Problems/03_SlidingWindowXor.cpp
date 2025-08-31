#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findAns(vector<ll> &nums, ll n, ll k){
    ll ans = 0;
    ll XOR = 0;

    int left = 0;
    for(int right=0; right < n; right++){
        XOR ^= nums[right];
        if(right-left+1 == k){
            ans ^= XOR;
            XOR ^= nums[left++];
        }
    }
    return ans;
}

int main(){
    ll n, k;
    cin>>n>>k;

    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll> nums(n);

    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = (a * nums[i-1] + b) % c;
    }

    ll ans = findAns(nums, n, k);

    cout<<ans;

    return 0;
}