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
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        vp[i] = {a,i+1};
    }
    sort(vp.begin(),vp.end());
    for(int i=0;i<n;i++){
        int curr = vp[i].first;
        int req_sum = x-curr;
        int l = i+1;
        int r = n-1;
        while(l < r){
            if(vp[l].first + vp[r].first > req_sum){
                r--;
            }else if(vp[l].first + vp[r].first < req_sum){
                l++;
            }else{
                cout<<vp[i].second<<" "<<vp[l].second<<" "<<vp[r].second<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}


int main() {
    ll t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
