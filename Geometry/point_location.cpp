#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>


void solve(){
    ll x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    y2-=y1;
    x2-=x1;
    y3-=y1;
    x3-=x1;
    ll val = x2*y3 - y2*x3;
    if(val > 0) cout<<"LEFT"<<endl;
    else if(val < 0) cout<<"RIGHT"<<endl;
    else cout<<"TOUCH"<<endl;
}


int main() {
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
	return 0;
}
