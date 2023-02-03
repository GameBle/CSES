#include <bits/stdc++.h>
#define int long long
#define vll vector<int>
using namespace std;
//priority_queue <int, vector<int>, greater<int>>

bool valid(int row,int col,int n,int m){
    return (row>=0 and row<n and col>=0 and col<m);
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    pair<int,int> start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'A')start = {i,j};
        }
    }
    
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    char dir[] = {'U','R','D','L'};
    
    std::queue<pair<int,int>> q;
    vis[start.first][start.second] = true;
    q.push({start.first,start.second});
    
    map<pair<int,int>,pair<pair<int,int>,char>> mp;
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nRow = a + delRow[i];
            int nCol = b + delCol[i];
            if(valid(nRow,nCol,n,m) and !vis[nRow][nCol]
            and (grid[nRow][nCol] == '.' or grid[nRow][nCol] == 'B')){
                mp[{nRow,nCol}] = {{a,b},dir[i]};
                
                if(grid[nRow][nCol] == 'B'){
                    pair<int,int> end = {nRow,nCol};
                    string res = "";
                    while(true){
                        res+=mp[end].second;
                        end = mp[end].first;
                        if(end.first == start.first and end.second == start.second){
                            break;
                        }
                    }
                    reverse(res.begin(),res.end());
                    cout<<"YES\n";
                    cout<<res.size()<<endl;
                    cout<<res;
                    return;
                }
                vis[nRow][nCol]=true;
                q.push({nRow,nCol});
            }
        }
    }
    cout<<"NO";
}


signed main() {
    int t = 1;
    //cin >> t;
    do { solve(); } while (--t);
	return 0;
}
