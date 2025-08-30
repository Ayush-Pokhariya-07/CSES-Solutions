#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n==1){
        cout<<1;
        return 0;
    }

    vector<int> v;
    for (int i = 1; i <= n; i++) v.push_back(i);

    int i = 1; 
    while(!v.empty()){
        cout << v[i] <<" ";
        v.erase(v.begin() + i);  

        if(v.empty())    break;

        i = (i+1) % v.size();  
    }

    return 0;
}
