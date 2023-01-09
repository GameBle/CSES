#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n,x;
    cin>>n>>x;
    vll v(n);
    for(auto &i : v) cin>>i;
    vector<pair<ll,ll>> vp;
    for(int i=0;i<n;i++){
        vp.push_back({v[i],i+1});
    }
    sort(v.begin(),v.end());
    sort(vp.begin(),vp.end());
    pair<ll,ll> ans = {-1,-1};
    for(int i=0;i<n;i++){
        ans.first = vp[i].second; ll it;
        if(x-v[i] >= vp[i].first)
        it = lower_bound(v.begin()+i+1,v.end(),x-v[i])-v.begin();
        else
        it = lower_bound(v.begin(),v.begin()+i,x-v[i])-v.begin();
        if(v[it] != x-v[i]) continue;
        ans.second = vp[it].second;
        break;
    }
    if(ans.first == -1 or ans.second == -1){
        cout<<"IMPOSSIBLE";
        return;
    }
    cout<<ans.first<<" "<<ans.second;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
