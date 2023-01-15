#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v) cin>>i;
    
    sort(v.begin(),v.end());
    if(v[0]!=1){
        cout<<1<<endl;
        return;
    }
    vll pref(n);
    pref[0] = v[0];
    for(int i=1;i<n;i++){
        pref[i] = v[i]+pref[i-1];
    }
    for(int i=0;i<n;i++){
        if(i==n-1 || v[i+1]>pref[i]+1){
            cout<<pref[i]+1<<endl;
            return;
        }
    }
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
