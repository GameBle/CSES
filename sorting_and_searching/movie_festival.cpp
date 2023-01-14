#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    vector<pair<ll,ll>> vp;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        vp.push_back({start,end});
    }
    sort(vp.begin(),vp.end());
    ll last = INT_MIN,ans = 0;
    for(int i=0;i<n;i++){
        if(vp[i].first >= last){
            ans++;
            last = vp[i].second;
        }
    }
    cout<<ans;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
