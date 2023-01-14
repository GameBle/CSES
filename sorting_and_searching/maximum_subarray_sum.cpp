#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    vll v(n);
    for(auto &i : v) cin>>i;
    ll max_sum = LLONG_MIN;
    ll curr_sum = 0;
    for(int i=0;i<n;i++){
        if(curr_sum + v[i] >= v[i]){
            curr_sum +=  v[i];
        }
        else{
            curr_sum = v[i];
        }
        max_sum = max(max_sum,curr_sum);
    }
    cout<<max_sum<<endl;
    return;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
