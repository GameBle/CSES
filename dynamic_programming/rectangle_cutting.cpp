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
	ll n,m;
	cin>>n>>m;
	vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i==j){
				dp[i][j] = 0;
			}
			// horizontal cut
			for(int k = 1; k < i; k++){
				dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
			}
			// vertical cut
			for(int k = 1; k < j; k++){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
			}
		}
	}
	cout<<dp[n][m];
}

int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}