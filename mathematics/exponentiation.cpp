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
    ll x,y;
    cin>>x>>y;
    // Initialize answer
    ll res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = ((res%mod) * (x%mod))%mod;
 
        // y = y/2
        y >>= 1;
 
        // Change x to x^2
        x = ((x%mod) * (x%mod))%mod;
    }
    cout<< res % mod <<endl;
}


int main() {
    ll t = 1;
    cin >> t;
    do { solve(); } while (--t);
	return 0;
}
