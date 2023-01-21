#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n,m;cin>>n>>m;
    set<ll> positions;
    multiset<ll> lengths;
    positions.insert(0);
    positions.insert(n);
    lengths.insert(n);
    for(ll i=0;i<m;i++){
        ll index;cin>>index;
        positions.insert(index);
        auto it = positions.find(index);
        ll prev_val = *prev(it);
        ll next_val = *next(it);
        lengths.erase(lengths.find(next_val-prev_val));
        lengths.insert(next_val-index);
        lengths.insert(index-prev_val);
        cout<<*lengths.rbegin()<<" ";
    }
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
