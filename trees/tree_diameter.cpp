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

// one way to do this is :-
// 1. run a bfs from u --> get a farthest node v
// 2. from v run another bfs --> get farthest node k
// 3. distance between v and k is the diameter of the tree (proof not required).

// solving using dp :-
// 1. root --> any arbitary node.
// 2. there are two cases --> root is included in the diameter / not included in the diameter
// 3. if it is not included then a recurrence relation is generated where maximum of
// diameter among each subtree of the child nodes is the answer
// 4. if it is included then 2 + downpath(cb1) + downpath(cb2);
// cb1 = longest downpath and cb2 = second longest downpath
// downpath = longest path starting from the node itself.

vll adj[2e5+1];
// diameter[i] = diameter if path pass through node i;
vll diameter(2e5+1);
// downpath[i] = longest simple path in subtree rooted at i starting from i
vll downPath(2e51+1);

void solve() {

}


int main() {
	ll t = 1;
	//cin >> t;
	while(t--){
		ll n;
		cin>>n;
		for(int i = 0; i < n; i++){
			int u,v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		eval_downPaths(1,0); // we are considering 1 as the root node.
		solve(1,0);
		cout<<diameter[1];
	}
	return 0;
}