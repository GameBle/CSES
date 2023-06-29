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

void solve() {
    ll n;cin>>n;
    vll v(n);
    vector<vll> dp(n,vll(n,0));
    ll sum = 0;
    for(int i = 0; i < n; i++){
    	cin>>v[i];
    	dp[i][i] = v[i];
    	sum += v[i];
    }
    for(int i = n-1; i >= 0; i--){
    	for(int j = i+1; j < n; j++){
    		dp[i][j] = max(v[i]-dp[i+1][j],v[j]-dp[i][j-1]);
    	}
    }
    cout<<(sum+dp[0][n-1])/2<<endl;
}

int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}