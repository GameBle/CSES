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
	ll n; cin >> n;
	std::vector<ll> arr(n);
	map<ll, ll> mp;
	ll count = 0, sum = 0;
	mp[0]++; // for rem == 0
	for (int i = 0; i < n; i++) {
		cin>>arr[i];
		sum = (((sum + arr[i])%n)+n)%n;
		count += mp[sum];
		mp[sum]++;
	}
	cout<<count<<endl;
}


int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}