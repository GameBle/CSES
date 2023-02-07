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
    ll n;cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0] == '*'){
        cout<<0;
        return;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    dp[1][1] = 1;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         if((i == 0 or j == 0)){
    //             dp[i][j] = 0;
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i-1][j-1] == '.'){
                    dp[i][j] = (dp[i][j]%mod + dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
                }
        }
    }
    cout<<dp[n][n];
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
