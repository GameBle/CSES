#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;
    cin >> n;
    vector<ll> vc;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        auto addr = lower_bound(vc.begin(),vc.end(),x+1);
        if(addr == vc.end()){
            vc.push_back(x);
        }else{
            vc[addr-vc.begin()] = x;
        }
    }
    cout << vc.size();
}


int main() {
    int t = 1;
    // cin >> t;
    do { solve(); } while (--t);
	return 0;
}
