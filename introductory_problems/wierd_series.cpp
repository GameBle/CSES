#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll n;cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2 == 0){
            n/=2;
            if(n==1){
                cout<<1;
                continue;
            }
            cout<<n<<" ";
        }else{
            n*=3;
            n+=1;
            if(n==1){
                cout<<1;
                continue;
            }
            cout<<n<<" ";
        }
    }
}


int main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
