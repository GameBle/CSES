#include <bits/stdc++.h>
 
using namespace std;
 
//Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;
 
//Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1000000007;
 
//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll, ll> umll;
typedef map<ll, ll> mll;
 
// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(ll i=0;i<n;i++)
#define rl(i,m,n) for(ll i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define vin(v) for(auto &i:v){cin>>i;}
#define println(x) printf("%lld\n",x);
#define print(x) printf("%lld ",x);
#define getI(a) scanf("%lld", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%lld%lld", &a, &b)
#define getIII(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define getS(x) scanf("%s", x) //get a char* string
 
 
// Mathematical functions
ll gcd(ll a, ll b) {if (b == 0)return a; return gcd(b, a % b);} //__gcd
ll lcm(ll a, ll b) {return (a / gcd(a, b) * b);}
 
//Bits
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}
 
//Check
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(ll n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}
 
//Code
void solve()
{
	string s;
	cin>>s;
	ll start = 0,end = 0;
	ll len = s.size();
	if(len==1){
		println(1ll)
		return;
	}
	vll size;
	fl(i,len-1){
		if(s[i]!=s[i+1]){
			end = i+1;
			size.pb(end-start);
			start = i+1;
		}
		if(s[i]==s[i+1] && i+1 == len-1){
			end = len;
			size.pb(end - start);
		}
	}
	ll sol = *max_element(vr(size));
	println(sol)
	return;
}
//Main
int main()
{
	#ifndef ONLINE_JUDGE
 
	freopen("input.txt", "r", stdin);
 
	freopen("output.txt", "w", stdout);
 
	#endif
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll t = 1;
	//cin >> t;
	fl(i, t)
	{
		solve();
	}
	return 0;
}
//End