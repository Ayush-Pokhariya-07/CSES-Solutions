#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> ans;

    ans.push_back(n);

    while(n != 1){
        if(n%2 == 0){
            n /= 2;
            ans.push_back(n);
        }
        else{
            n = n * 3 + 1;
            ans.push_back(n);
        }
    }

    for(int i=0;i<ans.size();i++)   cout<<ans[i]<<" ";

    return 0;
}