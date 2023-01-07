#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;



void solve(){
    priority_queue<int> pq;
    ll n;cin>>n;
    vll v(n);
    ll count = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i == 0){
            count++;
        }else{
            if(v[i] < pq.top()){
                count+=0;
            }else{
                count+=1;
            }
        }
        pq.push(v[i]);
    }
    cout<<count;
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
