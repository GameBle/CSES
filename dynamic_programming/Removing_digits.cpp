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
    // state --> dp[i] = minimum number of steps needed to go from i to 0;
    // transition --> dp[i] = min(dp[i-digitsI])+1;
    // final subproblem = dp[n];
    // base case --> if n == 0 return 0;
    vll dp(n+1,LLONG_MAX);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int num = i;
        while(num > 0){
            int rem = num % 10;
            if(i-rem >= 0 and rem!=0)
            dp[i] = min(dp[i-rem]+1,dp[i]);
            num/=10;
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
