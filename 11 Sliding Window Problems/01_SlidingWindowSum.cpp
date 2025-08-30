#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;

    long long x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<long long> nums(n);

    nums[0] = x;
    for(int i = 1; i < n; i++){
        nums[i] = (a * nums[i-1] + b) % c;
    }

    long long ans = 0, sum = 0;

    int left = 0, right = 0;
    while(right < n){
        if((right - left) >= k){
            sum -= nums[left++];
        }
        while((right - left) < k && right < n){
            sum += nums[right++];
        }
        ans ^= sum;
    }

    cout<<ans;

    return 0;
}