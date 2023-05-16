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
	std::vector<int> v;
	for(int i = 0; i < n; i++){
		v.push_back(i+1);
	}
	while(v.size() > 1){
		std::vector<int> supp;
		for (int i = 0; i < v.size(); ++i)
		{
			if(i%2 == 1){
				cout<<v[i]<<" ";
			}else{
				supp.push_back(v[i]);
			}
		}
		if(v.size()%2 == 0)
			v = supp;
		else{
			int startingElement = supp.back();
			supp.pop_back();
			v.clear();
			v.push_back(startingElement);
			for(int i = 0; i < supp.size(); i++){
				v.push_back(supp[i]);
			}
		}
	}
	cout<<v[0];
}


int main() {
	ll t = 1;
	// cin >> t;
	do { solve(); } while (--t);
	return 0;
}