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
 
void solve(){
    int n,x;cin>>n>>x;
    vector<int> v(n);
    for(auto &i : v) cin>>i;
    int l = 0,r = 0;
    int count = 0,curr_sum = v[0];
    while(r < n){
        if(curr_sum < x){
            r++;
            curr_sum += v[r];
        }else if(curr_sum > x){
            curr_sum -= v[l];
            l++;
        }else{
            count++;
            r++;
            curr_sum += v[r];
        }
        //cout<<curr_sum<<" "<<count<<" $ ";
    }
    //cout<<endl;
    cout<<count<<endl;
}


int main() {
    ll t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
