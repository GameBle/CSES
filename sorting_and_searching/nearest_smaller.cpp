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
	int n; cin >> n;
	std::vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	stack<pair<int, int>> S;
	// Traverse all array elements
	for (int i = 0; i < n; i++)
	{
		// Keep removing top element from S while the top
		// element is greater than or equal to arr[i]
		while (!S.empty() && S.top().ff >= arr[i]) {
			S.pop();
		}
		// If all elements in S were greater than arr[i]
		if (S.empty())
			cout << 0 << " ";
		else {
			int val = S.top().ff;
			int ind = S.top().ss;
			cout << ind << " ";
		} //Else print the nearest smaller element

		// Push this element
		S.push({arr[i],i+1});
	}
}


int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}