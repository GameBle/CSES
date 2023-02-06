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
    ll n,x;cin>>n>>x;
    vll v(n);
    for(auto &i : v) cin>>i;
    vll dp(x+1,0);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j-v[i] >= 0){
                dp[j] += dp[j-v[i]];
                dp[j] %= mod;
            }
        }
    }
    cout<<dp[x];
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
