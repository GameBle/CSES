#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define rep(a, b, c) for (int a = b; a < c; a++)
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
using namespace __gnu_pbds;
using namespace std;
 
void solve(){
    ll n,target;
    cin>>n>>target;
    vector<ll> v(n);
    for(auto &i : v) cin>>i;
    
    vector<ll> pref(n);
    pref[0] = v[0];
    for(ll i = 1; i < n; i++){
        pref[i] = v[i] + pref[i-1];
    }
    
    unordered_map<ll,ll> countPref;
    ll answer = 0;
    countPref[0]++;
    
    for(ll R=0;R<n;R++){
        //pref[R] - pref[L-1] = k
        //pref[L-1] = pref[R] - k ==> need
        ll need = pref[R] - target;
        answer+=countPref[need];
        countPref[pref[R]]++;
    }
    cout<<answer;
}


int main() {
    ll t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
