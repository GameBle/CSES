#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n,x;
    cin>>n>>x;
    vll v(n);
    for(auto &i : v) cin>>i;
    sort(v.begin(),v.end());
    int i=0,j=n-1;
    int ans = 0;
    vll mark(n,-1);
    while(i<j){
        while(v[j]+v[i] > x and j>i){
            j--;
        }
        mark[i] = 1;
        mark[j] = 1;
        j--;
        ans++;
        i++;
    }
    for(int k=0;k<n;k++){
        if(mark[k] == -1) ans++;
    }
    cout<<ans;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
