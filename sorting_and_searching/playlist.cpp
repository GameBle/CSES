#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v) cin>>i;
    map<ll,ll> mp;
    ll ans = LLONG_MIN;
    for(ll i=0,j=0;i<n;i++){
        while(mp[v[j]] < 1 and j<n){
            mp[v[j]]++;
            j++;
        }
        ans = max(ans,j-i);
        mp[v[i]]--;
    }
    cout<<ans;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
