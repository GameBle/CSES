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
	string A, B;
	cin >> A >> B;
	int n = (int)A.size();
	int m = (int)B.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for(int j = 0; j <= m; j++){
		dp[n][j] = m - j;
	}
	for(int i = 0; i <= n; i++){
		dp[i][m] = n - i;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i + 1][j + 1];
			} else {
				dp[i][j] = 1 + min(dp[i + 1][j],min(dp[i][j + 1],dp[i+1][j+1]));
			}
		}
	}
	cout << dp[0][0];
}

int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}