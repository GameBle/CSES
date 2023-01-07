#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main()
{
    string s;cin>>s;
    std::vector<string> ans;
    sort(s.begin(), s.end());///very important step because next permutation prints all permutations in order
    do{
      ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    cout<<ans.size()<<"\n";
    for(string a : ans){
      cout<<a<<"\n";
    }
    return 0;
}