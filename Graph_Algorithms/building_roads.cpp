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
 
void dfs(int node,vector<bool>& vis,vll adj[]){
    vis[node] = true;
    for(auto it : adj[node]){
        if(vis[it] == false)
        dfs(it,vis,adj);
    }
}
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vll adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n+1,false);
    ll count = 0;
    vll new_roades;
    for(int i=1;i<=n;i++){
        if(vis[i] == false){
            new_roades.push_back(i);
            dfs(i,vis,adj);
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=0;i<(int)new_roades.size()-1;i++){
        cout<<new_roades[i]<<" "<<new_roades[i+1]<<endl;
    }
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
