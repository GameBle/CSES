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

//Ctrl+Alt+F: Format current file.

int dfs(vector<int> adj[], vector<int>& vis, int u, int p){
	vis[u] = 1;
	for(auto &it : adj[u]){
		int val = dfs(adj,vis,it,u);
		// cout<<val<<endl;
		vis[u] += val;
	}
	return vis[u];
}


void solve() {
	int n;cin>>n;
	vector<int> adj[n+1];
	for(int i = 2; i <= n; i++){
		int x;
		cin>>x;
		adj[x].push_back(i);
	}
	// for(int i = 1; i <= n; i++){
	// 	for(auto &j : adj[i]){
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<int> vis(n+1, 0);
	int val = dfs(adj,vis,1,0);
	for(int i = 1; i <= n; i++){
		cout<<vis[i]-1<<" ";
	}
}


int main() {
	ll t = 1;
	//cin >> t;
	do { solve(); } while (--t);
	return 0;
}