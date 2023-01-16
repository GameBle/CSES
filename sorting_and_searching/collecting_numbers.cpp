#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>

void solve(){
    ll n;cin>>n;
    vector<pair<ll,ll>> vp;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        vp.push_back({x,i});
    }
    sort(vp.begin(),vp.end());
    ll count = 0;
    for(ll i=0;i<n;i++){
        if(i == n-1){
            count++;
            break;
        }
        while(vp[i].second < vp[i+1].second and i<n){
            i++;
            if(i == n-1) break;
        }
        count++;
    }
    cout<<count;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
