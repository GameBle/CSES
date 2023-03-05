#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <sstream>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
//using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
 
#define mod 1000000007
#define inf 1e9
#define f(i,n) for(int i=0;i<n;i++)
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define w(t) ll tt;cin>>tt;while(tt--)
#define pb push_back
#define endl "\n"
#define read(arr,n) for(ll i=0;i<n;i++){cin>>arr[i];};
#define pi pair<ll,ll>
#define all(arr) arr.begin(),arr.end()
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//options: less,greater_equal,less_equal,greater
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
const int N=3e5+5;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
int p[N];
 
ll modulo(ll a, ll b, ll n){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
            
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}
 
ll modmod(ll a,ll b,ll c){
    // Fermats Little Theorem
    // A^(M-1) = 1 (mod M) if M is a prime.
    // So write B^C as x*(M-1) + y
    
    ll y = modulo(b,c,mod-1);
 
    return modulo(a,y,mod);
}
 
ll value[1000001];
void fillNumberOfDivisorsArray(){
    for(ll i=1;i<=1000000;i++){
        for(ll j=1;i*j<=1000000;j++){
            value[i*j]++;
        }
    }
}
 
vector<ll> prime;
bool is_composite[N];
 
void sieve(ll n) {
 
    fill(is_composite,is_composite + n,false);
 
    for (ll i=2;i<n;i++){
 
        if(!is_composite[i]){
            prime.push_back(i);
        }
 
        for (int j=2;i*j < n;j++){
            is_composite[i * j] = true;
        }
    }
}
 
void addEdge(vector<ll> adj[],ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}
 
ll __lcm(ll a,ll b){
    return a*b/(__gcd(a,b));
}
 
vector<ll> fact;
void factorialFill(){
    fact.pb(1);
    fact.pb(1);
    for(ll i=2;i<=1000000;i++){
        fact.pb((i%mod * fact.back()%mod)%mod);
    }
}
ll getfact(ll num){
    return fact[num]%mod;
}
 
ll getBits(ll num){
    return log2(num) + 1;
}
 
 
struct cmp {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
        return a.first < b.first;
    }
};
 
struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd; // each node has two parts t/f and pointer to each alphabet
    TrieNode(){ // constructor
        isEnd = false;
        for(ll i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};
 
TrieNode *root;
bool searchString(string str){ // searching string in trie
    TrieNode *curr = root;
    ll n = str.length();
    for(ll i=0;i<n;i++){
        int idx = str[i] - 'a';
        if(curr->child[idx]==NULL){
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEnd;
}
 
void insertString(string str){
    TrieNode *curr = root;
    ll n = str.length();
    for(ll i=0;i<n;i++){
        int idx = str[i] - 'a';
        if(curr->child[idx] == NULL){
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}
 
void solve(ll tc){
    string str;
    cin>>str;
 
    ll n;
    cin>>n;
 
    root = new TrieNode();
 
    for(ll i=0;i<n;i++){
        string st;
        cin>>st;
        insertString(st);
    }
 
    ll len = str.length();
 
 
    vector<int> dp(len+1);
 
    dp[len] = 1;
 
    for(ll i=len-1;i>=0;i--){
        TrieNode *test = root;
        for(ll j=i;j<len;j++){
            ll idx = str[j] - 'a';
            if(test->child[idx] == NULL){
                break;
            }
            test = test->child[idx];
            if(test->isEnd){
                dp[i] = dp[i]%mod + dp[j+1]%mod;
                dp[i] = dp[i]%mod;
            }
        }
    }
    cout<<dp[0]<<endl;
}
 
int main() {
 
    FIO;
    #ifndef ONLINE_JUDGE
        freopen("debug.txt", "w", stderr);
    #endif
    ll tt = 1;
    for(ll i=1;i<=tt;i++){
        solve(i);
    }
 
    return 0;
}