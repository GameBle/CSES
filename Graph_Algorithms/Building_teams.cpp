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

std::vector<bool> vis(100005, false);
vll color(100005,0);
vll adj[100005];


bool dfs(int node, int c){
	vis[node] = true;
	color[node] = c;
	for(auto &it : adj[node]){
		if(vis[it] == false){
			bool res = dfs(it, c^1);
			if(res == false) return false;
		}else{
			if(color[node] == color[it]) return false;
		}
	}
	return true;
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
	bool flag = true;
	for(int i = 1; i <= n; i++){
		if(vis[i] == false){
			flag = dfs(i, 0);
			if(flag == false) break;
		}
	}
	if(!flag){
		cout<<"IMPOSSIBLE\n";
	}else{
		for(int i = 1; i <= n; i++){
			cout<<color[i]+1<<" ";
		}
	}
}

int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}