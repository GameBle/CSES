#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
 
 
vector<ll> dp(1000007,-1);
 
int noOfWays(int n){
    if(n<0) return 0;
    if(n == 0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = 0;
    for(int i=1;i<=6;i++){
        dp[n] = (dp[n]+noOfWays(n-i))%mod;
    }
    return dp[n];
}
 
 
 
int main(){
    int n;cin>>n;
    cout<<noOfWays(n)%mod<<endl;
    return 0;
}