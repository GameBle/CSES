#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v) cin>>i;
    ll xorr = v[0];
    for(int i=1;i<n;i++){
        xorr^=v[i];
    }
    if(xorr != 0){
        cout<<"first"<<endl;
    }else{
        cout<<"second"<<endl;
    }
}


int main() {
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
	return 0;
}
