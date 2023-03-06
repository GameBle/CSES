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
    string s;
    cin>>s;
    
    int n = (int)s.size();
    
    int lsp[n];
    lsp[0] = 0;
    
    int i = 1;
    int len = 0;
    
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lsp[i] = len;
            i++;
        }else{
            if(len > 0){
                len = lsp[len - 1];
            }else{
                lsp[i] = 0;
                i++;
            }
        }
    }
    
    vll sol;
    int j = n-1;
    while(j > 0){
        if(lsp[j]!=0)
        sol.push_back(lsp[j]);
        j = lsp[j - 1];
    }
    reverse(sol.begin(),sol.end());
    for(int k = 0;k<(int)sol.size();k++){
        cout<<sol[k]<<" ";
    }
    cout<<endl;
    return;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
