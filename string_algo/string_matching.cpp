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
    string dic;
    cin>>dic;
    
    string srch;
    cin>>srch;
    
    string newString = srch + "#" + dic;
    
    int n = (int)newString.size();
    
    int lps[n];
    lps[0] = 0;
    int i = 1;
    int len = 0;
    
    
    while(i < n){
        if(newString[i] == newString[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len > 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    int cnt = 0;
    for(int j = 0;j<n;j++){
        if(lps[j] == (int)srch.size()){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
