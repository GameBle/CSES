#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n,m;cin>>n>>m;
    vll tickets(n);
    vll customer(m);
    map<ll,ll> mp;
    for(ll i=0;i<n;i++) {cin>>tickets[i];mp[tickets[i]]++;}
    for(auto &i : customer) cin>>i;
    for(ll i=0;i<m;i++){
        auto it = mp.upper_bound(customer[i]);
        if(it == mp.begin()){
            cout<<-1<<endl;
            continue;
        }
        it--;
        cout<<it->first<<endl;
        it->second--;
        if(it->second == 0) mp.erase(it);
    }
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
