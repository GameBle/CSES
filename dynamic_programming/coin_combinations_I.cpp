#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mod 1000000007
using namespace std;
//priority_queue <int, vector<int>, greater<int>>

void solve(){
    ll n,x;cin>>n>>x;
    vll v(n);
    for(auto &i : v){
        cin>>i;
    }
    vll dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-v[j] >= 0)
            dp[i] = (dp[i] + dp[i-v[j]])%mod;
        }
    }
    if(dp[x] == 0){
        cout<<-1;
        return;
    }
    cout<<dp[x];
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
