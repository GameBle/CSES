#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
 ll n;cin>>n;
 vector<pair<ll,ll>> vp;
 for(int i=0;i<n;i++){
     ll start,end;
     cin>>start>>end;
     vp.push_back({end,start});
 }
 sort(vp.begin(),vp.end());
 ll curr = -1;
 ll count = 0;
 for(int i=0;i<n;i++){
     //cout<<curr<<" "<<vp[i].second<<endl;
     if(vp[i].second >= curr){
         curr = vp[i].first;
         count++;
     }
 }
    cout<<count<<endl;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
