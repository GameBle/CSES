#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>
#define mod 998244353

void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int row,int col,int n,int m){
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = true;
        while(!q.empty()){
            int nrow = q.front().first;
            int mcol = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nigga_row=nrow+i;
                    int migga_col=mcol+j;
                    if(nigga_row>=0 and nigga_row<n and migga_col>=0 and migga_col<m
                        and grid[nigga_row][migga_col]=='.' and !vis[nigga_row][migga_col]){
                            vis[nigga_row][migga_col] = true;
                            q.push({nigga_row,migga_col});
                    }
                }
            }
        }
    }
    void numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j] == '.'){
                    bfs(grid,vis,i,j,n,m);
                    count++;
                }
            }
        }
        cout<<count;
    }


int main() {
    int t = 1;
    //cin >> t;
    int n,m;cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    do { numIslands(grid); } while (--t);
	return 0;
}
