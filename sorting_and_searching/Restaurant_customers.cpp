#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    set<pair<ll,ll>> st;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        st.insert({a,1});
        st.insert({b,-1});
    }
    ll maxi = LLONG_MIN;
    ll count = 0;
    for(auto &i : st){
        count+=i.second;
        maxi = max(maxi,count);
    }
    cout<<maxi;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
