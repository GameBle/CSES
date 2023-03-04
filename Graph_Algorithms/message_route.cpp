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
    int n,m;cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1,INT_MAX);
    dist[1] = 0;
    priority_queue <pair<int,int>, vector<pair<int,int>>,
    greater<pair<int,int>>> pq;
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    pq.push({0,1});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjNode = it;
            if(dis + 1 < dist[adjNode]){
                dist[adjNode] = dis + 1;
                parent[adjNode] = node;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    if(dist[n] == INT_MAX){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<dist[n] + 1<<endl;
    int node = n;
    vector<int> path;
    while(parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(auto it : path){
        cout<<it<<" ";
    }
    return;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
