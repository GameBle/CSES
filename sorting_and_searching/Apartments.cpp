#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vll v(n);
    vll a(m);
    for(auto &i : v) cin>>i;
    for(auto &i : a) cin>>i;
    sort(v.begin(),v.end());
    sort(a.begin(),a.end());
    ll count = 0;
    for(int i=0,j=0;i<n;i++){
        while(j<m and a[j]<v[i]-k)
        j++;
        if(j<m and a[j] <= v[i]+k){
        j++;count++;}
    }
    cout<<count;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
