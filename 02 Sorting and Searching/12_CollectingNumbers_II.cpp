#include<bits/stdc++.h>
using namespace std;

int check(int i, vector<int>& pos){
    if(i > 1 && pos[i] < pos[i - 1])
        return 1;
    return 0;
}

int count(vector<int>& pos, int n){
    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]) cnt++;
    }
    return cnt;
}

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> v(n);
    for(int i = 0; i < n; i++)      cin >> v[i];

    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        pos[v[i]] = i;
    }

    int rounds = count(pos, n);

    while(t--){
        int x, y;
        cin >> x >> y;

        int i = v[x - 1];
        int j = v[y - 1];

        set<int> affected = {i, i+1, j, j+1};
        for(int val : affected){
            if(val >= 1 && val <= n)
                rounds -= check(val, pos);
        }

        swap(v[x - 1], v[y - 1]);
        swap(pos[i], pos[j]);

        for(int val : affected){
            if(val >= 1 && val <= n)
                rounds += check(val, pos);
        }

        cout << rounds << endl;
    }

    return 0;
}
