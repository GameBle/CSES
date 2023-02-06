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
#define mod 1000000007;
using namespace __gnu_pbds;
using namespace std;
 
void solve(){
    ll n;cin>>n;
    // state --> dp[i] = no. of ways to make sum i using the dice
    // transition --> dp[i] = no. of ways to make dp[i-1]+...+dp[i-6]
    // base case --> dp[0] = 1 to make sum 0 don't throw dice
    // final subproblem = dp[n] = no. of ways to make sum n using dice
    vll dp(n+1,0);
    // base case
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[n];
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
