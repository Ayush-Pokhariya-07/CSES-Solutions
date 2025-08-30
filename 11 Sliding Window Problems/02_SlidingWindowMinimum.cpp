#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findAns(vector<ll> &nums, ll n, ll k){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        ll ans = 0;
        
        int left = 0;
        for(int right=0; right < n; right++){
            pq.push({nums[right],right});

            if(right - left + 1 == k){
                while(left > pq.top().second){
                    pq.pop();
                }
                ans ^= pq.top().first;
                left++;
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