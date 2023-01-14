#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>

ll func(ll val,vll &v){
    ll ans = 0;
    for(ll i=0;i<v.size();i++){
        ans+=abs(v[i] - val);
    }
    return ans;
}
void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v) cin>>i;
    sort(v.begin(),v.end());
    if(n%2 != 0){
        ll mid_odd = n/2;
        ll val_mid = func(v[mid_odd],v);
        cout<<val_mid<<endl;
        return;
    }
    ll val_mid_one = func(v[n/2],v);
    ll val_mid_two = func(v[n/2 - 1],v);
    ll ans = min(val_mid_two,val_mid_one);
    cout<<ans<<endl;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
