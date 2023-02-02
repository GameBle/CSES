#include <bits/stdc++.h>
#define ll long long
#define vll vector<int>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>
 
void solve(){
   ll n,m;cin>>n>>m;
   vector<vector<char>> grid(n,vector<char>(m));
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           cin>>grid[i][j];
       }
   }
   queue<pair<ll,ll>> q;
   ll count = 0;
   ll delRow[] = {-1,0,+1,0};
   ll delCol[] = {0,+1,0,-1};
   
   vector<vector<bool>> vis(n,vector<bool>(m,false));
   
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(!vis[i][j] and grid[i][j] == '.'){
               q.push({i,j});
               vis[i][j] = true;
               while(!q.empty()){
                   int r = q.front().first;
                   int c = q.front().second;
                   q.pop();
                   for(int k=0;k<4;k++){
                       int nRow = r + delRow[k];
                       int nCol = c + delCol[k];
                       if(nRow<n and nRow>=0 and nCol<m and nCol>=0 and
                        grid[nRow][nCol] == '.' and vis[nRow][nCol] == false){
                           q.push({nRow,nCol});
                           vis[nRow][nCol] = true;
                       }
                   }
               }
               count++;
           }
       }
   }
   cout<<count;
}


int main() {
    //int t = 1;
  //  cin >> t;
    solve();
	return 0;
}
