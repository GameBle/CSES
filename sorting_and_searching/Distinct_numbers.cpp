#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;



void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v){
        cin>>i;
    }
    sort(v.begin(),v.end());
    int count = 0;
    for(int i=0;i<n;i++){
        while(v[i] == v[i+1]){
            i++;
        }
        count++;
    }
    cout<<count;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
