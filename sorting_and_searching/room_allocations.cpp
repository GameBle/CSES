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
	ll n;cin>>n;
	vector<pair<ll,pair<ll,ll>>> v(n,{0,{0,0}});
	for(int i = 0; i < n; i++){
		cin>>v[i].first>>v[i].second.first;
		v[i].second.second = i+1;
	}
	sort(v.begin(), v.end());
	// for(auto &i : v){
	// 	cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
	// }
	ll room_no = 1;
	priority_queue <pll, vector<pll>, greater<pll> > pq;
	ll b = v[0].second.first;
	pq.push({b,room_no});
	vll res(n,0);
	res[v[0].second.second-1] = room_no;
	ll count = 1;
	for(int i = 1; i < n; i++){
		ll s = v[i].first, e = v[i].second.first;
		ll loc = v[i].second.second-1;
		if(s > pq.top().first){ // room khaali hai
			ll rn = pq.top().second;
			pq.pop();
			//naya node of pq ghusa denge
			pq.push({e,rn});
			res[loc] = rn;
		}else{
			count++;
			// naya room banega
			room_no++;
			pq.push({e,room_no});
			res[loc] = room_no;
		}
	}	
	cout<<count<<endl;
	for(auto &i : res){
		cout<<i<<" ";
	}
	cout<<endl;
}


int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}