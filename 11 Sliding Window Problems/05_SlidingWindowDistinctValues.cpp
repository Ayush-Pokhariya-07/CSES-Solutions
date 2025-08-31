#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowDistinct(vector<int>& arr, int n, int k){
    unordered_map<int,int> freq;
    vector<int> result;

    int left = 0;
    for(int right = 0; right < n; right++){
        freq[arr[right]]++;
        if(right - left +1 == k){
            result.push_back((int)freq.size());
            if(--freq[arr[left]] == 0){
                freq.erase(arr[left]);
            }
            left++;
        }
    }
    
    return result;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin>>arr[i];

    vector<int> ans = slidingWindowDistinct(arr, n, k);

    for(int x : ans) cout<<x<<" ";
    cout<<"\n";

    return 0;
}
