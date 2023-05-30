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

vll par(100005);
vll path;
std::vector<bool> vis(100005, false);
vll adj[100005];
// ll par = 0, cnt = 0;
bool cycleFound = false;

void dfs(ll node, ll parent = -1){
	par[node] = parent;
	vis[node] = true;
	for(auto &it : adj[node]){
		if(it == parent){
			// cycleFound = true;
			continue;
		}
		if(vis[it]){
			cycleFound = true;
			ll temp = node;
			while(it != node){
				path.push_back(node);
				node = par[node];
			}
			path.push_back(it);
			path.push_back(temp);
			cout<<path.size()<<endl;
			ll sz = path.size();
			for(int i = 0; i < sz; i++){
				cout<<path[i]<<" ";
			}
			exit(0);
		}else{
			dfs(it, node);
		}
	}
	return;
}


void solve() {
	ll n,m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			// path.push_back(i);
			dfs(i);
		}
	}
	if(!cycleFound){
		cout<<"IMPOSSIBLE\n";
	}
}

int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}